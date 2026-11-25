#include "w3d_ptr.h"
#line 1 "d30j_load_image_resource_801712c4.cpp"
// Load the image of a resource if it is flagged as loadable: resolve the file
// through the loader service, flush its texels, optionally create a default
// texture for it, store the image on the matching map entry, and finish the
// loader. GWMP8P rev0 0x801712c4.
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
void w3d_string_base_init(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_string_release_header(Ptr32<void>);
Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
void fn_802fa988(Ptr32<void>, unsigned int);
}
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() { p = 0; }
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  Ref &operator=(const Ref &o) { Ptr32<T> old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct Str {
  Ptr32<char> p;
  template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
  Str &operator=(const Str &o) {
    ++*(Ptr32<unsigned short>)(o.p - 6);
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
inline void use(Str) {}
struct Block { char p0[24]; unsigned int size; unsigned short lock; char p1e[2]; char data[1]; };
struct Image : Iface { char p4[44] __attribute__((aligned(__alignof__(Iface)))); Ptr32<Block> block; };
struct Loader : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN6Loader3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN6Loader3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN6Loader3s28Ev")); int w3d_r_load(Ptr32<char>, Ptr32<Ref < Image >>) __asm__(W3D_SYM("_ZN6Loader4loadEPcP3RefI5ImageE")); void w3d_r_s36() __asm__(W3D_SYM("_ZN6Loader3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN6Loader3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN6Loader3s44Ev")); int w3d_r_done(int) __asm__(W3D_SYM("_ZN6Loader4doneEi"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int load(Ptr32<char> w3d_a0, Ptr32<Ref < Image >> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<char>, Ptr32<Ref < Image >>))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int done(int w3d_a0) { return ((int (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this), w3d_a0); } };
struct RootV : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN5RootV3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN5RootV3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN5RootV3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN5RootV3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN5RootV3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN5RootV3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN5RootV3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN5RootV3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN5RootV3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN5RootV3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN5RootV3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN5RootV3s64Ev")); void w3d_r_s68() __asm__(W3D_SYM("_ZN5RootV3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN5RootV3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN5RootV3s76Ev")); void w3d_r_s80() __asm__(W3D_SYM("_ZN5RootV3s80Ev")); void w3d_r_s84() __asm__(W3D_SYM("_ZN5RootV3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN5RootV3s88Ev")); Ptr32<Loader> w3d_r_loader(Ptr32<void>) __asm__(W3D_SYM("_ZN5RootV6loaderEPv"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Loader> loader(Ptr32<void> w3d_a0) { return ((Ptr32<Loader> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this), w3d_a0); } };
extern "C" Ptr32<RootV> w3d_auto_8020b648();
struct Tex : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN3Tex3s20Ev")); void w3d_r_set(Ptr32<Image>) __asm__(W3D_SYM("_ZN3Tex3setEP5Image")); void w3d_r_s28() __asm__(W3D_SYM("_ZN3Tex3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN3Tex3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN3Tex3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN3Tex3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN3Tex3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN3Tex3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN3Tex3s52Ev")); void w3d_r_setWrap(int) __asm__(W3D_SYM("_ZN3Tex7setWrapEi")); void w3d_r_s60() __asm__(W3D_SYM("_ZN3Tex3s60Ev")); void w3d_r_setMip(int) __asm__(W3D_SYM("_ZN3Tex6setMipEi")); void w3d_r_s68() __asm__(W3D_SYM("_ZN3Tex3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN3Tex3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN3Tex3s76Ev")); void w3d_r_setName(Ptr32<const char>, int) __asm__(W3D_SYM("_ZN3Tex7setNameEPKci")); void w3d_r_s84() __asm__(W3D_SYM("_ZN3Tex3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN3Tex3s88Ev")); void w3d_r_s92() __asm__(W3D_SYM("_ZN3Tex3s92Ev")); void w3d_r_s96() __asm__(W3D_SYM("_ZN3Tex3s96Ev")); void w3d_r_s100() __asm__(W3D_SYM("_ZN3Tex4s100Ev")); void w3d_r_s104() __asm__(W3D_SYM("_ZN3Tex4s104Ev")); void w3d_r_s108() __asm__(W3D_SYM("_ZN3Tex4s108Ev")); void w3d_r_s112() __asm__(W3D_SYM("_ZN3Tex4s112Ev")); void w3d_r_s116() __asm__(W3D_SYM("_ZN3Tex4s116Ev")); void w3d_r_s120() __asm__(W3D_SYM("_ZN3Tex4s120Ev")); void w3d_r_s124() __asm__(W3D_SYM("_ZN3Tex4s124Ev")); void w3d_r_s128() __asm__(W3D_SYM("_ZN3Tex4s128Ev")); void w3d_r_s132() __asm__(W3D_SYM("_ZN3Tex4s132Ev")); void w3d_r_s136() __asm__(W3D_SYM("_ZN3Tex4s136Ev")); void w3d_r_s140() __asm__(W3D_SYM("_ZN3Tex4s140Ev")); void w3d_r_setFilter(int) __asm__(W3D_SYM("_ZN3Tex9setFilterEi"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set(Ptr32<Image> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Image>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setWrap(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setMip(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setName(Ptr32<const char> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<const char>, int))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s100() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s104() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s108() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s112() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s116() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s120() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s124() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s128() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s132() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s136() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s140() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setFilter(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 36))(w3d::h2g(this), w3d_a0); } };
struct Item { char p0[60]; Ref<Image> image; };
struct Holder { char p0[20]; Str name; char p18[4]; Ptr32<Block> block; };
extern "C" Ptr32<Ptr32<Item>> w3d_auto_801d0858(Ptr32<Holder>, Ptr32<int>);
struct Self { char p0[20]; Str name; int flags; char p1c[4]; Ptr32<const char> file; char p24[14]; unsigned short state; char p34[24]; Ptr32<Holder> holder; };
extern char lbl_804143e0[], lbl_80413db0[];
extern const char lbl_803a6648[];
static inline Ptr32<Loader> get_loader(Ptr32<void> type) { return w3d_auto_8020b648()->loader(type); }
extern "C" int d30j_load_image_resource_801712c4(Ptr32<Self> self, Ptr32<const char> name) {
  if (!(self->flags & 0x8000)) return 0x80004005;
  Ptr32<Loader> ld = get_loader(lbl_804143e0);
  Ref<Image> img;
  Str path(name);
  { Ptr32<Holder> h = self->holder; h->name = Str(self->file); }
  self->holder->block->lock++;
  if (ld->load(path.p, &img) < 0) {
    use(path), use(self->name);
    return 0x80004005;
  }
  if (!(self->state & 256)) {
    Ref<Tex> t((Ptr32<Tex>)w3d_s10_service_forward_8020b680(lbl_80413db0));
    t->setWrap(4);
    t->setFilter(0);
    t->setMip(1);
    t->setName(lbl_803a6648, 5);
    t->set(img.p);
    Ptr32<Block> b = img->block;
    fn_802fa988(b->data, b->size);
  }
  int found;
  Ptr32<Ptr32<Item>> e = w3d_auto_801d0858(self->holder, &found);
  Ptr32<Item> it = found ? w3d::R(*e) : 0;
  it->image = img;
  ld->done(0);
  return 0;
}


