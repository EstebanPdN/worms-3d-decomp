#include "w3d_ptr.h"
#line 1 "cx14a_trail_endpoints_800e9d08.cpp"
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


extern "C" Ptr32<void> resolve_80164fc8(unsigned);extern "C" void matrix_80343740(Ptr32<void>),segment_80122800(Ptr32<void>,Ptr32<const Cx14aVec3>,Ptr32<const Cx14aVec3>,int);
extern "C" void w3d_cx14a_trail_endpoints_800e9d08(Ptr32<void> self){
 struct Matrix{float basis[9];Cx14aVec3 position;Matrix(){matrix_80343740(&position);}};
 Cx14aVec3 begin,end;
 Ptr32<void> trail=resolve_80164fc8(FIELD(self,unsigned,196));Matrix transform;
 Ptr32<void> a=FIELD(self,void *,200);VCALL(a,void (*)(void *,Matrix *),124)(a,&transform);begin=transform.position;
 Ptr32<void> b=FIELD(self,void *,204);VCALL(b,void (*)(void *,Matrix *),124)(b,&transform);end=transform.position;segment_80122800(trail,&begin,&end,0);}


