// Inferred four-stage engine state update, original entry 0x800f2dac.
// GC32 external object view, not an allocation or portable complete class.
// Byte ranges preserve observed field offsets; their contents are unknown.
// All calls retain original external ownership and are bound by call-site proof.
struct Mx16saStateOwner {
 unsigned char unknown_0000_042f[1072];
 int pending_second, pending_first;
 unsigned char unknown_0438_0bf3[1980];
 int timer;
 unsigned char unknown_0bf8_0c5f[104];
 int state, countdown;
 unsigned int unknown_0c68_0c6f[2];
 int first,second;
 void *expected,*current;
};
extern "C" void swap_handles_800f3028(Mx16saStateOwner *);
extern "C" void advance_pair_800f30f0(Mx16saStateOwner *);
extern "C" void start_stage_800f35e4(Mx16saStateOwner *);
extern "C" int poll_stage_800f5148(Mx16saStateOwner *);
extern "C" void refresh_stage_800f3ddc(Mx16saStateOwner *);
extern "C" void finish_stage_800f46b8(Mx16saStateOwner *);
extern "C" int mx16sa_update_state_800f2dac(Mx16saStateOwner *self) {
 switch(self->state) {
 case 1: {
  int remaining=self->countdown;
  if(remaining==0) {
   swap_handles_800f3028(self);
   self->countdown=remaining;
   self->state=2;
  } else self->countdown=remaining-1;
  break;
 }
 case 2:
  if(self->current==self->expected) {
   advance_pair_800f30f0(self);
   self->state=3;
   self->countdown=0;
  }
  break;
 case 3:
  if(self->countdown==0) {
   start_stage_800f35e4(self);
   self->state=4;
  } else --self->countdown;
  break;
 case 4:
  if(poll_stage_800f5148(self)) {
   refresh_stage_800f3ddc(self);
   self->timer=6;
  } else {
   int remaining=--self->timer;
   if(remaining==0) {
    int first=self->first;
    if(first>0) {
     self->timer=6;
     self->first=remaining;
     self->pending_first=first;
    } else {
     int second=self->second;
     if(second>0) {
      self->timer=6;
      self->second=remaining;
      self->pending_second=second;
     } else {
      self->state=remaining;
      finish_stage_800f46b8(self);
     }
    }
   }
  }
  break;
 }
 return 100;
}
