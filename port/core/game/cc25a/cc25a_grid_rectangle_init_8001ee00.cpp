#include "w3d_ptr.h"
#line 1 "cc25a_grid_rectangle_init_8001ee00.cpp"
// Original 0x8001ee00: initialize a grid-coordinate rectangle and iteration cursors.
struct cc25a_Rect1ee00{int flag,minX,maxX,minZ,maxZ,cursorX,cursorZ,unknown28;};
struct cc25a_Point1ee00{float x,y,z;};
struct cc25a_Grid1ee00{unsigned char unknown[104];float cellSize;unsigned char unknown108[8];cc25a_Point1ee00 origin;};
extern float cc25a_round_8036b89c[];
extern "C" Ptr32<cc25a_Rect1ee00> cc25a_grid_rectangle_init_8001ee00(Ptr32<cc25a_Rect1ee00> self,Ptr32<const cc25a_Point1ee00> p,Ptr32<const cc25a_Grid1ee00> grid,float radius){
 self->minX=(int)(((p->x-radius)-grid->origin.x)/grid->cellSize+0.5f);
 self->maxX=(int)(((p->x+radius)-grid->origin.x)/grid->cellSize+0.5f);
 self->minZ=(int)(((p->z-radius)-grid->origin.z)/grid->cellSize+0.5f);
 self->maxZ=(int)(((p->z+radius)-grid->origin.z)/grid->cellSize+0.5f);
 self->cursorX=self->minX;self->cursorZ=self->minZ;self->unknown28=0;self->flag=0;return self;
}


