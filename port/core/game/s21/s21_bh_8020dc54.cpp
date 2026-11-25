#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bh_8020dc54.c"
// desc: Appears to format an unsigned value as hexadecimal into a stack buffer, write the text through the writer's stream slot and return the writer.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[6]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<const char>, unsigned int, int)> write; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Writer { Ptr32<struct S21Stream> stream; };
extern const char lbl_803b3250[];
extern int fn_80355a44(Ptr32<char>, Ptr32<const char>, ...);
extern unsigned fn_802ef9c0(Ptr32<const char>);
Ptr32<struct S21Writer> w3d_s21_write_hex_8020dc54(Ptr32<struct S21Writer> self, unsigned value)
{
    char buffer[16];
    Ptr32<struct S21Stream> stream;
    Ptr32<struct S21StreamMethods> methods;
    Ptr32<char> text;
    fn_80355a44(buffer, lbl_803b3250, value);
    stream = self->stream;
    text = buffer;
    methods = stream->methods;
    methods->write(stream, text, fn_802ef9c0(text), 0);
    return self;
}

}
