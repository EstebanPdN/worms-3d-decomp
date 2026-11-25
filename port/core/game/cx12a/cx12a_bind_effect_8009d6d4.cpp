#include "w3d_ptr.h"
#line 1 "cx12a_bind_effect_8009d6d4.cpp"
// PPC32 layout: all offsets below are observed; action and field names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern Ptr32<void> context_804b1788;
extern "C" unsigned launch_800e5ca4(Ptr32<void>,Ptr32<const char>,int,float);
extern "C" void w3d_cx12a_bind_effect_8009d6d4(Ptr32<void> self,Ptr32<void> params,Ptr32<void> position){
 Ptr32<const char> name=FIELD(params,const char *,0x118);
 if(FIELD(name,unsigned short,-4)!=0&&FIELD(self,int,0x6c)!=1)FIELD(self,unsigned,0x78)=launch_800e5ca4(position,name,0,FIELD(params,float,0xf4));
 Ptr32<const char> other=FIELD(params,const char *,0x108);
 if(FIELD(other,unsigned short,-4)!=0&&FIELD(context_804b1788,void *,0x6c)){
 if(FIELD(self,void *,0x44)){VCALL(FIELD(self,void *,0x44),void (*)(void *),0x18)(FIELD(self,void *,0x44));if(FIELD(self,void *,0x44))VCALL(FIELD(self,void *,0x44),void (*)(void *),0x10)(FIELD(self,void *,0x44));FIELD(self,void *,0x44)=0;}
 Ptr32<void> svc=FIELD(context_804b1788,void *,0x6c);VCALL(svc,int (*)(void *,const char *,void **),0x5c)(svc,FIELD(params,const char *,0x108),&FIELD(self,void *,0x44));
 Ptr32<void> effect=FIELD(self,void *,0x44);VCALL(effect,int (*)(void *,int,void *),0x38)(effect,3,position);
 effect=FIELD(self,void *,0x44);VCALL(effect,void (*)(void *),0x14)(effect);
 }
}


