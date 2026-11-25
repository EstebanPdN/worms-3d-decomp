// RGBA8 to RGB5A3 4x4 tile conversion (0x801d8034), trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };

extern "C" void d10d_ta(const unsigned char *source, unsigned int pitch, unsigned int width, unsigned int height,
                        unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        const unsigned char *in = source + x * 4 + pitch * (row + y);
        for (unsigned int column = 0; column < columns; column++) {
            d10d_Rgba8 c = *(const d10d_Rgba8 *)in;
            if (c.a > 223) {
                out[1] = ((c.g << 2) & 0xe0) | (c.b >> 3);
                out[0] = 0x80 | ((c.r >> 1) & 0x7c) | (c.g >> 6);
            } else {
                out[1] = (c.g & 0xf0) | (c.b >> 4);
                out[0] = ((c.a << 3) & 0x70) | (c.r >> 4);
            }
            out += 2;
            in += 4;
        }
    }
}
