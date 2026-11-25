
struct Cx8bBindingInterface;
struct Cx8bBindingInterfaceVtable {void *unknown00[3];void (*retain)(Cx8bBindingInterface *);void (*release)(Cx8bBindingInterface *);};
struct Cx8bBindingInterface {Cx8bBindingInterfaceVtable *vtable;};
struct Cx8bBindingOwner;
struct Cx8bBindingVtable {void *unknown00[15];int (*notify)(Cx8bBindingOwner *,int);};
struct Cx8bBindingOwner {Cx8bBindingVtable *vtable;char unknown04[16];Cx8bBindingInterface *held;};
extern "C" void fn_8019a010(Cx8bBindingOwner *);
extern "C" int w3d_cx8b_held_binding_refresh_80198b88(Cx8bBindingOwner *self,Cx8bBindingInterface *incoming) {
 if(incoming) incoming->vtable->retain(incoming);
 if(self->held) self->held->vtable->release(self->held);
 self->held=incoming;self->vtable->notify(self,-1);fn_8019a010(self);return 0;
}


