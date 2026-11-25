// Original circular grid footprint marking. Signed16 cell bounds, ordered disk inclusion.
struct cc26a_VecF4f4 {float x,y,z;};
struct cc26a_RegionF4f4 {unsigned int unknown;cc26a_VecF4f4 position;float radius;int active;};
struct cc26a_GridF4f4 {unsigned char unknown[104];float spacing;unsigned char unknown108[8];cc26a_VecF4f4 origin;};
extern "C" int cc26a_select_8001e328(cc26a_GridF4f4*,const cc26a_VecF4f4*,short*,short*,unsigned int*);
extern "C" unsigned char *cc26a_cell_8001dff8(cc26a_GridF4f4*,int,int,unsigned int);
extern "C" void cc26a_grid_mark_disk_8001f4f4(cc26a_GridF4f4 *self,cc26a_RegionF4f4 *region){
 struct {cc26a_VecF4f4 position;unsigned int unknown20;short x,z;unsigned int layer;unsigned char unknown[40];} w;
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
    unsigned char *cell=cc26a_cell_8001dff8(self,x,z,w.layer);if(*cell==0)*cell=4;
   }
  }
 }}
 region->active=1;
}
