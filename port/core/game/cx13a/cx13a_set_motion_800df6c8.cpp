#include "w3d_ptr.h"
#line 1 "cx13a_set_motion_800df6c8.cpp"
// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
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
extern "C" void w3d_cx13a_set_motion_800df6c8(Ptr32<void> self,Ptr32<const Cx13aVec3> position,Ptr32<const Cx13aVec3> velocity,Ptr32<const Cx13aVec3> acceleration){
 FIELD(self,Cx13aVec3,0x44)=*position;FIELD(self,Cx13aVec3,0x2c)=*velocity;FIELD(self,Cx13aVec3,0x38)=*acceleration;
 if(sqrt_802e82c0(velocity->dot(*velocity))!=zero_80389cb8[0]||sqrt_802e82c0(acceleration->dot(*acceleration))!=zero_80389cb8[0])FIELD(self,unsigned,0x98)|=2;else FIELD(self,unsigned,0x98)&=~2U;
}


