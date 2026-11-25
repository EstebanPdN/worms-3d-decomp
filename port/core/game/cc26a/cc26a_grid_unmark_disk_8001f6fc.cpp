#include "w3d_ptr.h"
#line 1 "cc26a_grid_unmark_disk_8001f6fc.cpp"
// Original circular grid footprint removal. Signed16 cell bounds, ordered disk inclusion.
struct cc26a_VecF6fc {float x,y,z;};
struct cc26a_RegionF6fc {unsigned int unknown;cc26a_VecF6fc position;float radius;int active;};
struct cc26a_GridF6fc {unsigned char unknown[104];float spacing;unsigned char unknown108[8];cc26a_VecF6fc origin;};
extern "C" int cc26a_select_8001e328(Ptr32<cc26a_GridF6fc>,Ptr32<const cc26a_VecF6fc>,Ptr32<short>,Ptr32<short>,Ptr32<unsigned int>);
extern "C" Ptr32<unsigned char> cc26a_cell_8001dff8(Ptr32<cc26a_GridF6fc>,int,int,unsigned int);
extern "C" void cc26a_grid_unmark_disk_8001f6fc(Ptr32<cc26a_GridF6fc> self,Ptr32<cc26a_RegionF6fc> region){
 struct {cc26a_VecF6fc position;unsigned int unknown20;short x,z;unsigned int layer;unsigned char unknown[40];} w;
 // Workspace fields beyond observed vector and coordinate outputs retain unknown purpose.
 float radius=region->radius,centerX=region->position.x,centerZ=region->position.z;
 float squared=radius*radius;
 int xmin=(short)(int)((centerX-radius-self->origin.x)/self->spacing+0.5f);
 int zmin=(short)(int)((centerZ-radius-self->origin.z)/self->spacing+0.5f);
 int xmax=(short)(int)((centerX+radius-self->origin.x)/self->spacing+0.5f);
 int zmax=(short)(int)((centerZ+radius-self->origin.z)/self->spacing+0.5f);
 for(int x=xmin;x<=xmax;++x){for(int z=zmin;z<=zmax;++z){
  float dz=centerZ-((float)z*self->spacing+self->origin.z);
  float dx=centerX-((float)x*self->spacing+self->origin.x);
  if(dx*dx+dz*dz<=squared){
   w.position.x=centerX-dx;w.position.y=region->position.y;w.position.z=centerZ-dz;
   if(cc26a_select_8001e328(self,&w.position,&w.x,&w.z,&w.layer)){
    Ptr32<unsigned char> cell=cc26a_cell_8001dff8(self,x,z,w.layer);if(*cell==4)*cell=0;
   }
  }
 }}
 region->active=0;
}


