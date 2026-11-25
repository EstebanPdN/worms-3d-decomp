#include "w3d_ptr.h"
#line 1 "cx7b_held_resource_reset_802ba680.cpp"
struct Cx7bHeld;
struct Cx7bHeldVtable { Ptr32<void> unknown[4]; Ptr32<void (Ptr32<Cx7bHeld>)> release; };
struct Cx7bHeld { Ptr32<Cx7bHeldVtable> vtable; };
struct Cx7bResourceOwner { char unknown00[28]; char member[188]; Ptr32<Cx7bHeld> held; };
extern "C" void fn_802bacc8(Ptr32<Cx7bResourceOwner>);
extern "C" void fn_802b0fec(Ptr32<void>);
extern "C" void w3d_cx7b_held_resource_reset_802ba680(Ptr32<Cx7bResourceOwner> self) {
 if(self->held) self->held->vtable->release(self->held);
 self->held=0; fn_802bacc8(self); fn_802b0fec(self->member);
}


