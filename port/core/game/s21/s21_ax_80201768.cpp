#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ax_80201768.c"
// desc: Appears to read four bytes from the inner stream directly into the output word and store its byte-swapped value. Same bytes as its sibling.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> read; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Reader { char pad[20]; Ptr32<struct S21Stream> stream; };
void w3d_s21_read_u32_direct_b_80201768(Ptr32<struct S21Reader> self, Ptr32<unsigned int> out)
{
  unsigned value;
  Ptr32<unsigned int> new_var;
  self->stream->methods->read(self->stream, out, 4, 0);
 do { new_var = out; value = *new_var; *out = value; } while (0);
}

}
