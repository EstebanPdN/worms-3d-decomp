#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_be_8020e560.c"
// desc: Appears to copy the last byte of each source word into consecutive destination bytes for a given count and return zero.
int w3d_s21_unpack_bytes_8020e560(Ptr32<unsigned char> src, int unused1, Ptr32<unsigned char> dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = src[3];
        src += 4;
    }
    return 0;
}

}
