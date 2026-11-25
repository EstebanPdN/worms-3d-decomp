// RGB565 source to RGB565 4x4 tile (0x801d7c94, 0x801d7e20), mask trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}
static inline void d10d_read_565_t(d10d_Rgba8 &c, unsigned int v, int bytes) {
    c.r = (v & 0x1f) << 3;
    c.g = (v & 0x7e0) >> 2;
    c.b = (v & 0xf800) >> 8;
    c.a = bytes > 3 ? 0 : 255;
}
static inline void d10d_read_565_o(d10d_Rgba8 &c, unsigned int v, int opaque) {
    c.r = (v & 0x1f) << 3;
    c.g = (v & 0x7e0) >> 2;
    c.b = (v & 0xf800) >> 8;
    c.a = opaque ? 255 : 0;
}
static inline void d10d_read_565_a(d10d_Rgba8 &c, unsigned int v) {
    c.r = (v & 0x1f) << 3;
    c.g = (v & 0x7e0) >> 2;
    c.b = (v & 0xf800) >> 8;
    c.a = 255;
}

extern "C" void d10d_ets(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            unsigned short v = *(const unsigned short *)in;
            d10d_read_565_t(c, v, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_eos(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            unsigned short v = *(const unsigned short *)in;
            d10d_read_565_o(c, v, 1);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_eas(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            unsigned short v = *(const unsigned short *)in;
            d10d_read_565_a(c, v);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_eti(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            unsigned int v = *(const unsigned short *)in;
            d10d_read_565_t(c, v, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_eoi(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            unsigned int v = *(const unsigned short *)in;
            d10d_read_565_o(c, v, 1);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_eai(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            unsigned int v = *(const unsigned short *)in;
            d10d_read_565_a(c, v);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}
