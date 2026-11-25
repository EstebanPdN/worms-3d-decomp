#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8sorted_800e265c.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aaea4;
extern int lbl_804aecd0;
extern int lbl_804aecd4;
extern int lbl_804aecd8;
extern int lbl_804aecbc;
extern int lbl_804aecc4;
extern int lbl_804aecc8;
extern int lbl_804aecdc;
extern int lbl_804aecc0;
extern int lbl_804aeccc;
extern s8_SmallObject lbl_804aece0;
extern char lbl_80389f18[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
extern s8_SmallObject lbl_804aece8;
extern char lbl_80389f30[];
extern s8_SmallObject lbl_804aecf0;
extern char lbl_80389f48[];
extern s8_SmallObject lbl_804aecf8;
extern char lbl_80389f60[];
extern s8_SmallObject lbl_804aed00;
extern char lbl_80389f7c[];
extern s8_SmallObject lbl_804aed08;
extern char lbl_80389f8c[];
extern char lbl_80360cf0[];
extern char lbl_803e8194[];
extern char lbl_803617d0[];
int fn_800e05a4(void);
int fn_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
void s8_static_init_800e265c(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aaea4;
        int offset1=base0+16368;
        int offset2=base0+16304;
        int offset3=base0+16176;
        int offset4=base0+16384;
        int offset5=base0+736;
        int offset6=base0+12400;
        lbl_804aecbc=offset4;
        lbl_804aecc0=base0;
        lbl_804aecc4=offset5;
        lbl_804aecc8=offset6;
        lbl_804aeccc=base0;
        lbl_804aecd0=offset1;
        lbl_804aecd4=offset2;
        lbl_804aecd8=offset3;
        lbl_804aecdc=base0;
        fn_8015f518(&lbl_804aece0, lbl_80389f18);
        fn_8015f518(&lbl_804aece8, lbl_80389f30);
        fn_8015f518(&lbl_804aecf0, lbl_80389f48);
        fn_8015f518(&lbl_804aecf8, lbl_80389f60);
        fn_8015f518(&lbl_804aed00, lbl_80389f7c);
        fn_8015f518(&lbl_804aed08, lbl_80389f8c);
        fn_80160038(lbl_80360cf0, lbl_803e8194, lbl_803617d0, fn_800e05a4, 9, 0);
    }
}

}
