#include "w3d_ptr.h"
#line 1 "cx16a_initialize_named_actor_8004971c.cpp"
// Observed actor initialization phases. Semantic member names remain inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern "C" Ptr32<void> handle_80126184(Ptr32<void>);
// Observed actor initialization phases. Semantic member names remain inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern "C" Ptr32<void> string_803426b8(Ptr32<void>);
// Observed actor initialization phases. Semantic member names remain inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char*)w3d::AG(p)+(o)))
extern "C" int base_80161014(Ptr32<void>);
extern int vtable_8040e9b8[];
extern const float value_80376e30[],value_80376e34[],value_80376e38[];
static inline Ptr32<void> cx16a_initialize(Ptr32<void> self,int zero){
 base_80161014(self);FIELD(self,void*,0)=vtable_8040e9b8;string_803426b8((Ptr32<char>)self+148);
FIELD(self,int,176)=zero;FIELD(self,int,180)=zero;FIELD(self,int,184)=zero;FIELD(self,int,196)=zero;FIELD(self,int,200)=zero;FIELD(self,int,204)=zero;FIELD(self,int,208)=zero;FIELD(self,int,212)=zero;FIELD(self,int,216)=zero;FIELD(self,int,220)=zero;FIELD(self,int,224)=zero;FIELD(self,int,228)=zero;FIELD(self,int,232)=zero;handle_80126184((Ptr32<char>)self+236);Ptr32<const float> pa=value_80376e30;float b=value_80376e34[0];float a=*pa;float c=value_80376e38[0];FIELD(self,float,152)=a;FIELD(self,int,100)=zero;FIELD(self,int,104)=zero;FIELD(self,int,188)=zero;FIELD(self,int,192)=zero;FIELD(self,int,144)=zero;FIELD(self,int,248)=zero;FIELD(self,int,244)=zero;FIELD(self,int,132)=zero;FIELD(self,int,160)=zero;FIELD(self,int,156)=zero;FIELD(self,int,164)=1;FIELD(self,int,252)=1;FIELD(self,int,256)=1;FIELD(self,float,272)=b;FIELD(self,float,276)=b;FIELD(self,float,168)=c;FIELD(self,int,172)=zero;return self;}
extern "C" Ptr32<void> w3d_cx16a_initialize_named_actor_8004971c(Ptr32<void> self){return cx16a_initialize(self,0);}


