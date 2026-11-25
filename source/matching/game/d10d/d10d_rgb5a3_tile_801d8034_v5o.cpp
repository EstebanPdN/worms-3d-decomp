// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), expression-form trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_xo00_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo00(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo00_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo01_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo01(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo01_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo02_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo02(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo02_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo03_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo03(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo03_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo04_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo04(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo04_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo05_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo05(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo05_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo06_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo06(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo06_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo07_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo07(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo07_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo08_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo08(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo08_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo09_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo09(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo09_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo10_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo10(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo10_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo11_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo11(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo11_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo12_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 3) << 2) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo12(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo12_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo13_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo13(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo13_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo14_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = ((c.r >> 3) << 2) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo14(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo14_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo15_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = ((c.r >> 3) << 2) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo15(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo15_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo16_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo16(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo16_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo17_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r >> 3) << 2) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo17(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo17_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo18_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo18(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo18_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo19_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo19(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo19_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo20_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo20(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo20_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo21_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo21(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo21_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo22_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo22(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo22_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo23_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo23(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo23_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo24_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo24(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo24_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo25_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo25(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo25_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo26_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo26(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo26_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo27_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo27(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo27_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo28_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo28(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo28_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo29_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo29(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo29_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo30_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 3) << 2) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo30(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo30_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo31_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo31(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo31_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo32_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = ((c.r >> 3) << 2) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo32(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo32_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo33_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = ((c.r >> 3) << 2) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo33(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo33_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo34_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo34(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo34_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo35_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g & 0x38) << 2) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r >> 3) << 2) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo35(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo35_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo36_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo36(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo36_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo37_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo37(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo37_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo38_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo38(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo38_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo39_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo39(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo39_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo40_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo40(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo40_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo41_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo41(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo41_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo42_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo42(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo42_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo43_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo43(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo43_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo44_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo44(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo44_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo45_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo45(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo45_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo46_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo46(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo46_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo47_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo47(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo47_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo48_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 3) << 2) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo48(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo48_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo49_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo49(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo49_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo50_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = ((c.r >> 3) << 2) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo50(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo50_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo51_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = ((c.r >> 3) << 2) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo51(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo51_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo52_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo52(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo52_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo53_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = (c.g >> 6) | ((c.r >> 3) << 2) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo53(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo53_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo54_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo54(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo54_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo55_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo55(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo55_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo56_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo56(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo56_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo57_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo57(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo57_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo58_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo58(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo58_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo59_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo59(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo59_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo60_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo60(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo60_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo61_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo61(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo61_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo62_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo62(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo62_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo63_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo63(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo63_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo64_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo64(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo64_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo65_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo65(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo65_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo66_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = 0x80 | ((c.r >> 3) << 2) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo66(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo66_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo67_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo67(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo67_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo68_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = ((c.r >> 3) << 2) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo68(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo68_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo69_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = ((c.r >> 3) << 2) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo69(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo69_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo70_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo70(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo70_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo71_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g << 2) & 0xe0);
        out[0] = (c.g >> 6) | ((c.r >> 3) << 2) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo71(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo71_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo72_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo72(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo72_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo73_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo73(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo73_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo74_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo74(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo74_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo75_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo75(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo75_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo76_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo76(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo76_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo77_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo77(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo77_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo78_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo78(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo78_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo79_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo79(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo79_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo80_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo80(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo80_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo81_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo81(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo81_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo82_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo82(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo82_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo83_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo83(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo83_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo84_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = 0x80 | ((c.r >> 3) << 2) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo84(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo84_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo85_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo85(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo85_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo86_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = ((c.r >> 3) << 2) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo86(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo86_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo87_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = ((c.r >> 3) << 2) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo87(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo87_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo88_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo88(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo88_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo89_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g & 0x38) << 2);
        out[0] = (c.g >> 6) | ((c.r >> 3) << 2) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo89(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo89_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo90_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo90(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo90_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo91_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo91(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo91_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo92_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo92(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo92_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo93_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = ((c.r >> 1) & 0x7c) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo93(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo93_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo94_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 1) & 0x7c);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo94(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo94_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo95_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = (c.g >> 6) | ((c.r >> 1) & 0x7c) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo95(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo95_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo96_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = 0x80 | ((c.r & 0xf8) >> 1) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo96(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo96_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo97_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = 0x80 | (c.g >> 6) | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo97(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo97_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo98_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = ((c.r & 0xf8) >> 1) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo98(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo98_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo99_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = ((c.r & 0xf8) >> 1) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo99(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo99_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo100_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = (c.g >> 6) | 0x80 | ((c.r & 0xf8) >> 1);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo100(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo100_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo101_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = (c.g >> 6) | ((c.r & 0xf8) >> 1) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo101(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo101_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo102_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = 0x80 | ((c.r >> 3) << 2) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo102(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo102_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo103_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = 0x80 | (c.g >> 6) | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo103(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo103_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo104_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = ((c.r >> 3) << 2) | 0x80 | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo104(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo104_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo105_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = ((c.r >> 3) << 2) | (c.g >> 6) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo105(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo105_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo106_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = (c.g >> 6) | 0x80 | ((c.r >> 3) << 2);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo106(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo106_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xo107_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = (c.b >> 3) | ((c.g >> 3) << 5);
        out[0] = (c.g >> 6) | ((c.r >> 3) << 2) | 0x80;
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xo107(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xo107_pack(out, c);
            out += 2;
        }
    }
}
