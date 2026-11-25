#include "w3d_ptr.h"
#line 1 "cx13a_initialize_screen_800c8574.cpp"
// PPC32 field and pointer offsets are observed; all action names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))
extern "C" Ptr32<void> base_8015fef0(Ptr32<void>);extern unsigned char vtable_8040fb38[];extern const float initial_80387af4[];
extern "C" Ptr32<void> w3d_cx13a_initialize_screen_800c8574(Ptr32<void> self){
 base_8015fef0(self);FIELD(self,unsigned,28)=0;FIELD(self,void *,0)=vtable_8040fb38;FIELD(self,unsigned,32)=0;FIELD(self,unsigned,36)=0;FIELD(self,unsigned,40)=0;
 Ptr32<unsigned int> slot=(Ptr32<unsigned int>)((Ptr32<char>)self+44);int count=1;do{*slot++=0;}while(count--!=0);FIELD(self,unsigned,52)=0;slot=(Ptr32<unsigned int>)((Ptr32<char>)self+60);count=4;do{*slot++=0;}while(--count);count=21;do{}while(--count);FIELD(self,unsigned,352)=0;FIELD(self,float,360)=initial_80387af4[0];FIELD(self,unsigned,356)=0;FIELD(self,unsigned,372)=0;FIELD(self,unsigned,380)=0;return self;
}


