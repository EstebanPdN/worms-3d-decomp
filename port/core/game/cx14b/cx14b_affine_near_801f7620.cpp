#include "w3d_ptr.h"
#line 1 "cx14b_affine_near_801f7620.cpp"

// PPC32 affine matrix consists of twelve four-byte floats; translation starts +36.
struct Matrix{float m[12];};extern "C" int near_801f659c(Ptr32<const Matrix>,Ptr32<const Matrix>,float);
inline int translation(Ptr32<const float> a,Ptr32<const float> b,float e){int n=3,off=0;do{if(__builtin_fabsf(*(Ptr32<const float>)w3d::G((off+(unsigned)w3d::H(b)))-*(Ptr32<const float>)w3d::G((off+(unsigned)w3d::H(a))))>e)return 0;off+=4;}while(--n);return 1;}
extern "C" int w3d_cx14b_affine_near_801f7620(Ptr32<const Matrix> a,Ptr32<const Matrix> b,float epsilon){return near_801f659c(a,b,epsilon)&&translation(a->m+9,b->m+9,epsilon);}




