#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8static_800af134.c"
typedef struct s8_SmallObject { int a,b; } s8_SmallObject;
extern char lbl_80360870[];
extern char lbl_803e7ef4[];
extern char lbl_803617d0[];
Ptr32<void> fn_800ad984(void);
int fn_80160038(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void (void)>, int, int);
extern s8_SmallObject lbl_804ae3dc;
extern char lbl_80382230[];
int fn_8015f518(Ptr32<void>, Ptr32<void>);
extern s8_SmallObject lbl_804ae3e4;
extern char lbl_80382244[];
void s8_static_init_800af134(int initialize,int priority)
{
    if(priority==0xffff && initialize) {
        fn_80160038(lbl_80360870, lbl_803e7ef4, lbl_803617d0, fn_800ad984, 9, 0);
        fn_8015f518(&lbl_804ae3dc, lbl_80382230);
        fn_8015f518(&lbl_804ae3e4, lbl_80382244);
    }
}

}
