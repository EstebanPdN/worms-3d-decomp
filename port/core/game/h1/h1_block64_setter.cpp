#include "w3d_ptr.h"
#line 1 "h1_block64_setter.cpp"
/* COM-style setter that copies a 64-byte block into its owner, marks it
 * as set and returns 0 (session b169b320). */

struct W3dBlock64
{
    int words[16];
};
struct W3dBlock64Owner
{
    unsigned char unknown_00[44];
    W3dBlock64 block;                 /* 0x2c */
    int block_set;                    /* 0x6c */
};

extern "C" int w3d_block64_owner_set_8034bbdc(Ptr32<W3dBlock64Owner> self, Ptr32<const W3dBlock64> block)
{
    self->block = *block;
    self->block_set = 1;
    return 0;
}


