#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8static_800da85c.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern char lbl_80360c90[];
extern char lbl_803e815c[];
extern char lbl_803617d0[];
Ptr32<void> fn_800da17c(void);
int fn_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
extern s8_SmallObject lbl_804aeb8c;
extern char lbl_803897a4[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
extern s8_SmallObject lbl_804aeb94;
extern char lbl_803897bc[];
void s8_static_init_800da85c(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        fn_80160038(lbl_80360c90, lbl_803e815c, lbl_803617d0, fn_800da17c, 9, 0);
        fn_8015f518(&lbl_804aeb8c, lbl_803897a4);
        fn_8015f518(&lbl_804aeb94, lbl_803897bc);
    }
}

}
