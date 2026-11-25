// Partial layout and state roles inferred from original instructions.
struct Owner {char pad[140];int active;char pad90[32];int mode;char padb4[52];void *first[3],*second[3];char pad100[120];void *third;};
extern "C" void fn_802b2344(void*,int);
extern "C" void *fn_802eefe0(void*,...);
extern "C" void fn_8025f064(void*,int),fn_8029459c(void*,int),fn_8029677c(void*,int);
struct States {int values[3];States(){fn_802eefe0(this,0,12);}int &operator[](unsigned i){return values[i];}};
extern "C" void w3d_refresh_toggle_states_802a0ebc(Owner*self,int selected){
 fn_802b2344((char*)self+28,selected);
 States states;
 if(self->mode)states.values[1]=1;else if(!selected)states.values[2]=1;else states.values[0]=1;
 for(unsigned i=0;i<3;++i){if(self->first[i])fn_8025f064(self->first[i],states[i]);if(self->second[i])fn_8029459c(self->second[i],states[i]);}
 if(self->third)fn_8029677c(self->third,self->active);
}
