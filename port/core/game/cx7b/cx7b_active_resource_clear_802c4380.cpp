#include "w3d_ptr.h"
#line 1 "cx7b_active_resource_clear_802c4380.cpp"
struct Cx7bActive;
struct Cx7bActiveVtable { Ptr32<void> unknown00[4]; Ptr32<void (Ptr32<Cx7bActive>)> release; Ptr32<void> unknown14; Ptr32<void (Ptr32<Cx7bActive>)> stop; };
struct Cx7bActive { Ptr32<Cx7bActiveVtable> vtable; };
struct Cx7bActiveOwner { char unknown00[236]; Ptr32<Cx7bActive> held; int active; };
extern "C" void w3d_cx7b_active_resource_clear_802c4380(Ptr32<Cx7bActiveOwner> self) {
 if(self->held) self->held->vtable->stop(self->held);
 int zero=0; self->active=zero;
 if(self->held) self->held->vtable->release(self->held);
 self->held=0;
}


