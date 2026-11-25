#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fp_801f79d4.c"
// desc: Appears to be a static initialization entry that sets a global quaternion to identity (three zeros and a one from global constants) through a helper when called with the final priority.
extern char lbl_8045e778[];
extern float lbl_803b1814[];
extern float lbl_803b1818[];
extern void fn_80359cd8(Ptr32<void>, float, float, float, float);
void w3d_s21_static_identity_quat_801f79d4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        float zero = lbl_803b1814[0];
        fn_80359cd8(lbl_8045e778, zero, zero, zero, lbl_803b1818[0]);
    }
}

}
