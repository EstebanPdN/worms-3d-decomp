// RGB565 source to RGB565 4x4 tile (0x801d7c94, 0x801d7e20), reader trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}
static inline void d10d_read_565_p(d10d_Rgba8 &c, const unsigned char *in) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3;
    c.g = (v & 0x7e0) >> 2;
    c.b = (v & 0xf800) >> 8;
    c.a = 255;
}
static inline void d10d_read_565_pt(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3;
    c.g = (v & 0x7e0) >> 2;
    c.b = (v & 0xf800) >> 8;
    c.a = bytes > 3 ? in[3] : 255;
}
static inline void d10d_read_565_v(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3;
    c.g = (v & 0x7e0) >> 2;
    c.b = (v & 0xf800) >> 8;
    c.a = 255;
}

extern "C" void d10d_nAp1(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_565_p(c, in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nAp2(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_565_p(c, in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_nAq1(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_565_pt(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nAq2(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_565_pt(c, in, 2);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_nAv1(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_565_v(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nAv2(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_read_565_v(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_nAw1(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            c.r = (v & 0x1f) << 3;
            c.g = (v & 0x7e0) >> 2;
            c.b = (v & 0xf800) >> 8;
            c.a = 255;
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nAw2(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            c.r = (v & 0x1f) << 3;
            c.g = (v & 0x7e0) >> 2;
            c.b = (v & 0xf800) >> 8;
            c.a = 255;
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_nBp1(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            d10d_read_565_p(c, in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nBp2(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            d10d_read_565_p(c, in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_nBq1(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            d10d_read_565_pt(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nBq2(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            d10d_read_565_pt(c, in, 2);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_nBv1(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            d10d_read_565_v(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nBv2(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            d10d_read_565_v(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

extern "C" void d10d_nBw1(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            unsigned short v = *(const unsigned short *)in;
            c.r = (v & 0x1f) << 3;
            c.g = (v & 0x7e0) >> 2;
            c.b = (v & 0xf800) >> 8;
            c.a = 255;
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

extern "C" void d10d_nBw2(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * sizeof(unsigned short);
            d10d_Rgba8 c;
            unsigned short v = *(const unsigned short *)in;
            c.r = (v & 0x1f) << 3;
            c.g = (v & 0x7e0) >> 2;
            c.b = (v & 0xf800) >> 8;
            c.a = 255;
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}
