#include "w3d_ptr.h"
#line 1 "f1b_integrate_velocity_80146aa4.cpp"
// Partial position/velocity state. A named scaled vector is materialized before
// the in-place add; this preserves single-precision intermediate rounding.
// Worm sinking in deep water (state 19, called from 0x80146190). v25 (owner's request): the sinking runs at
// w3d_hundir_velocidad() of its speed (core/native/ahogo.cpp, 0.35 by default). Each 20 ms tick then advances k of a
// tick: step 20*k, damping 0.98^k and easing 1-0.5^k. With k = 1 the original code runs unchanged.
struct f1b_Vector {
 float x,y,z;
 f1b_Vector(){}
 f1b_Vector(float a,float b,float c):x(a),y(b),z(c){}
 f1b_Vector(const f1b_Vector &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
 f1b_Vector operator*(float f)const{f1b_Vector out;out.x=x*f;out.y=y*f;out.z=z*f;return out;}
 f1b_Vector& operator+=(const f1b_Vector &v){x+=v.x;y+=v.y;z+=v.z;return *this;}
};
struct f1b_Motion { unsigned char unknown0[560];f1b_Vector position;unsigned char unknown572[104];f1b_Vector velocity; };
extern const float f1b_step_803a0fc0[],f1b_threshold_803a0fc4[],f1b_damp_803a0fc8[],f1b_target_803a0fcc[],f1b_ease_803a0fd0[];
extern "C" float w3d_hundir_velocidad(void);
extern "C" float w3d_hundir_freno(void);
extern "C" float w3d_hundir_suave(void);
extern "C" void f1b_integrate_velocity_80146aa4(Ptr32<f1b_Motion> self)
{
 float k=w3d_hundir_velocidad();
 if(k!=1.0f){
  float damp=w3d_hundir_freno(),ease=w3d_hundir_suave();
  f1b_Vector delta=self->velocity*(f1b_step_803a0fc0[0]*k);
  self->position+=delta;
  if(__builtin_fabsf(self->velocity.y)>f1b_threshold_803a0fc4[0])self->velocity.y*=damp;
  else self->velocity.y=(f1b_target_803a0fcc[0]-self->velocity.y)*ease+self->velocity.y;
  self->velocity.x*=damp;
  self->velocity.z*=damp;
  return;
 }
 f1b_Vector delta=self->velocity*f1b_step_803a0fc0[0];
 self->position+=delta;
 if(__builtin_fabsf(self->velocity.y)>f1b_threshold_803a0fc4[0])self->velocity.y*=f1b_damp_803a0fc8[0];
 else self->velocity.y=(f1b_target_803a0fcc[0]-self->velocity.y)*f1b_ease_803a0fd0[0]+self->velocity.y;
 self->velocity.x*=f1b_damp_803a0fc8[0];
 self->velocity.z*=f1b_damp_803a0fc8[0];
}

