// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), addressable pixel trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
struct d10d_Rgba8c {
    unsigned char r, g, b, a;
    d10d_Rgba8c(const d10d_Rgba8c &o) : r(o.r), g(o.g), b(o.b), a(o.a) {}
};
struct d10d_Rgba8p {
    unsigned char r, g, b, a;
    d10d_Rgba8p(const unsigned char *p) : r(p[0]), g(p[1]), b(p[2]), a(p[3]) {}
};
static inline void d10d_pack_ref(unsigned char *out, const d10d_Rgba8 &c) {
    if (c.a > 223) {
        out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
        out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
    } else {
        out[1] = (c.g & 0xf0) | (c.b >> 4);
        out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
    }
}
static inline void d10d_pack_ptr(unsigned char *out, const unsigned char *c) {
    if (c[3] > 223) {
        out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
        out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
    } else {
        out[1] = (c[1] & 0xf0) | (c[2] >> 4);
        out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
    }
}

extern "C" void d10d_vAr(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            d10d_pack_ref(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_vAq(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            d10d_pack_ptr(out, c);
            out += 2;
        }
    }
}

extern "C" void d10d_vAc(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8c c = *(const d10d_Rgba8c *)in;
            if (c.a > 223) {
                out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
                out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
            } else {
                out[1] = (c.g & 0xf0) | (c.b >> 4);
                out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
            }
            out += 2;
        }
    }
}

extern "C" void d10d_vAp(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8p c(in);
            if (c.a > 223) {
                out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
                out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
            } else {
                out[1] = (c.g & 0xf0) | (c.b >> 4);
                out[0] = ((c.a >> 1) & 0x70) | (c.r >> 4);
            }
            out += 2;
        }
    }
}

extern "C" void d10d_vAk(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            d10d_Rgba8 c = *(const d10d_Rgba8 *)in;
            d10d_pack_ref(out, c);
            out += 2;
        }
    }
}
