#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_b_801ff100.c"
extern double fn_802ed878(int);
int w3d_s21_read_float_801ff100(Ptr32<void> self, Ptr32<float> out, int value)
{
    *out = (float)fn_802ed878(value);
    return 0;
}

}
