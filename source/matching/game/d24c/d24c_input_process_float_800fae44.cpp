// d24c: 0x800fae44 (884 bytes). Record an input while the service is recording (+432) and accepts it: push
// it on the queue at +380; past 100 records, create a list object, copy each field into its
// arrays, empty the queue and send the list to the sink at 0x804abac0. Names are inferred.
// CAVEAT: the empty ListType passed by value exists only to give the original 8-byte stack
// gap at sp+16; nothing in the original witnesses it. See needs_decision in the report.
extern const unsigned char record_vtable_80410500[];
extern const unsigned char record_vtable_804104c0[];
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void *alloc_fallback_803413d8(unsigned);
extern "C" void release_802134fc(void *);
// Input record: 16-bit id and a value, the virtual table pointer after the data,
// then the derived class's fields.
struct InputRecord {
    unsigned short id;
    int value;
    const void *vtable;
    float a;
    InputRecord(unsigned short i, int v, float x) {
        vtable = record_vtable_80410500;
        id = i;
        value = v;
        a = x;
        vtable = record_vtable_804104c0;
    }
    void copy_from(const InputRecord &o) {
        vtable = record_vtable_80410500;
        id = o.id;
        value = o.value;
        vtable = record_vtable_804104c0;
        a = o.a;
    }
    ~InputRecord() {}
};
inline void construct(InputRecord *p, const InputRecord &x) {
    if (p) p->copy_from(x);
}
inline const unsigned &maximum(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
inline InputRecord *copy_records(const InputRecord *first, const InputRecord *last, InputRecord *out) {
    for (; first != last; first++, out++) construct(out, *first);
    return out;
}
inline InputRecord *fill_records(InputRecord *out, unsigned n, const InputRecord &x) {
    for (; n != 0; n--, out++) construct(out, x);
    return out;
}
inline void destroy_records(InputRecord *first, InputRecord *last) {
    for (; first != last; first++) first->~InputRecord();
}
struct NotPod {};
struct RecordVector {
    InputRecord *start, *finish;
    int allocator;
    InputRecord *end_of_storage;
    unsigned size() const { return finish - start; }
    void clear() {
        destroy_records(start, finish);
        finish = start;
    }
    void set(InputRecord *s, InputRecord *f, InputRecord *e) { start = s; finish = f; end_of_storage = e; }
    static void *node_allocate(unsigned bytes) {
        void *p = alloc_80212fd4(bytes);
        if (!p) p = alloc_fallback_803413d8(bytes);
        return p;
    }
    InputRecord *allocate(unsigned n) {
        return n != 0 ? (InputRecord *)node_allocate(n * sizeof(InputRecord)) : 0;
    }
    void overflow(InputRecord *pos, const InputRecord &x, const NotPod &, unsigned n, bool at_end) {
        const unsigned old_size = finish - start;
        const unsigned length = old_size + maximum(old_size, n);
        InputRecord *new_start = allocate(length);
        InputRecord *new_finish = new_start;
        new_finish = copy_records(start, pos, new_start);
        if (n == 1) {
            construct(new_finish, x);
            new_finish++;
        } else {
            new_finish = fill_records(new_finish, n, x);
        }
        destroy_records(start, finish);
        if (start) release_802134fc(start);
        set(new_start, new_finish, new_start + length);
    }
    void push_back(const InputRecord &x) {
        if (finish != end_of_storage) {
            construct(finish, x);
            finish++;
        } else {
            overflow(finish, x, NotPod(), 1, true);
        }
    }
};
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *value;
    Ref(Object *o) : value(o) { if (value) value->vtable->retain(value); }
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Sink { struct V { void *u[10]; void (*send)(Sink *, Object *); } *vtable; };
extern Sink *sink_804abac0;
struct Input {
    unsigned char u0[380];
    RecordVector queue;     // +380
    unsigned char utail[36];
    int active;             // +432
};
extern "C" int can_accept_800f899c(Input *, const InputRecord *);
extern "C" Object *forward_8020b680(const void *);
extern "C" int *array_80240bf8(Object *, unsigned, int, int);
extern "C" int *array_80240cc8(Object *, unsigned, int, int);
extern "C" float *array_802410d8(Object *, unsigned, int, int);
extern const unsigned char key_8041aaa8[];
struct ListType { ListType() {} ListType(const ListType &) {} };
inline Object *create_list(ListType) { return forward_8020b680(key_8041aaa8); }
inline void flush(Input *self, RecordVector *q) {
    Ref h(create_list(ListType()));
    InputRecord *p = self->queue.start;
    Object *o = h.value;
    unsigned n = q->finish - p;
    int *ids = array_80240bf8(o, n, 0, 0);
    int *values = array_80240cc8(o, n, 0, 0);
    float *as = array_802410d8(o, n, 0, 0);
    while (p != q->finish) {
        *ids++ = p->id;
        *values++ = p->value;
        *as++ = p->a;
        p++;
    }
    InputRecord *first = self->queue.start;
    destroy_records(first, q->finish);
    q->finish = first;
    sink_804abac0->vtable->send(sink_804abac0, h.value);
}
extern "C" void d24c_input_process_float_800fae44(Input *self, const InputRecord *x) {
    if (self->active && can_accept_800f899c(self, x)) {
        self->queue.push_back(*x);
        if (self->queue.size() > 100) flush(self, &self->queue);
    }
}
