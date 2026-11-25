#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ao_801ff0a0.c"
// desc: Appears to pass a float read through a pointer to a text conversion helper for the output string, returning its result.
struct S21Text;
extern int fn_8020dcc8(Ptr32<struct S21Text>, float);
int w3d_s21_float_to_text_801ff0a0(Ptr32<void> self, Ptr32<struct S21Text> out, Ptr32<const float> value)
{
    return fn_8020dcc8(out, *value);
}

}
