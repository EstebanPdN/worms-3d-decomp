#include "w3d_ptr.h"
#line 1 "cc44a_upload_transform_8016a0a4_v3.cpp"
// Layout views only: matrix starts, dirty flag, mode bits and cached output are
// witnessed independently. No full renderer class size is inferred.
struct cc44a_Column { float x,y,z,w; };
struct cc44a_Matrix34 { float m[3][4]; };
struct cc44a_TransformState {
 unsigned char unknown0[44];
 cc44a_Column columns[4];
 int dirty;
 unsigned char unknown112[68];
 unsigned int flags;
 unsigned char unknown184[52];
 cc44a_Matrix34 native;
};
// Original inverse explicitly returns 0 on singularity and 1 on success.
extern "C" int cc44a_inverse_80302ca8(Ptr32<const cc44a_Matrix34>,Ptr32<cc44a_Matrix34>);
// Other actual definitions write their output/FIFO and do not define a result.
extern "C" void cc44a_transpose_80302c58(Ptr32<const cc44a_Matrix34>,Ptr32<cc44a_Matrix34>);
extern "C" void cc44a_load_position_8030bff4(Ptr32<const cc44a_Matrix34>,unsigned int);
extern "C" void cc44a_load_normal_8030c044(Ptr32<const cc44a_Matrix34>,unsigned int);
// Inferred native column-copy helper: each input column is read in x/y/z order
// while writing its three transposed destinations, preserving alias-sensitive order.
inline void cc44a_copy_column(const cc44a_Column &column,float &x,float &y,float &z) { x=column.x; y=column.y; z=column.z; }
extern "C" void cc44a_upload_transform_8016a0a4(Ptr32<cc44a_TransformState> self) {
 if(self->dirty) {
   cc44a_copy_column(self->columns[0], self->native.m[0][0], self->native.m[1][0], self->native.m[2][0]);
   cc44a_copy_column(self->columns[1], self->native.m[0][1], self->native.m[1][1], self->native.m[2][1]);
   cc44a_copy_column(self->columns[2], self->native.m[0][2], self->native.m[1][2], self->native.m[2][2]);
   cc44a_copy_column(self->columns[3], self->native.m[0][3], self->native.m[1][3], self->native.m[2][3]);
   cc44a_load_position_8030bff4(&self->native,0);
   if(self->flags & 0x02000000) {
     cc44a_Matrix34 inverse,transposed;
     cc44a_inverse_80302ca8(&self->native,&inverse);
     cc44a_transpose_80302c58(&inverse,&transposed);
     cc44a_load_normal_8030c044(&transposed,0);
   }
   self->dirty=0;
 }
}


