// 16-bit 1-5-5-5 pixels to RGB5A3 4x4 tile conversion (0x801d814c).
// Each source pixel occupies a 32-bit slot (pitch bytes per row); its first
// halfword holds three 5-bit channels (bits 0-4 to r, 5-9 to g, 10-14 to b,
// each widened by << 3) and a 1-bit alpha (bit 15, widened to 255 or 0).
// The expanded pixel is then packed like the RGBA8 converter at 0x801d8034:
// alpha above 223 gives an opaque texel (1, r5, g5, b5), otherwise a
// translucent one (0, a3, r4, g4, b4). Edge blocks are clipped to the image
// and clipped texels keep their bytes.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}

static inline void d10d_pack_rgb5a3(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_store_texel(out, ((0x20 | (c.r >> 3)) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_store_texel(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}

extern "C" void d10d_rgb5551_tile_801d814c(const unsigned char *source, unsigned int pitch, unsigned int width,
                                           unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            unsigned short v = *(const unsigned short *)in;
            c.r = (v & 0x1f) << 3;
            c.g = (v >> 5 & 0x1f) << 3;
            c.b = (v >> 10 & 0x1f) << 3;
            if (v >> 15) c.a = 255; else c.a = 0;
            d10d_pack_rgb5a3(out, c);
            out += 2;
        }
    }
}
