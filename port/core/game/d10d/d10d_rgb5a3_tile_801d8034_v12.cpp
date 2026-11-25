#include "w3d_ptr.h"
#line 1 "d10d_rgb5a3_tile_801d8034_v12.cpp"
// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034).
// Converts the block at (x, y) of a 32-bit RGBA image (bytes r, g, b, a;
// pitch bytes per row) into one big-endian RGB5A3 tile (8 bytes per row).
// Edge blocks are clipped to the image; untouched texels keep their bytes.
// Alpha above 223 gives an opaque texel (1, r5, g5, b5); otherwise the
// texel is translucent (0, a3, r4, g4, b4).
// The pixel is copied to an addressable local and the two texel bytes pass
// through unsigned char parameters of the store helper, as in the original.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_store_texel(Ptr32<unsigned char> out, unsigned char hi, unsigned char lo) {
    out[1] = lo;
    out[0] = hi;
}

static inline void d10d_pack_rgb5a3(Ptr32<unsigned char> out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_store_texel(out, ((0x20 | (c.r >> 3)) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_store_texel(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}

extern "C" void d10d_rgb5a3_tile_801d8034(Ptr32<const unsigned char> source, unsigned int pitch, unsigned int width,
                                          unsigned int height, unsigned int x, unsigned int y, Ptr32<unsigned char> tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        Ptr32<unsigned char> out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            Ptr32<const unsigned char> in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_pack_rgb5a3(out, c);
            out += 2;
        }
    }
}


