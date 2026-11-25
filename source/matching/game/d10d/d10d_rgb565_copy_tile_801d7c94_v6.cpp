// RGB565 source to RGB565 4x4 tile (0x801d7c94, 0x801d7e20), ternary-alpha order trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}

static inline void d10d_trgba_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_trgba(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_trgba_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_trgab_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_trgab(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_trgab_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_trbga_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_trbga(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_trbga_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_trbag_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_trbag(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_trbag_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tragb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_tragb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tragb_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_trabg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_trabg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_trabg_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tgrba_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_tgrba(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tgrba_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tgrab_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_tgrab(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tgrab_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tgbra_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_tgbra(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tgbra_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tgbar_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_tgbar(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tgbar_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tgarb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_tgarb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tgarb_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tgabr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_tgabr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tgabr_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tbrga_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_tbrga(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tbrga_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tbrag_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_tbrag(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tbrag_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tbgra_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_tbgra(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tbgra_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tbgar_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_tbgar(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tbgar_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tbarg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_tbarg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tbarg_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tbagr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_tbagr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tbagr_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_targb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_targb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_targb_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tarbg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_tarbg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tarbg_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tagrb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_tagrb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tagrb_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tagbr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_tagbr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tagbr_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tabrg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_tabrg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tabrg_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}

static inline void d10d_tabgr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_tabgr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_tabgr_read(c, in, 2);
            d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
            out += 2;
        }
    }
}
