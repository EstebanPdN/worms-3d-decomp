#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cu_80218774.c"
// desc: Appears to assign a shared string pointer from the third argument into the field at offset 24, adjusting reference counts and releasing the old header at zero.
struct S21Object { char pad[24]; Ptr32<char> text; };
extern void fn_8020bb2c(Ptr32<void>);
void w3d_s21_assign_text_80218774(Ptr32<struct S21Object> self, int unused, Ptr32<Ptr32<char>> source)
{
    Ptr32<unsigned short> incoming = (Ptr32<unsigned short>)(*source - 6);
    ++*incoming;
    {
        Ptr32<unsigned short> old = (Ptr32<unsigned short>)(self->text - 6);
        unsigned short remaining = --*old;
        if (remaining == 0)
            fn_8020bb2c(old);
    }
    self->text = *source;
}

}
