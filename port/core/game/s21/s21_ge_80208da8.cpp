#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ge_80208da8.c"
// desc: Appears to append bytes to a memory stream: it grows the stream through virtual slot 8 when the end passes the size, copies the data at the current position, advances the position and reports the count.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[8]; Ptr32<int (Ptr32<struct S21Stream>, unsigned int)> reserve; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; char pad[16]; Ptr32<char> buffer; int pad1; unsigned position; unsigned size; };
extern Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned);
int w3d_s21_write_bytes_80208da8(Ptr32<struct S21Stream> self, Ptr32<const void> data, unsigned count, Ptr32<unsigned int> written)
{
    if (self->position + count > self->size)
        self->methods->reserve(self, self->position + count);
    fn_802eee50(self->buffer + self->position, data, count);
    self->position += count;
    if (written)
        *written = count;
    return 0;
}

}
