#include "w3d_ptr.h"
#line 1 "d10d_rgb565_tile_801d7ad0_v0.cpp"
// RGB8 to RGB565 4x4 tile conversion (0x801d7ad0).
// Converts the block at (x, y) of a 24-bit RGB image (bytes r, g, b; pitch
// bytes per row) into one big-endian RGB565 tile with 8-byte rows. Edge
// blocks are clipped to the image; clipped texels keep their bytes.
// The pixel reader takes the source pixel size as an inline parameter (alpha
// 255 without an alpha byte); the alpha is stored to the pixel local but not
// used by this format, as in the original.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_read_pixel(d10d_Rgba8 &c, Ptr32<const unsigned char> in, int bytes) {
    c.r = in[0];
    c.g = in[1];
    c.b = in[2];
    c.a = bytes > 3 ? in[3] : 255;
}

static inline void d10d_store_texel(Ptr32<unsigned char> out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}

extern "C" void d10d_rgb565_tile_801d7ad0(Ptr32<const unsigned char> source, unsigned int pitch, unsigned int width,
                                          unsigned int height, unsigned int x, unsigned int y, Ptr32<unsigned char> tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        Ptr32<unsigned char> out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            Ptr32<const unsigned char> in = source + pitch * (row + y) + (x + column) * 3;
            d10d_Rgba8 c;
            d10d_read_pixel(c, in, 3);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}


