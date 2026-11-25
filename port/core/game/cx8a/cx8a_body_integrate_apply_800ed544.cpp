#include "w3d_ptr.h"
#line 1 "cx8a_body_integrate_apply_800ed544.cpp"
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
// Body position +0x24 and velocity +0x30; refreshed position is forwarded.
struct Cx8aBody {unsigned char unknown00[0x24];Cx8aVec3 position,velocity;};
extern const float step_8038b610[];
extern "C" void position_apply_800eac84(Ptr32<Cx8aBody>,Ptr32<Cx8aVec3>);
extern "C" void w3d_cx8a_body_integrate_apply_800ed544(Ptr32<Cx8aBody> self){
 self->position=self->position.plus(self->velocity.scaled(step_8038b610[0]));position_apply_800eac84(self,&self->position);
}


