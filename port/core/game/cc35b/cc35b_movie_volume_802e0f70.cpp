#include "w3d_ptr.h"
#line 1 "cc35b_movie_volume_802e0f70.cpp"
typedef unsigned char cc35b_u8;
// Inferred partial state view; gain interpolation widths and branch order come from original instructions.
struct cc35b_VolumeState { cc35b_u8 unknown0[160];int opened,playing,busy,audio_present;cc35b_u8 unknown176[32];float current,target,step;int samples; };
struct cc35b_VolumePlayer { int unknown0;Ptr32<cc35b_VolumeState> state; };
extern "C" int fn_803114f0();
extern "C" int fn_802fdb6c();
extern "C" int fn_802fdb94(int);
extern "C" int w3d_cc35b_movie_volume_802e0f70(Ptr32<cc35b_VolumePlayer> self,int volume,int milliseconds) {
 if(self->state->opened && self->state->audio_present) {
 int rate=48;
 if(!fn_803114f0())rate=32;
 if(volume>127)volume=127;else if(volume<0)volume=0;
 if(milliseconds>60000)milliseconds=60000;else if(milliseconds<0)milliseconds=0;
 int token=fn_802fdb6c();
 self->state->target=(float)volume;
 if(milliseconds) {
  self->state->samples=rate*milliseconds;
  self->state->step=(self->state->target-self->state->current)/(float)self->state->samples;
 } else {
  self->state->samples=milliseconds;
  self->state->current=self->state->target;
 }
 fn_802fdb94(token);
 return 1;
 }
 return 0;
}


