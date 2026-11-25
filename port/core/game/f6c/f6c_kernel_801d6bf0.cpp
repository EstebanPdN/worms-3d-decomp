#include "w3d_ptr.h"
#line 1 "f6c_kernel_801d6bf0.cpp"
// Names, float kernel role and types are inferred from original instructions.
extern const float lbl_803af680[],lbl_803af684[],lbl_803af688[],lbl_803af68c[],lbl_803af690[],lbl_803af694[],lbl_803af698[],lbl_803af69c[],lbl_803af6a0[],lbl_803af6a4[],lbl_803af6a8[];extern "C" float f6c_kernel_801d6bf0(float x){float x2=x*x;if(x<lbl_803af680[0])x=-x;if(x<lbl_803af684[0]){x=x*x2*lbl_803af688[0]+x2*lbl_803af68c[0]+lbl_803af690[0];return x/lbl_803af694[0];}if(x<lbl_803af698[0]){x=x*lbl_803af6a4[0]+(x*x2*lbl_803af69c[0]+x2*lbl_803af6a0[0])+lbl_803af6a8[0];return x/lbl_803af694[0];}return lbl_803af680[0];}


