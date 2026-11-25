#include "w3d_ptr.h"
#line 1 "k4a_request_dispatch_8008c280.cpp"
struct K4aRefVtable;
struct K4aRef { Ptr32<const K4aRefVtable> vtable; };
struct K4aRefVtable { Ptr32<void (void)> unknown_00[3]; Ptr32<void (Ptr32<K4aRef>)> retain; Ptr32<void (Ptr32<K4aRef>)> release; };
struct K4aHeld {
    Ptr32<K4aRef> ref;
    template <class W3dU> K4aHeld(Ptr32<W3dU> w3d_p) : K4aHeld((K4aRef *)w3d_p.get()) {}
 K4aHeld(K4aRef *r) : ref(r) { if (ref) ref->vtable->retain(ref); }
    ~K4aHeld() { if (ref) ref->vtable->release(ref); }
};
struct K4aRequest { char pad0[20]; unsigned int value; };
extern "C" char w3d_service_8040e708[];
extern "C" Ptr32<K4aRef> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" int FUN_80164514(Ptr32<void> context, Ptr32<K4aRef> ref, unsigned int value);
extern "C" Ptr32<void> w3d_context_804b178c;

extern "C" void k4a_request_dispatch_8008c280(Ptr32<K4aRequest> self)
{
    K4aHeld held(w3d_s10_service_forward_8020b680(w3d_service_8040e708));
    FUN_80164514(w3d_context_804b178c, held.ref, self->value);
}


