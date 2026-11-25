// RGB565 source to RGB565 4x4 tile (0x801d7c94, 0x801d7e20), channel and pack order trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}
static inline void d10d_store_texel1(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[1] = lo;
    out[0] = hi;
}

static inline void d10d_prbga0_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga0(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga0_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbga1_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga1(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga1_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbga2_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga2(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga2_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prbga3_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga3(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga3_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prbga4_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga4(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga4_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbga5_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga5(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga5_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbga6_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga6(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga6_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prbga7_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_prbga7(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbga7_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prbag8_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag8(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag8_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbag9_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag9(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag9_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbag10_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag10(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag10_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prbag11_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag11(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag11_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prbag12_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag12(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag12_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbag13_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag13(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag13_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prbag14_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag14(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag14_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prbag15_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_prbag15(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prbag15_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbrga16_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga16(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga16_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbrga17_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga17(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga17_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbrga18_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga18(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga18_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbrga19_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga19(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga19_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbrga20_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga20(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga20_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbrga21_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga21(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga21_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbrga22_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga22(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga22_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbrga23_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_pbrga23(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbrga23_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prgba24_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba24(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba24_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prgba25_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba25(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba25_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prgba26_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba26(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba26_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prgba27_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba27(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba27_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prgba28_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba28(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba28_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prgba29_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba29(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba29_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_prgba30_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba30(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba30_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_prgba31_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_prgba31(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_prgba31_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbgra32_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra32(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra32_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbgra33_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra33(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra33_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbgra34_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra34(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra34_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbgra35_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra35(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra35_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.r & 0xf8) | (c.g >> 5), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbgra36_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra36(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra36_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbgra37_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra37(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra37_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_pbgra38_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra38(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra38_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}

static inline void d10d_pbgra39_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_pbgra39(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_pbgra39_read(c, *(const unsigned short *)in);
            d10d_store_texel1(out, (c.g >> 5) | (c.r & 0xf8), (c.b >> 3) | ((c.g << 3) & 0xe0));
            out += 2;
        }
    }
}
