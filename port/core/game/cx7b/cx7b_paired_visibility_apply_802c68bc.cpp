#include "w3d_ptr.h"
#line 1 "cx7b_paired_visibility_apply_802c68bc.cpp"
struct Cx7bVisible;
struct Cx7bVisibleVtable { Ptr32<void> unknown[22]; Ptr32<void (Ptr32<Cx7bVisible>, int)> set; };
struct Cx7bVisible { Ptr32<Cx7bVisibleVtable> vtable; };
struct Cx7bPairedVisibility { char unknown00[36]; int enabled; int state; int unknown2c; Ptr32<Cx7bVisible> first; Ptr32<Cx7bVisible> second; };
extern "C" void w3d_cx7b_paired_visibility_apply_802c68bc(Ptr32<Cx7bPairedVisibility> self) {
 if(self->enabled) { self->first->vtable->set(self->first,self->state^1); self->second->vtable->set(self->second,self->state); }
}


