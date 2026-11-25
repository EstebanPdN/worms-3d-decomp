#include "w3d_ptr.h"
#line 1 "f8b_pack_corner_occupancy_800b3fe4.cpp"
// Inferred byte-grid extents and eight neighboring occupancy tests.
struct F8CornerExtent{unsigned char width,height,p,minX,minY,minZ,maxX,maxY,maxZ;};
extern "C" int sample_8002c73c(Ptr32<void>,int,int,int,int);
extern "C" void f8b_pack_corner_occupancy_800b3fe4(Ptr32<void> grid,Ptr32<unsigned char> out,Ptr32<const F8CornerExtent> e){for(unsigned char z=e->minZ;z<=e->maxZ;++z)for(unsigned char x=e->minX;x<=e->maxX;++x)for(unsigned char y=e->minY;y<=e->maxY;++y){unsigned char bits=0;if(sample_8002c73c(grid,x,y,z,4))bits|=1;int px=x-1;if(sample_8002c73c(grid,px,y,z,4))bits|=2;int pz=z-1;if(sample_8002c73c(grid,x,y,pz,4))bits|=4;if(sample_8002c73c(grid,px,y,pz,4))bits|=8;int py=y-1;if(sample_8002c73c(grid,x,py,z,4))bits|=16;if(sample_8002c73c(grid,px,py,z,4))bits|=32;if(sample_8002c73c(grid,x,py,pz,4))bits|=64;if(sample_8002c73c(grid,px,py,pz,4))bits|=128;out[y+e->height*(x+z*e->width)]=bits;}}


