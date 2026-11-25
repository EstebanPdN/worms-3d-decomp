#include "w3d_ptr.h"
#line 1 "f4b_signed_direction_800af580.cpp"
// Partial observed layout and sign-bit absolute-value operations.
extern "C" float sqrt_802e82c0(float);extern const float zero_803822c8[],one_803822cc[];
struct Vec3{float x,y,z;float length2()const{return x*x+y*y+z*z;}void scale(float f){float a=x*f,b=y*f,c=z*f;x=a;y=b;z=c;}};
struct Owner{Ptr32<Ptr32<void>> vt;char gap[68];Vec3 direction;char gap2[108];Ptr32<void> service;};extern "C" Ptr32<void> identity_80341584(Ptr32<void>);extern "C" Ptr32<void> config_801797b4(Ptr32<void>);
inline float absolute(float f){union{float f;unsigned bits;}v;v.f=f;v.bits&=0x7fffffff;return v.f;}
extern "C" void f4b_signed_direction_800af580(Ptr32<Owner> s,int arg,Ptr32<Vec3> out){config_801797b4(identity_80341584(s->service));((Ptr32<void (Ptr32<Owner>, int, Ptr32<Vec3>)>)s->vt[12])(s,arg,out);float zero=zero_803822c8[0];if(out->length2()>zero)out->scale(one_803822cc[0]/sqrt_802e82c0(out->length2()));float x;if(s->direction.x>zero)x=absolute(out->x);else x=-absolute(out->x);out->x=x;float z;if(s->direction.z>zero_803822c8[0])z=absolute(out->z);else z=-absolute(out->z);out->z=z;}


