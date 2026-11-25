#include "w3d_ptr.h"
#line 1 "d24d_acquire_message_80162024.cpp"
// d24d: 0x80162024 (748 bytes). Acquire a pooled message for an id: clear the
// out reference; take the last message of the free pool 0x80455244 (0x80004005
// when empty) and keep it retained in the out reference; set its owner (+4, from
// the sender's +20), id (+8) and active flag (+16). The sender's class (virtual
// slot 5) is tested against three class records by walking the base link (+20)
// until a class is its own base; each selects a per-id list table (0x804ab4b4,
// 0x804ab4b8, 0x804ab4b0), indexed by the id without bit 15. The message is
// appended to that list and 0 is returned; an unknown class returns 0x80004005.
// The list stores 32-bit values, so the message pointer is passed as an int.
#include "d24d_int_list_range.h"
struct d24d_Message { Ptr32<Ptr32<void>> vtable; int owner; unsigned short id; char pad[6]; int active; };
struct d24d_MessageRef { Ptr32<d24d_Message> value;
  void reset() { if (value) ((Ptr32<void (Ptr32<d24d_Message>)>)value->vtable[4])(value); value = 0; }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((d24d_Message *)w3d_p.get()); }
 void operator=(d24d_Message *o) { if (o) ((Ptr32<void (Ptr32<d24d_Message>)>)o->vtable[3])(o); if (value) ((Ptr32<void (Ptr32<d24d_Message>)>)value->vtable[4])(value); value = o; } };
struct d24d_Class { char pad[20]; Ptr32<d24d_Class> base; };
inline int d24d_is_kind(Ptr32<const d24d_Class> c, Ptr32<const d24d_Class> t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct d24d_MessagePool { Ptr32<Ptr32<d24d_Message>> start; Ptr32<Ptr32<d24d_Message>> finish; Ptr32<Ptr32<d24d_Message>> end; unsigned count() { return ((unsigned)((Ptr32<char>)finish - (Ptr32<char>)start)) / 4; } Ptr32<d24d_Message> back() { return finish[-1]; } void pop_back() { --finish; } };
struct d24d_Sender { Ptr32<Ptr32<void>> vtable; char pad[16]; int owner; Ptr32<d24d_Class> cls() { return ((Ptr32<Ptr32<d24d_Class> (Ptr32<d24d_Sender>)>)vtable[5])(this); } };
extern d24d_MessagePool d24d_free_pool_80455244;
extern d24d_Class d24d_class_a_80361860[], d24d_class_b_803617d0[], d24d_class_c_803618f0[];
extern Ptr32<d24d_RangeList> d24d_lists_a_804ab4b4; extern Ptr32<d24d_RangeList> d24d_lists_b_804ab4b8; extern Ptr32<d24d_RangeList> d24d_lists_c_804ab4b0;
extern "C" int d24d_acquire_message_80162024(Ptr32<d24d_Sender> self, Ptr32<const unsigned short> id, Ptr32<d24d_MessageRef> out) {
    out->reset();
    if (d24d_free_pool_80455244.count() == 0) return 0x80004005;
    *out = d24d_free_pool_80455244.back();
    d24d_free_pool_80455244.pop_back();
    out->value->owner = self->owner;
    out->value->id = *id;
    out->value->active = 1;
    Ptr32<d24d_RangeList> list;
    if (d24d_is_kind(self->cls(), d24d_class_a_80361860)) list = &d24d_lists_a_804ab4b4[*id & ~0x8000];
    else if (d24d_is_kind(self->cls(), d24d_class_b_803617d0)) list = &d24d_lists_b_804ab4b8[*id & ~0x8000];
    else if (d24d_is_kind(self->cls(), d24d_class_c_803618f0)) list = &d24d_lists_c_804ab4b0[*id & ~0x8000];
    else return 0x80004005;
    list->push_back((int)w3d::H(out->value));
    return 0;
}


