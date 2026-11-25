#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dj_80211520.c"
// desc: Appears to assign a shared string pointer from the argument into the field at offset 32, adjusting reference counts and releasing the old header at zero, returning zero.
struct S21Object { char pad[32]; Ptr32<char> text; };
extern void fn_8020bb2c(Ptr32<void>);
int w3d_s21_set_text_80211520(Ptr32<struct S21Object> self, Ptr32<Ptr32<char>> source)
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
    return 0;
}

}
