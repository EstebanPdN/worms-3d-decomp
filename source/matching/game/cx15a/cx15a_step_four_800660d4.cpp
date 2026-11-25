// Inferred actions. PPC32 field byte offsets are observed in original instructions.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
inline void release(void*p){if(p)VCALL(p,void(*)(void*),16)(p);}

extern "C" void*resolve_80164fc8(void*);extern "C" int step_80064950(void*);extern "C" float value_80178df0(void*);extern "C" void rate_80064548(void*,float),finish_800661c4(void*);extern const float zero_80379e8c[];
extern "C" int w3d_cx15a_step_four_800660d4(void*self){void**begin=(void**)((char*)self+28);float maximum=zero_80379e8c[0];int done=1;void**p=begin;int left=4;do{void*entry=resolve_80164fc8(*p++);if(!step_80064950(entry))done=0;if(FIELD(entry,float,44)>maximum)maximum=FIELD(entry,float,44);}while(--left);value_80178df0(FIELD(self,void*,88));if(maximum>FIELD(self,float,124)){float rate=value_80178df0(FIELD(self,void*,88))/maximum;FIELD(self,float,124)=maximum;void**p=begin;void**end=p+3;do{rate_80064548(resolve_80164fc8(*p++),rate);}while((int)p<=(int)end);}if(done)finish_800661c4(self);return done;}
