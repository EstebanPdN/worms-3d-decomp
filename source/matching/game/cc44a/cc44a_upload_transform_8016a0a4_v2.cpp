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
extern "C" int cc44a_inverse_80302ca8(const cc44a_Matrix34 *,cc44a_Matrix34 *);
// Other actual definitions write their output/FIFO and do not define a result.
extern "C" void cc44a_transpose_80302c58(const cc44a_Matrix34 *,cc44a_Matrix34 *);
extern "C" void cc44a_load_position_8030bff4(const cc44a_Matrix34 *,unsigned int);
extern "C" void cc44a_load_normal_8030c044(const cc44a_Matrix34 *,unsigned int);
inline void cc44a_convert(const cc44a_Column *source,cc44a_Matrix34 *dest) {
   dest->m[0][0]=source[0].x;
   dest->m[1][0]=source[0].y;
   dest->m[2][0]=source[0].z;
   dest->m[0][1]=source[1].x;
   dest->m[1][1]=source[1].y;
   dest->m[2][1]=source[1].z;
   dest->m[0][2]=source[2].x;
   dest->m[1][2]=source[2].y;
   dest->m[2][2]=source[2].z;
   dest->m[0][3]=source[3].x;
   dest->m[1][3]=source[3].y;
   dest->m[2][3]=source[3].z;
}
extern "C" void cc44a_upload_transform_8016a0a4(cc44a_TransformState *self) {
 if(self->dirty) {
   cc44a_convert(self->columns,&self->native);
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
