#include "w3d_ptr.h"
#line 1 "s21_dl_8021140c.cpp"
// desc: Appears to build and discard a temporary copy of a shared string, then assign the string pointer into the field at offset 28 with reference-count adjustment, returning zero.
struct S21Text;
extern void fn_8020c5c0(Ptr32<S21Text>);
extern Ptr32<unsigned short> fn_80341884(Ptr32<S21Text>);
extern void fn_8020c5c4(Ptr32<S21Text>);
extern void fn_80341588(Ptr32<S21Text>);
extern void fn_8020bb2c(Ptr32<void>);
struct S21Text {
    Ptr32<char> data;
    S21Text(const S21Text &other) { fn_8020c5c0(this); data = other.data; ++*fn_80341884(this); }
    ~S21Text() { fn_8020c5c4(this); fn_80341588(this); }
};
struct S21Object { char pad[28]; Ptr32<char> text; };
extern "C" int w3d_s21_set_text_checked_8021140c(Ptr32<S21Object> self, Ptr32<S21Text> source)
{
    {
        S21Text temporary(*source);
    }
    Ptr32<unsigned short> incoming = (Ptr32<unsigned short>)(source->data - 6);
    ++*incoming;
    {
        Ptr32<unsigned short> old = (Ptr32<unsigned short>)(self->text - 6);
        unsigned short remaining = --*old;
        if (remaining == 0)
            fn_8020bb2c(old);
    }
    self->text = source->data;
    return 0;
}


