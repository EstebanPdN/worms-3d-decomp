#include "w3d_ptr.h"
#line 1 "cx9a_grid_layer_find_8001df1c.cpp"
// PPC32 half-open X/Z bounds +0x1c; cached layer +0x1c, layer range +0x58/+0x5c.
struct Cx9aBounds {short xmin,zmin,xmax,zmax;int contains(int x,int z)const {return x>=xmin && x<xmax && z>=zmin && z<zmax;}};
struct Cx9aLayer {unsigned char unknown00[0x1c];Cx9aBounds bounds;};
struct Cx9aGrid {unsigned char unknown00[0x1c];Ptr32<Cx9aLayer> cached;unsigned char unknown20[0x38];Ptr32<Ptr32<Cx9aLayer>> begin; Ptr32<Ptr32<Cx9aLayer>> end;};
extern "C" Ptr32<Cx9aLayer> w3d_cx9a_grid_layer_find_8001df1c(Ptr32<Cx9aGrid> self,int x,int z){
 if(self->cached->bounds.contains(x,z))return self->cached;
 int index=0;int count=self->end-self->begin;
 if(index<count){Ptr32<Ptr32<Cx9aLayer>> cursor=self->begin;for(;index<count;++index,++cursor){Ptr32<Cx9aLayer> layer=*cursor;if(layer->bounds.contains(x,z)){self->cached=layer;return layer;}}}return 0;
}


