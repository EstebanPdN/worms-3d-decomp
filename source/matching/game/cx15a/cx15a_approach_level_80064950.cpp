// Inferred actions. PPC32 field byte offsets are observed in original instructions.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
inline void release(void*p){if(p)VCALL(p,void(*)(void*),16)(p);}

extern "C" float value_80178df0(void*);extern "C" int refresh_800642ac(void*);extern const float epsilon_80379db8[],zero_80379dbc[];
extern "C" int w3d_cx15a_approach_level_80064950(void*self){int done=0;float delta=FIELD(self,float,44)-FIELD(self,float,40);float step=value_80178df0(FIELD(self,void*,140));float result;if(__builtin_fabsf(delta)<epsilon_80379db8[0]||delta<zero_80379dbc[0]||step>delta){result=FIELD(self,float,40);done=1;}else result=FIELD(self,float,44)-step;FIELD(self,float,44)=result;refresh_800642ac(self);return done;}
