#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bi_8020dd44.c"
// desc: Appears to format a double with width and precision taken from the writer's format bits into a stack buffer, write it through the stream slot and return the writer.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[6]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<const char>, unsigned int, int)> write; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Writer { Ptr32<struct S21Stream> stream; unsigned format; };
extern const char lbl_803b3258[];
extern int fn_8035cb74(Ptr32<char>, Ptr32<const char>, ...);
extern unsigned fn_802ef9c0(Ptr32<const char>);
Ptr32<struct S21Writer> w3d_s21_write_double_8020dd44(Ptr32<struct S21Writer> self, double value)
{
    char buffer[64];
    Ptr32<struct S21Stream> stream;
    Ptr32<struct S21StreamMethods> methods;
    Ptr32<char> text;
    fn_8035cb74(buffer, lbl_803b3258, *(Ptr32<unsigned char>)((Ptr32<char>)self + 5), (self->format >> 11) & 31, value);
    stream = self->stream;
    text = buffer;
    methods = stream->methods;
    methods->write(stream, text, fn_802ef9c0(text), 0);
    return self;
}

}
