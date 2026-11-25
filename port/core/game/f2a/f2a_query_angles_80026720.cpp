#include "w3d_ptr.h"
#line 1 "f2a_query_angles_80026720.cpp"
// Original entry 0x80026720; vector layout observed, field meanings inferred.
struct Vec {float x,y,z;Vec(float a,float b,float c):x(a),y(b),z(c){}Vec(const Vec&v):x(v.x),y(v.y),z(v.z){} };
struct Input {char p[32];Ptr32<void> name;};struct Body {char p[72];float angle;char q[40];float offset;};
extern "C" {Ptr32<void> fn_803426b4(Ptr32<void>);int fn_80178c48(Ptr32<void>);Ptr32<Body> fn_800fc6dc(int);extern float lbl_8036ca58[];
Vec w3d_f2a_query_angles_80026720(Ptr32<Input> p){Vec v(lbl_8036ca58[0],lbl_8036ca58[0],lbl_8036ca58[0]);Ptr32<Body> b=fn_800fc6dc(fn_80178c48(fn_803426b4(p->name)));v.x-=b->offset;v.y=b->angle;return v;}}


