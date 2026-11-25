#include "w3d_ptr.h"
#line 1 "d40e_prepare_texture_801abab8.cpp"
// (Worms 3D GameCube PAL, 0x801abab8).
//
// Prepares a texture for a device: applies the colour key, clamps the size to
// the device caps through several power-of-two modes, converts the format if
// the device asks, and for alpha mode 3 premultiplies a format 1 image and
// swizzles an 8-bit palette (formats 7 and 8) through a 1,024-byte buffer.
// Returns 0. Names are inferred.

struct Blob { char head[4]; unsigned short count; char u6[18]; unsigned size; unsigned short locks; char pad[2]; unsigned char bytes[1]; };
struct BlobRef;
extern "C" Ptr32<unsigned char> w3d_k5b_array_ref_lock_801ef048(Ptr32<BlobRef>, unsigned, int, int);
struct BlobRef {
    Ptr32<Blob> p;
    Ptr32<unsigned char> Lock() {
        Ptr32<Blob> q = p;
        unsigned n = q->size;
        Ptr32<unsigned char> r;
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
    Ptr32<Palette> palette;
    int format;
    Ptr32<Table> offsets;
    Ptr32<Table> pitches;
    char u36[4];
    unsigned short flags;
    unsigned short levels;
    unsigned short height, width;
    BlobRef data;
};
struct Vec { float x, y, z; };
struct Device {
    void w3d_r_a0() __asm__(W3D_SYM("_ZN6Device2a0Ev")),w3d_r_a1() __asm__(W3D_SYM("_ZN6Device2a1Ev")),w3d_r_a2() __asm__(W3D_SYM("_ZN6Device2a2Ev")),w3d_r_a3() __asm__(W3D_SYM("_ZN6Device2a3Ev")),w3d_r_a4() __asm__(W3D_SYM("_ZN6Device2a4Ev")),w3d_r_a5() __asm__(W3D_SYM("_ZN6Device2a5Ev")),w3d_r_a6() __asm__(W3D_SYM("_ZN6Device2a6Ev")),w3d_r_a7() __asm__(W3D_SYM("_ZN6Device2a7Ev")),w3d_r_a8() __asm__(W3D_SYM("_ZN6Device2a8Ev")),w3d_r_a9() __asm__(W3D_SYM("_ZN6Device2a9Ev")),w3d_r_a10() __asm__(W3D_SYM("_ZN6Device3a10Ev")),w3d_r_a11() __asm__(W3D_SYM("_ZN6Device3a11Ev")),w3d_r_a12() __asm__(W3D_SYM("_ZN6Device3a12Ev")),w3d_r_a13() __asm__(W3D_SYM("_ZN6Device3a13Ev")),w3d_r_a14() __asm__(W3D_SYM("_ZN6Device3a14Ev"));
    int w3d_r_NeedsConvert() __asm__(W3D_SYM("_ZN6Device12NeedsConvertEv"));
    void w3d_r_b0() __asm__(W3D_SYM("_ZN6Device2b0Ev"));
    int w3d_r_FormatFor(int) __asm__(W3D_SYM("_ZN6Device9FormatForEi"));
    void w3d_r_c0() __asm__(W3D_SYM("_ZN6Device2c0Ev")),w3d_r_c1() __asm__(W3D_SYM("_ZN6Device2c1Ev")),w3d_r_c2() __asm__(W3D_SYM("_ZN6Device2c2Ev")),w3d_r_c3() __asm__(W3D_SYM("_ZN6Device2c3Ev")),w3d_r_c4() __asm__(W3D_SYM("_ZN6Device2c4Ev")),w3d_r_c5() __asm__(W3D_SYM("_ZN6Device2c5Ev")),w3d_r_c6() __asm__(W3D_SYM("_ZN6Device2c6Ev")),w3d_r_c7() __asm__(W3D_SYM("_ZN6Device2c7Ev")),w3d_r_c8() __asm__(W3D_SYM("_ZN6Device2c8Ev")),w3d_r_c9() __asm__(W3D_SYM("_ZN6Device2c9Ev")),w3d_r_c10() __asm__(W3D_SYM("_ZN6Device3c10Ev")),w3d_r_c11() __asm__(W3D_SYM("_ZN6Device3c11Ev")),w3d_r_c12() __asm__(W3D_SYM("_ZN6Device3c12Ev")),w3d_r_c13() __asm__(W3D_SYM("_ZN6Device3c13Ev")),w3d_r_c14() __asm__(W3D_SYM("_ZN6Device3c14Ev")),w3d_r_c15() __asm__(W3D_SYM("_ZN6Device3c15Ev")),w3d_r_c16() __asm__(W3D_SYM("_ZN6Device3c16Ev"));
    int w3d_r_CanResize() __asm__(W3D_SYM("_ZN6Device9CanResizeEv"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int NeedsConvert() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void b0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int FormatFor(int w3d_a0) { return ((int (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Device, 19))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void c0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void c16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 36))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int CanResize() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Device, 37))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Device; };
struct Dev : Device {
    char u4[44] __attribute__((aligned(__alignof__(Device))));
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
extern "C" void fn_801afe54(Ptr32<Image>, Ptr32<const Vec>);
extern "C" unsigned w3d_auto_801aba98(unsigned);
extern "C" void fn_801afd5c(Ptr32<Image>, unsigned, unsigned);
extern "C" int w3d_d31e_convert_image_801d95c4(Ptr32<Image>, int, Ptr32<Image>);
inline const unsigned &umax(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
static inline unsigned Id(const unsigned &x) { return x; }
extern "C" int w3d_d40e_prepare_texture_801abab8(Ptr32<char> iface, Ptr32<Image> img)
{
    unsigned char temp[1024];
    Ptr32<Dev> d = iface ? w3d::R((Ptr32<Dev>)(iface - 4)) : 0;
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
            Ptr32<unsigned char> p = img->data.Lock();
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
            Ptr32<unsigned char> p = c.Lock();
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


