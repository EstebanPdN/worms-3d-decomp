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

extern "C" void * touch_80341584(void*);extern "C" int refresh_801797b4(void *);
// PPC32 position +0x30, velocity +0x3c, optional acceleration +0x0, provider +0xc0, unsigned start tick +0x170.
struct Cx11aTrajectory {unsigned char unknown00[0x30];Cx11aVec3 position,velocity;unsigned char unknownRest[0x78];void *provider;unsigned char unknownc4[0xac];unsigned int started;};
extern const float neutral_80389568[];
extern "C" void w3d_cx11a_trajectory_800d9628(Cx11aTrajectory *self,unsigned int now,Cx11aVec3 *out){refresh_801797b4((void *)touch_80341584(self->provider));float t=(float)now-(float)self->started;if(t<neutral_80389568[0])t=neutral_80389568[0];*out=self->position.plus(self->velocity.scaled(t));}
