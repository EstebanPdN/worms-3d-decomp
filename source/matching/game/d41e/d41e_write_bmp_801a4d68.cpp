// (Worms 3D GameCube PAL, 0x801a4d68).
//
// Writes one mip level of a texture to a stream as an uncompressed BMP: picks
// bits per pixel from the texture format (failing with E_FAIL for unsupported
// ones), halves the size level times, fills the 14-byte little-endian file
// header and the 40-byte info header, writes a grey palette for 8-bit images,
// then writes each row through a new[] row buffer, swapping BGR or copying as
// the format requires. Standard BMP layout; other names inferred.

extern "C" void *memcpy(void *, const void *, unsigned, ...);

struct Stream {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int Write(const void *p, unsigned n, unsigned *written);
};
struct FileHeader {
    unsigned short type;
    unsigned char size[4];
    unsigned short reserved1, reserved2;
    unsigned char offset[4];
};
struct InfoHeader {
    unsigned size;
    unsigned width, height;
    unsigned short planes, bits;
    unsigned compression, imageSize;
    unsigned xres, yres;
    unsigned used, important;
};
struct Table { char head[32]; unsigned v[1]; };
struct Blob { char head[32]; unsigned char bytes[1]; };
struct Texture {
    char pad0[24];
    int format;
    Table *offsets;
    Table *pitches;
    char pad36[8];
    unsigned short height, width;
    Blob *data;
};

static inline unsigned Val(const unsigned &v) { return v; }
extern "C" int w3d_d41e_write_bmp_801a4d68(Texture *self, Stream *stream, int flag, unsigned level)
{
    int format = self->format;
    int bits;
    switch (format) {
    case 0:
        bits = 24;
        break;
    case 1:
        bits = 24;
        if (flag == 0) break;
    case 6:
        bits = 8;
        break;
    case 3: case 4:
        bits = 16;
        break;
    case 5:
        bits = 16;
        break;
    default:
        return 0x80004005;
    }
    FileHeader file;
    InfoHeader info;
    unsigned w = self->width, h = self->height;
    for (unsigned i = 0; i < level; i++) {
        w >>= 1;
        h >>= 1;
    }
    unsigned image = w * h * bits >> 3;
    file.type = 0x424d;
    unsigned total = image + 54;
    file.size[0] = total;
    file.size[1] = total >> 8;
    file.size[2] = total >> 16;
    file.size[3] = total >> 24;
    file.reserved1 = 0;
    file.reserved2 = 0;
    unsigned off0 = 54;
    file.offset[0] = off0;
    file.offset[1] = off0 >> 8;
    file.offset[2] = off0 >> 16; file.offset[3] = off0 >> 24;
    file.offset[3] = off0 >> 24;
    info.size = 40;
    info.width = w;
    info.height = h;
    info.planes = 1;
    info.bits = bits;
    info.compression = 0;
    info.imageSize = image;
    info.xres = 2834;
    info.yres = 2834;
    if (bits == 8) {
        info.used = 256;
        info.important = 256;
        unsigned x = Val(off0 + 1024);
        file.offset[0] = x; file.offset[1] = x >> 8; file.offset[2] = x >> 16; file.offset[3] = x >> 24;
    } else {
        info.used = 0;
        info.important = 0;
    }
    stream->Write(&file, 14, 0);
    stream->Write(&info, 40, 0);
    if (bits == 8) {
        unsigned char entry[4];
        for (unsigned i = 0; i < 256; i++) {
            entry[0] = i;
            entry[1] = i;
            entry[2] = i;
            entry[3] = 0;
            stream->Write(entry, 4, 0);
        }
    }
    unsigned rowBytes = info.width * bits >> 3;
    unsigned *t1 = self->offsets->v; unsigned *t2 = self->pitches->v;
    unsigned char *data = self->data->bytes;
    unsigned off = *(unsigned *)(level * 4 + (int)t1);
    unsigned pitch = *(unsigned *)(level * 4 + (int)t2);
    unsigned char *base = data + off;
    unsigned char *row = new unsigned char[rowBytes];
    for (unsigned y = 0; y < info.height; y++) {
        unsigned char *s = base + pitch * y;
        switch (format) {
        case 6:
            memcpy(row, s, rowBytes);
            break;
        case 1:
            if (bits == 8) {
                unsigned j = 0;
                for (unsigned i = 0; i < info.width * 3; i += 3) {
                    row[j] = s[i + j + 3];
                    j++;
                }
            } else {
                unsigned j = 0;
                for (unsigned i = 0; i < info.width * 3; i += 3) {
                    row[i] = s[i + j + 2];
                    row[i + 1] = s[i + j + 1];
                    row[i + 2] = s[i + j];
                    j++;
                }
            }
            break;
        case 0: {
            for (unsigned i = 0; i < rowBytes; i += 3) {
                row[i] = s[2];
                row[i + 1] = s[1];
                row[i + 2] = s[0];
                s += 3;
            }
            break;
        }
        case 3: case 4: case 5:
            break;
        }
        stream->Write(row, rowBytes, 0);
    }
    delete[] row;
    return 0;
}
