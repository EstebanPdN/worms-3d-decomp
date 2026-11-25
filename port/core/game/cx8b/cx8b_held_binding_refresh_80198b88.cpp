#include "w3d_ptr.h"
#line 1 "cx8b_held_binding_refresh_80198b88.cpp"

struct Cx8bBindingInterface;
struct Cx8bBindingInterfaceVtable {Ptr32<void> unknown00[3];Ptr32<void (Ptr32<Cx8bBindingInterface>)> retain;Ptr32<void (Ptr32<Cx8bBindingInterface>)> release;};
struct Cx8bBindingInterface {Ptr32<Cx8bBindingInterfaceVtable> vtable;};
struct Cx8bBindingOwner;
struct Cx8bBindingVtable {Ptr32<void> unknown00[15];Ptr32<int (Ptr32<Cx8bBindingOwner>, int)> notify;};
struct Cx8bBindingOwner {Ptr32<Cx8bBindingVtable> vtable;char unknown04[16];Ptr32<Cx8bBindingInterface> held;};
extern "C" void fn_8019a010(Ptr32<Cx8bBindingOwner>);
extern "C" int w3d_cx8b_held_binding_refresh_80198b88(Ptr32<Cx8bBindingOwner> self,Ptr32<Cx8bBindingInterface> incoming) {
 if(incoming) incoming->vtable->retain(incoming);
 if(self->held) self->held->vtable->release(self->held);
 self->held=incoming;self->vtable->notify(self,-1);fn_8019a010(self);return 0;
}




