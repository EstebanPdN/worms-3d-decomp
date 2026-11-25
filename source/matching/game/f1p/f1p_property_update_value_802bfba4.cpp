// Original 0x802bfba4: inferred property mode/value update.
// Separate inline applications preserve the original comparison scheduling.
struct Owner { char pad00[20]; int state; float value; float initial; char pad20[40]; void *property; char pad4c[56]; int mode; };
extern "C" unsigned fn_80178d1c(void *);
extern "C" void fn_802bfc64(Owner *);
extern float value_803d8418[];
inline void apply(Owner *self,float value) { self->value=value; if(self->state==0) self->initial=value; }
extern "C" void w3d_property_update_value_802bfba4(Owner *self,int mode) {
 if(self->mode != mode) {
  self->mode=mode;
  if(mode==1) apply(self,value_803d8418[0]);
  else apply(self,(float)fn_80178d1c(self->property));
  if(self->state==1) fn_802bfc64(self);
 }
}
