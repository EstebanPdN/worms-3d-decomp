#include "w3d_ptr.h"
#line 1 "f10a_refresh_controls_8027014c.cpp"
// Partial object layout, state and colour meanings inferred from the original.
struct F10aControls_8027014c {char pad[140];int active;char p90[32];int mode;char pb4[28];Ptr32<Ptr32<void>> table;char pd4[12];Ptr32<void> first[3]; Ptr32<void> second[3];char p100[40];Ptr32<void> third; Ptr32<void> fourth;};
struct F10aColor_8027014c {unsigned char r,g,b; signed char a; F10aColor_8027014c(unsigned char v):r(v),g(v),b(v),a(-1){}};
extern "C" Ptr32<void> fn_802eefe0(Ptr32<void>,...);
struct F10aStates_8027014c {int values[3];F10aStates_8027014c(){fn_802eefe0(this,0,12);}int &operator[](unsigned i){return values[i];}};
extern "C" void fn_8025f064(Ptr32<void>,int),fn_8029459c(Ptr32<void>,int),fn_802bcd18(Ptr32<void>,int),fn_8029677c(Ptr32<void>,int);
extern "C" void fn_8025eed0(Ptr32<void>,Ptr32<const F10aColor_8027014c>),fn_80294408(Ptr32<void>,Ptr32<const F10aColor_8027014c>);
extern "C" void w3d_f10a_refresh_controls_8027014c(Ptr32<F10aControls_8027014c> self){
 unsigned char v=255;if(!self->active)v=128;
 F10aColor_8027014c color(v);F10aStates_8027014c states;
 if(self->mode)states.values[1]=1;else if(!self->active)states.values[2]=1;else states.values[0]=1;
 for(unsigned i=0;i<3;++i){if(self->first[i])fn_8025f064(self->first[i],states[i]);if(self->second[i])fn_8029459c(self->second[i],states[i]);}
 for(unsigned i=0;i<2;++i){if(self->first[i])fn_8025eed0(self->first[i],&color);if(self->second[i])fn_80294408(self->second[i],&color);}
 if(self->third)fn_802bcd18(self->third,self->active);
 if(!self->active)((Ptr32<void (Ptr32<void>, int)>)self->table[13])((Ptr32<char>)self+28,0);
 if(self->fourth)fn_8029677c(self->fourth,self->active);
}


