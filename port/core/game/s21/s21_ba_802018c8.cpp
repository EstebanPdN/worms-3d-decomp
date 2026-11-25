#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ba_802018c8.c"
// desc: Appears to read single bytes from the inner stream into an array of booleans, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> read; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Reader { char pad[20]; Ptr32<struct S21Stream> stream; };
int w3d_s21_read_bools_802018c8(Ptr32<struct S21Reader> self, Ptr32<int> out, unsigned count)
{
    unsigned i = 0;
    while (i < count) {
        unsigned char value;
        int status = self->stream->methods->read(self->stream, &value, 1, 0);
        if (status < 0)
            return status;
        if (out)
            *out++ = value ? 1 : 0;
        i++;
    }
    return 0;
}

}
