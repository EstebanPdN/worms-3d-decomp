// RGB565 source to RGB565 4x4 tile (0x801d7c94, 0x801d7e20), channel-order trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}

static inline void d10d_orgba_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_orgba(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_orgba_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_orgab_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_orgab(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_orgab_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_orbga_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_orbga(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_orbga_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_orbag_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_orbag(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_orbag_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_oragb_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.a = 255; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_oragb(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_oragb_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_orabg_read(d10d_Rgba8 &c, unsigned short v) {
    c.r = (v & 0x1f) << 3; c.a = 255; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_orabg(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_orabg_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_ogrba_read(d10d_Rgba8 &c, unsigned short v) {
    c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = 255;
}
extern "C" void d10d_ogrba(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_ogrba_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_ograb_read(d10d_Rgba8 &c, unsigned short v) {
    c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_ograb(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_ograb_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_ogbra_read(d10d_Rgba8 &c, unsigned short v) {
    c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_ogbra(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_ogbra_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_ogbar_read(d10d_Rgba8 &c, unsigned short v) {
    c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = 255; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_ogbar(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_ogbar_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_ogarb_read(d10d_Rgba8 &c, unsigned short v) {
    c.g = (v & 0x7e0) >> 2; c.a = 255; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_ogarb(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_ogarb_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_ogabr_read(d10d_Rgba8 &c, unsigned short v) {
    c.g = (v & 0x7e0) >> 2; c.a = 255; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_ogabr(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_ogabr_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_obrga_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = 255;
}
extern "C" void d10d_obrga(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_obrga_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_obrag_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.a = 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_obrag(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_obrag_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_obgra_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = 255;
}
extern "C" void d10d_obgra(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_obgra_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_obgar_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = 255; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_obgar(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_obgar_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_obarg_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.a = 255; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_obarg(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_obarg_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_obagr_read(d10d_Rgba8 &c, unsigned short v) {
    c.b = (v & 0xf800) >> 8; c.a = 255; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_obagr(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_obagr_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_oargb_read(d10d_Rgba8 &c, unsigned short v) {
    c.a = 255; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_oargb(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_oargb_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_oarbg_read(d10d_Rgba8 &c, unsigned short v) {
    c.a = 255; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_oarbg(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_oarbg_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_oagrb_read(d10d_Rgba8 &c, unsigned short v) {
    c.a = 255; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_oagrb(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_oagrb_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_oagbr_read(d10d_Rgba8 &c, unsigned short v) {
    c.a = 255; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_oagbr(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_oagbr_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_oabrg_read(d10d_Rgba8 &c, unsigned short v) {
    c.a = 255; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_oabrg(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_oabrg_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_oabgr_read(d10d_Rgba8 &c, unsigned short v) {
    c.a = 255; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_oabgr(const unsigned char *source, unsigned int pitch, unsigned int width,
                   unsigned int height, unsigned int x, unsigned int y, unsigned char *tile) {
    unsigned int rows = height - y;
    unsigned int columns = width - x;
    if (rows > 4) rows = 4;
    if (columns > 4) columns = 4;
    for (unsigned int row = 0; row < rows; row++) {
        unsigned char *out = tile + row * 8;
        for (unsigned int column = 0; column < columns; column++) {
            const unsigned char *in = source + pitch * (row + y) + (x + column) * 2;
            d10d_Rgba8 c;
            d10d_oabgr_read(c, *(const unsigned short *)in);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}
