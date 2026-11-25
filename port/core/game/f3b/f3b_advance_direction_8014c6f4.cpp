#include "w3d_ptr.h"
#line 1 "f3b_advance_direction_8014c6f4.cpp"
// Partial observed layout. Position, direction and count roles are inferred.
struct Vec3 {float x,y,z;Vec3(){} Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;} Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;} Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;} void operator*=(float f){x*=f;y*=f;z*=f;} float length2()const{return x*x+y*y+z*z;} void operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;} };
extern Vec3 vector_8045e788;
struct Owner{char pad[676];Vec3 position;char pad2[28];int flag;char pad3[40];int state;char pad4[60];int other;char pad5[16];int count;};
extern "C" Vec3 direction_80146f10(Ptr32<Owner>);extern const float limit_803a1510[],scale_803a1514[];
extern "C" void f3b_advance_direction_8014c6f4(Ptr32<Owner> s){if(s->flag||s->other<0){Vec3 dir=direction_80146f10(s);if(dir.length2()>limit_803a1510[0]){dir*=scale_803a1514[0];s->position+=dir;int n=++s->count;if(n>0){if(s->count>20){s->position=vector_8045e788;s->state=10;}}}}}


