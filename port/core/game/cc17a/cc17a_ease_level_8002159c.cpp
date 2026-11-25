#include "w3d_ptr.h"
#line 1 "cc17a_ease_level_8002159c.cpp"
// Inferred names; PPC32 field offsets and vector component positions are observed.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
struct Cc17aVec3 {float x,y,z;Cc17aVec3(){} Cc17aVec3(float a,float b,float c){x=a;y=b;z=c;} Cc17aVec3(const Cc17aVec3&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;}};

extern "C" Ptr32<void> cast_803426b4(Ptr32<void>); Ptr32<void> cast_80342a74(Ptr32<void>); Ptr32<void> index_800fc6dc(int); Ptr32<void> handle_800fc710(int,Ptr32<void>);extern "C" int integer_80178c48(Ptr32<void>);extern "C" float value_80178df0(Ptr32<void>);extern "C" void destroy_80178474(Ptr32<void>,int);extern const float factor_8036c03c[],epsilon_8036c040[];
extern "C" void w3d_cc17a_ease_level_8002159c(Ptr32<void> self){int id=integer_80178c48(cast_803426b4(FIELD(self,void*,24)));float previous=FIELD(index_800fc6dc(id),float,116);value_80178df0(cast_80342a74(FIELD(self,void*,20)));struct Cc17aHandle {unsigned words[2];char reserved[8];} h;Ptr32<unsigned int> slot=h.words;slot[0]=0;slot[1]=0xe3a8;Ptr32<void> target=handle_800fc710(id,slot);float result=(previous-FIELD(self,float,28))*factor_8036c03c[0]+FIELD(self,float,28);float epsilon=epsilon_8036c040[0];FIELD(target,float,116)=result;if(__builtin_fabsf(result-FIELD(self,float,28))<epsilon)FIELD(self,int,4)=1;destroy_80178474(slot,2);}


