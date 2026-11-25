#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_b_801ff220.c"
extern double fn_802ed878(int);
int w3d_s21_read_double_801ff220(Ptr32<void> self, Ptr32<double> out, int value)
{
    *out = fn_802ed878(value);
    return 0;
}

}
