#include "w3d_ptr.h"
#line 1 "g1p_card_read_tick_802abffc.cpp"
// Partial external card read state, never locally constructed.
struct ReadState{char unknown0[12];int state;char unknown16[132];int start;};
extern "C" void fn_802ac814(int);
extern "C" void fn_802ac1e4(Ptr32<ReadState>),fn_802ac224(Ptr32<ReadState>),fn_802ac7b0(Ptr32<ReadState>),fn_802ac2ec(Ptr32<ReadState>),fn_802ac37c(Ptr32<ReadState>),fn_802ac438(Ptr32<ReadState>),fn_802ac4bc(Ptr32<ReadState>),fn_802ac564(Ptr32<ReadState>),fn_802ac600(Ptr32<ReadState>),fn_802ac668(Ptr32<ReadState>),fn_802ac6ec(Ptr32<ReadState>),fn_802ac74c(Ptr32<ReadState>);
extern "C" void fn_802fb82c(Ptr32<const char>,int,Ptr32<const char>,...);
extern char path_803d6cc4[],message_803d6cdc[];
extern "C" int g1p_card_read_tick_802abffc(Ptr32<ReadState> p){
 fn_802ac814(p->state);
 switch(p->state){
 case 192:p->start=1;fn_802ac1e4(p);return -1;
 case 193:fn_802ac224(p);return -1;
 case -34:fn_802ac7b0(p);return -34;
 case 194:fn_802ac2ec(p);return -1;
 case 195:fn_802ac37c(p);return -1;
 case 196:fn_802ac438(p);return -1;
 case 197:fn_802ac4bc(p);return -1;
 case 198:fn_802ac564(p);return -1;
 case -38:fn_802ac600(p);return -38;
 case -39:fn_802ac668(p);return -39;
 case -37:fn_802ac6ec(p);return -37;
 case -36:fn_802ac74c(p);return -36;
 case 3:p->state=192;return 3;
 case 1:p->state=192;return 1;
 case 2:p->state=192;return 2;
 case 0:p->state=192;return 0;
 default:fn_802fb82c(path_803d6cc4,163,message_803d6cdc);return 0;
 }
}


