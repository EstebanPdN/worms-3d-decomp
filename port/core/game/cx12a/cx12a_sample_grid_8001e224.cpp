#include "w3d_ptr.h"
#line 1 "cx12a_sample_grid_8001e224.cpp"
// PPC32 byte offsets, four-byte pointer slots and three-float vectors are observed. Semantic names inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx12aVec3 {
 float x,y,z;
 Cx12aVec3() {}
 Cx12aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx12aVec3(const Cx12aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx12aVec3 scaled(float k) const {Cx12aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx12aVec3 plus(const Cx12aVec3 &o) const {Cx12aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx12aVec3 minus(const Cx12aVec3 &o) const {Cx12aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx12aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx12aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};

extern "C" float height_8001e07c(Ptr32<void>,int,int,unsigned);
extern "C" Ptr32<Cx12aVec3> w3d_cx12a_sample_grid_8001e224(Ptr32<Cx12aVec3> out,Ptr32<void> self,int x,int z,unsigned flags){
 float px=(float)x*FIELD(self,float,0x68)+FIELD(self,float,0x74);float y=height_8001e07c(self,x,z,flags);float pz=(float)z*FIELD(self,float,0x68)+FIELD(self,float,0x7c);out->x=px;out->y=y;out->z=pz;return out;
}


