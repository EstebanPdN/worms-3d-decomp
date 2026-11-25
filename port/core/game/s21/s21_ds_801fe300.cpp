#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ds_801fe300.c"
// desc: Appears to clear the top two bits of the word the pointer refers to and return the pointer.
Ptr32<unsigned int> w3d_s21_clear_top_bits_801fe300(Ptr32<unsigned int> word)
{
    *word &= 0x3fffffff;
    return word;
}

}
