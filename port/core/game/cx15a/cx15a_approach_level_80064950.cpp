#include "w3d_ptr.h"
#line 1 "cx15a_approach_level_80064950.cpp"
// Inferred actions. PPC32 field byte offsets are observed in original instructions.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
inline void release(Ptr32<void> p){if(p)VCALL(p,void(*)(void*),16)(p);}

extern "C" float value_80178df0(Ptr32<void>);extern "C" int refresh_800642ac(Ptr32<void>);extern const float epsilon_80379db8[],zero_80379dbc[];
extern "C" int w3d_cx15a_approach_level_80064950(Ptr32<void> self){int done=0;float delta=FIELD(self,float,44)-FIELD(self,float,40);float step=value_80178df0(FIELD(self,void*,140));float result;if(__builtin_fabsf(delta)<epsilon_80379db8[0]||delta<zero_80379dbc[0]||step>delta){result=FIELD(self,float,40);done=1;}else result=FIELD(self,float,44)-step;FIELD(self,float,44)=result;refresh_800642ac(self);return done;}


