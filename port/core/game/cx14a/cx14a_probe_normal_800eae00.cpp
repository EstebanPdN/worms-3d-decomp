#include "w3d_ptr.h"
#line 1 "cx14a_probe_normal_800eae00.cpp"
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


extern const Cx14aVec3 bias_8045e788[],point_8043ae20[],normal_8043ae38[];
extern unsigned distance_804b1764,mode_804b1784;
extern const float one_8038b400[];
extern "C" float sqrt_802e82c0(float);
extern "C" void trace_800b0824(Ptr32<void>,Ptr32<void>,Ptr32<const Cx14aVec3>,int,int),select_800bd920();
extern "C" int w3d_cx14a_probe_normal_800eae00(Ptr32<void>,Ptr32<void> start,Ptr32<void> direction,Ptr32<Cx14aVec3> normal,Ptr32<Cx14aVec3> point){
 Cx14aVec3 bias(bias_8045e788[0]);trace_800b0824(start,direction,&bias,20,1);unsigned d=distance_804b1764;*point=point_8043ae20[0];if(!mode_804b1784)select_800bd920();*normal=normal_8043ae38[0];normal->multiply(one_8038b400[0]/sqrt_802e82c0(normal->dot(*normal)));return d<21;
}


