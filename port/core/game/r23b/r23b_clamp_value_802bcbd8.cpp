#include "w3d_ptr.h"
#line 1 "r23b_clamp_value_802bcbd8.cpp"
// desc: Clamp a changed float at +0x4c and refresh when mode +0x50 is one; names inferred.
// Bounds and refresh implementation remain unresolved externs witnessed by original instructions.
struct R23bValueObject { unsigned char unknown[0x4c]; float value; int mode; };
extern const float r23b_lower_803d82f8[];
extern const float r23b_upper_803d82fc[];
extern "C" void r23b_refresh_802bc570(Ptr32<R23bValueObject>);
extern "C" void w3d_r23b_clamp_value_802bcbd8(Ptr32<R23bValueObject> self, float value) {
 if(self->value!=value) {
 self->value=value;
 if(value<r23b_lower_803d82f8[0]) self->value=r23b_lower_803d82f8[0];
 if(self->value>r23b_upper_803d82fc[0]) self->value=r23b_upper_803d82fc[0];
 if(self->mode==1) r23b_refresh_802bc570(self);
 }
}


