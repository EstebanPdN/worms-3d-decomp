#include "w3d_ptr.h"
#line 1 "cc23a_path_vertical_fit_8000519c.cpp"
// Large path-search object: offsets are observed; roles remain inferred.
struct Cc23aPath8000519c {unsigned char unknown00[0x8038];float tolerance8038;};
extern "C" {extern Ptr32<void> lbl_804b1758;Ptr32<float> fn_8001e11c(Ptr32<void>,int,int,int);Ptr32<float> fn_8001e1a0(Ptr32<void>,int,int,int);}
extern "C" int cc23a_path_vertical_fit_8000519c(Ptr32<Cc23aPath8000519c> self,int x,int y,int z,float low,float high){
 Ptr32<void> grid=lbl_804b1758;
 float floor=*fn_8001e11c(grid,x,y,z);
 float ceiling=*fn_8001e1a0(grid,x,y,z);
 if(ceiling-low>self->tolerance8038)return 0;
 if(high-floor>self->tolerance8038)return 0;
 return 1;
}


