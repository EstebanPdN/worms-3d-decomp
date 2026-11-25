#include "w3d_ptr.h"
#line 1 "cx15b_projection_matrix_apply_80167748.cpp"
// Inferred engine names. Layout offsets and PPC32 four-byte pointers follow original effective addresses.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))

extern "C" {void projection_8030bec4(Ptr32<float>,int);extern float value_803a4e18[];extern float value_803a4e1c[];}
struct Matrix{float m[16];};
extern "C" int w3d_cx15b_projection_matrix_apply_80167748(Ptr32<void> self,Ptr32<const Matrix> matrix){float local[16];local[0]=matrix->m[0];local[2]=matrix->m[8];local[5]=matrix->m[5];local[6]=matrix->m[9];local[10]=value_803a4e18[0];local[11]=value_803a4e1c[0];projection_8030bec4(local,0);FIELD(self,Matrix,48)=*matrix;return 0;}




