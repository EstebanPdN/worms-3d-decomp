// Partial memory-card state and command roles inferred from original offsets.
struct State{int unknown,state;int result;int pad12,pad16,command;char pad24[28];char card[4];};
extern "C" int fn_802ada18(void*,int);
extern "C" void fn_802fb82c(const char*,int,const char*,...);
extern const char file_803d6c64[],error_803d6ca0[];
extern "C" void w3d_check_card_802abd94(State*self){if(self->command==2)self->result=fn_802ada18(self->card,0);else self->result=fn_802ada18(self->card,1);int result=self->result;switch(result){case 1:switch(self->command){case 1:self->state=result;break;case 3:self->state=163;break;case 2:self->state=164;break;default:fn_802fb82c(file_803d6c64,399,error_803d6ca0);break;}break;case 3:switch(self->command){case 1:self->state=result;break;case 2:self->state=result;break;case 3:self->state=163;break;default:fn_802fb82c(file_803d6c64,422,error_803d6ca0);break;}break;case 4:self->state=result;break;case 0:self->state=161;break;case 2:self->state=2;break;case -1:self->state=162;break;}}
