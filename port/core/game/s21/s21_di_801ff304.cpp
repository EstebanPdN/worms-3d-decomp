#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_di_801ff304.c"
// desc: Appears to assign a shared string pointer through the output pointer from the source pointer, adjusting reference counts and releasing the old header at zero, returning zero.
extern void fn_8020bb2c(Ptr32<void>);
int w3d_s21_assign_text_801ff304(Ptr32<void> self, Ptr32<Ptr32<char>> dest, Ptr32<Ptr32<char>> source)
{
    Ptr32<unsigned short> incoming = (Ptr32<unsigned short>)(*source - 6);
    ++*incoming;
    {
        Ptr32<unsigned short> old = (Ptr32<unsigned short>)(*dest - 6);
        unsigned short remaining = --*old;
        if (remaining == 0)
            fn_8020bb2c(old);
    }
    *dest = *source;
    return 0;
}

}
