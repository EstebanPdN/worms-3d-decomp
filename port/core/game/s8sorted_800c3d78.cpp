#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8sorted_800c3d78.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aaddc;
extern int lbl_804ae6cc;
extern int lbl_804ae6d0;
extern int lbl_804ae6d4;
extern int lbl_804ae6b8;
extern int lbl_804ae6c0;
extern int lbl_804ae6c4;
extern int lbl_804ae6d8;
extern int lbl_804ae6bc;
extern int lbl_804ae6c8;
extern s8_SmallObject lbl_804ae6dc;
extern char lbl_803832c0[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
extern s8_SmallObject lbl_804ae6e4;
extern char lbl_803832d0[];
extern s8_SmallObject lbl_804ae6ec;
extern char lbl_803832e4[];
extern s8_SmallObject lbl_804ae6f4;
extern char lbl_803832f8[];
extern s8_SmallObject lbl_804ae6fc;
extern char lbl_80383310[];
extern s8_SmallObject lbl_804ae704;
extern char lbl_80383324[];
extern s8_SmallObject lbl_804ae70c;
extern char lbl_80383340[];
extern s8_SmallObject lbl_804ae714;
extern char lbl_80383350[];
extern s8_SmallObject lbl_804ae71c;
extern char lbl_8038336c[];
extern s8_SmallObject lbl_804ae724;
extern char lbl_80383388[];
extern s8_SmallObject lbl_804ae72c;
extern char lbl_80383398[];
extern s8_SmallObject lbl_804ae734;
extern char lbl_803833b8[];
extern s8_SmallObject lbl_804ae73c;
extern char lbl_803833cc[];
extern s8_SmallObject lbl_804ae744;
extern char lbl_803833e0[];
extern s8_SmallObject lbl_804ae74c;
extern char lbl_803833f4[];
extern s8_SmallObject lbl_804ae754;
extern char lbl_80383404[];
extern s8_SmallObject lbl_804ae75c;
extern char lbl_80383420[];
extern char lbl_80360a20[];
extern char lbl_803e7ff0[];
extern char lbl_80361860[];
Ptr32<void> fn_800c26a4(void);
int fn_8016115c(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
void s8_static_init_800c3d78(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aaddc;
        int offset1=base0+16368;
        int offset2=base0+16304;
        int offset3=base0+16176;
        int offset4=base0+16384;
        int offset5=base0+736;
        int offset6=base0+12400;
        lbl_804ae6b8=offset4;
        lbl_804ae6bc=base0;
        lbl_804ae6c0=offset5;
        lbl_804ae6c4=offset6;
        lbl_804ae6c8=base0;
        lbl_804ae6cc=offset1;
        lbl_804ae6d0=offset2;
        lbl_804ae6d4=offset3;
        lbl_804ae6d8=base0;
        fn_8015f518(&lbl_804ae6dc, lbl_803832c0);
        fn_8015f518(&lbl_804ae6e4, lbl_803832d0);
        fn_8015f518(&lbl_804ae6ec, lbl_803832e4);
        fn_8015f518(&lbl_804ae6f4, lbl_803832f8);
        fn_8015f518(&lbl_804ae6fc, lbl_80383310);
        fn_8015f518(&lbl_804ae704, lbl_80383324);
        fn_8015f518(&lbl_804ae70c, lbl_80383340);
        fn_8015f518(&lbl_804ae714, lbl_80383350);
        fn_8015f518(&lbl_804ae71c, lbl_8038336c);
        fn_8015f518(&lbl_804ae724, lbl_80383388);
        fn_8015f518(&lbl_804ae72c, lbl_80383398);
        fn_8015f518(&lbl_804ae734, lbl_803833b8);
        fn_8015f518(&lbl_804ae73c, lbl_803833cc);
        fn_8015f518(&lbl_804ae744, lbl_803833e0);
        fn_8015f518(&lbl_804ae74c, lbl_803833f4);
        fn_8015f518(&lbl_804ae754, lbl_80383404);
        fn_8015f518(&lbl_804ae75c, lbl_80383420);
        fn_8016115c(lbl_80360a20, lbl_803e7ff0, lbl_80361860, fn_800c26a4, 11, 0);
    }
}

}
