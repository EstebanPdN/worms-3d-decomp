#include "w3d_ptr.h"
#line 1 "cx8a_path_interpolate_offset_800e6f20.cpp"
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx8aVec3 {
 float x,y,z;
 Cx8aVec3() {}
 Cx8aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx8aVec3(const Cx8aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx8aVec3 scaled(float k) const {Cx8aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx8aVec3 plus(const Cx8aVec3 &o) const {Cx8aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx8aVec3 minus(const Cx8aVec3 &o) const {Cx8aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx8aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 float dot(const Cx8aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};
// Interpolated displacement: begin tick +0x64, start/end vectors +0x8c/+0x98, end tick +0xa4.
struct Cx8aPath {unsigned char unknown00[0x64];unsigned int begin_tick;unsigned char unknown68[0x24];Cx8aVec3 start,end;unsigned int end_tick;};
extern const float one_8038afb8[];
extern "C" void w3d_cx8a_path_interpolate_offset_800e6f20(Ptr32<Cx8aPath> self,unsigned int tick,Ptr32<Cx8aVec3> out,Ptr32<const Cx8aVec3> base){
 float ratio=(float)(tick-self->begin_tick)/(float)(self->end_tick-self->begin_tick);*out=*base;
 out->add(self->start.scaled(one_8038afb8[0]-ratio).plus(self->end.scaled(ratio)));
}


