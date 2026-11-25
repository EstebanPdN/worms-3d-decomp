#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bf_8020e690.c"
// desc: Appears to copy each source word into consecutive destination words, as its sibling for a given count and return zero.
int w3d_s21_unpack_words_b_8020e690(Ptr32<unsigned char> src, int unused1, Ptr32<unsigned int> dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = *(Ptr32<unsigned int>)src;
        src += 4;
    }
    return 0;
}

}
