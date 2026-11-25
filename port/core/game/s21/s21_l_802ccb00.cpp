#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_l_802ccb00.c"
// desc: Appears to report whether a flag in a sixteen-entry table is set when the subsystem is enabled.
extern int lbl_804abce4;
extern int lbl_80473724[];
int w3d_s21_flag_is_set_802ccb00(unsigned index)
{
    if (!lbl_804abce4 || index > 15)
        return 0;
    return *(Ptr32<int>)((index << 2) + (Ptr32<char>)lbl_80473724) != 0;
}

}
