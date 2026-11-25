// 16-bit (1-5-5-5) pixels in 32-bit slots to RGB5A3 4x4 tile (0x801d814c), mask and store-order trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[1] = lo;
    out[0] = hi;
}
static inline void d10d_pack_rgb5a3(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_store_texel(out, ((0x20 | (c.r >> 3)) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_store_texel(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
static inline void d10d_store_texel0(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}
static inline void d10d_pack_rgb5a3_0(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_store_texel0(out, ((0x20 | (c.r >> 3)) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_store_texel0(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}

extern "C" void d10d_s2ms3(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            if (v >> 15) c.a = 255; else c.a = 0;
            d10d_pack_rgb5a3(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2ms0(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            if (v >> 15) c.a = 255; else c.a = 0;
            d10d_pack_rgb5a3_0(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2ns3(const unsigned char *source, unsigned int pitch, unsigned int width,
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

extern "C" void d10d_s2ns0(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pack_rgb5a3_0(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2os3(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            c.a = (v >> 15) ? 255 : 0;
            d10d_pack_rgb5a3(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2os0(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            c.a = (v >> 15) ? 255 : 0;
            d10d_pack_rgb5a3_0(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2mi3(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            unsigned int v = *(const unsigned short *)in;
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            if (v >> 15) c.a = 255; else c.a = 0;
            d10d_pack_rgb5a3(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2mi0(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            unsigned int v = *(const unsigned short *)in;
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            if (v >> 15) c.a = 255; else c.a = 0;
            d10d_pack_rgb5a3_0(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2ni3(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            unsigned int v = *(const unsigned short *)in;
            c.r = (v & 0x1f) << 3;
            c.g = (v >> 5 & 0x1f) << 3;
            c.b = (v >> 10 & 0x1f) << 3;
            if (v >> 15) c.a = 255; else c.a = 0;
            d10d_pack_rgb5a3(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2ni0(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            unsigned int v = *(const unsigned short *)in;
            c.r = (v & 0x1f) << 3;
            c.g = (v >> 5 & 0x1f) << 3;
            c.b = (v >> 10 & 0x1f) << 3;
            if (v >> 15) c.a = 255; else c.a = 0;
            d10d_pack_rgb5a3_0(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2oi3(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            unsigned int v = *(const unsigned short *)in;
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            c.a = (v >> 15) ? 255 : 0;
            d10d_pack_rgb5a3(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_s2oi0(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            unsigned int v = *(const unsigned short *)in;
            c.r = (v << 3) & 0xf8;
            c.g = (v >> 2) & 0xf8;
            c.b = (v >> 7) & 0xf8;
            c.a = (v >> 15) ? 255 : 0;
            d10d_pack_rgb5a3_0(out, c);
            out += 2;
        }
    }
}
