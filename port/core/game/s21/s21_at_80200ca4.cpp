#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_at_80200ca4.c"
// desc: Appears to recurse through a first-child pointer, then call the function pointer at offset 12 and return its negative status or zero.
struct S21Node { Ptr32<struct S21Node> first; char pad[8]; Ptr32<int (void)> callback; };
int w3d_s21_run_callbacks_80200ca4(Ptr32<struct S21Node> node)
{
    if (!node)
        return 0;
    if (node->first)
        w3d_s21_run_callbacks_80200ca4(node->first);
    if (node->callback) {
        int status = node->callback();
        if (status < 0)
            return status;
    }
    return 0;
}

}
