struct Cx7bHeld;
struct Cx7bHeldVtable { void *unknown[4]; void (*release)(Cx7bHeld *); };
struct Cx7bHeld { Cx7bHeldVtable *vtable; };
struct Cx7bResourceOwner { char unknown00[28]; char member[188]; Cx7bHeld *held; };
extern "C" void fn_802bacc8(Cx7bResourceOwner *);
extern "C" void fn_802b0fec(void *);
extern "C" void w3d_cx7b_held_resource_reset_802ba680(Cx7bResourceOwner *self) {
 if(self->held) self->held->vtable->release(self->held);
 self->held=0; fn_802bacc8(self); fn_802b0fec(self->member);
}
