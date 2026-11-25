#include "w3d_ptr.h"
#line 1 "cx13b_gx_textured_quad_emit_8016dfcc.cpp"

// PPC32 object starts with a pointer to a descriptor containing unsigned dimensions.
struct Descriptor{unsigned char opaque[16];unsigned short width,height;};struct Object{Ptr32<Descriptor> descriptor;};extern "C" volatile unsigned short fifo_cc008000[];extern "C" void begin_803089c8(int,int,int);
extern "C" void w3d_cx13b_gx_textured_quad_emit_8016dfcc(Ptr32<Object> self,int x,int y,int u,int v){Ptr32<Descriptor> d=self->descriptor;short left=x,top=y,startU=u,startV=v;short right=d->width+left,bottom=d->height+top,endU=d->width+u,endV=d->height+v;begin_803089c8(128,0,4);fifo_cc008000[0]=left;fifo_cc008000[0]=top;fifo_cc008000[0]=0;fifo_cc008000[0]=startU;fifo_cc008000[0]=startV;fifo_cc008000[0]=right;fifo_cc008000[0]=top;fifo_cc008000[0]=0;fifo_cc008000[0]=endU;fifo_cc008000[0]=startV;fifo_cc008000[0]=right;fifo_cc008000[0]=bottom;fifo_cc008000[0]=0;fifo_cc008000[0]=endU;fifo_cc008000[0]=endV;fifo_cc008000[0]=left;fifo_cc008000[0]=bottom;fifo_cc008000[0]=0;fifo_cc008000[0]=startU;fifo_cc008000[0]=endV;}



