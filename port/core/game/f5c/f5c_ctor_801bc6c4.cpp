#include "w3d_ptr.h"
#line 1 "f5c_ctor_801bc6c4.cpp"
inline void*operator new(__SIZE_TYPE__,void*p){return p;}struct Vec3_80343740{unsigned x,y,z;Vec3_80343740();};struct Rot{unsigned words[9];};struct Matrix{Rot rotation;Vec3_80343740 pos;};struct O{Ptr32<void> v;char unknown[16];Matrix matrix;unsigned value;};extern const Matrix lbl_8045e748[];extern unsigned char lbl_804152d0[];extern "C" int fn_801b529c(Ptr32<O>, Ptr32<void>);extern "C" Ptr32<O> f5c_ctor_801bc6c4(Ptr32<O> self, Ptr32<void> arg_r4){Ptr32<Matrix> m=&self->matrix;fn_801b529c(self, arg_r4);self->v=lbl_804152d0;Ptr32<const Matrix> identity=lbl_8045e748;new(&m->pos)Vec3_80343740;m->rotation=identity->rotation;m->pos=identity->pos;self->value=0;return self;}

