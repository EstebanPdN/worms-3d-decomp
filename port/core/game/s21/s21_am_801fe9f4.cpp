#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_am_801fe9f4.c"
// desc: Appears to format an unsigned halfword read through a pointer into the output string with a global format string, returning zero.
struct S21Text;
extern const char lbl_803b29c8[];
extern void fn_8020c510(Ptr32<struct S21Text>, Ptr32<const char>, ...);
int w3d_s21_u16_to_text_801fe9f4(Ptr32<void> self, Ptr32<struct S21Text> out, Ptr32<const unsigned short> value)
{
    fn_8020c510(out, lbl_803b29c8, *value);
    return 0;
}

}
