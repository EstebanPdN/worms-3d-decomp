#include "w3d_ptr.h"
#line 1 "cc34b_movie_init_802e02ec.cpp"
typedef unsigned int cc34b_u32;
struct cc34b_MovieState_802e02ec { char before_volume[208]; float volume; float target; float delta; int duration; };
struct cc34b_Player_802e02ec { int unknown; Ptr32<cc34b_MovieState_802e02ec> movie; Ptr32<void> workspace; int initialized; char before_mode[68]; int mode; };
extern "C" {
Ptr32<void> fn_801fe1d8(unsigned int);
Ptr32<void> fn_802eefe0(Ptr32<void>,int,unsigned int);
int fn_802fab90(); int fn_80322268();
int fn_802e20e4(Ptr32<cc34b_Player_802e02ec>,int);
int fn_802ebfbc(Ptr32<const char>,...);
extern const char lbl_803db030[];
extern const float lbl_803db050[];
extern const float lbl_803db054[];
int w3d_cc34b_movie_init_802e02ec(Ptr32<cc34b_Player_802e02ec> self) {
 if(self->initialized!=1) {
  self->movie=(Ptr32<cc34b_MovieState_802e02ec>)fn_801fe1d8(416);
  self->workspace=fn_801fe1d8(96);
  if(self->movie && self->workspace) {
   fn_802eefe0(self->movie,0,416);
   fn_802fab90();
   if(!fn_80322268()) return 0;
   if(fn_802e20e4(self,2)) {
    self->initialized=1;self->mode=2;
    self->movie->delta=lbl_803db050[0];
    self->movie->duration=0;
    self->movie->target=self->movie->volume=lbl_803db054[0];
    return 1;
   }
  }
 } else fn_802ebfbc(lbl_803db030);
 return 0;
}
}


