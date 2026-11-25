#include "w3d_ptr.h"
#line 1 "f7b_reflect_800675fc.cpp"
// Inferred observed vector roles and PPC32 layout.
struct F7ReflectVec{float x,y,z;F7ReflectVec(){}F7ReflectVec(const F7ReflectVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}F7ReflectVec operator*(float f)const{F7ReflectVec r;r.x=x*f;r.y=y*f;r.z=z*f;return r;}F7ReflectVec operator-(const F7ReflectVec&o)const{F7ReflectVec r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}float dot(const F7ReflectVec&o)const{return x*o.x+y*o.y+z*o.z;}};
inline const float&maxval(const float&a,const float&b){return a<b?b:a;}inline const float&minval(const float&a,const float&b){return b<a?b:a;}
extern const float lower_8037a0e0[],upper_8037a0e4[],damping_8037a0e8[];
struct F7Reflect{char pad[28];F7ReflectVec velocity;};
extern "C" F7ReflectVec normal_80067770(Ptr32<F7Reflect>);
extern "C" void f7b_reflect_800675fc(Ptr32<F7Reflect> s){F7ReflectVec n=normal_80067770(s);float d=s->velocity.dot(n);float lo=lower_8037a0e0[0];d=maxval(d,lo);float hi=upper_8037a0e4[0];d=minval(d,hi);float damping=damping_8037a0e8[0];s->velocity=s->velocity-n*(d+d);s->velocity=s->velocity*damping;}


