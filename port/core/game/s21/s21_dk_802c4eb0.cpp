#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dk_802c4eb0.c"
// desc: Appears to assign a shared string pointer from the argument into the field at offset 260, adjusting reference counts, then destroy the source string object.
struct S21Text { Ptr32<char> data; };
struct S21Object { char pad[260]; Ptr32<char> text; };
extern void fn_8020bb2c(Ptr32<void>);
extern void fn_8020c5c4(Ptr32<struct S21Text>);
extern void fn_80341588(Ptr32<struct S21Text>);
void w3d_s21_take_text_b_802c4eb0(Ptr32<struct S21Object> self, Ptr32<struct S21Text> source)
{
    Ptr32<unsigned short> incoming = (Ptr32<unsigned short>)(source->data - 6);
    ++*incoming;
    {
        Ptr32<unsigned short> old = (Ptr32<unsigned short>)(self->text - 6);
        unsigned short remaining = --*old;
        if (remaining == 0)
            fn_8020bb2c(old);
    }
    self->text = source->data;
    fn_8020c5c4(source);
    fn_80341588(source);
}

}
