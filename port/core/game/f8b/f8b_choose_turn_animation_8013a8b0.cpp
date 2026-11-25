#include "w3d_ptr.h"
#line 1 "f8b_choose_turn_animation_8013a8b0.cpp"
// Inferred turning animation decision using observed state/thresholds.
struct F8TurnOwner{char p[612];int mode;float blend,speed;char p2[60];int state;};
extern const float zero_8039f77c[],rate_8039f780[],left_8039f784[],right_8039f788[];extern Ptr32<const char> idle_804ab1ac; extern Ptr32<const char> turnLeft_804ab19c; extern Ptr32<const char> turnRight_804ab1a0; extern Ptr32<const char> walkLeft_804ab1a4; extern Ptr32<const char> walkRight_804ab1a8;
extern "C" int playing_80181ccc(Ptr32<void>,int);extern "C" int play_801359ec(Ptr32<F8TurnOwner>,Ptr32<void>,Ptr32<const char>,Ptr32<int>,float,float,float);
extern "C" void f8b_choose_turn_animation_8013a8b0(Ptr32<F8TurnOwner> s,Ptr32<void> mesh,Ptr32<int> animation){if(s->state==41)return;if(*animation!=-1&&!playing_80181ccc(mesh,*animation))return;if(s->blend==zero_8039f77c[0]&&s->mode!=0)play_801359ec(s,mesh,idle_804ab1ac,animation,rate_8039f780[0],zero_8039f77c[0],zero_8039f77c[0]);else switch(s->mode){case 1:{if(s->speed<left_8039f784[0])play_801359ec(s,mesh,turnLeft_804ab19c,animation,rate_8039f780[0],zero_8039f77c[0],zero_8039f77c[0]);else play_801359ec(s,mesh,walkLeft_804ab1a4,animation,rate_8039f780[0],zero_8039f77c[0],zero_8039f77c[0]);break;}case 2:{if(s->speed>right_8039f788[0])play_801359ec(s,mesh,turnRight_804ab1a0,animation,rate_8039f780[0],zero_8039f77c[0],zero_8039f77c[0]);else play_801359ec(s,mesh,walkRight_804ab1a8,animation,rate_8039f780[0],zero_8039f77c[0],zero_8039f77c[0]);break;}}}


