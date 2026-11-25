#include "w3d_ptr.h"
#line 1 "cx16a_cache_clips_80070678.cpp"
// Inferred actions. PPC32 field byte offsets are observed in original instructions.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
inline void release(Ptr32<void> p){if(p)VCALL(p,void(*)(void*),16)(p);}

extern "C" Ptr32<void> cast_80341584(Ptr32<void>); Ptr32<void> parameters_801797b4(Ptr32<void>);extern "C" int find_80181598(Ptr32<void>,Ptr32<void>,Ptr32<void>);extern "C" float length_80181d30(Ptr32<void>,Ptr32<void>);extern const float zero_8037ca04[];
extern "C" void w3d_cx16a_cache_clips_80070678(Ptr32<void> self){Ptr32<void> p=parameters_801797b4(cast_80341584(FIELD(self,void*,28)));find_80181598(FIELD(self,void*,32),FIELD(p,void*,604),(Ptr32<char>)self+236);find_80181598(FIELD(self,void*,32),FIELD(p,void*,600),(Ptr32<char>)self+232);FIELD(self,float,224)=length_80181d30(FIELD(self,void*,32),FIELD(p,void*,604));float length=length_80181d30(FIELD(self,void*,32),FIELD(p,void*,600));float zero=zero_8037ca04[0];FIELD(self,float,220)=zero;FIELD(self,float,228)=length;FIELD(self,float,216)=zero;FIELD(self,int,240)=0;}


