#include "w3d_ptr.h"
#line 1 "cx16b_reset_sequence_801fe3b0.cpp"
/* Original reset-call sequence. Platform service semantics beyond this
   observed sequence remain inferred, and are not reimplemented here. */
extern "C" {
extern const char str_803b2974[];
void fn_802fb7ac(Ptr32<const char>,...);
void fn_803085a0();
void fn_80304b84(int);
void fn_803049e8();
void fn_80303964();
void fn_80331a40();
int fn_80301ba0(unsigned);
int fn_802f7b40();
unsigned fn_802feb50();
void fn_802fe898(int,unsigned,int);
void w3d_cx16b_reset_sequence_801fe3b0(Ptr32<void> unused,int mode)
{
    fn_802fb7ac(str_803b2974);
    fn_803085a0();
    fn_80304b84(1);
    fn_803049e8();
    fn_80303964();
    fn_80331a40();
    fn_80301ba0(0xf0000000U);
    if(!fn_802f7b40())fn_802fe898(1,fn_802feb50(),0);
    if(mode)fn_802fe898(1,fn_802feb50(),mode);
    else fn_802fe898(0,fn_802feb50(),0);
}
}


