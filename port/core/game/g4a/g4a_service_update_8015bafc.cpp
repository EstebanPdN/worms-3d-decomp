#include "w3d_ptr.h"
#line 1 "g4a_service_update_8015bafc.cpp"
extern "C" unsigned long long elapsed_801fe4d8();
extern "C" unsigned ticks_801fe508(unsigned);
extern "C" void toggle_8015ba30(Ptr32<void>,unsigned);
struct G4aTimingTarget{Ptr32<Ptr32<void>> vt;char unknown4[160];union {unsigned flags;struct{unsigned int rest:30; unsigned int next:1; unsigned int top:1;} bits;};};
union G4aTimestamp{unsigned long long ticks;struct{ unsigned int lo; unsigned int hi; }words;G4aTimestamp(){ticks=elapsed_801fe4d8();}unsigned delta(){return (unsigned)elapsed_801fe4d8()-words.lo;}};
struct G4aTimingOwner{Ptr32<Ptr32<void>> vt;char unknown4[36];unsigned state;char unknown44[16];unsigned elapsed;float scale;Ptr32<G4aTimingTarget> target;unsigned unknown72,flags;int quantum,remainder;};
extern "C" void g4a_service_update_8015bafc(Ptr32<G4aTimingOwner> self,unsigned amount){
 if(amount>100)amount=100;
 int step=(int)((float)amount*self->scale);
 if(self->flags&0x4000000){int total=step;if(self->flags&0x2000000)total+=self->remainder;int quantized=(total/self->quantum)*self->quantum;
 if(quantized<self->quantum){self->remainder=0;step=self->quantum;}else{step=quantized;self->remainder=total-step;}}
 if(!(self->flags&0x40000000)){
  Ptr32<G4aTimingTarget> target=self->target;
  target->bits.next=(self->flags>>29)&1;
  target->bits.top=(self->flags>>28)&1;
  ((Ptr32<void (Ptr32<G4aTimingTarget>, int)>)self->target->vt[10])(self->target,step);
 }else if(self->flags&0x8000000)((Ptr32<void (Ptr32<G4aTimingTarget>)>)self->target->vt[11])(self->target);
 if(self->flags&0x10000000){
  G4aTimestamp start;
  ((Ptr32<void (Ptr32<G4aTimingOwner>, int)>)self->vt[17])(self,step);
  self->elapsed=ticks_801fe508(start.delta());
  ((Ptr32<void (Ptr32<G4aTimingOwner>)>)self->vt[14])(self);
  if(self->state&0x40000000){toggle_8015ba30(self,(self->state>>31)^1);self->state&=~0x40000000u;}
 }
}


