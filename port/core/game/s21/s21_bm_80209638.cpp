#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bm_80209638.c"
// desc: Appears to allocate aligned memory when a flag bit is set, otherwise to call the allocation function pointer of the inner object with the same arguments.
struct S21Inner { char pad[24]; Ptr32<Ptr32<void> (Ptr32<struct S21Inner>, int, int)> allocate; };
struct S21Allocator { Ptr32<struct S21Inner> inner; char pad[16]; unsigned flags; };
extern Ptr32<void> fn_801fe2a8(int, int);
Ptr32<void> w3d_s21_allocate_80209638(Ptr32<struct S21Allocator> self, int size, int alignment)
{
    Ptr32<void> result;
    if (self->flags & 16)
        result = fn_801fe2a8(size, alignment);
    else
        result = self->inner->allocate(self->inner, size, alignment);
    return result;
}

}
