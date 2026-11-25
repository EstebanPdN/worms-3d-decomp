#include "w3d_ptr.h"
#line 1 "f2a_polar_vector_80028f48.cpp"
// Original entry 0x80028f48. Field meanings and names are inferred.
// The second local vector accounts for the observed unused frame reservation.
struct Vec { float x,y,z; Vec(){} Vec(const Vec &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;} };
struct Obj {char p[72];float angle;char q[20];Ptr32<void> a; Ptr32<void> b;};
extern "C" {float fn_80178df0(Ptr32<void>);float fn_802e86d4(float);float fn_802e88ac(float);extern float lbl_8036cedc[],lbl_8036cee0[];
Vec w3d_f2a_polar_vector_80028f48(Ptr32<Obj> p){Vec v;Vec spare;float a=fn_80178df0(p->a);float c=fn_802e86d4(p->angle);float scale=lbl_8036cedc[0];v.x=c*(a*scale);float b=fn_80178df0(p->a);v.y=fn_802e88ac(p->angle)*(b*scale);v.z=lbl_8036cee0[0];v.x-=fn_80178df0(p->b)*scale;return v;}}


