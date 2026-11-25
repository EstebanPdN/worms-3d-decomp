#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ho_8020d82c.c"
// desc: Appears to write a length-prefixed text buffer through a virtual slot of its stream object with a trailing zero and return itself.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[6]; Ptr32<void (Ptr32<struct S21Stream>, Ptr32<char>, unsigned int, int)> write; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Writer { Ptr32<struct S21Stream> stream; };
Ptr32<struct S21Writer> w3d_s21_write_text_8020d82c(Ptr32<struct S21Writer> self, Ptr32<Ptr32<char>> text)
{
    Ptr32<char> data = *text;
    self->stream->methods->write(self->stream, data, *(Ptr32<unsigned short>)(data - 4), 0);
    return self;
}

}
