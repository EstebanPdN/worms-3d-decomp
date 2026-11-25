#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bf_8020e600.c"
// desc: Appears to copy the low halfword of each source word into consecutive destination halfwords for a given count and return zero.
int w3d_s21_unpack_halves_8020e600(Ptr32<unsigned char> src, int unused1, Ptr32<unsigned short> dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = *(Ptr32<unsigned short>)(src + 2);
        src += 4;
    }
    return 0;
}

}
