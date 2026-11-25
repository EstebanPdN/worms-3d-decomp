// Names are inferred. PPC32 byte offsets are observed in the original DOL.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))

extern "C" int active_804aa5a0;extern "C" void*parameters_804aa6d8;extern unsigned position_8041d3a0[];
extern "C" int probe_80009674(void**,void*,void*,int,float);
extern "C" bool w3d_cx15a_probe_actor_80017c38(void*self){if(active_804aa5a0)return true;void*held[2];held[0]=(void*)active_804aa5a0;int result=probe_80009674(held,position_8041d3a0,(char*)self+16,-1,FIELD(parameters_804aa6d8,float,188));if(held[0])((void(*)(void*,int))(*(void**)(FIELD(held[0],char*,16)+8)))(held[0],3);held[0]=0;return result==0;}
