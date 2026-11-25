#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bb_80208af8.c"
// desc: Appears to allocate a 44-byte object, construct it, initialize it from two arguments and return it.
extern Ptr32<void> fn_801fe1d8(int);
extern Ptr32<void> fn_80208c0c(Ptr32<void>);
extern int fn_80208f48(Ptr32<void>, Ptr32<void>, Ptr32<void>);
Ptr32<void> w3d_s21_create_80208af8(Ptr32<void> a, Ptr32<void> b)
{
    Ptr32<void> object = fn_80208c0c(fn_801fe1d8(44));
    fn_80208f48(object, a, b);
    return object;
}

}
