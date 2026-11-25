#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_au_80201438.c"
// desc: Appears to read two bytes from the inner stream into a stack halfword, byte-swap it and store it through the output pointer.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> read; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Reader { char pad[20]; Ptr32<struct S21Stream> stream; };
void w3d_s21_read_u16_swapped_80201438(Ptr32<struct S21Reader> self, Ptr32<unsigned short> out)
{
    unsigned short value;
    self->stream->methods->read(self->stream, &value, 2, 0);
    *out = value;
}

}
