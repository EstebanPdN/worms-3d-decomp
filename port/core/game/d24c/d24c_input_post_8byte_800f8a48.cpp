#include "w3d_ptr.h"
#line 1 "d24c_input_post_8byte_800f8a48.cpp"
// d24c: 0x800f8a48 (900 bytes). Queue an input record {id, value}: push it on the menu
// queue (+124) when the input service (0x804aaf48) is in menu mode (+428), otherwise on
// the game queue (+28), then process it through 0x800f8dcc. The vector code is the
// inlined STLport-style push_back: _M_insert_overflow with growth old + max(old, 1),
// element-wise copy, then clear and set. Elements are 12 bytes with the virtual table
// pointer after the data (0x80410500). Names are inferred.
extern const unsigned char record_vtable_80410500[];
extern "C" Ptr32<void> alloc_80212fd4(unsigned);
extern "C" Ptr32<void> alloc_fallback_803413d8(unsigned);
extern "C" void release_802134fc(Ptr32<void>);
// Input record: 16-bit id and a value, with the virtual table pointer after the data.
struct InputRecord {
    unsigned short id;
    int value;
    Ptr32<const void> vtable;
    InputRecord(unsigned short i, int v) { vtable = record_vtable_80410500; id = i; value = v; }
    InputRecord(const InputRecord &o) { vtable = record_vtable_80410500; id = o.id; value = o.value; }
    ~InputRecord() {}
};
inline void construct(Ptr32<InputRecord> p, const InputRecord &x) {
    if (p) { p->vtable = record_vtable_80410500; p->id = x.id; p->value = x.value; }
}
inline const unsigned &maximum(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
inline Ptr32<InputRecord> copy_records(Ptr32<const InputRecord> first, Ptr32<const InputRecord> last, Ptr32<InputRecord> out) {
    for (; first != last; first++, out++) construct(out, *first);
    return out;
}
inline Ptr32<InputRecord> fill_records(Ptr32<InputRecord> out, unsigned n, const InputRecord &x) {
    for (; n != 0; n--, out++) construct(out, x);
    return out;
}
inline void destroy_records(Ptr32<InputRecord> first, Ptr32<InputRecord> last) {
    for (; first != last; first++) first->~InputRecord();
}
struct NotPod { char w3d_empty; };
struct RecordVector {
    Ptr32<InputRecord> start; Ptr32<InputRecord> finish;
    int allocator;
    Ptr32<InputRecord> end_of_storage;
    void set(Ptr32<InputRecord> s, Ptr32<InputRecord> f, Ptr32<InputRecord> e) { start = s; finish = f; end_of_storage = e; }
    static Ptr32<void> node_allocate(unsigned bytes) {
        Ptr32<void> p = alloc_80212fd4(bytes);
        if (!p) p = alloc_fallback_803413d8(bytes);
        return p;
    }
    Ptr32<InputRecord> allocate(unsigned n) {
        return n != 0 ? w3d::R((Ptr32<InputRecord>)node_allocate(n * 12)) : 0;
    }
    void overflow(Ptr32<InputRecord> pos, const InputRecord &x, const NotPod &, unsigned n, bool at_end) {
        const unsigned old_size = finish - start;
        const unsigned length = old_size + maximum(old_size, n);
        Ptr32<InputRecord> new_start = allocate(length);
        Ptr32<InputRecord> new_finish = new_start;
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
extern Ptr32<Input> input_804aaf48;
extern "C" void process_800f8dcc(Ptr32<Input>, Ptr32<const InputRecord>);
extern "C" void d24c_input_post_8byte_800f8a48(unsigned short id, int value) {
    InputRecord r(id, value);
    if (input_804aaf48->in_menu) input_804aaf48->menu.push_back(r);
    else input_804aaf48->game.push_back(r);
    process_800f8dcc(input_804aaf48, &r);
}


