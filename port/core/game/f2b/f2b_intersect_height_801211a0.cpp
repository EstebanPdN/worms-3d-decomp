#include "w3d_ptr.h"
#line 1 "f2b_intersect_height_801211a0.cpp"
// Partial observed layout and vector operations; height/intersection roles are inferred.
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}Vec3 operator+(const Vec3&o)const{Vec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}float lengthSquared()const{return x*x+y*y+z*z;}};
struct Owner{char pad[152];Ptr32<void> service;};
extern "C" float value_80178df0(Ptr32<void>);
extern const float zero_8039b700[],one_8039b704[];
extern "C" void f2b_intersect_height_801211a0(Ptr32<Owner> s,Ptr32<Vec3> p,Ptr32<const Vec3> q){Vec3 position=*p;Vec3 delta=*p-*q;float zero=zero_8039b700[0];if(delta.lengthSquared()>zero){float t=(value_80178df0(s->service)-q->y)/delta.y;if(t>zero && t<one_8039b704[0]){Vec3 result=*q+delta*t;*p=result;}}}


