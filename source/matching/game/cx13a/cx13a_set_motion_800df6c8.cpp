// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx13aVec3 {
 float x,y,z;
 Cx13aVec3() {}
 Cx13aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx13aVec3(const Cx13aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx13aVec3 scaled(float k) const {Cx13aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx13aVec3 plus(const Cx13aVec3 &o) const {Cx13aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx13aVec3 minus(const Cx13aVec3 &o) const {Cx13aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx13aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx13aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

extern "C" float sqrt_802e82c0(float);extern const float zero_80389cb8[];
extern "C" void w3d_cx13a_set_motion_800df6c8(void *self,const Cx13aVec3 *position,const Cx13aVec3 *velocity,const Cx13aVec3 *acceleration){
 FIELD(self,Cx13aVec3,0x44)=*position;FIELD(self,Cx13aVec3,0x2c)=*velocity;FIELD(self,Cx13aVec3,0x38)=*acceleration;
 if(sqrt_802e82c0(velocity->dot(*velocity))!=zero_80389cb8[0]||sqrt_802e82c0(acceleration->dot(*acceleration))!=zero_80389cb8[0])FIELD(self,unsigned,0x98)|=2;else FIELD(self,unsigned,0x98)&=~2U;
}
