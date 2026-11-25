#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ap_801ff5a4.c"
// desc: Appears to convert a text argument to an unsigned number and store it zero-extended into a 64-bit output, returning zero. Identical in bytes to its sibling.
extern unsigned fn_802ed89c(Ptr32<const char>);
int w3d_s21_text_to_u64_b_801ff5a4(Ptr32<void> self, Ptr32<unsigned long long> out, Ptr32<const char> text)
{
    *out = fn_802ed89c(text);
    return 0;
}

}
