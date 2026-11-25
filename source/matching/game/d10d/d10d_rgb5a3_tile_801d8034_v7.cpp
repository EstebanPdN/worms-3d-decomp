// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), per-branch 16-bit texel trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_y00_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned short v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y00(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y00_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y01_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned short v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y01(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y01_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y02_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned short v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y02(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y02_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y03_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned short v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y03(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y03_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y04_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned short v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y04(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y04_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y05_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned short v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y05(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y05_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y06_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned short v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y06(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y06_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y07_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned short v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned short v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y07(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y07_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y08_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y08(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y08_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y09_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y09(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y09_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y10_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y10(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y10_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y11_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y11(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y11_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y12_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y12(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y12_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y13_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y13(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y13_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y14_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        unsigned int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y14(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y14_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y15_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        unsigned int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y15(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y15_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y16_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y16(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y16_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y17_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y17(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y17_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y18_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y18(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y18_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y19_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y19(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y19_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y20_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y20(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y20_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y21_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        int v = ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y21(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y21_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y22_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[1] = v;
        out[0] = v >> 8;
    } else {
        int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[1] = v;
        out[0] = v >> 8;
    }
}
extern "C" void d10d_y22(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y22_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_y23_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        int v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
        out[0] = v >> 8;
        out[1] = v;
    } else {
        int v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = v >> 8;
        out[1] = v;
    }
}
extern "C" void d10d_y23(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_y23_pack(out, c);
            out += 2;
        }
    }
}
