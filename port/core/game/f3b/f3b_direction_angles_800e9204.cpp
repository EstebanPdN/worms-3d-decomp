#include "w3d_ptr.h"
#line 1 "f3b_direction_angles_800e9204.cpp"
// Observed vector operations and partial layouts; semantic roles are inferred.
extern const float zero_8038b258[],one_8038b25c[],halfturn_8038b260[];extern "C" float asin_802e7c30(float);extern "C" float sqrt_802e82c0(float);
struct Vec3{float x,y,z;float length2()const{return x*x+y*y+z*z;}void operator*=(float f){x*=f;y*=f;z*=f;}};
struct Owner{char pad[40];float angle;};
extern "C" void f3b_direction_angles_800e9204(Ptr32<Owner> s,Ptr32<const Vec3> in,Ptr32<Vec3> out){out->x=-asin_802e7c30(in->y);out->z=zero_8038b258[0];Vec3 v;v=*in;v.y=zero_8038b258[0];if(v.length2()>zero_8038b258[0]){v*=one_8038b25c[0]/sqrt_802e82c0(v.length2());float angle=asin_802e7c30(v.x);if(in->z<zero_8038b258[0])angle=halfturn_8038b260[0]-angle;out->y=angle;}else out->y=s->angle;}


