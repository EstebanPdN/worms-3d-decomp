struct Cx7bActive;
struct Cx7bActiveVtable { void *unknown00[4]; void (*release)(Cx7bActive *); void *unknown14; void (*stop)(Cx7bActive *); };
struct Cx7bActive { Cx7bActiveVtable *vtable; };
struct Cx7bActiveOwner { char unknown00[236]; Cx7bActive *held; int active; };
extern "C" void w3d_cx7b_active_resource_clear_802c4380(Cx7bActiveOwner *self) {
 if(self->held) self->held->vtable->stop(self->held);
 int zero=0; self->active=zero;
 if(self->held) self->held->vtable->release(self->held);
 self->held=0;
}
