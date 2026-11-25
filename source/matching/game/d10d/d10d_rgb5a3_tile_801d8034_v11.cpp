// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), channel-local trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_put_hl(unsigned char *out, unsigned char hi, unsigned char lo) { out[1] = lo; out[0] = hi; }
static inline void d10d_put_lh(unsigned char *out, unsigned char lo, unsigned char hi) { out[1] = lo; out[0] = hi; }
static inline void d10d_put_hl2(unsigned char *out, unsigned char hi, unsigned char lo) { out[0] = hi; out[1] = lo; }
static inline void d10d_put_s(unsigned char *out, unsigned short v) { out[1] = v; out[0] = v >> 8; }

static inline void d10d_r00_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned char hi = 0x80 | ((c.r >> 1) & 0x7c);
        d10d_put_hl(out, hi | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r00(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r00_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r01_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int hi = 0x80 | ((c.r >> 1) & 0x7c);
        d10d_put_hl(out, hi | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r01(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r01_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r02_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned char r5 = c.r >> 3, g5 = c.g >> 3, b5 = c.b >> 3;
        d10d_put_hl(out, 0x80 | (r5 << 2) | (g5 >> 3), (g5 << 5) | b5);
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r02(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r02_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r03_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned char r5 = c.r >> 3, g5 = c.g >> 3, b5 = c.b >> 3;
        d10d_put_hl(out, (r5 << 2) | 0x80 | (g5 >> 3), (g5 << 5) | b5);
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r03(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r03_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r04_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int r5 = c.r >> 3, g5 = c.g >> 3, b5 = c.b >> 3;
        d10d_put_hl(out, 0x80 | (r5 << 2) | (g5 >> 3), (g5 << 5) | b5);
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r04(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r04_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r05_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl(out, ((0x20 | (c.r >> 3)) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r05(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r05_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r06_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl(out, (((c.r >> 3) | 0x20) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r06(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r06_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r07_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl(out, ((0x8000 | ((c.r & 0xf8) << 7)) >> 8) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r07(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r07_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r08_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl(out, (0x80 | ((c.r >> 1) & 0x7c)) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r08(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r08_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r09_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned char hi = 0x80 | ((c.r >> 1) & 0x7c);
        d10d_put_hl2(out, hi | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r09(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r09_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r10_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int hi = 0x80 | ((c.r >> 1) & 0x7c);
        d10d_put_hl2(out, hi | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r10(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r10_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r11_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned char r5 = c.r >> 3, g5 = c.g >> 3, b5 = c.b >> 3;
        d10d_put_hl2(out, 0x80 | (r5 << 2) | (g5 >> 3), (g5 << 5) | b5);
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r11(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r11_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r12_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned char r5 = c.r >> 3, g5 = c.g >> 3, b5 = c.b >> 3;
        d10d_put_hl2(out, (r5 << 2) | 0x80 | (g5 >> 3), (g5 << 5) | b5);
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r12(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r12_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r13_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        unsigned int r5 = c.r >> 3, g5 = c.g >> 3, b5 = c.b >> 3;
        d10d_put_hl2(out, 0x80 | (r5 << 2) | (g5 >> 3), (g5 << 5) | b5);
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r13(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r13_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r14_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl2(out, ((0x20 | (c.r >> 3)) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r14(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r14_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r15_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl2(out, (((c.r >> 3) | 0x20) << 2) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r15(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r15_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r16_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl2(out, ((0x8000 | ((c.r & 0xf8) << 7)) >> 8) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r16(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r16_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_r17_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        
        d10d_put_hl2(out, (0x80 | ((c.r >> 1) & 0x7c)) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    } else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_r17(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_r17_pack(out, c);
            out += 2;
        }
    }
}
