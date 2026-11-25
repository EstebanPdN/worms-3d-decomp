#include "w3d_ptr.h"
#line 1 "cc39a_contour_next_8010b75c.cpp"
// Inferred contour scan; signed cursor globals and runtime grid marks remain unowned.
struct cc39a_Grid;
extern "C" {
extern int cc39a_row_804af2b0,cc39a_column_804af2b4;
extern signed char cc39a_marks_8044c9ec[];
extern int cc39a_start_80399ee8[];
int cc39a_cell_8010b560(Ptr32<cc39a_Grid>,int,int);
int cc39a_inside_8010b594(int,int,unsigned);
void cc39a_backtrack_8010b5e8(Ptr32<cc39a_Grid>,int,int,Ptr32<int>,Ptr32<int>,Ptr32<unsigned int>);
}
inline int cc39a_borderRow(int x){return (x+1)*9+1;}
inline void cc39a_advance(){
 if(++cc39a_column_804af2b4>7){cc39a_column_804af2b4=0;++cc39a_row_804af2b0;}
}
extern "C" int cc39a_contour_next_8010b75c(Ptr32<cc39a_Grid> grid,Ptr32<int> outX,Ptr32<int> outY,Ptr32<unsigned int> outDirection){
 while(cc39a_row_804af2b0<=7){
  int mark=cc39a_marks_8044c9ec[cc39a_column_804af2b4+cc39a_borderRow(cc39a_row_804af2b0)];
  if(mark>0){
   int cell=cc39a_cell_8010b560(grid,cc39a_row_804af2b0,cc39a_column_804af2b4);
   if(cell!=0 && cell!=15 && cc39a_inside_8010b594(cc39a_row_804af2b0,cc39a_column_804af2b4,(cc39a_start_80399ee8[cell]+mark)&3)){
    cc39a_backtrack_8010b5e8(grid,cc39a_row_804af2b0,cc39a_column_804af2b4,outX,outY,outDirection);
    cc39a_advance();return 1;
   }
  }
  cc39a_advance();
 }
 return 0;
}


