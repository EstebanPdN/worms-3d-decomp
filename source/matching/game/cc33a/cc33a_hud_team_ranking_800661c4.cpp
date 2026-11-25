// Team HUD ranking inferred from the original total, disabled-team and XOR-sort loops.
struct cc33a_Player_800661c4 {unsigned char unknown0[170];unsigned short total;unsigned char unknown172[41];unsigned char team;unsigned char unknown214[6];int active;};
struct cc33a_Team_800661c4 {unsigned char unknown[44];int disabled;};
struct cc33a_Hud_800661c4 {unsigned char unknown[28];void* handles[4];};
extern "C" {
cc33a_Player_800661c4* cc33a_player_800fc6dc(unsigned int);
cc33a_Team_800661c4* cc33a_team_800fc7f8(unsigned int);
void* cc33a_object_80164fc8(void*);
void cc33a_set_80064190(void*,int);
void cc33a_hud_team_ranking_800661c4(cc33a_Hud_800661c4* self) {
 int totals[4]; unsigned int order[4];unsigned int i;
 for(i=0;i<4;++i)totals[i]=0;
 for(i=0;i<16;++i){cc33a_Player_800661c4* player=cc33a_player_800fc6dc(i);if(player->active)totals[player->team]+=player->total;}
 for(i=0;i<4;++i){if(cc33a_team_800fc7f8(i)->disabled)totals[i]=0;}
 int maximum=0,positive=0;
 for(int* p=totals,count=4;count;--count){int v=*p++;if(v>maximum)maximum=v;if(v>0)++positive;}
 int missing=4-positive;
 for(i=0;i<4;++i)order[i]=i;
 bool sorted;
 do{sorted=true;for(i=0;i<3;++i){if(totals[order[i]]<totals[order[i+1]]){order[i]^=order[i+1];sorted=false;order[i+1]=order[i]^order[i+1];order[i]^=order[i+1];}}}while(!sorted);
 for(i=0;i<4;++i){void* object=cc33a_object_80164fc8(self->handles[i]);for(unsigned int rank=0;rank<4;++rank){if(order[rank]==i)cc33a_set_80064190(object,rank+missing);}}
}
}
