// RGB565 source to RGB565 4x4 tile (0x801d7c94, 0x801d7e20), packer-helper trials.
struct d10d_Rgba8 { unsigned char r, g, b, a; };
static inline void d10d_store_texel(unsigned char *out, unsigned char hi, unsigned char lo) {
    out[0] = hi;
    out[1] = lo;
}
static inline void d10d_pack_rgb565(unsigned char *out, const d10d_Rgba8 &c) {
    d10d_store_texel(out, (c.r & 0xf8) | (c.g >> 5), ((c.g << 3) & 0xe0) | (c.b >> 3));
}

static inline void d10d_krgba_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_krgba(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_krgba_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_krgab_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_krgab(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_krgab_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_krbga_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_krbga(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_krbga_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_krbag_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_krbag(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_krbag_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kragb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_kragb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kragb_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_krabg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_krabg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_krabg_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kgrba_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_kgrba(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kgrba_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kgrab_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_kgrab(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kgrab_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kgbra_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_kgbra(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kgbra_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kgbar_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_kgbar(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kgbar_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kgarb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_kgarb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kgarb_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kgabr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_kgabr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kgabr_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kbrga_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_kbrga(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kbrga_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kbrag_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_kbrag(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kbrag_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kbgra_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.a = bytes > 3 ? in[3] : 255;
}
extern "C" void d10d_kbgra(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kbgra_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kbgar_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_kbgar(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kbgar_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kbarg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_kbarg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kbarg_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kbagr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.b = (v & 0xf800) >> 8; c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_kbagr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kbagr_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kargb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_kargb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kargb_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_karbg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_karbg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_karbg_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kagrb_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3; c.b = (v & 0xf800) >> 8;
}
extern "C" void d10d_kagrb(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kagrb_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kagbr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.g = (v & 0x7e0) >> 2; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_kagbr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kagbr_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kabrg_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.r = (v & 0x1f) << 3; c.g = (v & 0x7e0) >> 2;
}
extern "C" void d10d_kabrg(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kabrg_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}

static inline void d10d_kabgr_read(d10d_Rgba8 &c, const unsigned char *in, int bytes) {
    unsigned short v = *(const unsigned short *)in;
    c.a = bytes > 3 ? in[3] : 255; c.b = (v & 0xf800) >> 8; c.g = (v & 0x7e0) >> 2; c.r = (v & 0x1f) << 3;
}
extern "C" void d10d_kabgr(const unsigned char *source, unsigned int pitch, unsigned int width,
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
            d10d_kabgr_read(c, in, 2);
            d10d_pack_rgb565(out, c);
            out += 2;
        }
    }
}
