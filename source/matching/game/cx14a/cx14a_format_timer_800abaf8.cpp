// PPC32 offsets and interface slots are observed; descriptive names are inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))

extern "C" int remaining_800ac0f4(void *),format_802ec254(char *,const char *,...);extern "C" void *context_80165254();extern const char format_80381c1c[];
extern "C" void w3d_cx14a_format_timer_800abaf8(void *self){char text[8];unsigned ticks;if(!FIELD(self,int,72))ticks=(remaining_800ac0f4(self)+250)/500;else {int remain=remaining_800ac0f4(self);void *context=context_80165254();ticks=(remain-(FIELD(context,int,52)-FIELD(self,int,112))+250U)/500;}format_802ec254(text,format_80381c1c,ticks);void *view=FIELD(self,void *,120);VCALL(view,void (*)(void *,const char *),44)(view,text);}
