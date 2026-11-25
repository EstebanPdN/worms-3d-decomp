#include "w3d_ptr.h"
#line 1 "cx15a_probe_actor_80017c38.cpp"
// Names are inferred. PPC32 byte offsets are observed in the original DOL.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))

extern "C" int active_804aa5a0;extern "C" Ptr32<void> parameters_804aa6d8;extern unsigned position_8041d3a0[];
extern "C" int probe_80009674(Ptr32<Ptr32<void>>,Ptr32<void>,Ptr32<void>,int,float);
extern "C" bool w3d_cx15a_probe_actor_80017c38(Ptr32<void> self){if(active_804aa5a0)return true;Ptr32<void> held[2];held[0]=(Ptr32<void>)w3d::G(active_804aa5a0);int result=probe_80009674(held,position_8041d3a0,(Ptr32<char>)self+16,-1,FIELD(parameters_804aa6d8,float,188));if(held[0])((Ptr32<void (Ptr32<void>, int)>)(*(Ptr32<Ptr32<void>>)(FIELD(held[0],char*,16)+8)))(held[0],3);held[0]=0;return result==0;}


