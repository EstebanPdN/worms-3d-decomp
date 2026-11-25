// Inferred actions. PPC32 field byte offsets are observed in original instructions.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
inline void release(void*p){if(p)VCALL(p,void(*)(void*),16)(p);}

extern "C" void*cast_80341584(void*),*parameters_801797b4(void*);extern "C" int find_80181598(void*,void*,void*);extern "C" float length_80181d30(void*,void*);extern const float zero_8037ca04[];
extern "C" void w3d_cx16a_cache_clips_80070678(void*self){void*p=parameters_801797b4(cast_80341584(FIELD(self,void*,28)));find_80181598(FIELD(self,void*,32),FIELD(p,void*,604),(char*)self+236);find_80181598(FIELD(self,void*,32),FIELD(p,void*,600),(char*)self+232);FIELD(self,float,224)=length_80181d30(FIELD(self,void*,32),FIELD(p,void*,604));float length=length_80181d30(FIELD(self,void*,32),FIELD(p,void*,600));float zero=zero_8037ca04[0];FIELD(self,float,220)=zero;FIELD(self,float,228)=length;FIELD(self,float,216)=zero;FIELD(self,int,240)=0;}
