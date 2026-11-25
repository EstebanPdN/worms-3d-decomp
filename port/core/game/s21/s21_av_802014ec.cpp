#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_av_802014ec.c"
// desc: Appears to read four bytes from the inner stream into a stack word, byte-swap it and store it through the output pointer.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> read; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Reader { char pad[20]; Ptr32<struct S21Stream> stream; };
void w3d_s21_read_u32_swapped_802014ec(Ptr32<struct S21Reader> self, Ptr32<unsigned int> out)
{
  unsigned value;
  self->stream->methods->read(self->stream, &value, 4, 0);
 do { *out = value; } while (0);
}

}
