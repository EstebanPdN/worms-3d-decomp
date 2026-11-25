#include "w3d_ptr.h"
#line 1 "f2a_cell_corner_masks_800b3e20.cpp"
// Original entry 0x800b3e20. Corner-mask interpretation is inferred.
extern "C" int fn_8002c73c(Ptr32<void>,int,int,int,int);
extern "C" void w3d_f2a_cell_corner_masks_800b3e20(Ptr32<void> grid,Ptr32<unsigned char> out,unsigned xMax,unsigned yMax,unsigned zMax){
 for(unsigned char z=0;z<=zMax;++z){for(unsigned char x=0;x<=xMax;++x){for(unsigned char y=0;y<=yMax;++y){
 unsigned mask=0;
 if(fn_8002c73c(grid,x,y,z,4))mask=1;
 int px=x-1;
 if(fn_8002c73c(grid,px,y,z,4))mask|=2;
 int pz=z-1;
 if(fn_8002c73c(grid,x,y,pz,4))mask|=4;
 if(fn_8002c73c(grid,px,y,pz,4))mask|=8;
 int py=y-1;
 if(fn_8002c73c(grid,x,py,z,4))mask|=16;
 if(fn_8002c73c(grid,px,py,z,4))mask|=32;
 if(fn_8002c73c(grid,x,py,pz,4))mask|=64;
 if(fn_8002c73c(grid,px,py,pz,4))mask|=128;
 *out++=mask;
 }}}
}


