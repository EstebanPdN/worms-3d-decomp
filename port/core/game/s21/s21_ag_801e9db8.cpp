#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ag_801e9db8.c"
// desc: Appears to return the pointer at an index of a pointer vector, or zero when the index is out of range.
struct S21Vector { char pad[60]; Ptr32<int> begin; Ptr32<int> end; };
int w3d_s21_vector_get_801e9db8(Ptr32<struct S21Vector> self, unsigned index)
{
    if (index >= (unsigned)(self->end - self->begin))
        return 0;
    return *(Ptr32<int>)((Ptr32<char>)self->begin + (index << 2));
}

}
