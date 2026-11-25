#include "w3d_ptr.h"
#line 1 "d31e_convert_image_801d95c4.cpp"
// (Worms 3D GameCube PAL, 0x801d95c4).
//
// Converts an image to another pixel format, in place when no destination is
// given (going through a temporary fetched with 0x801ea470 and swapped back
// with 0x801ea4c8). Sizes the destination, locks its data, finds a from/to
// pair in the 21-entry table 0x803af714 and calls its converter for every
// mip level, halving width and height. Returns the converter result, or
// 0x80004001 when no converter exists; 0 when nothing changes. Names are
// inferred.

struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Ref {
    Ptr32<Obj> p;
    Ref() : p(0) { }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) {
        if (q) q->AddRef();
        if (p) p->Release();
        p = q;
        return *this;
    }
};
struct Table { char head[32]; int v[1]; };
static inline int At(Ptr32<int> p, unsigned i) { return *(Ptr32<int>)w3d::G((i * 4 + (int)w3d::H(p))); }
struct Blob { char head[4]; unsigned short count; char u6[18]; int size; unsigned short locks; char pad[2]; unsigned char bytes[1]; };
struct BlobRef;
extern "C" Ptr32<unsigned char> w3d_k5b_array_ref_lock_801ef048(Ptr32<BlobRef>, int, int, int);
struct BlobRef {
    Ptr32<Blob> p;
    Ptr32<unsigned char> Lock() {
        Ptr32<Blob> q = p;
        int n = q->size;
        Ptr32<unsigned char> r;
        if (q->count == 1) {
            q->locks++;
            r = q->bytes;
        } else r = w3d_k5b_array_ref_lock_801ef048(this, n, 1, 2);
        return r;
    }
};
struct Image : Obj {
    char u4[20] __attribute__((aligned(__alignof__(Obj))));
    int format;
    Ptr32<Table> offsets;
    Ptr32<Table> pitchTable;
    char u36[6];
    unsigned short levels;
    unsigned short height, width;
    BlobRef data;
    Ptr32<Table> Field(const int &k) { return *(Ptr32<Ptr32<Table>>)((Ptr32<char>)this + k); }
};
typedef Ptr32<int (Ptr32<unsigned char>, int, int, unsigned int, unsigned int, Ptr32<unsigned char>, int, int, Ptr32<int>)> Convert;
struct Conv { int from, to; Convert fn; };
extern Conv g_conv[];
extern "C" void f3c_propagate_tag_801ea4c8(Ptr32<Image>, Ptr32<Image>);
extern "C" Ptr32<Image> w3d_s21_fetch_801ea470(Ptr32<Image>);
extern "C" void fn_801afac0(Ptr32<Image>);
extern "C" int w3d_d31e_convert_image_801d95c4(Ptr32<Image> src, int format, Ptr32<Image> dst)
{
    if (!dst) dst = src;
    int from = src->format;
    bool inplace = false;
    if (dst == src) {
        if (format == from) return 0;
        inplace = true;
    }
    int hr = 0x80004001;
    unsigned w = src->width, h = src->height;
    if (from == format) {
        f3c_propagate_tag_801ea4c8(dst, src);
        return 0;
    }
    Ref tmp;
    if (inplace) {
        Ptr32<Image> t = w3d_s21_fetch_801ea470(src);
        tmp = t;
        dst = t;
    }
    dst->width = w;
    dst->height = h;
    dst->format = format;
    dst->levels = src->levels;
    fn_801afac0(dst);
    Ptr32<unsigned char> out = dst->data.Lock();
    Ptr32<Conv> t = g_conv;
    Ptr32<Conv> c = t;
    do {
        if (c->from == from && c->to == format) {
            unsigned ww = w;
            unsigned hh = h;
            for (unsigned i = 0; i < src->levels; i++) {
                int size;
int off = At(src->offsets->v, i);
int sp = At(src->Field(32)->v, i);
int dp = At(dst->Field(32)->v, i);
Ptr32<unsigned char> base = src->data.p->bytes;
                hr = c->fn(base + off, from, sp, ww, hh, out, format, dp, &size);
                out += size;
                if (ww > 1) ww >>= 1;
                if (hh > 1) hh >>= 1;
            }
            if (inplace) f3c_propagate_tag_801ea4c8(src, dst);
            return hr;
        }
        c++;
    } while (c <= t + 20);
    return 0x80004001;
}


