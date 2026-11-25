#include "w3d_ptr.h"
#line 1 "cx14a_dispatch_normal_8001baf4.cpp"
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



extern unsigned selected_804b1784;extern const Cx14aVec3 normal_8043ae38[];extern Ptr32<void> actor_804aa77c;extern const Cx14aVec3 position_8041e85c[];extern const float one_8036b070[];extern "C" void select_800bd920(),motion_800ec400(Ptr32<void>,unsigned,Ptr32<const Cx14aVec3>,Ptr32<void>,Ptr32<const Cx14aVec3>);extern "C" float sqrt_802e82c0(float);
extern "C" void w3d_cx14a_dispatch_normal_8001baf4(unsigned key){if(!selected_804b1784)select_800bd920();Cx14aVec3 normal(normal_8043ae38[0]);normal.multiply(one_8036b070[0]/sqrt_802e82c0(normal.dot(normal)));motion_800ec400(actor_804aa77c,1,position_8041e85c,(Ptr32<void>)w3d::G(key),&normal);}


