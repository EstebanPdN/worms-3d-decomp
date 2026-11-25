#include "w3d_ptr.h"
#line 1 "f1p_set_vector_mode_8026d8e8.cpp"
// Original 0x8026d8e8. Vector layout and initialization observed; naming inferred.
struct Vec3 { float x,y,z; Vec3(float a,float b,float c):x(a),y(b),z(c){} Vec3(const Vec3 &v) { float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c; } };
struct Owner { char pad[76];int ready; };
extern "C" void fn_8026dbe8(Ptr32<Owner>);
extern "C" void fn_8026d524(Ptr32<Owner>,Ptr32<const Vec3>);  // Por puntero, como en PowerPC (w3d_set_triple_notify_8026d524).
extern float value_803cbd74[],value_803cbd78[];
extern "C" void w3d_set_vector_mode_8026d8e8(Ptr32<Owner> self,int mode) {
 if(!self->ready) fn_8026dbe8(self);
 if(mode==1) { Vec3 v(value_803cbd74[0],value_803cbd74[0],value_803cbd74[0]);fn_8026d524(self,&v); }
 else {Vec3 v(value_803cbd78[0],value_803cbd74[0],value_803cbd74[0]);fn_8026d524(self,&v);}
}


