// RGBA8 to GX RGBA8 4x4 tile conversion (0x801d7914).
// Copies the block at (x, y) of a 32-bit RGBA image (bytes r, g, b, a;
// pitch bytes per row) into one 64-byte tile: the first 32 bytes hold the
// alpha/red pairs and the second 32 bytes the green/blue pairs, 8 bytes per
// row. Edge blocks are clipped to the image; clipped texels keep their bytes.
// The pixel is copied to an addressable local first, as in the original.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_put_argb(unsigned char *ar, unsigned char *gb, const d10d_Rgba8 &c) {
    ar[0] = c.a;
    ar[1] = c.r;
    gb[0] = c.g;
    gb[1] = c.b;
}

extern "C" void d10d_rgba8_tile_801d7914(const unsigned char *source, unsigned int pitch, unsigned int width,
                                         unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *ar = tile + row * 8;
        unsigned char *gb = tile + 32 + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_put_argb(ar, gb, c);
            ar += 2;
            gb += 2;
        }
    }
}
