#include "w3d_ptr.h"
#line 1 "f1p_property_update_value_802bfba4.cpp"
// Original 0x802bfba4: inferred property mode/value update.
// Separate inline applications preserve the original comparison scheduling.
struct Owner { char pad00[20]; int state; float value; float initial; char pad20[40]; Ptr32<void> property; char pad4c[56]; int mode; };
extern "C" unsigned fn_80178d1c(Ptr32<void>);
extern "C" void fn_802bfc64(Ptr32<Owner>);
extern float value_803d8418[];
inline void apply(Ptr32<Owner> self,float value) { self->value=value; if(self->state==0) self->initial=value; }
extern "C" void w3d_property_update_value_802bfba4(Ptr32<Owner> self,int mode) {
 if(self->mode != mode) {
  self->mode=mode;
  if(mode==1) apply(self,value_803d8418[0]);
  else apply(self,(float)fn_80178d1c(self->property));
  if(self->state==1) fn_802bfc64(self);
 }
}


