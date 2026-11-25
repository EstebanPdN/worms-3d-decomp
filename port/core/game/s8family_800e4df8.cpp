#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8family_800e4df8.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aaeb4;
extern int lbl_804aed34;
extern int lbl_804aed38;
extern int lbl_804aed3c;
extern int lbl_804aed20;
extern int lbl_804aed28;
extern int lbl_804aed2c;
extern int lbl_804aed40;
extern int lbl_804aed24;
extern int lbl_804aed30;
extern s8_SmallObject lbl_804aed44;
extern char lbl_8038a134[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
extern s8_SmallObject lbl_804aed4c;
extern char lbl_8038a14c[];
extern s8_SmallObject lbl_804aed54;
extern char lbl_8038a15c[];
extern s8_SmallObject lbl_804aed5c;
extern char lbl_8038a170[];
extern s8_SmallObject lbl_804aed64;
extern char lbl_8038a17c[];
extern s8_SmallObject lbl_804aed6c;
extern char lbl_8038a18c[];
extern s8_SmallObject lbl_804aed74;
extern char lbl_8038a1a4[];
extern char lbl_80360d50[];
extern char lbl_803e81cc[];
extern char lbl_80361860[];
int fn_800e3528(void);
int fn_8016115c(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
void s8_static_init_800e4df8(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aaeb4;
        int offset1=base0+16368;
        int offset2=base0+16304;
        int offset3=base0+16176;
        int offset4=base0+16384;
        int offset5=base0+736;
        int offset6=base0+12400;
        lbl_804aed20=offset4;
        lbl_804aed24=base0;
        lbl_804aed28=offset5;
        lbl_804aed2c=offset6;
        lbl_804aed30=base0;
        lbl_804aed34=offset1;
        lbl_804aed38=offset2;
        lbl_804aed3c=offset3;
        lbl_804aed40=base0;
        fn_8015f518(&lbl_804aed44, lbl_8038a134);
        fn_8015f518(&lbl_804aed4c, lbl_8038a14c);
        fn_8015f518(&lbl_804aed54, lbl_8038a15c);
        fn_8015f518(&lbl_804aed5c, lbl_8038a170);
        fn_8015f518(&lbl_804aed64, lbl_8038a17c);
        fn_8015f518(&lbl_804aed6c, lbl_8038a18c);
        fn_8015f518(&lbl_804aed74, lbl_8038a1a4);
        fn_8016115c(lbl_80360d50, lbl_803e81cc, lbl_80361860, fn_800e3528, 11, 0);
    }
}

}
