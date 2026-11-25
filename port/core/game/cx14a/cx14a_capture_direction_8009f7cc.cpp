#include "w3d_ptr.h"
#line 1 "cx14a_capture_direction_8009f7cc.cpp"
// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx14aVec3 {
 float x,y,z;
 Cx14aVec3() {}
 Cx14aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx14aVec3(const Cx14aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx14aVec3 scaled(float k) const {Cx14aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx14aVec3 plus(const Cx14aVec3 &o) const {Cx14aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx14aVec3 minus(const Cx14aVec3 &o) const {Cx14aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx14aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx14aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};



extern "C" Ptr32<void> lookup_80341584(Ptr32<void>); Ptr32<void> parameters_801797b4(Ptr32<void>);extern "C" float sqrt_802e82c0(float);extern const float one_80380788[];
extern "C" void w3d_cx14a_capture_direction_8009f7cc(Ptr32<void> self){parameters_801797b4(lookup_80341584(FIELD(self,void *,192)));FIELD(self,Cx14aVec3,320)=FIELD(self,Cx14aVec3,48);Cx14aVec3 &d=FIELD(self,Cx14aVec3,320);d.multiply(one_80380788[0]/sqrt_802e82c0(d.dot(d)));}


