// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx9aVec3 {
 float x,y,z;
 Cx9aVec3() {}
 Cx9aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx9aVec3(const Cx9aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx9aVec3 scaled(float k) const {Cx9aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx9aVec3 plus(const Cx9aVec3 &o) const {Cx9aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx9aVec3 minus(const Cx9aVec3 &o) const {Cx9aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx9aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 float dot(const Cx9aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};
// Inferred ballistic state: position +0, velocity +0xc, acceleration +0x18.
struct Cx9aTrajectory {Cx9aVec3 position,velocity,acceleration;};
extern const float half_803891a4[];
extern "C" void w3d_cx9a_ballistic_sample_800d75f0(Cx9aTrajectory *self,Cx9aVec3 *out,float t) {
 *out=self->position.plus(self->velocity.scaled(t)).plus(self->acceleration.scaled(t*t*half_803891a4[0]));
}
