// d24c: 0x800f90e8 (1024 bytes). Queue a derived input record: push it on the menu queue (+140) when
// the input service is in menu mode (+428), otherwise on the game queue (+44), then process
// it. Same inlined STLport-style push_back as d24c_input_post_8byte_800f8a48; the element
// constructors store the base vtable, then the derived one (0x804104f0). Names are inferred.
extern const unsigned char record_vtable_80410500[];
extern const unsigned char record_vtable_804104f0[];
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void *alloc_fallback_803413d8(unsigned);
extern "C" void release_802134fc(void *);
// Input record: 16-bit id and a value, the virtual table pointer after the data,
// then the derived class's fields.
struct InputRecord {
    unsigned short id;
    int value;
    const void *vtable;
    int extra;
    InputRecord(unsigned short i, int e, int v) {
        vtable = record_vtable_80410500;
        id = i;
        value = v;
        extra = e;
        vtable = record_vtable_804104f0;
    }
    void copy_from(const InputRecord &o) {
        vtable = record_vtable_80410500;
        id = o.id;
        value = o.value;
        vtable = record_vtable_804104f0;
        extra = o.extra;
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
    unsigned char u0[44];
    RecordVector game;      // +44
    unsigned char ugap[80];
    RecordVector menu;      // +140
    unsigned char utail[272];
    int in_menu;            // +428
};
extern Input *input_804aaf48;
extern "C" void process_800f94e8(Input *, const InputRecord *);
extern "C" void d24c_input_post_16byte_800f90e8(unsigned short id, int extra, int value) {
    InputRecord r(id, extra, value);
    if (input_804aaf48->in_menu) input_804aaf48->menu.push_back(r);
    else input_804aaf48->game.push_back(r);
    process_800f94e8(input_804aaf48, &r);
}
