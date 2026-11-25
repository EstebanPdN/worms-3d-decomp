#include "w3d_ptr.h"
#line 1 "cx16c_panel_bounds_publish_802c1c90.cpp"

// Observed endpoints at +84/+96 form an axis-aligned bound; dirty flag is +108.
struct Cx16cBoundVector { float x,y,z; };
struct Cx16cBoundsPanel { char reserved[48]; Ptr32<void> held; char gap[32]; Cx16cBoundVector a,b; int dirty; };
extern int cx16c_live_804abb60;
extern Cx16cBoundVector cx16c_bounds_min_804668d0[];
extern Cx16cBoundVector cx16c_bounds_max_804668dc[];
extern "C" int cx16c_held_close_8015fd1c(Ptr32<void>);
static inline const float &cx16c_min(const float &a,const float &b) { if(b<a)return b;return a; }
static inline const float &cx16c_max(const float &a,const float &b) { if(a<b)return b;return a; }
extern "C" void w3d_cx16c_panel_bounds_publish_802c1c90(Ptr32<Cx16cBoundsPanel> self) {
 if(self->held) { cx16c_held_close_8015fd1c(self->held);self->held=0;cx16c_live_804abb60-=2; }
 if(self->dirty) {
  self->dirty=0;
  cx16c_bounds_min_804668d0[0].x=cx16c_min(self->a.x,self->b.x);
  cx16c_bounds_min_804668d0[0].y=cx16c_min(self->a.y,self->b.y);
  cx16c_bounds_min_804668d0[0].z=cx16c_min(self->a.z,self->b.z);
  cx16c_bounds_max_804668dc[0].x=cx16c_max(self->a.x,self->b.x);
  cx16c_bounds_max_804668dc[0].y=cx16c_max(self->a.y,self->b.y);
  cx16c_bounds_max_804668dc[0].z=cx16c_max(self->a.z,self->b.z);
 }
}


