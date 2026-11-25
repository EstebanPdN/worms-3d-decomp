#include "w3d_ptr.h"
#line 1 "cx14a_distance_falloff_80017380.cpp"
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



extern const Cx14aVec3 target_8041d3a0[];extern Ptr32<void> parameters_804aa6d8;extern "C" void base_80016bec(Ptr32<void>);extern "C" float sqrt_802e82c0(float),factor_800155d0();
extern "C" void w3d_cx14a_distance_falloff_80017380(Ptr32<void> self){base_80016bec(self);if(FIELD(self,int,36)){const Cx14aVec3 &position=FIELD(self,Cx14aVec3,20);float x=target_8041d3a0[0].x-position.x,y=target_8041d3a0[0].y-position.y,z=target_8041d3a0[0].z-position.z;float distance=sqrt_802e82c0(x*x+y*y+z*z);if(distance>=FIELD(parameters_804aa6d8,float,224))FIELD(self,float,4)*=FIELD(parameters_804aa6d8,float,224)/distance;}float factor=factor_800155d0();if(factor<FIELD(parameters_804aa6d8,float,136))FIELD(self,float,4)*=factor/FIELD(parameters_804aa6d8,float,136);}


