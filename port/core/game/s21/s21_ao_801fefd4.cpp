#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ao_801fefd4.c"
// desc: Appears to convert a text argument to a signed number and store it sign-extended into a 64-bit output, returning zero.
extern int fn_802ed89c(Ptr32<const char>);
int w3d_s21_text_to_s64_801fefd4(Ptr32<void> self, Ptr32<long long> out, Ptr32<const char> text)
{
    *out = fn_802ed89c(text);
    return 0;
}

}
