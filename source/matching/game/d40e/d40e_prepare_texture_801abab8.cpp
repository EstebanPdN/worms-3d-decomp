// (Worms 3D GameCube PAL, 0x801abab8).
//
// Prepares a texture for a device: applies the colour key, clamps the size to
// the device caps through several power-of-two modes, converts the format if
// the device asks, and for alpha mode 3 premultiplies a format 1 image and
// swizzles an 8-bit palette (formats 7 and 8) through a 1,024-byte buffer.
// Returns 0. Names are inferred.

struct Blob { char head[4]; unsigned short count; char u6[18]; unsigned size; unsigned short locks; char pad[2]; unsigned char bytes[1]; };
struct BlobRef;
extern "C" unsigned char *w3d_k5b_array_ref_lock_801ef048(BlobRef *, unsigned, int, int);
struct BlobRef {
    Blob *p;
    unsigned char *Lock() {
        Blob *q = p;
        unsigned n = q->size;
        unsigned char *r;
        if (q->count == 1) {
            q->locks++;
            r = q->bytes;
        } else r = w3d_k5b_array_ref_lock_801ef048(this, n, 1, 2);
        return r;
    }
};
struct Table { char head[32]; int v[1]; };
struct Palette { char u[28]; BlobRef colors; };
struct Image {
    char u0[20];
    Palette *palette;
    int format;
    Table *offsets;
    Table *pitches;
    char u36[4];
    unsigned short flags;
    unsigned short levels;
    unsigned short height, width;
    BlobRef data;
};
struct Vec { float x, y, z; };
struct Device {
    virtual void a0(),a1(),a2(),a3(),a4(),a5(),a6(),a7(),a8(),a9(),a10(),a11(),a12(),a13(),a14();
    virtual int NeedsConvert();
    virtual void b0();
    virtual int FormatFor(int);
    virtual void c0(),c1(),c2(),c3(),c4(),c5(),c6(),c7(),c8(),c9(),c10(),c11(),c12(),c13(),c14(),c15(),c16();
    virtual int CanResize();
};
struct Dev : Device {
    char u4[44];
    int alphaMode;
    unsigned minW, maxW;
    unsigned minH, maxH;
    int caps;
    char u72[4];
    int sizeMode;
    char u80[12];
    int useKey;
    Vec key;
};
extern "C" void fn_801afe54(Image *, const Vec *);
extern "C" unsigned w3d_auto_801aba98(unsigned);
extern "C" void fn_801afd5c(Image *, unsigned, unsigned);
extern "C" int w3d_d31e_convert_image_801d95c4(Image *, int, Image *);
inline const unsigned &umax(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
static inline unsigned Id(const unsigned &x) { return x; }
extern "C" int w3d_d40e_prepare_texture_801abab8(char *iface, Image *img)
{
    unsigned char temp[1024];
    Dev *d = iface ? (Dev *)(iface - 4) : 0;
    if (d->useKey) fn_801afe54(img, &d->key);
    if (d->CanResize()) {
        unsigned w = img->width, h = img->height;
        unsigned W = w, H = h;
        if (d->caps & 2) {
            int mode = d->sizeMode;
            switch (mode) {
            case 0:
                W = mode;
                H = mode;
                break;
            case 1: {
                W = mode << w3d_auto_801aba98(w);
                H = mode << w3d_auto_801aba98(H);
                break;
            }
            case 2: {
                unsigned pw = 1 << w3d_auto_801aba98(w);
                unsigned ph = 1 << w3d_auto_801aba98(H);
                if (W - pw <= pw >> 1) W = pw; else W = pw + pw;
                if (H - ph <= ph >> 1) H = ph; else H = ph + ph;
                break;
            }
            case 3:
                W = 1 << (w3d_auto_801aba98(w - 1) + 1);
                H = 1 << (w3d_auto_801aba98(H - 1) + 1);
                break;
            case 4:
                H = W = -1;
                break;
            }
        }
        if (d->caps & 1) H = W = umax(H, W);
        if (W > d->maxW) W = d->maxW;
        if (H > d->maxH) H = d->maxH;
        if (W < d->minW) W = d->minW;
        if (H < d->minH) H = d->minH;
        if (H != h || W != w) fn_801afd5c(img, W, H);
    }
    if (d->NeedsConvert()) w3d_d31e_convert_image_801d95c4(img, d->FormatFor(img->format), 0);
    if (d->alphaMode == 3 && !(img->flags & 8)) {
        if (img->format == 1) {
            unsigned char *p = img->data.Lock();
            unsigned rows = img->height, cols = img->width;
            int pitch = img->pitches->v[0];
            for (unsigned y = 0; y < rows; y++) {
                for (unsigned x = 0; x < cols; x++) {
                    p[x * 4 + 3] = (p[x * 4 + 3] << 7) / 255;
                }
                p += pitch;
            }
            img->flags |= 8;
        }
        int fmt = img->format;
        if (fmt != 8) {
            if (fmt != 7) goto done;
        }
        {
            BlobRef &c = img->palette->colors;
            unsigned n = c.p->size;
            unsigned char *p = c.Lock();
            for (unsigned i = 0; i < Id(n) / 4; i++) {
                unsigned j = (i & 231) | ((i & 16) >> 1) | ((i & 8) << 1);
                j *= 4;
                temp[j] = p[i * 4 + 2];
                temp[j + 1] = p[i * 4 + 1];
                temp[j + 2] = p[i * 4];
                temp[j + 3] = (p[i * 4 + 3] << 7) / 255u;
            }
            for (unsigned k = 0; k < Id(n); k++) p[k] = temp[k];
            img->flags |= 8;
        }
    }
done:
    return 0;
}
