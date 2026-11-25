// d24c: 0x800fa21c (1108 bytes). Queue a derived input record: push it on the menu queue (+172) when
// the input service is in menu mode (+428), otherwise on the game queue (+76), then process
// it. Same inlined STLport-style push_back as d24c_input_post_8byte_800f8a48; the element
// constructors store the base vtable, then the derived one (0x804104d0). Names are inferred.
extern const unsigned char record_vtable_80410500[];
extern const unsigned char record_vtable_804104d0[];
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void *alloc_fallback_803413d8(unsigned);
extern "C" void release_802134fc(void *);
// Input record: 16-bit id and a value, the virtual table pointer after the data,
// then the derived class's fields.
struct InputRecord {
    unsigned short id;
    int value;
    const void *vtable;
    int a, b;
    InputRecord(unsigned short i, int x, int y, int v) {
        vtable = record_vtable_80410500;
        id = i;
        value = v;
        a = x;
        b = y;
        vtable = record_vtable_804104d0;
    }
    void copy_from(const InputRecord &o) {
        vtable = record_vtable_80410500;
        id = o.id;
        value = o.value;
        vtable = record_vtable_804104d0;
        a = o.a;
        b = o.b;
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
struct Input {
    unsigned char u0[76];
    RecordVector game;      // +76
    unsigned char ugap[80];
    RecordVector menu;      // +172
    unsigned char utail[240];
    int in_menu;            // +428
};
extern Input *input_804aaf48;
extern "C" void process_800fa670(Input *, const InputRecord *);
extern "C" void d24c_input_post_20byte_800fa21c(unsigned short id, int a, int b, int value) {
    InputRecord r(id, a, b, value);
    if (input_804aaf48->in_menu) input_804aaf48->menu.push_back(r);
    else input_804aaf48->game.push_back(r);
    process_800fa670(input_804aaf48, &r);
}
