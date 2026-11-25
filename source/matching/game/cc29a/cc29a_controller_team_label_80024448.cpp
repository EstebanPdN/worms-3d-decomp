// Original player-validity gate and team-property label update.
struct cc29a_Controller_80024448 {unsigned char unknown[32];void*label;unsigned char unknown36[100];unsigned player;};
struct cc29a_Player_80024448 {unsigned char unknown[213];unsigned char team;};
extern "C" {void cc29a_enable_800243a8(void*,int);cc29a_Player_80024448*cc29a_player_800fc6dc(unsigned);void*cc29a_label_8034357c(void*);void * cc29a_team_800fd3e4(void*,unsigned,...);int cc29a_set_80173df0(void*,void*);void cc29a_refresh_800248f8(void*);}
extern "C" void cc29a_controller_team_label_80024448(cc29a_Controller_80024448*self){
 if(self->player>15)cc29a_enable_800243a8(self,0);
 else {cc29a_enable_800243a8(self,1);unsigned char team=cc29a_player_800fc6dc(self->player)->team;void*label=cc29a_label_8034357c(self->label);unsigned property[2];cc29a_team_800fd3e4(property,team);cc29a_set_80173df0(label,property);cc29a_refresh_800248f8(self);}
}
