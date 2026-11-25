#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fu_801fa5c0.c"
// desc: Appears to copy a five-word request, accept type two or three (mapping three to two) and forward it with the first argument through a lookup helper, or return 0x80004005 for other types.
struct S21Request { int type; int b; int c; int d; int e; };
extern Ptr32<void> fn_801fac44(Ptr32<void>);
extern int fn_801f9c60(Ptr32<void>, int, Ptr32<struct S21Request>);
int w3d_s21_submit_b_801fa5c0(Ptr32<void> self, int handle, Ptr32<const struct S21Request> request)
{
    struct S21Request local = *request;
    switch (local.type) {
    case 2:
        break;
    case 3:
        local.type = 2;
        break;
    case 0:
    case 1:
    default:
        return 0x80004005;
    }
    return fn_801f9c60(fn_801fac44(self), handle, &local);
}

}
