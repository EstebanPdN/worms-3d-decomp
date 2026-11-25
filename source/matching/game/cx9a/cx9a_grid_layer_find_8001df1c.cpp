// PPC32 half-open X/Z bounds +0x1c; cached layer +0x1c, layer range +0x58/+0x5c.
struct Cx9aBounds {short xmin,zmin,xmax,zmax;int contains(int x,int z)const {return x>=xmin && x<xmax && z>=zmin && z<zmax;}};
struct Cx9aLayer {unsigned char unknown00[0x1c];Cx9aBounds bounds;};
struct Cx9aGrid {unsigned char unknown00[0x1c];Cx9aLayer *cached;unsigned char unknown20[0x38];Cx9aLayer **begin,**end;};
extern "C" Cx9aLayer *w3d_cx9a_grid_layer_find_8001df1c(Cx9aGrid *self,int x,int z){
 if(self->cached->bounds.contains(x,z))return self->cached;
 int index=0;int count=self->end-self->begin;
 if(index<count){Cx9aLayer **cursor=self->begin;for(;index<count;++index,++cursor){Cx9aLayer *layer=*cursor;if(layer->bounds.contains(x,z)){self->cached=layer;return layer;}}}return 0;
}
