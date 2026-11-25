#include "w3d_ptr.h"
#line 1 "cx13b_movie_quad_emit_802e2a00.cpp"

// PPC32 GX FIFO is a volatile halfword port. Texture records have stride 32.
struct Texture{unsigned char opaque[32];};extern "C" void bind_8030a21c(Ptr32<Texture>,int);extern "C" void begin_803089c8(int,int,int);
extern "C" volatile unsigned short fifo_cc008000[];
extern "C" void w3d_cx13b_movie_quad_emit_802e2a00(Ptr32<Texture> textures,short x,short y,short width,short height){bind_8030a21c(textures,0);bind_8030a21c(textures+1,1);bind_8030a21c(textures+2,2);begin_803089c8(128,7,4);fifo_cc008000[0]=x;short right=x+width;fifo_cc008000[0]=y;fifo_cc008000[0]=0;fifo_cc008000[0]=0;short bottom=y+height;fifo_cc008000[0]=0;fifo_cc008000[0]=right;fifo_cc008000[0]=y;fifo_cc008000[0]=0;fifo_cc008000[0]=1;fifo_cc008000[0]=0;fifo_cc008000[0]=right;fifo_cc008000[0]=bottom;fifo_cc008000[0]=0;fifo_cc008000[0]=1;fifo_cc008000[0]=1;fifo_cc008000[0]=x;fifo_cc008000[0]=bottom;fifo_cc008000[0]=0;fifo_cc008000[0]=0;fifo_cc008000[0]=1;}




