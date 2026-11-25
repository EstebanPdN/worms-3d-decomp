#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bn_8020b960.c"
// desc: Appears to replace the global singleton pointer, retaining the new object and releasing the previous one through virtual slots.
struct S21Singleton;
struct S21SingletonMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Singleton>)> retain; Ptr32<void (Ptr32<struct S21Singleton>)> release; };
struct S21Singleton { Ptr32<struct S21SingletonMethods> methods; };
extern Ptr32<struct S21Singleton> lbl_804b0698;
void w3d_s21_set_singleton_8020b960(Ptr32<struct S21Singleton> fresh)
{
    if (fresh)
        fresh->methods->retain(fresh);
    if (lbl_804b0698)
        lbl_804b0698->methods->release(lbl_804b0698);
    lbl_804b0698 = fresh;
}

}
