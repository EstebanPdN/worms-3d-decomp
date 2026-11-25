#include "w3d_ptr.h"
#line 1 "cx15a_score_splash_80011a70.cpp"
// Names are inferred. PPC32 byte offsets are observed in the original DOL.
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
#define VCALL(p,T,o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p)+(o))))

 extern "C" Ptr32<void> lookup_80341694(Ptr32<void>,int);extern "C" float damage_800105cc(Ptr32<void>),radius_80010608(Ptr32<void>);extern "C" void score_80011950(Ptr32<void>,float,float);
 extern "C" void w3d_cx15a_score_splash_80011a70(Ptr32<void> self){Ptr32<void> a=lookup_80341694(self,0);FIELD(self,int,20)=36;Ptr32<void> b=lookup_80341694(self,0);FIELD(self,int,20)=2;float damage=damage_800105cc(self);damage=(float)FIELD(a,unsigned,256)*FIELD(b,float,200)+damage;score_80011950(self,damage,radius_80010608(self));}
 

