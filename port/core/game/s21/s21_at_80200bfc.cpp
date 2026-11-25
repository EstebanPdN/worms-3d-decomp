#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_at_80200bfc.c"
// desc: Appears to walk a linked chain recursively through a child pointer at offset 12, starting from a global root when none is given, and finish the node.
struct S21Node { char pad[12]; Ptr32<struct S21Node> child; };
extern Ptr32<struct S21Node> lbl_804b18e8;
extern int fn_80200c44(Ptr32<struct S21Node>);
int w3d_s21_finish_chain_80200bfc(Ptr32<struct S21Node> node)
{
    if (!node)
        node = lbl_804b18e8;
    if (node->child)
        w3d_s21_finish_chain_80200bfc(node->child);
    return fn_80200c44(node);
}

}
