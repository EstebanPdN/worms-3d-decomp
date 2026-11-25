#include "w3d_ptr.h"
#line 1 "cc39a_contour_backtrack_8010b5e8.cpp"
// Partial grid view and inferred contour directions; globals remain unowned.
struct cc39a_Grid;
extern "C" {
int cc39a_cell_8010b560(Ptr32<cc39a_Grid>,int,int);
int cc39a_inside_8010b594(int,int,unsigned);
extern signed char cc39a_marks_8044c9ec[];
extern int cc39a_turn_80399e88[],cc39a_dx_80399ec8[],cc39a_dy_80399ed8[],cc39a_start_80399ee8[];
}
inline int cc39a_borderRow(int x) {return (x+1)*9+1;}
extern "C" void cc39a_contour_backtrack_8010b5e8(Ptr32<cc39a_Grid> grid,int startX,int startY,Ptr32<int> outX,Ptr32<int> outY,Ptr32<unsigned int> outDirection){
 int x=startX,y=startY;
 int mark=cc39a_marks_8044c9ec[y+cc39a_borderRow(x)];
 int cell=cc39a_cell_8010b560(grid,x,y);
 unsigned initial=(cc39a_start_80399ee8[cell]+mark)&3;
 unsigned direction=(initial-cc39a_turn_80399e88[cell])&3;
 x-=cc39a_dx_80399ec8[direction]; y-=cc39a_dy_80399ed8[direction];
 while((x!=startX || y!=startY || direction!=initial) && cc39a_inside_8010b594(x,y,direction)){
  cell=cc39a_cell_8010b560(grid,x,y);
  direction=(direction-cc39a_turn_80399e88[cell])&3;
  x-=cc39a_dx_80399ec8[direction]; y-=cc39a_dy_80399ed8[direction];
 }
 int dx=cc39a_dx_80399ec8[direction],dy=cc39a_dy_80399ed8[direction];
 *outX=x+dx;*outY=y+dy;*outDirection=direction;
}


