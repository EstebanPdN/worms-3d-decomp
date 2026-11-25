#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9perm_8014be44.c"
/* Control-flow scope reproduces the reference compiler's conditional argument move. */
typedef struct S9RouteState { char unknown[300]; int active; } S9RouteState;
extern void fn_8015aa04(Ptr32<void>, Ptr32<void>);
extern void fn_801f67e0(Ptr32<void>);
extern int lbl_804aa8c8;
void s9_permute_8014be44(Ptr32<const S9RouteState> self,int value)
{
    do {
        if(!self->active)goto global_setting;
        fn_801f67e0(w3d::G(value));
        return;
global_setting:
        fn_8015aa04(w3d::G(lbl_804aa8c8+328), (Ptr32<void>)w3d::G(value));
    } while(0);
}

}
