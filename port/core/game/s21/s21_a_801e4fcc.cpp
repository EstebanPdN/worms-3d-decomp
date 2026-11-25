#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_a_801e4fcc.c"
struct S21Counter { int pad0[2]; int remaining; int pad1; int handle; };
extern int fn_803229bc(int);
int w3d_s21_counter_poll_801e4fcc(Ptr32<struct S21Counter> c)
{
    if (c->remaining > 0) return 1;
    {
        int r = fn_803229bc(c->handle);
        if (r == -1) { c->handle = r; return 0; }
        return 1;
    }
}

}
