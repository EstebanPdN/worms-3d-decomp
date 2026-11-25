// Inferred names; PPC32 field offsets and vector component positions are observed.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
struct Cc17aVec3 {float x,y,z;Cc17aVec3(){} Cc17aVec3(float a,float b,float c){x=a;y=b;z=c;} Cc17aVec3(const Cc17aVec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}};

extern "C" void*cast_803426b4(void*),*cast_80342a74(void*),*index_800fc6dc(int),*handle_800fc710(int,void*);extern "C" int integer_80178c48(void*);extern "C" float value_80178df0(void*);extern "C" void destroy_80178474(void*,int);extern const float factor_8036c03c[],epsilon_8036c040[];
extern "C" void w3d_cc17a_ease_level_8002159c(void*self){int id=integer_80178c48(cast_803426b4(FIELD(self,void*,24)));float previous=FIELD(index_800fc6dc(id),float,116);value_80178df0(cast_80342a74(FIELD(self,void*,20)));struct Cc17aHandle {unsigned words[2];char reserved[8];} h;unsigned *slot=h.words;slot[0]=0;slot[1]=0xe3a8;void*target=handle_800fc710(id,slot);float result=(previous-FIELD(self,float,28))*factor_8036c03c[0]+FIELD(self,float,28);float epsilon=epsilon_8036c040[0];FIELD(target,float,116)=result;if(__builtin_fabsf(result-FIELD(self,float,28))<epsilon)FIELD(self,int,4)=1;destroy_80178474(slot,2);}
