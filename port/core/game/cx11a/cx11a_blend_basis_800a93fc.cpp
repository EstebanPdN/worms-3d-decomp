#include "w3d_ptr.h"
#line 1 "cx11a_blend_basis_800a93fc.cpp"
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx11aVec3 {
 float x,y,z;
 Cx11aVec3() {}
 Cx11aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx11aVec3(const Cx11aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx11aVec3 scaled(float k) const {Cx11aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx11aVec3 plus(const Cx11aVec3 &o) const {Cx11aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx11aVec3 minus(const Cx11aVec3 &o) const {Cx11aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx11aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx11aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

extern "C" float read_80178df0(Ptr32<void>);extern const float one_80381910[];
struct Cx11aBlend {unsigned int unknown00;Cx11aVec3 first,second,third;unsigned char unknown28[0x2c];Cx11aVec3 goalFirst,goalSecond,goalThird;unsigned char unknown78[8];Ptr32<void> factor;};
extern "C" void w3d_cx11a_blend_basis_800a93fc(Ptr32<Cx11aBlend> self){float t=read_80178df0(self->factor),rest=one_80381910[0]-t;self->first=self->first.scaled(rest).plus(self->goalFirst.scaled(t));self->third=self->third.scaled(rest).plus(self->goalThird.scaled(t));self->second=self->second.scaled(rest).plus(self->goalSecond.scaled(t));}


