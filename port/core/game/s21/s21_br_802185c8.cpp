#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_br_802185c8.c"
// desc: Appears to call virtual slot 5 of the object with its arguments, clearing bit 4 of the last one.
struct S21Object;
struct S21Methods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Object>, int, unsigned int)> open; };
struct S21Object { Ptr32<struct S21Methods> methods; };
int w3d_s21_open_masked_802185c8(Ptr32<struct S21Object> self, int name, unsigned flags)
{
    return self->methods->open(self, name, flags & ~4);
}

}
