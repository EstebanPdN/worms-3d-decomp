// Names are inferred. PPC32 byte offsets are observed in the original DOL.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))

 extern "C" void*lookup_80341694(void*,int);extern "C" float damage_800105cc(void*),radius_80010608(void*);extern "C" void score_80011950(void*,float,float);
 extern "C" void w3d_cx15a_score_splash_80011a70(void*self){void*a=lookup_80341694(self,0);FIELD(self,int,20)=36;void*b=lookup_80341694(self,0);FIELD(self,int,20)=2;float damage=damage_800105cc(self);damage=(float)FIELD(a,unsigned,256)*FIELD(b,float,200)+damage;score_80011950(self,damage,radius_80010608(self));}
 