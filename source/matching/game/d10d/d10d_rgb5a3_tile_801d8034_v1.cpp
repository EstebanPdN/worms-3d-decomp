// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), per-pixel indexing trials.

extern "C" void d10d_tAa1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tAa2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}

extern "C" void d10d_tAb1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tAb2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 4;
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}

extern "C" void d10d_tBa1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + (x + column) * 4 + pitch * (row + y);
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tBa2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + (x + column) * 4 + pitch * (row + y);
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}

extern "C" void d10d_tBb1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + (x + column) * 4 + pitch * (row + y);
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tBb2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + (x + column) * 4 + pitch * (row + y);
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}

extern "C" void d10d_tCa1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = x * 4 + source + pitch * (row + y) + column * 4;
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tCa2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = x * 4 + source + pitch * (row + y) + column * 4;
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}

extern "C" void d10d_tCb1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = x * 4 + source + pitch * (row + y) + column * 4;
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tCb2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = x * 4 + source + pitch * (row + y) + column * 4;
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}

extern "C" void d10d_tDa1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = &source[(row + y) * pitch + (x + column) * 4];
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tDa2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = &source[(row + y) * pitch + (x + column) * 4];
            unsigned char *out = tile + row * 8 + column * 2;
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}

extern "C" void d10d_tDb1(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = &source[(row + y) * pitch + (x + column) * 4];
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
            } else {
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
            }
        }
}

extern "C" void d10d_tDb2(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++)
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = &source[(row + y) * pitch + (x + column) * 4];
            unsigned char *out = &tile[row * 8 + column * 2];
            unsigned char c[4];
            c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
            if (c[3] > 223) {
                out[0] = 0x80 | ((c[0] >> 1) & 0x7c) | (c[1] >> 6);
                out[1] = ((c[1] << 2) & 0xe0) | (c[2] >> 3);
            } else {
                out[0] = ((c[3] >> 1) & 0x70) | (c[0] >> 4);
                out[1] = (c[1] & 0xf0) | (c[2] >> 4);
            }
        }
}
