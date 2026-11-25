#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ao_801ff1c0.c"
// desc: Appears to pass a double read through a pointer to a text conversion helper for the output string, returning its result.
struct S21Text;
extern int fn_8020dd44(Ptr32<struct S21Text>, double);
int w3d_s21_double_to_text_801ff1c0(Ptr32<void> self, Ptr32<struct S21Text> out, Ptr32<const double> value)
{
    return fn_8020dd44(out, *value);
}

}
