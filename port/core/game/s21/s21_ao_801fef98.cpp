#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ao_801fef98.c"
// desc: Appears to format a 64-bit value read through a pointer into the output string with a global signed format string, returning zero.
struct S21Text;
extern const char lbl_803b29c4[];
extern void fn_8020c510(Ptr32<struct S21Text>, Ptr32<const char>, ...);
int w3d_s21_s64_to_text_801fef98(Ptr32<void> self, Ptr32<struct S21Text> out, Ptr32<const long long> value)
{
    fn_8020c510(out, lbl_803b29c4, *value);
    return 0;
}

}
