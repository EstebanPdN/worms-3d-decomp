#include "w3d_ptr.h"
#line 1 "cx14a_unfreeze_animation_8013dcb8.cpp"
// PPC32 offsets and interface slots are observed; descriptive names are inferred.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))

extern "C" Ptr32<void> resolve_80164fc8(unsigned);extern "C" void release_800a4cd0(Ptr32<void>);
extern "C" int play_801359ec(Ptr32<void>,unsigned,Ptr32<const char>,Ptr32<void>,float,float,float);
extern Ptr32<const char> name_804ab1e0; extern Ptr32<const char> name_804ab1e4; extern Ptr32<const char> name_804ab1e8;extern const float rate_8039fb68[],zero_8039fb6c[];
extern "C" void w3d_cx14a_unfreeze_animation_8013dcb8(Ptr32<void> self,unsigned flags){Ptr32<void> object=resolve_80164fc8(FIELD(self,unsigned,152));if(!object){FIELD(self,unsigned,152)=~0U;return;}release_800a4cd0(object);FIELD(self,unsigned,152)=~0U;switch(FIELD(self,int,160)){case 0:play_801359ec(self,flags,name_804ab1e0,(Ptr32<char>)self+472,rate_8039fb68[0],zero_8039fb6c[0],zero_8039fb6c[0]);break;case 1:play_801359ec(self,flags,name_804ab1e4,(Ptr32<char>)self+472,rate_8039fb68[0],zero_8039fb6c[0],zero_8039fb6c[0]);break;case 2:play_801359ec(self,flags,name_804ab1e8,(Ptr32<char>)self+472,rate_8039fb68[0],zero_8039fb6c[0],zero_8039fb6c[0]);break;}}


