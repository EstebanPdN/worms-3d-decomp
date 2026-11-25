// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), byte-parameter store trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_put_hl(unsigned char *out, unsigned char hi, unsigned char lo) { out[1] = lo; out[0] = hi; }
static inline void d10d_put_lh(unsigned char *out, unsigned char lo, unsigned char hi) { out[1] = lo; out[0] = hi; }
static inline void d10d_put_hl2(unsigned char *out, unsigned char hi, unsigned char lo) { out[0] = hi; out[1] = lo; }
static inline void d10d_put_s(unsigned char *out, unsigned short v) { out[1] = v; out[0] = v >> 8; }

static inline void d10d_z00_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_z00(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z00_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_z01_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_lh(out, ((c.g << 2) & 0xe0) | (c.b >> 3), 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6));
    else
        d10d_put_lh(out, (c.g & 0xf0) | (c.b >> 4), ((c.a >> 1) & 0x70) | (c.r >> 4));
}
extern "C" void d10d_z01(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z01_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_z02_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_z02(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z02_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_z03_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl(out, ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_z03(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z03_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_z04_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_lh(out, ((c.g << 2) & 0xe0) | (c.b >> 3), ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6));
    else
        d10d_put_lh(out, (c.g & 0xf0) | (c.b >> 4), ((c.a >> 1) & 0x70) | (c.r >> 4));
}
extern "C" void d10d_z04(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z04_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_z05_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_hl2(out, ((c.r >> 1) & 0x7c) | 0x80 | (c.g >> 6), ((c.g << 2) & 0xe0) | (c.b >> 3));
    else
        d10d_put_hl2(out, ((c.a >> 1) & 0x70) | (c.r >> 4), (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_z05(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z05_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_z06_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_s(out, 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3));
    else
        d10d_put_s(out, ((c.a & 0xe0) << 7) | ((c.r & 0xf0) << 4) | (c.g & 0xf0) | (c.b >> 4));
}
extern "C" void d10d_z06(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z06_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_z07_pack(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223)
        d10d_put_s(out, 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3));
    else
        d10d_put_s(out, ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4));
}
extern "C" void d10d_z07(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_z07_pack(out, c);
            out += 2;
        }
    }
}
