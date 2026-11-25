// GWMP8P rev0. Native receiver/context/output views are partial, never allocated here.
// Timestamp and top-bit channel flags are observed; rumble roles are inferred.
// The disable helper receives the tested flag word in r3, although its body ignores it.
struct F15cRumble {char unknown0[40];int timestamp;char unknown44[48];unsigned flags;};
struct F15cRumbleContext {char unknown0[240];unsigned flags;};
struct F15cRumbleOutput {void **vtable;};
extern F15cRumbleContext *context_804aaabc;
extern void *runtime_804b1788,*service_804b17f0;
extern const char option_80398148[];
extern "C" {
int property_800fc230(const char**,int*);
int paused_8015ccbc(void*);
F15cRumbleOutput *output_80160e34(void*,int);
void update_800fdfec(F15cRumble*,int,int);
void stop_800fde38(unsigned);
int f15c_rumble_update_800fdb00(F15cRumble*self,int now){
 const char *name=option_80398148; int enabled=1;
 property_800fc230(&name,&enabled);
 if(context_804aaabc->flags&0x200000)enabled=0;
 if(enabled){
  int previous=self->timestamp;self->timestamp=now;now-=previous;
  if(!paused_8015ccbc(runtime_804b1788)){
   if(self->flags&0x40000000)update_800fdfec(self,1,now);
   if((int)self->flags<0)update_800fdfec(self,0,now);
  }
  if(paused_8015ccbc(runtime_804b1788)||(!(self->flags&0x40000000)&&(int)self->flags>=0)){
   F15cRumbleOutput *out=output_80160e34(service_804b17f0,0);
   if(out)((void(*)(F15cRumbleOutput*,int,int))out->vtable[18])(out,0,0);
  }
 }else{
  unsigned flags=self->flags;
  if((flags&0x40000000)||(int)flags<0)stop_800fde38(flags);
 }
 return 0;
}
}
