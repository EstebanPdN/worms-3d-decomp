#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ad.c"
/* Guarded helper pair. */
extern void fn_803089c8(int, int, Ptr32<void>);
extern int fn_8016ac3c(int, Ptr32<char>, Ptr32<char>);
extern void fn_8016acac(Ptr32<char>, Ptr32<char>, Ptr32<char>);

void w3d_s20_apply_if_enabled_8016b384(int unused, Ptr32<char> a, Ptr32<char> b, Ptr32<char> c) {
    if (*(Ptr32<int>)(c + 188) != 0) {
        fn_803089c8(unused, 0, (Ptr32<void>)b);
        b++;
        b--;
        if (fn_8016ac3c(w3d::H(a), b, c) == 0)
            fn_8016acac(a, b, c);
    }
}

}
