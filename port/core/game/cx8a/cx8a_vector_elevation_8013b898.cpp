#include "w3d_ptr.h"
#line 1 "cx8a_vector_elevation_8013b898.cpp"
// PPC32 vector components +0/+4/+8; explicit float copy constructor reproduces value temporaries.
struct Cx8aVec3 {
 float x,y,z;
 Cx8aVec3() {}
 Cx8aVec3(float a,float b,float c) {x=a;y=b;z=c;}
 Cx8aVec3(const Cx8aVec3 &o) {float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}
 Cx8aVec3 scaled(float k) const {Cx8aVec3 r;r.x=x*k;r.y=y*k;r.z=z*k;return r;}
 Cx8aVec3 plus(const Cx8aVec3 &o) const {Cx8aVec3 r;r.x=x+o.x;r.y=y+o.y;r.z=z+o.z;return r;}
 Cx8aVec3 minus(const Cx8aVec3 &o) const {Cx8aVec3 r;r.x=x-o.x;r.y=y-o.y;r.z=z-o.z;return r;}
 void add(const Cx8aVec3 &o){x+=o.x;y+=o.y;z+=o.z;}
 float dot(const Cx8aVec3 &o)const{return x*o.x+y*o.y+z*o.z;}
};
extern const float zero_8039f800[];
extern "C" float root_802e82c0(float);extern "C" float angle_802e83ec(float);
extern "C" float w3d_cx8a_vector_elevation_8013b898(Ptr32<void>,Ptr32<const Cx8aVec3> from,Ptr32<const Cx8aVec3> to){
 Cx8aVec3 delta=from->minus(*to);Cx8aVec3 planar(delta);planar.y=zero_8039f800[0];return angle_802e83ec(delta.y/root_802e82c0((planar.x*planar.x+planar.y)+planar.z*planar.z));
}


