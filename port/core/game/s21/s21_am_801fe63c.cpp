#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_am_801fe63c.c"
// desc: Appears to assign the text true or false to the output string depending on a boolean value read through a pointer, returning zero.
struct S21Text;
extern const char lbl_803b298c[];
extern const char lbl_803b2994[];
extern void fn_8020bd38(Ptr32<struct S21Text>, Ptr32<const char>);
int w3d_s21_bool_to_text_801fe63c(Ptr32<void> self, Ptr32<struct S21Text> out, Ptr32<const int> value)
{
    if (*value)
        fn_8020bd38(out, lbl_803b298c);
    else
        fn_8020bd38(out, lbl_803b2994);
    return 0;
}

}
