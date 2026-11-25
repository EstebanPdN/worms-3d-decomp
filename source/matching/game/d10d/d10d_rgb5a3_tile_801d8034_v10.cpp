// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), byte-parameter operand-order trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_put_hl(unsigned char *out, unsigned char hi, unsigned char lo) { out[1] = lo; out[0] = hi; }
static inline void d10d_put_lh(unsigned char *out, unsigned char lo, unsigned char hi) { out[1] = lo; out[0] = hi; }
static inline void d10d_put_hl2(unsigned char *out, unsigned char hi, unsigned char lo) { out[0] = hi; out[1] = lo; }
static inline void d10d_put_s(unsigned char *out, unsigned short v) { out[1] = v; out[0] = v >> 8; }

static inline void d10d_q00_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q00(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q00_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q01_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q01(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q01_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q02_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q02(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q02_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q03_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q03(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q03_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q04_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q04(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q04_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q05_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q05(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q05_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q06_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q06(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q06_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q07_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q07(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q07_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q08_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q08(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q08_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q09_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q09(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q09_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q10_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q10(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q10_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q11_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q11(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q11_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q12_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q12(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q12_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q13_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q13(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q13_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q14_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q14(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q14_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q15_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q15(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q15_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q16_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q16(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q16_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q17_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q17(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q17_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q18_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q18(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q18_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q19_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q19(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q19_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q20_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q20(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q20_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q21_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q21(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q21_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q22_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q22(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q22_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q23_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q23(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q23_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q24_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q24(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q24_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q25_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q25(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q25_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q26_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q26(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q26_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q27_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q27(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q27_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q28_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q28(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q28_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q29_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q29(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q29_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q30_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q30(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q30_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q31_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q31(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q31_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q32_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q32(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q32_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q33_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q33(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q33_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q34_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q34(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q34_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q35_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q35(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q35_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q36_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q36(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q36_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q37_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q37(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q37_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q38_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q38(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q38_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q39_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q39(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q39_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q40_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q40(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q40_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q41_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q41(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q41_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q42_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q42(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q42_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q43_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q43(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q43_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q44_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q44(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q44_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q45_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1), (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q45(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q45_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q46_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80, ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q46(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q46_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_q47_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80, (c.b >> 3) | ((c.g << 2) & 0xe0));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_q47(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c;
            c.r = in[0]; c.g = in[1]; c.b = in[2]; c.a = in[3];
            d10d_q47_pack(out, c);
            out += 2;
        }
    }
}
