#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cv_802dd10c.c"
// desc: Appears to be a Lua argument checker: it reads a number, and for a zero value verifies that the argument really is a number, raising a type error otherwise.
extern const float lbl_803da850[];
extern double fn_802cdc5c(Ptr32<void>, int);
extern int fn_802cda9c(Ptr32<void>, int);
extern void fn_802dcda8(Ptr32<void>, int, int);
double w3d_s21_check_number_802dd10c(Ptr32<void> state, int index)
{
    double value = fn_802cdc5c(state, index);
    if (value == lbl_803da850[0] && !fn_802cda9c(state, index))
        fn_802dcda8(state, index, 3);
    return value;
}

}
