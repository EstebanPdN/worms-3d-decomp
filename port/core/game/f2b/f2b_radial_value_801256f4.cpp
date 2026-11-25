#include "w3d_ptr.h"
#line 1 "f2b_radial_value_801256f4.cpp"
// Partial observed layouts; center, radius and amount roles are inferred.
struct Vec3{float x,y,z;float distanceSquared(const Vec3&o)const{float a=x-o.x,b=y-o.y,c=z-o.z;return a*a+b*b+c*c;}};
struct Owner{char pad[28];Vec3 center;float radius;char gap[32];int gateA,gateB;int gap2;int gateC;};
extern "C" Vec3 position_80066894(Ptr32<void>);
extern "C" float radius_800668e4(Ptr32<void>),weight_800668f4(Ptr32<void>);
extern "C" void apply_801257f0(Ptr32<Owner>,float);
extern float one_8039baa8[];
inline float squared(float x){return x*x;}
extern "C" void f2b_radial_value_801256f4(Ptr32<Owner> s,Ptr32<void> actor){if(!s->gateA&&!s->gateB&&!s->gateC){Vec3 pos=position_80066894(actor);float d=s->center.distanceSquared(pos);float r=squared(radius_800668e4(actor)+s->radius);if(d<r){float amount=(r-d)*weight_800668f4(actor)/r;if((int)amount<=0)amount+=one_8039baa8[0];apply_801257f0(s,amount);}}}


