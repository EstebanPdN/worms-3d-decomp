#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bp_80217fc8.c"
// desc: Appears to print its argument with a global format string through a log function when a global debug flag is set.
extern int lbl_804ab9a4;
extern const char lbl_803b383c[];
extern int fn_802fb7ac(Ptr32<const char>, ...);
void w3d_s21_trace_80217fc8(int value)
{
    if (lbl_804ab9a4)
        fn_802fb7ac(lbl_803b383c, value);
}

}
