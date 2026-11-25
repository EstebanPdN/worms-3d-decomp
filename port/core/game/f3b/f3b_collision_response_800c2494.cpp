#include "w3d_ptr.h"
#line 1 "f3b_collision_response_800c2494.cpp"
// Observed projection/scaling operations. Collision, bounce, slide and cutoff roles are inferred.
extern const float zero_803831a0[];extern "C" float sqrt_802e82c0(float);
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}float dot(const Vec3&o)const{return x*o.x+y*o.y+z*o.z;}float length2()const{return x*x+y*y+z*z;}void operator*=(float f){x*=f;y*=f;z*=f;}Vec3 operator-(const Vec3&o)const{Vec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}void difference(const Vec3&a,const Vec3&b){x=a.x-b.x;y=a.y-b.y;z=a.z-b.z;}void clear(float zero){x=zero;y=zero;z=zero;}};
extern "C" void f3b_collision_response_800c2494(Ptr32<Vec3> v,Ptr32<const Vec3> n,float bounce,float slide,float cutoff){float zero=zero_803831a0[0];float dot=v->dot(*n);if(dot>zero){float len=sqrt_802e82c0(v->length2());if(len<cutoff)goto clear;*v=*n;*v*=len*bounce;return;}else{Vec3 normal(*n);normal*=dot;Vec3 tangent;tangent.difference(*v,normal);normal*=bounce;tangent*=slide;v->difference(tangent,normal);if(v->length2()<cutoff*cutoff)goto clear;return;}clear:v->clear(zero);}


