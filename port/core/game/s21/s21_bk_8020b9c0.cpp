#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bk_8020b9c0.c"
// desc: Appears to release a second global singleton through a virtual slot, clear the global pointer and return zero.
struct S21Singleton;
struct S21SingletonMethods { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<struct S21Singleton>)> release; };
struct S21Singleton { Ptr32<struct S21SingletonMethods> methods; };
extern Ptr32<struct S21Singleton> lbl_804b0698;
int w3d_s21_release_singleton_b_8020b9c0(void)
{
    if (lbl_804b0698)
        lbl_804b0698->methods->release(lbl_804b0698);
    lbl_804b0698 = 0;
    return 0;
}

}
