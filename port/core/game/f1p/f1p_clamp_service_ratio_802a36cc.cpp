#include "w3d_ptr.h"
#line 1 "f1p_clamp_service_ratio_802a36cc.cpp"
// Original 0x802a36cc; inferred service ratio limiter.
struct Source { char pad[128]; };
struct Owner { char pad[40];Ptr32<Source> source;char pad2c[188];float value; };
extern "C" Ptr32<void> fn_8015ae3c(Ptr32<void>);
extern "C" Ptr32<void> fn_8034435c(Ptr32<void>);
extern "C" float fn_8018b4cc(Ptr32<void>,int);
extern float zero_803d2e38[];
extern "C" float w3d_clamp_service_ratio_802a36cc(Ptr32<Owner> self,int key,float threshold,float maximum,float cap) {
 float v=fn_8018b4cc(fn_8034435c(fn_8015ae3c((Ptr32<char>)self->source+128)),key);
 self->value=v;
 float result;
 if(threshold < v) result=zero_803d2e38[0];
 else {
  result=zero_803d2e38[0];
  if(v<result) { } else {
   result=threshold/v;
   if(result>maximum) result=maximum;
   if(result>cap) result=cap;
   self->value=result*v;
  }
 }
 return result;
}


