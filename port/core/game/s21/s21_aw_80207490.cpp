#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aw_80207490.c"
// desc: Appears to obtain an object from a helper for a global handle, clear its first two words and return it.
struct S21Pair { int first; int second; };
extern Ptr32<struct S21Pair> fn_802099f8(Ptr32<void>);
extern int lbl_804b064c;
Ptr32<struct S21Pair> w3d_s21_acquire_cleared_80207490(void)
{
    Ptr32<struct S21Pair> pair = fn_802099f8(&lbl_804b064c);
    pair->first = 0;
    pair->second = 0;
    return pair;
}

}
