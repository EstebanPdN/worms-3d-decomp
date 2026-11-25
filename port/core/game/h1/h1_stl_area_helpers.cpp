#include "w3d_ptr.h"
#line 1 "h1_stl_area_helpers.cpp"
/* Small helpers near the STL code (session b169b320): an empty variadic
 * trace stub, a COM-style setter that copies a 32-byte block and returns 0,
 * and a bit-array assign. The bit address is written as base + offset in
 * integer form: that operand order is what the original indexed loads use. */

struct W3dBlock32
{
    int words[8];
};
struct W3dBlockOwner
{
    unsigned char unknown_00[116];
    W3dBlock32 block;                 /* 0x74 */
};
struct W3dBitWords
{
    Ptr32<unsigned int> words;
};
extern "C" void w3d_trace_stub_80347324(int channel, Ptr32<const char> format, ...)
{
}

extern "C" int w3d_block_owner_set_80348764(Ptr32<W3dBlockOwner> self, Ptr32<const W3dBlock32> block)
{
    self->block = *block;
    return 0;
}

static inline void w3d_bits_assign_at(Ptr32<W3dBitWords> bits, unsigned int word, unsigned int bit, int value)
{
    if (value)
        *(Ptr32<unsigned int>)w3d::G(((unsigned int)w3d::H(bits->words) + (word << 2))) |= 1U << bit;
    else
        *(Ptr32<unsigned int>)w3d::G(((unsigned int)w3d::H(bits->words) + (word << 2))) &= ~(1U << bit);
}

extern "C" void w3d_bits_assign_8034bef8(Ptr32<W3dBitWords> self, unsigned int index, int value)
{
    w3d_bits_assign_at(self, index >> 5, index & 31, value);
}


