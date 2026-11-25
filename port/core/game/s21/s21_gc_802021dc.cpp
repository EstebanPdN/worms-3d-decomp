#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_gc_802021dc.c"
// desc: Appears to read an array of 32-bit words from the inner stream and byte-swap each in place, stopping on a negative status, or skip the bytes when no buffer is given, returning zero on success.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> read; Ptr32<void (void)> reserved1; Ptr32<int (Ptr32<struct S21Stream>, int, int, int)> skip; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Reader { char pad[20]; Ptr32<struct S21Stream> stream; };
int w3d_s21_read_u32_array_checked_802021dc(Ptr32<struct S21Reader> self, Ptr32<unsigned int> out, unsigned count)
{
    int status;
    unsigned i;
    if (out == 0)
        return self->stream->methods->skip(self->stream, count << 2, 1, 0);
    status = self->stream->methods->read(self->stream, out, count << 2, 0);
    if (status < 0)
        return status;
    i = 0;
    if (i < count) {
        do {
            unsigned value = *out;
            i++;
            *out = value;
            out++;
        } while (i < count);
    }
    return 0;
}

}
