#include "w3d_ptr.h"
#line 1 "cx11a_interpolate_800ecd60.cpp"
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

extern "C" Ptr32<void> touch_80341584(Ptr32<void>);extern "C" int refresh_801797b4(Ptr32<void>);
// PPC32 interpolation endpoints +0xe0/+0xec, elapsed origin +0xd8 and signed duration +0xdc.
struct Cx11aInterpolation {unsigned char unknown00[0xc0];Ptr32<void> provider;unsigned char unknownc4[0x14];unsigned int started;int duration;Cx11aVec3 end,start;};
extern const float zero_8038b5c0[],one_8038b5c4[];
extern "C" void w3d_cx11a_interpolate_800ecd60(Ptr32<Cx11aInterpolation> self,unsigned int now,Ptr32<Cx11aVec3> out){refresh_801797b4((Ptr32<void>)touch_80341584(self->provider));float t;if(self->duration>0)t=(float)(now-self->started)/(float)self->duration;else t=zero_8038b5c0[0];if(t>one_8038b5c4[0])t=one_8038b5c4[0];*out=self->start.scaled(one_8038b5c4[0]-t).plus(self->end.scaled(t));}


