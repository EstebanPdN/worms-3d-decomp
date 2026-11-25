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
// Three input vectors +4/+0x10/+0x1c; reset vectors +0x8c/+0x98/+0xa4; flag +0xc8.
struct Cx8aMotionState {void *vtable;Cx8aVec3 first,second,third;unsigned char unknown28[100];Cx8aVec3 reset_a,reset_b,reset_c;unsigned char unknownb0[24];unsigned char ready;};
extern const float reset_80388cc4[];extern "C" int state_query_8015a6b8(Cx8aMotionState *,const Cx8aMotionState *);
static inline void reset_vector(Cx8aVec3 *v,float k){v->x=k;v->y=k;v->z=k;}
extern "C" void w3d_cx8a_motion_state_assign_800d308c(Cx8aMotionState *self,const Cx8aMotionState *from){
 self->first=from->first;self->second=from->second;self->third=from->third;float k=reset_80388cc4[0];self->ready=0;
 reset_vector(&self->reset_a,k);reset_vector(&self->reset_b,k);reset_vector(&self->reset_c,k);state_query_8015a6b8(self,from);
}
