#include "w3d_ptr.h"
#line 1 "cx10a_cached_probe_800cffa0.cpp"
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx10aVec3 {
 float x,y,z;
 Cx10aVec3() {}
 Cx10aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx10aVec3(const Cx10aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx10aVec3 scaled(float k) const {Cx10aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx10aVec3 plus(const Cx10aVec3 &o) const {Cx10aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx10aVec3 minus(const Cx10aVec3 &o) const {Cx10aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx10aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 void multiply(float k){x*=k;y*=k;z*=k;}
 void set(float a,float b,float c){x=a;y=b;z=c;}
 float dot(const Cx10aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};


extern const float zero_80388138[],scale_8038813c[];
extern int initialized_804ae868;
extern Cx10aVec3 origin_8043fddc[];
extern int result_804b1764;
extern "C" void probe_800b0824(Ptr32<void>,Ptr32<const Cx10aVec3>,Ptr32<const Cx10aVec3>,int,int);
extern "C" bool w3d_cx10a_cached_probe_800cffa0(Ptr32<void> unused,Ptr32<void> context,Ptr32<const Cx10aVec3> direction){
 if(!initialized_804ae868){initialized_804ae868=1;origin_8043fddc[0].set(zero_80388138[0],zero_80388138[0],zero_80388138[0]);}
 Cx10aVec3 delta(direction->scaled(scale_8038813c[0]));
 probe_800b0824(context,&delta,origin_8043fddc,1000,1);return result_804b1764<1001;
}


