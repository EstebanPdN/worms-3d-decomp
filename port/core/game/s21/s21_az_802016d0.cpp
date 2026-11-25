#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_az_802016d0.c"
// desc: Appears to read a sixteen-byte identifier from the inner stream and byte-swap its leading word and two halfwords when the read succeeds, returning the status.
struct S21Stream;
struct S21StreamMethods { Ptr32<void (void)> reserved[5]; Ptr32<int (Ptr32<struct S21Stream>, Ptr32<void>, int, int)> read; };
struct S21Stream { Ptr32<struct S21StreamMethods> methods; };
struct S21Reader { char pad[20]; Ptr32<struct S21Stream> stream; };
struct S21Guid { unsigned data1; unsigned short data2; unsigned short data3; unsigned char data4[8]; };
int w3d_s21_read_guid_802016d0(Ptr32<struct S21Reader> self, Ptr32<struct S21Guid> guid)
{
    int status = self->stream->methods->read(self->stream, guid, 16, 0);
    if (status >= 0) {
        unsigned a = guid->data1;
        unsigned short b = guid->data2;
        unsigned short c = guid->data3;
        guid->data1 = a;
        guid->data2 = b;
        guid->data3 = c;
    }
    return status;
}

}
