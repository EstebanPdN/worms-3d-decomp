#include "w3d_ptr.h"
#line 1 "cc33a_hud_remaining_totals_800663a8.cpp"
// Observed player/team fields; unknown regions do not claim complete class layout.
struct cc33a_Player_800663a8 { unsigned char unknown0[164]; int spent; unsigned short unknown168; unsigned short total; unsigned char unknown172[41]; unsigned char team; unsigned char unknown214[6]; int active; };
struct cc33a_Team_800663a8 { unsigned char unknown[44]; int disabled; };
struct cc33a_Hud_800663a8 { unsigned char unknown[28]; Ptr32<void> handles[4]; };
extern "C" {
Ptr32<cc33a_Player_800663a8> cc33a_player_800fc6dc(unsigned int);
Ptr32<cc33a_Team_800663a8> cc33a_team_800fc7f8(unsigned int);
Ptr32<void> cc33a_object_80164fc8(Ptr32<void>);
void cc33a_set_8006456c(Ptr32<void>,int);
void cc33a_hud_remaining_totals_800663a8(Ptr32<cc33a_Hud_800663a8> self) {
 int totals[4];
 for(unsigned int i=0;i<4;++i)totals[i]=0;
 for(unsigned int i=0;i<16;++i) {
  Ptr32<cc33a_Player_800663a8> p=cc33a_player_800fc6dc(i);
  if(p->active){int spent=p->spent;int total=p->total;unsigned int team=p->team;if(spent<total)totals[team]+=total-spent;}
 }
 for(unsigned int i=0;i<4;++i) { if(cc33a_team_800fc7f8(i)->disabled)totals[i]=0; }
 int maximum=0;
 for(int* p=totals,count=4;count;--count) { int current=*p++;if(current>maximum)maximum=current; }
 for(unsigned int i=0;i<4;++i) cc33a_set_8006456c(cc33a_object_80164fc8(self->handles[i]),totals[i]);
}
}


