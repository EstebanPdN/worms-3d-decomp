#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8static_800d5180.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aae4c;
extern int lbl_804ae9ec;
extern int lbl_804ae9f4;
extern int lbl_804ae9f8;
extern int lbl_804aea00;
extern int lbl_804aea04;
extern int lbl_804aea08;
extern int lbl_804ae9f0;
extern int lbl_804ae9fc;
extern int lbl_804aea0c;
extern s8_SmallObject lbl_804aea10;
extern char lbl_80388d4c[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
extern s8_SmallObject lbl_804aea18;
extern char lbl_80388d60[];
void s8_static_init_800d5180(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aae4c;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804ae9ec=offset1;
        lbl_804ae9f4=offset2;
        lbl_804ae9f8=offset3;
        lbl_804aea00=offset4;
        lbl_804aea04=offset5;
        lbl_804aea08=offset6;
        lbl_804ae9f0=base0;
        lbl_804ae9fc=base0;
        lbl_804aea0c=base0;
        fn_8015f518(&lbl_804aea10, lbl_80388d4c);
        fn_8015f518(&lbl_804aea18, lbl_80388d60);
    }
}

}
