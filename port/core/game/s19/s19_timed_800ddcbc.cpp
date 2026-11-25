#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_timed_800ddcbc.c"
extern void FUN_800ddb28(Ptr32<void>, float, Ptr32<void>, Ptr32<void>, int, Ptr32<void>);

void s19_start_timed_800ddcbc(Ptr32<void> self, unsigned t, int a, int b, int c, int d)
{
    FUN_800ddb28(self, (float)(t - *(Ptr32<unsigned int>)((Ptr32<char>)self + 100)), w3d::G(a), w3d::G(b), c, w3d::G(d));
}

}
