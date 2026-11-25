#include "w3d_ptr.h"
#line 1 "s1_random_messages.cpp"
/* Random localized display messages; keys remain external original objects. */
extern "C" {
struct W3dS1QueuedText { Ptr32<char> text; unsigned int unused; };
Ptr32<void> w3d_string_from_text(Ptr32<W3dS1QueuedText>,Ptr32<const char>);
void w3d_fn_80043134(Ptr32<unsigned int>,Ptr32<W3dS1QueuedText>,unsigned int);
unsigned int w3d_auto_8015ff5c(Ptr32<unsigned int>);
Ptr32<void> w3d_fn_800fc2b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<const char>>);
extern const char w3d_str_80375134[];
extern const char w3d_str_80375148[];
extern const char w3d_str_8037515c[];
extern const char w3d_str_80375170[];
extern const char w3d_str_80375184[];
extern const char w3d_str_80375198[];
extern const char w3d_str_803751ac[];
extern const char w3d_str_803751c0[];
extern const char w3d_str_803751d4[];
void w3d_fn_80044ef8(Ptr32<unsigned int> self)
{
    struct { W3dS1QueuedText argument; Ptr32<const char> key0; Ptr32<const char> text; Ptr32<const char> keys[8]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%9) {
    case 0: local.key0=w3d_str_80375134; w3d_fn_800fc2b0(&local.key0,&local.text); break;
    case 1: local.keys[0]=w3d_str_80375148; w3d_fn_800fc2b0(&local.keys[0],&local.text); break;
    case 2: local.keys[1]=w3d_str_8037515c; w3d_fn_800fc2b0(&local.keys[1],&local.text); break;
    case 3: local.keys[2]=w3d_str_80375170; w3d_fn_800fc2b0(&local.keys[2],&local.text); break;
    case 4: local.keys[3]=w3d_str_80375184; w3d_fn_800fc2b0(&local.keys[3],&local.text); break;
    case 5: local.keys[4]=w3d_str_80375198; w3d_fn_800fc2b0(&local.keys[4],&local.text); break;
    case 6: local.keys[5]=w3d_str_803751ac; w3d_fn_800fc2b0(&local.keys[5],&local.text); break;
    case 7: local.keys[6]=w3d_str_803751c0; w3d_fn_800fc2b0(&local.keys[6],&local.text); break;
    default: local.keys[7]=w3d_str_803751d4; w3d_fn_800fc2b0(&local.keys[7],&local.text); break;
    }
    w3d_string_from_text(&local.argument,local.text);
    w3d_fn_80043134(self,&local.argument,0);
}
extern const char w3d_str_803751e8[];
extern const char w3d_str_803751fc[];
extern const char w3d_str_80375210[];
extern const char w3d_str_80375224[];
extern const char w3d_str_80375238[];
extern const char w3d_str_8037524c[];
extern const char w3d_str_80375260[];
extern const char w3d_str_80375274[];
extern const char w3d_str_80375288[];
extern const char w3d_str_8037529c[];
void w3d_fn_800450a4(Ptr32<unsigned int> self)
{
    struct { W3dS1QueuedText argument; Ptr32<const char> key0; Ptr32<const char> text; Ptr32<const char> keys[9]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%10) {
    case 0: local.key0=w3d_str_803751e8; w3d_fn_800fc2b0(&local.key0,&local.text); break;
    case 1: local.keys[0]=w3d_str_803751fc; w3d_fn_800fc2b0(&local.keys[0],&local.text); break;
    case 2: local.keys[1]=w3d_str_80375210; w3d_fn_800fc2b0(&local.keys[1],&local.text); break;
    case 3: local.keys[2]=w3d_str_80375224; w3d_fn_800fc2b0(&local.keys[2],&local.text); break;
    case 4: local.keys[3]=w3d_str_80375238; w3d_fn_800fc2b0(&local.keys[3],&local.text); break;
    case 5: local.keys[4]=w3d_str_8037524c; w3d_fn_800fc2b0(&local.keys[4],&local.text); break;
    case 6: local.keys[5]=w3d_str_80375260; w3d_fn_800fc2b0(&local.keys[5],&local.text); break;
    case 7: local.keys[6]=w3d_str_80375274; w3d_fn_800fc2b0(&local.keys[6],&local.text); break;
    case 8: local.keys[7]=w3d_str_80375288; w3d_fn_800fc2b0(&local.keys[7],&local.text); break;
    default: local.keys[8]=w3d_str_8037529c; w3d_fn_800fc2b0(&local.keys[8],&local.text); break;
    }
    w3d_string_from_text(&local.argument,local.text);
    w3d_fn_80043134(self,&local.argument,0);
}
extern const char w3d_str_8037597c[];
extern const char w3d_str_80375990[];
extern const char w3d_str_803759a4[];
extern const char w3d_str_803759b8[];
extern const char w3d_str_803759cc[];
extern const char w3d_str_803759e0[];
extern const char w3d_str_803759f4[];
void w3d_fn_80046290(Ptr32<unsigned int> self)
{
    struct { W3dS1QueuedText argument; Ptr32<const char> key0; Ptr32<const char> text; Ptr32<const char> keys[6]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%7) {
    case 0: local.key0=w3d_str_8037597c; w3d_fn_800fc2b0(&local.key0,&local.text); break;
    case 1: local.keys[0]=w3d_str_80375990; w3d_fn_800fc2b0(&local.keys[0],&local.text); break;
    case 2: local.keys[1]=w3d_str_803759a4; w3d_fn_800fc2b0(&local.keys[1],&local.text); break;
    case 3: local.keys[2]=w3d_str_803759b8; w3d_fn_800fc2b0(&local.keys[2],&local.text); break;
    case 4: local.keys[3]=w3d_str_803759cc; w3d_fn_800fc2b0(&local.keys[3],&local.text); break;
    case 5: local.keys[4]=w3d_str_803759e0; w3d_fn_800fc2b0(&local.keys[4],&local.text); break;
    case 6: local.keys[5]=w3d_str_803759f4; w3d_fn_800fc2b0(&local.keys[5],&local.text); break;
    }
    w3d_string_from_text(&local.argument,local.text);
    w3d_fn_80043134(self,&local.argument,0);
}
extern const char w3d_str_80375b5c[];
extern const char w3d_str_80375b70[];
extern const char w3d_str_80375b84[];
extern const char w3d_str_80375b98[];
extern const char w3d_str_80375bac[];
extern const char w3d_str_80375bc0[];
extern const char w3d_str_80375bd4[];
void w3d_fn_80046764(Ptr32<unsigned int> self)
{
    struct { W3dS1QueuedText argument; Ptr32<const char> key0; Ptr32<const char> text; Ptr32<const char> keys[6]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%7) {
    case 0: local.key0=w3d_str_80375b5c; w3d_fn_800fc2b0(&local.key0,&local.text); break;
    case 1: local.keys[0]=w3d_str_80375b70; w3d_fn_800fc2b0(&local.keys[0],&local.text); break;
    case 2: local.keys[1]=w3d_str_80375b84; w3d_fn_800fc2b0(&local.keys[1],&local.text); break;
    case 3: local.keys[2]=w3d_str_80375b98; w3d_fn_800fc2b0(&local.keys[2],&local.text); break;
    case 4: local.keys[3]=w3d_str_80375bac; w3d_fn_800fc2b0(&local.keys[3],&local.text); break;
    case 5: local.keys[4]=w3d_str_80375bc0; w3d_fn_800fc2b0(&local.keys[4],&local.text); break;
    case 6: local.keys[5]=w3d_str_80375bd4; w3d_fn_800fc2b0(&local.keys[5],&local.text); break;
    }
    w3d_string_from_text(&local.argument,local.text);
    w3d_fn_80043134(self,&local.argument,0);
}
extern const char w3d_str_80376344[];
extern const char w3d_str_80376358[];
extern const char w3d_str_8037636c[];
extern const char w3d_str_80376380[];
extern const char w3d_str_80376394[];
extern const char w3d_str_803763a8[];
void w3d_fn_80047d50(Ptr32<unsigned int> self)
{
    struct { W3dS1QueuedText argument; Ptr32<const char> key0; Ptr32<const char> text; Ptr32<const char> keys[5]; } local;
    local.text=0;
    switch(w3d_auto_8015ff5c(self)%6) {
    case 0: local.key0=w3d_str_80376344; w3d_fn_800fc2b0(&local.key0,&local.text); break;
    case 1: local.keys[0]=w3d_str_80376358; w3d_fn_800fc2b0(&local.keys[0],&local.text); break;
    case 2: local.keys[1]=w3d_str_8037636c; w3d_fn_800fc2b0(&local.keys[1],&local.text); break;
    case 3: local.keys[2]=w3d_str_80376380; w3d_fn_800fc2b0(&local.keys[2],&local.text); break;
    case 4: local.keys[3]=w3d_str_80376394; w3d_fn_800fc2b0(&local.keys[3],&local.text); break;
    default: local.keys[4]=w3d_str_803763a8; w3d_fn_800fc2b0(&local.keys[4],&local.text); break;
    }
    w3d_string_from_text(&local.argument,local.text);
    w3d_fn_80043134(self,&local.argument,0);
}
void w3d_fn_80047fcc(Ptr32<unsigned int> self)
{
    struct { W3dS1QueuedText argument; Ptr32<const char> key0; Ptr32<const char> text; Ptr32<const char> keys[5]; } local;
    local.text=0;
    switch(w3d_auto_8015ff5c(self)%6) {
    case 0: local.key0=w3d_str_8037597c; w3d_fn_800fc2b0(&local.key0,&local.text); break;
    case 1: local.keys[0]=w3d_str_80375990; w3d_fn_800fc2b0(&local.keys[0],&local.text); break;
    case 2: local.keys[1]=w3d_str_803759a4; w3d_fn_800fc2b0(&local.keys[1],&local.text); break;
    case 3: local.keys[2]=w3d_str_803759b8; w3d_fn_800fc2b0(&local.keys[2],&local.text); break;
    case 4: local.keys[3]=w3d_str_803759cc; w3d_fn_800fc2b0(&local.keys[3],&local.text); break;
    default: local.keys[4]=w3d_str_803759e0; w3d_fn_800fc2b0(&local.keys[4],&local.text); break;
    }
    w3d_string_from_text(&local.argument,local.text);
    w3d_fn_80043134(self,&local.argument,0);
}
}


