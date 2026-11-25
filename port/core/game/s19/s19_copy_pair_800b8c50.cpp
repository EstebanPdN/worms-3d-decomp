#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_copy_pair_800b8c50.c"
struct S19Pair { int w[12]; };
struct S19Owner { char pad0[4]; Ptr32<char> data; };

void s19_copy_pair_800b8c50(Ptr32<struct S19Owner> self, Ptr32<struct S19Pair> dst)
{
    *dst = *(Ptr32<struct S19Pair>)(self->data + 240);
}

void s19_copy_pair_800b8ca0(Ptr32<struct S19Owner> self, Ptr32<struct S19Pair> dst)
{
    *dst = *(Ptr32<struct S19Pair>)(self->data + 144);
}

}
