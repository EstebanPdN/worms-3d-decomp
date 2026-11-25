#include "w3d_ptr.h"
#line 1 "cx12a_accumulate_limit_800ac03c.cpp"
// PPC32 byte offsets, four-byte pointer slots and three-float vectors are observed. Semantic names inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
inline const float &cx12a_max(const float &a,const float &b){return a<b?b:a;}
inline const float &cx12a_min(const float &a,const float &b){return b<a?b:a;}
extern "C" float read_80178df0(Ptr32<void>);extern const float one_80381c44[];
extern "C" void w3d_cx12a_accumulate_limit_800ac03c(Ptr32<void> self){
 float delta=(one_80381c44[0]-FIELD(self,float,0x68))*read_80178df0(FIELD(self,void *,0xd0));
 delta=cx12a_min(delta,read_80178df0(FIELD(self,void *,0xec)));
 FIELD(self,float,0xa0)=delta*read_80178df0(FIELD(self,void *,0xd4))+FIELD(self,float,0xa0);
 FIELD(self,float,0xa0)=cx12a_min(FIELD(self,float,0xa0),read_80178df0(FIELD(self,void *,0xec)));
}


