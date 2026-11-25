#include "w3d_ptr.h"
#line 1 "f1a_clamp_vector_800949a8.cpp"
// Original 0x800949a8. Observed center at +280 and equal axis extent at +344.
struct F1aVecClamp {float x,y,z; F1aVecClamp(){}
 F1aVecClamp(float a,float b,float c):x(a),y(b),z(c){}
 F1aVecClamp(const F1aVecClamp&v):x(v.x),y(v.y),z(v.z){}
 F1aVecClamp operator-(const F1aVecClamp &v)const {F1aVecClamp r;r.x=x-v.x;r.y=y-v.y;r.z=z-v.z;return r;}
};
struct F1aClampObject {char unknown[280];F1aVecClamp center;char unknown124[52];float extent;};
extern "C" void w3d_f1a_clamp_vector_800949a8(Ptr32<F1aClampObject> self,Ptr32<F1aVecClamp> v) {
 F1aVecClamp delta=*v-self->center;
 if((float)__builtin_fabs(delta.x)>self->extent) {
  if(v->x<self->center.x)v->x=self->center.x-self->extent;
  else v->x=self->center.x+self->extent;
 }
 if((float)__builtin_fabs(delta.y)>self->extent) {
  if(v->y<self->center.y)v->y=self->center.y-self->extent;
  else v->y=self->center.y+self->extent;
 }
 if((float)__builtin_fabs(delta.z)>self->extent) {
  if(v->z<self->center.z)v->z=self->center.z-self->extent;
  else v->z=self->center.z+self->extent;
 }
}


