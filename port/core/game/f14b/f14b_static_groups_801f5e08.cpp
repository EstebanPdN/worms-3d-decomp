#include "w3d_ptr.h"
#line 1 "f14b_static_groups_801f5e08.cpp"
// Inferred static math-object views: three 16-byte four-float views, one
// 28-byte parameter view and two 24-byte paired-vector views. Placement new
// expresses initialization of external storage and performs no allocation.
// Names, original API identities and complete external class identities are unknown.
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct F14bV4{float x,y,z,w;F14bV4(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}};
struct F14bV3s{float x,y,z;F14bV3s(float a,float b,float c):x(a),y(b),z(c){}};
struct F14bRange{F14bV3s a,b;F14bRange(float hi,float lo):a(hi,hi,hi),b(lo,lo,lo){}};
struct F14bProjection{float left,right,bottom,top,nearPlane,farPlane;int mode;F14bProjection(float a,float b,float c,float d,float e,float f):left(a),right(b),bottom(c),top(d),nearPlane(e),farPlane(f),mode(0){}};
extern F14bV4 lbl_8045e62c[],lbl_8045e63c[],lbl_8045e64c[];extern F14bProjection lbl_8045e65c[];extern F14bRange lbl_8045e678[],lbl_8045e690[];
extern "C" void f14b_static_groups_801f5e08(int initialize,int priority){if(priority==65535&&initialize){
new(&lbl_8045e62c[0])F14bV4(0.0f,0.0f,0.0f,0.0f);
new(&lbl_8045e63c[0])F14bV4(0.0f,0.0f,0.0f,-1.0f);
new(&lbl_8045e64c[0])F14bV4(0.0f,0.0f,0.0f,1e38f);
new(&lbl_8045e65c[0])F14bProjection(-1.0f,1.0f,-1.0f,1.0f,0.1f,1000.0f);
new(&lbl_8045e678[0])F14bRange(0.0f,0.0f);
new(&lbl_8045e690[0])F14bRange(3.4028234663852886e38f,-3.4028234663852886e38f);
}}


