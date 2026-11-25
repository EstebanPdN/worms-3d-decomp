#include "w3d_ptr.h"
#line 1 "cx8b_active_resource_clear_802b24bc.cpp"

struct Cx8bActiveInterface;
struct Cx8bActiveVtable {Ptr32<void> unknown00[4];Ptr32<void (Ptr32<Cx8bActiveInterface>)> release;Ptr32<void> unknown14;Ptr32<void (Ptr32<Cx8bActiveInterface>)> stop;};
struct Cx8bActiveInterface {Ptr32<Cx8bActiveVtable> vtable;};
struct Cx8bActiveResource {char unknown00[104];int state,active;char unknown70[4];int pending;char unknown78[12];Ptr32<Cx8bActiveInterface> held;};
static inline void clear(Ptr32<Cx8bActiveResource> self,int zero) {
 self->active=zero;self->state=zero;self->pending=zero;
 if(self->held) self->held->vtable->release(self->held);
 self->held=(Ptr32<Cx8bActiveInterface>)w3d::G(zero);
}
extern "C" void w3d_cx8b_active_resource_clear_802b24bc(Ptr32<Cx8bActiveResource> self) {
 if(self->active) {if(self->held) self->held->vtable->stop(self->held);clear(self,0);}
}



