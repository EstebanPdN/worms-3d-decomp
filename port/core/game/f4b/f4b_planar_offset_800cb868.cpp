#include "w3d_ptr.h"
#line 1 "f4b_planar_offset_800cb868.cpp"
// Partial observed layout and vector arithmetic. Position, center, up and snapshot roles are inferred.
extern "C" float sqrt_802e82c0(float);extern const float zero_80387d00[],one_80387d04[],range_80387d08[],scale_80387d0c[];
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}Vec3 operator+(const Vec3&o)const{Vec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}Vec3 operator*(float f)const{Vec3 r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}void operator*=(float f){x*=f;y*=f;z*=f;}float length2()const{return x*x+y*y+z*z;}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct Owner{int word;Vec3 position,center,up;char gap[36];Vec3 previous,oldUp,saved;};
extern "C" void f4b_planar_offset_800cb868(Ptr32<Owner> s){s->center=s->saved;Vec3 dir=s->position-s->center;dir.y=zero_80387d00[0];if(dir.length2()==zero_80387d00[0])dir.x=one_80387d04[0];dir*=one_80387d04[0]/sqrt_802e82c0(dir.length2());s->position=s->center+dir*range_80387d08[0]*scale_80387d0c[0];s->previous=s->position;s->up.set(zero_80387d00[0],one_80387d04[0],zero_80387d00[0]);s->oldUp=s->up;}


