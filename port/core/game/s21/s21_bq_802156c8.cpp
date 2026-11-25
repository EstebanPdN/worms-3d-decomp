#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bq_802156c8.c"
// desc: Appears to swap in a minus-one handler through a helper and, when the previous value is not negative, restore it.
extern int fn_80217f8c(int);
void w3d_s21_swap_restore_802156c8(void)
{
    int previous = fn_80217f8c(-1);
    if (previous >= 0)
        fn_80217f8c(previous);
}

}
