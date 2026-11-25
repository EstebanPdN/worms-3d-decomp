#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_an_801fee3c.c"
// desc: Appears to pass a 64-bit value read through a pointer to a text conversion helper for the output string, returning its result.
struct S21Text;
extern int fn_8020db88(Ptr32<struct S21Text>, long long);
int w3d_s21_i64_to_text_801fee3c(Ptr32<void> self, Ptr32<struct S21Text> out, Ptr32<const long long> value)
{
    return fn_8020db88(out, *value);
}

}
