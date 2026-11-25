#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_as_802002fc.c"
// desc: Appears to release a global singleton through a virtual slot, clear the global pointer and return zero.
struct S21Singleton;
struct S21SingletonMethods { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<struct S21Singleton>)> release; };
struct S21Singleton { Ptr32<struct S21SingletonMethods> methods; };
extern Ptr32<struct S21Singleton> lbl_804b063c;
int w3d_s21_release_singleton_802002fc(void)
{
    if (lbl_804b063c)
        lbl_804b063c->methods->release(lbl_804b063c);
    lbl_804b063c = 0;
    return 0;
}

}
