#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bg_8020dbf8.c"
// desc: Appears to write a C string through the writer's stream slot using its length and return the writer.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[6]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<const char>, unsigned int, int)> write; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Writer { Ptr32<struct S21Stream> stream; };
extern unsigned fn_802ef9c0(Ptr32<const char>);
Ptr32<struct S21Writer> w3d_s21_write_text_8020dbf8(Ptr32<struct S21Writer> self, Ptr32<const char> text)
{
    unsigned length = fn_802ef9c0(text);
    Ptr32<struct S21Stream> stream = self->stream;
    stream->methods->write(stream, text, length, 0);
    return self;
}

}
