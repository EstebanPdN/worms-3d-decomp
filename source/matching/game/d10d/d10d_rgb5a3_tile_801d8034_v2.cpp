// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), stack pixel trials.
extern "C" void *memcpy(void *, const void *, unsigned int);
struct d10d_Rgba8 { unsigned char r, g, b, a; };

extern "C" void d10d_uAm(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            memcpy(c, in, 4);
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
            out += 2;
        }
    }
}

extern "C" void d10d_uAb(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            __builtin_memcpy(c, in, 4);
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
            out += 2;
        }
    }
}

extern "C" void d10d_uAs(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
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
            memcpy(&c, in, 4);
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

extern "C" void d10d_uCm(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = x * 4 + source + pitch * (row + y) + column * 4;
            unsigned char c[4];
            memcpy(c, in, 4);
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
            out += 2;
        }
    }
}

extern "C" void d10d_uCb(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = x * 4 + source + pitch * (row + y) + column * 4;
            unsigned char c[4];
            __builtin_memcpy(c, in, 4);
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
            out += 2;
        }
    }
}

extern "C" void d10d_uCs(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = x * 4 + source + pitch * (row + y) + column * 4;
            d10d_Rgba8 c;
            memcpy(&c, in, 4);
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
