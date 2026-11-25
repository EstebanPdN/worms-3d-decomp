#include "w3d_ptr.h"
#line 1 "d26e_tile_16_to_565_b_801d7e20.cpp"
// (Worms 3D GameCube PAL, 0x801d7e20).
//
// Second copy of the 16-bit to RGB565 tile conversion at 0x801d7c94, with
// identical instructions: converts the block at (ox, oy) into one big-endian
// RGB565 4x4 tile with 8-byte rows. Why two copies exist is not known; they
// may be two format entries of one converter table.

struct Colour { unsigned char r, g, b, a; };
inline void Decode(Colour &c, Ptr32<const unsigned char> in) {
    unsigned short p = *(Ptr32<const unsigned short>)in;
    c.r = (p & 0x1f) << 3;
    c.g = (p & 0x7e0) >> 2;
    c.b = (p >> 11) << 3;
    c.a = 255;
}
inline void Encode(Ptr32<unsigned char> o, const Colour &c) { o[0] = (c.r & 0xf8) | (c.g >> 5); o[1] = ((c.g & 0x1c) << 3) | (c.b >> 3); }
extern "C" void w3d_d26e_tile_16_to_565_b_801d7e20(Ptr32<const unsigned char> src, unsigned stride, unsigned width, unsigned height, unsigned ox, unsigned oy, Ptr32<unsigned char> dst) {
    unsigned rows = height - oy;
    width -= ox;
    if (rows > 4) rows = 4;
    if (width > 4) width = 4;
    for (unsigned y = 0; y < rows; ++y) {
        Ptr32<unsigned char> o = dst + y * 8;
        for (unsigned x = 0; x < width; ++x) {
            Ptr32<const unsigned char> in = src + stride * (y + oy) + (ox + x) * 2;
            Colour c;
            Decode(c, in);
            Encode(o, c);
            o += 2;
        }
    }
}


