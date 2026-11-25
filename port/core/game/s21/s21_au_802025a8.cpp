#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_au_802025a8.c"
// desc: Appears to forward two arguments to the read slot of the inner stream with a trailing zero and return its result.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> read; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Reader { char pad[20]; Ptr32<struct S21Stream> stream; };
int w3d_s21_read_forward_802025a8(Ptr32<struct S21Reader> self, Ptr32<void> buffer, int size)
{
    return self->stream->methods->read(self->stream, buffer, size, 0);
}

}
