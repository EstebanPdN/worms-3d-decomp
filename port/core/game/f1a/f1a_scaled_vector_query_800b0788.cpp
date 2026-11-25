#include "w3d_ptr.h"
#line 1 "f1a_scaled_vector_query_800b0788.cpp"
// Original 0x800b0788; vector layout and operations are observed, purpose inferred.
struct F1aVec {
 float x,y,z;
 F1aVec(float a,float b,float c):x(a),y(b),z(c){}
 F1aVec(const F1aVec &v):x(v.x),y(v.y),z(v.z){}
};
inline F1aVec multiply(const F1aVec &v,float s){F1aVec r(v.x*s,v.y*s,v.z*s);return r;}
extern "C" {
extern float lbl_803823a4[],lbl_803823a8[],lbl_803823ac[];
extern unsigned lbl_804b1764;
void fn_800b0824(Ptr32<void>,Ptr32<F1aVec>,Ptr32<F1aVec>,int,int);
int w3d_f1a_scaled_vector_query_800b0788(Ptr32<void> self,Ptr32<const F1aVec> v) {
 float denom=lbl_803823a8[0];float scale=lbl_803823ac[0]/denom;
 F1aVec zero(lbl_803823a4[0],lbl_803823a4[0],lbl_803823a4[0]);
 F1aVec scaled=multiply(*v,scale);
 fn_800b0824(self,&scaled,&zero,1000,1);
 return lbl_804b1764<=1000;
}
}


