// d24c: 0x800f8a48 (900 bytes). Queue an input record {id, value}: push it on the menu
// queue (+124) when the input service (0x804aaf48) is in menu mode (+428), otherwise on
// the game queue (+28), then process it through 0x800f8dcc. The vector code is the
// inlined STLport-style push_back: _M_insert_overflow with growth old + max(old, 1),
// element-wise copy, then clear and set. Elements are 12 bytes with the virtual table
// pointer after the data (0x80410500). Names are inferred.
extern const unsigned char record_vtable_80410500[];
extern "C" void *alloc_80212fd4(unsigned);
extern "C" void *alloc_fallback_803413d8(unsigned);
extern "C" void release_802134fc(void *);
// Input record: 16-bit id and a value, with the virtual table pointer after the data.
struct InputRecord {
    unsigned short id;
    int value;
    const void *vtable;
    InputRecord(unsigned short i, int v) { vtable = record_vtable_80410500; id = i; value = v; }
    InputRecord(const InputRecord &o) { vtable = record_vtable_80410500; id = o.id; value = o.value; }
    ~InputRecord() {}
};
inline void construct(InputRecord *p, const InputRecord &x) {
    if (p) { p->vtable = record_vtable_80410500; p->id = x.id; p->value = x.value; }
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
    void set(InputRecord *s, InputRecord *f, InputRecord *e) { start = s; finish = f; end_of_storage = e; }
    static void *node_allocate(unsigned bytes) {
        void *p = alloc_80212fd4(bytes);
        if (!p) p = alloc_fallback_803413d8(bytes);
        return p;
    }
    InputRecord *allocate(unsigned n) {
        return n != 0 ? (InputRecord *)node_allocate(n * 12) : 0;
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
    unsigned char u0[28];
    RecordVector game;      // +28
    unsigned char u44[80];
    RecordVector menu;      // +124
    unsigned char u140[288];
    int in_menu;            // +428
};
extern Input *input_804aaf48;
extern "C" void process_800f8dcc(Input *, const InputRecord *);
extern "C" void d24c_input_post_8byte_800f8a48(unsigned short id, int value) {
    InputRecord r(id, value);
    if (input_804aaf48->in_menu) input_804aaf48->menu.push_back(r);
    else input_804aaf48->game.push_back(r);
    process_800f8dcc(input_804aaf48, &r);
}
