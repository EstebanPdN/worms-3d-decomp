#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8static_800e71ac.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern int lbl_804aaed4;
extern int lbl_804aedfc;
extern int lbl_804aee04;
extern int lbl_804aee08;
extern int lbl_804aee10;
extern int lbl_804aee14;
extern int lbl_804aee18;
extern int lbl_804aee00;
extern int lbl_804aee0c;
extern int lbl_804aee1c;
extern s8_SmallObject lbl_804aee20;
extern char lbl_8038afbc[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
void s8_static_init_800e71ac(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        int base0=lbl_804aaed4;
        int offset1=base0+16384;
        int offset2=base0+736;
        int offset3=base0+12400;
        int offset4=base0+16368;
        int offset5=base0+16304;
        int offset6=base0+16176;
        lbl_804aedfc=offset1;
        lbl_804aee04=offset2;
        lbl_804aee08=offset3;
        lbl_804aee10=offset4;
        lbl_804aee14=offset5;
        lbl_804aee18=offset6;
        lbl_804aee00=base0;
        lbl_804aee0c=base0;
        lbl_804aee1c=base0;
        fn_8015f518(&lbl_804aee20, lbl_8038afbc);
    }
}

}
