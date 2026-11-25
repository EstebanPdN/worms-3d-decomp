#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8static_800d6a20.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aae5c;
extern int lbl_804aea34;
extern int lbl_804aea3c;
extern int lbl_804aea40;
extern int lbl_804aea38;
extern int lbl_804aea44;
extern int lbl_804aea54;
extern int lbl_804aea48;
extern int lbl_804aea4c;
extern int lbl_804aea50;
extern char lbl_80360c30[];
extern char lbl_803e8124[];
extern char lbl_80361860[];
Ptr32<void> fn_800d5818(void);
int fn_8016115c(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
extern s8_SmallObject lbl_804aea58;
extern char lbl_80388fcc[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
extern s8_SmallObject lbl_804aea60;
extern char lbl_80388fd8[];
extern s8_SmallObject lbl_804aea68;
extern char lbl_80388fe8[];
extern s8_SmallObject lbl_804aea70;
extern char lbl_80388ff8[];
extern s8_SmallObject lbl_804aea78;
extern char lbl_80389008[];
void s8_static_init_800d6a20(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aae5c;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804aea34=offset1;
        lbl_804aea3c=offset2;
        lbl_804aea40=offset3;
        lbl_804aea38=base0;
        lbl_804aea44=base0;
        lbl_804aea54=base0;
        lbl_804aea48=offset4;
        lbl_804aea4c=offset5;
        lbl_804aea50=offset6;
        fn_8016115c(lbl_80360c30, lbl_803e8124, lbl_80361860, fn_800d5818, 11, 0);
        fn_8015f518(&lbl_804aea58, lbl_80388fcc);
        fn_8015f518(&lbl_804aea60, lbl_80388fd8);
        fn_8015f518(&lbl_804aea68, lbl_80388fe8);
        fn_8015f518(&lbl_804aea70, lbl_80388ff8);
        fn_8015f518(&lbl_804aea78, lbl_80389008);
    }
}

}
