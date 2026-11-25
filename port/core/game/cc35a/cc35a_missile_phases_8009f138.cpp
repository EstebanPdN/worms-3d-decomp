#include "w3d_ptr.h"
#line 1 "cc35a_missile_phases_8009f138.cpp"

struct cc35a_Vector_8009f138 {float x,y,z; cc35a_Vector_8009f138(float value){ x=value;y=value;z=value; }};
struct cc35a_Missile_8009f138 {char p0[28];int start;char p1[4];cc35a_Vector_8009f138 position,direction;char p2[28];int armed;char p3[24];int enabled;char p4[72];Ptr32<void> context;char p5[140];unsigned int phase;};
struct cc35a_Timing_8009f138 {char prefix[568];int finalDelay,activeDelay,armDelay;};
struct cc35a_Service_8009f138 {char prefix[108];Ptr32<void> sound;};
extern "C" {Ptr32<void> cc35a_context_80341584(Ptr32<void>);Ptr32<cc35a_Timing_8009f138> cc35a_timing_801797b4(Ptr32<void>);
extern Ptr32<cc35a_Service_8009f138> cc35a_service_804b1788;extern const char cc35a_sound_803806e0[];extern float cc35a_zero_803806f4[];
void cc35a_finish_800ec6a8(Ptr32<void>,Ptr32<cc35a_Vector_8009f138>,Ptr32<cc35a_Vector_8009f138>,Ptr32<cc35a_Vector_8009f138>);
}
extern "C" void cc35a_missile_phases_8009f138(Ptr32<cc35a_Missile_8009f138> self,int now) {Ptr32<cc35a_Timing_8009f138> t=cc35a_timing_801797b4((Ptr32<void>)cc35a_context_80341584(self->context));
 int elapsed=now-self->start;int armDelay=t->armDelay;int activeDelay=t->activeDelay;int finalDelay=t->finalDelay;
 switch(self->phase){
 case 1: if(elapsed>armDelay && self->armed){Ptr32<void> sound=cc35a_service_804b1788->sound;((Ptr32<void (Ptr32<void>, Ptr32<const char>, Ptr32<cc35a_Vector_8009f138>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)sound)[24])(sound,cc35a_sound_803806e0,&self->position);self->phase=2;self->enabled=0;}break;
 case 2:if(elapsed>armDelay+activeDelay){self->phase=3;self->enabled=1;}break;
 case 3:if(elapsed>armDelay+activeDelay+finalDelay){cc35a_Vector_8009f138 zero(cc35a_zero_803806f4[0]);cc35a_finish_800ec6a8(self,&self->position,&self->direction,&zero);}break;
 }
}


