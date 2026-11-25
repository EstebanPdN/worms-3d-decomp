// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), 16-bit texel trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

static inline void d10d_wah_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned short v;
    if (c.a > 223)
        v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[0] = v >> 8;
    out[1] = v;
}
extern "C" void d10d_wah(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wah_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wal_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned short v;
    if (c.a > 223)
        v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[1] = v;
    out[0] = v >> 8;
}
extern "C" void d10d_wal(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wal_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wbh_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned int v;
    if (c.a > 223)
        v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[0] = v >> 8;
    out[1] = v;
}
extern "C" void d10d_wbh(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wbh_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wbl_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned int v;
    if (c.a > 223)
        v = 0x8000 | ((c.r & 0xf8) << 7) | ((c.g & 0xf8) << 2) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[1] = v;
    out[0] = v >> 8;
}
extern "C" void d10d_wbl(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wbl_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wch_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned short v;
    if (c.a > 223)
        v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[0] = v >> 8;
    out[1] = v;
}
extern "C" void d10d_wch(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wch_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wcl_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned short v;
    if (c.a > 223)
        v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[1] = v;
    out[0] = v >> 8;
}
extern "C" void d10d_wcl(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wcl_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wdh_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned int v;
    if (c.a > 223)
        v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[0] = v >> 8;
    out[1] = v;
}
extern "C" void d10d_wdh(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wdh_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wdl_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned int v;
    if (c.a > 223)
        v = 0x8000 | ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3);
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[1] = v;
    out[0] = v >> 8;
}
extern "C" void d10d_wdl(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wdl_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_weh_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned short v;
    if (c.a > 223)
        v = ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3) | 0x8000;
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[0] = v >> 8;
    out[1] = v;
}
extern "C" void d10d_weh(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_weh_pack(out, c);
            out += 2;
        }
    }
}

static inline void d10d_wel_pack(unsigned char *out, const d10d_Rgba8 &c) {
    unsigned short v;
    if (c.a > 223)
        v = ((c.r >> 3) << 10) | ((c.g >> 3) << 5) | (c.b >> 3) | 0x8000;
    else
        v = ((c.a >> 5) << 12) | ((c.r >> 4) << 8) | ((c.g >> 4) << 4) | (c.b >> 4);
    out[1] = v;
    out[0] = v >> 8;
}
extern "C" void d10d_wel(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_wel_pack(out, c);
            out += 2;
        }
    }
}
