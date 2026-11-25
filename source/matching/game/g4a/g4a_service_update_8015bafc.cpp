extern "C" unsigned long long elapsed_801fe4d8();
extern "C" unsigned ticks_801fe508(unsigned);
extern "C" void toggle_8015ba30(void*,unsigned);
struct G4aTimingTarget{void**vt;char unknown4[160];union {unsigned flags;struct{unsigned top:1,next:1,rest:30;} bits;};};
union G4aTimestamp{unsigned long long ticks;struct{unsigned hi,lo;}words;G4aTimestamp(){ticks=elapsed_801fe4d8();}unsigned delta(){return (unsigned)elapsed_801fe4d8()-words.lo;}};
struct G4aTimingOwner{void**vt;char unknown4[36];unsigned state;char unknown44[16];unsigned elapsed;float scale;G4aTimingTarget*target;unsigned unknown72,flags;int quantum,remainder;};
extern "C" void g4a_service_update_8015bafc(G4aTimingOwner*self,unsigned amount){
 if(amount>100)amount=100;
 int step=(int)((float)amount*self->scale);
 if(self->flags&0x4000000){int total=step;if(self->flags&0x2000000)total+=self->remainder;int quantized=(total/self->quantum)*self->quantum;
 if(quantized<self->quantum){self->remainder=0;step=self->quantum;}else{step=quantized;self->remainder=total-step;}}
 if(!(self->flags&0x40000000)){
  G4aTimingTarget*target=self->target;
  target->bits.next=(self->flags>>29)&1;
  target->bits.top=(self->flags>>28)&1;
  ((void(*)(G4aTimingTarget*,int))self->target->vt[10])(self->target,step);
 }else if(self->flags&0x8000000)((void(*)(G4aTimingTarget*))self->target->vt[11])(self->target);
 if(self->flags&0x10000000){
  G4aTimestamp start;
  ((void(*)(G4aTimingOwner*,int))self->vt[17])(self,step);
  self->elapsed=ticks_801fe508(start.delta());
  ((void(*)(G4aTimingOwner*))self->vt[14])(self);
  if(self->state&0x40000000){toggle_8015ba30(self,(self->state>>31)^1);self->state&=~0x40000000u;}
 }
}
