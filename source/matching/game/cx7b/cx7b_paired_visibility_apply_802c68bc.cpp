struct Cx7bVisible;
struct Cx7bVisibleVtable { void *unknown[22]; void (*set)(Cx7bVisible *, int); };
struct Cx7bVisible { Cx7bVisibleVtable *vtable; };
struct Cx7bPairedVisibility { char unknown00[36]; int enabled; int state; int unknown2c; Cx7bVisible *first,*second; };
extern "C" void w3d_cx7b_paired_visibility_apply_802c68bc(Cx7bPairedVisibility *self) {
 if(self->enabled) { self->first->vtable->set(self->first,self->state^1); self->second->vtable->set(self->second,self->state); }
}
