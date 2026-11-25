// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), expression-form trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_xt00_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xt00(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt00_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt01_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 5) << 4) | (c.r >> 4);
    }
}
extern "C" void d10d_xt01(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt01_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt02_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a & 0xe0) >> 1) | (c.r >> 4);
    }
}
extern "C" void d10d_xt02(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt02_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt03_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = (c.r >> 4) | ((c.a >> 1) & 0x70);
    }
}
extern "C" void d10d_xt03(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt03_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt04_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = (c.r >> 4) | ((c.a >> 5) << 4);
    }
}
extern "C" void d10d_xt04(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt04_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt05_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = (c.r >> 4) | ((c.a & 0xe0) >> 1);
    }
}
extern "C" void d10d_xt05(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt05_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt06_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.b >> 4) | (c.g & 0xf0);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xt06(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt06_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt07_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.b >> 4) | (c.g & 0xf0);
        out[0] = ((c.a >> 5) << 4) | (c.r >> 4);
    }
}
extern "C" void d10d_xt07(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt07_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt08_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.b >> 4) | (c.g & 0xf0);
        out[0] = ((c.a & 0xe0) >> 1) | (c.r >> 4);
    }
}
extern "C" void d10d_xt08(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt08_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt09_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.b >> 4) | (c.g & 0xf0);
        out[0] = (c.r >> 4) | ((c.a >> 1) & 0x70);
    }
}
extern "C" void d10d_xt09(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt09_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt10_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.b >> 4) | (c.g & 0xf0);
        out[0] = (c.r >> 4) | ((c.a >> 5) << 4);
    }
}
extern "C" void d10d_xt10(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt10_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt11_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.b >> 4) | (c.g & 0xf0);
        out[0] = (c.r >> 4) | ((c.a & 0xe0) >> 1);
    }
}
extern "C" void d10d_xt11(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt11_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt12_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
extern "C" void d10d_xt12(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt12_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt13_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = ((c.a >> 5) << 4) | (c.r >> 4);
    }
}
extern "C" void d10d_xt13(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt13_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt14_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = ((c.a & 0xe0) >> 1) | (c.r >> 4);
    }
}
extern "C" void d10d_xt14(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt14_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt15_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = (c.r >> 4) | ((c.a >> 1) & 0x70);
    }
}
extern "C" void d10d_xt15(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt15_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt16_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = (c.r >> 4) | ((c.a >> 5) << 4);
    }
}
extern "C" void d10d_xt16(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt16_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_xt17_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = ((c.g >> 4) << 4) | (c.b >> 4);
        out[0] = (c.r >> 4) | ((c.a & 0xe0) >> 1);
    }
}
extern "C" void d10d_xt17(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_xt17_pack(out, c);
            out += 2;
        }
    }
}
