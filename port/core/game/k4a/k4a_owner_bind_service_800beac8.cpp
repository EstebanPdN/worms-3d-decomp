#include "w3d_ptr.h"
#line 1 "k4a_owner_bind_service_800beac8.cpp"
struct K4aRefVtable;
struct K4aRef { Ptr32<const K4aRefVtable> vtable; };
struct K4aRefVtable { Ptr32<void (void)> unknown_00[3]; Ptr32<void (Ptr32<K4aRef>)> retain; Ptr32<void (Ptr32<K4aRef>)> release; };
struct K4aHeld {
    Ptr32<K4aRef> ref;
    template <class W3dU> K4aHeld(Ptr32<W3dU> w3d_p) : K4aHeld((K4aRef *)w3d_p.get()) {}
 K4aHeld(K4aRef *r) : ref(r) { if (ref) ref->vtable->retain(ref); }
    ~K4aHeld() { if (ref) ref->vtable->release(ref); }
};
struct K4aOwner { char pad0[28]; Ptr32<K4aRef> ref; };
extern "C" char w3d_service_804144f8[];
extern "C" Ptr32<K4aRef> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" int w3d_s20_forward_owner_801750f4(Ptr32<void> owner, Ptr32<K4aRef> ref);
extern "C" Ptr32<K4aRef> w3d_held_804ae5e4;

extern "C" int k4a_owner_bind_service_800beac8(Ptr32<K4aOwner> self)
{
    K4aHeld held(w3d_s10_service_forward_8020b680(w3d_service_804144f8));
    w3d_s20_forward_owner_801750f4(self, held.ref);
    if (held.ref != 0)
        held.ref->vtable->retain(held.ref);
    if (w3d_held_804ae5e4 != 0)
        w3d_held_804ae5e4->vtable->release(w3d_held_804ae5e4);
    w3d_held_804ae5e4 = held.ref;
    return 0;
}


