// RGB8 source tile conversions (0x801d79f0, 0x801d7ad0), integer alpha-parameter trials.
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
extern "C" void d10d_j1i(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_i(c, in, 255);
            d10d_put_argb(ar, gb, c);
            ar += 2;
            gb += 2;
        }
    }
}

extern "C" void d10d_j1u(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_u(c, in, 255);
            d10d_put_argb(ar, gb, c);
            ar += 2;
            gb += 2;
        }
    }
}

extern "C" void d10d_k1lai(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_i(c, in, 255);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_k1lau(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_u(c, in, 255);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_k1lbi(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_i(c, in, 255);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_k1lbu(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_u(c, in, 255);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_k11ai(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_i(c, in, 255);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_k11au(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_u(c, in, 255);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_k11bi(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_i(c, in, 255);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_k11bu(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_rgb8_u(c, in, 255);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}
