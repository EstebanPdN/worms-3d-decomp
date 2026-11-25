// RGB8 source tile conversions (0x801d79f0, 0x801d7ad0), byte-count reader trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_put_argb(unsigned char *ar, unsigned char *gb, const d10d_Rgba8 &c) {
    ar[0] = c.a; ar[1] = c.r; gb[0] = c.g; gb[1] = c.b;
}
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi; out[1] = lo;
}
static inline void d10d_store_texel1(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[1] = lo; out[0] = hi;
}
static inline void d10d_set_rgba(d10d_Rgba8 &c, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    c.r = r; c.g = g; c.b = b; c.a = a;
}

static inline void d10d_read_rgb8_i(d10d_Rgba8 &c, const unsigned char *in, int alpha) {
    c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = alpha;
}
static inline void d10d_read_rgb8_u(d10d_Rgba8 &c, const unsigned char *in, unsigned int alpha) {
    c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = alpha;
}
static inline void d10d_read_t(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = bytes > 3 ? in[3] : 255;
}
static inline void d10d_read_u(d10d_Rgba8 &c, const unsigned char *in, unsigned int bytes) {
    c.r = in[0]; c.g = in[1]; c.b = in[2];
    if (bytes == 4) c.a = in[3]; else c.a = 255;
}

extern "C" void d10d_j1iT(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_t(c, in, 3);
            d10d_put_argb(ar, gb, c);
            ar += 2;
            gb += 2;
        }
    }
}

extern "C" void d10d_j1iU(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_u(c, in, 3);
            d10d_put_argb(ar, gb, c);
            ar += 2;
            gb += 2;
        }
    }
}

extern "C" void d10d_k1laiT(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 3;
            d10d_Rgba8 c;
            d10d_read_t(c, in, 3);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_k1laiU(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 3;
            d10d_Rgba8 c;
            d10d_read_u(c, in, 3);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_j1i4(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_t(c, in, 4);
            d10d_put_argb(ar, gb, c);
            ar += 2;
            gb += 2;
        }
    }
}
