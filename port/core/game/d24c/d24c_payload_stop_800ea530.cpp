#include "w3d_ptr.h"
#line 1 "d24c_payload_stop_800ea530.cpp"
// d24c: 0x800ea530 (252 bytes). Stop a payload: run the shared stop 0x800edbbc, write
// the entity id to the "Payload." setting and post a target-id message, release both
// actor handles (+252, +256, mode 3) and clear them, empty the word vector at +260
// (erase from begin: the memcpy of a size only known zero after CSE is kept), and
// release and clear the reference at +100. Names are inferred; the null local is the
// zero kept in a saved register across the calls.
typedef unsigned int size_t;
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[4];
    Ptr32<void (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Key { Ptr32<const char> text; };
extern "C" Ptr32<void> memcpy(Ptr32<void>, Ptr32<const void>, size_t);
struct Vec {
    Ptr32<int> start; Ptr32<int> finish; Ptr32<int> eos;
    void clear() {
        Ptr32<int> first = start;
        Ptr32<int> last = finish;
        int removed = (Ptr32<char>)last - (Ptr32<char>)first;
        memcpy(first, last, (Ptr32<char>)finish - (Ptr32<char>)last);
        finish = (Ptr32<int>)((Ptr32<char>)finish - removed);
    }
};
struct Payload {
    unsigned char u0[20];
    int id;            // +20
    unsigned char u24[76];
    Ptr32<Object> held;      // +100
    unsigned char u104[148];
    Ptr32<void> h252;        // +252
    Ptr32<void> h256;        // +256
    Vec list;          // +260
};
extern "C" void base_800edbbc(Ptr32<Payload>);
extern "C" int write_800fc43c(Ptr32<Key>, int);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<void> msg_init_801190b4(Ptr32<void>, unsigned short, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" void member_80126230(Ptr32<void>, int);
extern Ptr32<void> arena_804b1754;
extern int cache_804aef28;
extern const char name_8038b3dc[];
extern "C" void d24c_payload_stop_800ea530(Ptr32<Payload> self) {
    base_800edbbc(self);
    int id = self->id;
    { Key k; k.text = name_8038b3dc; write_800fc43c(&k, id); }
    Ptr32<void> m = arena_801613f0(arena_804b1754, 12);
    post_8016239c(msg_init_801190b4(m, message_id_8015f5a0(&cache_804aef28, 1), id));
    if (self->h252) member_80126230(self->h252, 3);
    Ptr32<void> none = 0;
    self->h252 = none;
    if (self->h256) member_80126230(self->h256, 3);
    self->h256 = none;
    self->list.clear();
    if (self->held) self->held->vtable->release(self->held);
    self->held = (Ptr32<Object>)none;
}


