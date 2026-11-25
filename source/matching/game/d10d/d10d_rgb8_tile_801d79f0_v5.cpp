// RGB8 to GX RGBA8 4x4 tile conversion (0x801d79f0).
// Copies the block at (x, y) of a 24-bit RGB image (bytes r, g, b; pitch
// bytes per row) into one 64-byte tile: alpha/red pairs in the first 32
// bytes, green/blue pairs in the second 32, 8 bytes per row; alpha is 255.
// Edge blocks are clipped to the image; clipped texels keep their bytes.
// The pixel reader takes the source pixel size as an inline parameter: pixels
// without an alpha byte read 255. The parameter is folded only after RTL jump
// optimization, so the 255 stays a zero-extended register value as in the
// original.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_read_pixel(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    c.r = in[0];
    c.g = in[1];
    c.b = in[2];
    c.a = bytes > 3 ? in[3] : 255;
}

static inline void d10d_put_argb(unsigned char *ar, unsigned char *gb, const d10d_Rgba8 &c) {
    ar[0] = c.a;
    ar[1] = c.r;
    gb[0] = c.g;
    gb[1] = c.b;
}

extern "C" void d10d_rgb8_tile_801d79f0(const unsigned char *source, unsigned int pitch, unsigned int width,
                                        unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *ar = tile + row * 8;
        unsigned char *gb = tile + 32 + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 3;
            d10d_Rgba8 c;
            d10d_read_pixel(c, in, 3);
            d10d_put_argb(ar, gb, c);
            ar += 2;
            gb += 2;
        }
    }
}
