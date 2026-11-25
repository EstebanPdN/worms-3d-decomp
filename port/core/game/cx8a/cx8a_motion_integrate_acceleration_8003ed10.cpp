#include "w3d_ptr.h"
#line 1 "cx8a_motion_integrate_acceleration_8003ed10.cpp"
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
struct Cx8aMotion {unsigned char unknown00[0x1c];Cx8aVec3 position,velocity,acceleration;};
extern const float step_80374684[],half_80374688[];
extern "C" void w3d_cx8a_motion_integrate_acceleration_8003ed10(Ptr32<Cx8aMotion> self) {
 float dt=step_80374684[0];
 self->position.add(self->velocity.scaled(dt).plus(self->acceleration.scaled(dt*half_80374688[0]*dt)));
 self->velocity.add(self->acceleration.scaled(dt));
}


