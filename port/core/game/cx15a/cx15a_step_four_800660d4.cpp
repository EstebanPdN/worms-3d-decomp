#include "w3d_ptr.h"
#line 1 "cx15a_step_four_800660d4.cpp"
// Inferred actions. PPC32 field byte offsets are observed in original instructions.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
inline void release(Ptr32<void> p){if(p)VCALL(p,void(*)(void*),16)(p);}

extern "C" Ptr32<void> resolve_80164fc8(Ptr32<void>);extern "C" int step_80064950(Ptr32<void>);extern "C" float value_80178df0(Ptr32<void>);extern "C" void rate_80064548(Ptr32<void>,float),finish_800661c4(Ptr32<void>);extern const float zero_80379e8c[];
extern "C" int w3d_cx15a_step_four_800660d4(Ptr32<void> self){Ptr32<Ptr32<void>> begin=(Ptr32<Ptr32<void>>)((Ptr32<char>)self+28);float maximum=zero_80379e8c[0];int done=1;Ptr32<Ptr32<void>> p=begin;int left=4;do{Ptr32<void> entry=resolve_80164fc8(*p++);if(!step_80064950(entry))done=0;if(FIELD(entry,float,44)>maximum)maximum=FIELD(entry,float,44);}while(--left);value_80178df0(FIELD(self,void*,88));if(maximum>FIELD(self,float,124)){float rate=value_80178df0(FIELD(self,void*,88))/maximum;FIELD(self,float,124)=maximum;Ptr32<Ptr32<void>> p=begin;Ptr32<Ptr32<void>> end=p+3;do{rate_80064548(resolve_80164fc8(*p++),rate);}while((int)w3d::H(p)<=(int)w3d::H(end));}if(done)finish_800661c4(self);return done;}


