#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fl_801f3ccc.c"
// desc: Appears to walk every node of a global list and clear the top bit of its flag word at offset 32.
struct S21Node { char pad[32]; unsigned flags; };
extern char lbl_803657d8[];
extern Ptr32<struct S21Node> fn_8020fe00(Ptr32<void>);
extern Ptr32<struct S21Node> fn_8020fe18(Ptr32<void>, Ptr32<struct S21Node>);
void w3d_s21_clear_flags_801f3ccc(void)
{
    Ptr32<void> list = lbl_803657d8;
    Ptr32<struct S21Node> node = fn_8020fe00(list);
    for (; node; node = fn_8020fe18(list, node))
        node->flags &= 0x7fffffff;
}

}
