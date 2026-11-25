#include "w3d_ptr.h"
#line 1 "d30j_load_geometry_block_8017ffbc.cpp"
// Load a geometry block once: read it from the buffer service into temporary
// memory, parse it through a stream into a new object, store the object under
// the name GeoMoik and keep a reference to it. GWMP8P rev0 0x8017ffbc.
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
Ptr32<void> tsonnet_c26_temp_alloc_801fe0b8(int);
void w3d_temporary_release(Ptr32<void>);
Ptr32<void> w3d_buffer_request_service();
int w3d_buffer_request_read(Ptr32<void>, Ptr32<void>, Ptr32<void>, int);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
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
  Ref &operator=(const Ref &o) { Ptr32<T> q = o.p; if (q) q->add(); if (p) p->release(); p = q; return *this; }
};
struct Str {
  Ptr32<char> p;
  template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
  Str(const Str &);
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Stream : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN6Stream2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN6Stream2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN6Stream2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN6Stream2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN6Stream2a7Ev")); int w3d_r_header(Ptr32<void>) __asm__(W3D_SYM("_ZN6Stream6headerEPv"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int header(Ptr32<void> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this), w3d_a0); } };
extern "C" Ptr32<Stream> w3d_s21_create_80208af8(Ptr32<void>, int);
struct Parser : Iface { int w3d_r_read(Ptr32<Stream>) __asm__(W3D_SYM("_ZN6Parser4readEP6Stream")); void w3d_r_a4() __asm__(W3D_SYM("_ZN6Parser2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN6Parser2a5Ev")); int w3d_r_run(Ptr32<Ptr32<Iface>>, int) __asm__(W3D_SYM("_ZN6Parser3runEPP5Ifacei"));  __attribute__((always_inline)) inline int read(Ptr32<Stream> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<Stream>))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int run(Ptr32<Ptr32<Iface>> w3d_a0, int w3d_a1) { return ((int (*)(w3d_u32, Ptr32<Ptr32<Iface>>, int))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this), w3d_a0, w3d_a1); } };
struct Store : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN5Store2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN5Store2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN5Store2a5Ev")); int w3d_r_put(Ptr32<void>, Ptr32<Iface>, const Str &) __asm__(W3D_SYM("_ZN5Store3putEPvP5IfaceRK3Str"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int put(Ptr32<void> w3d_a0, Ptr32<Iface> w3d_a1, const Str &w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<Iface>, w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this), w3d_a0, w3d_a1, w3d::h2g(__builtin_addressof(w3d_a2))); } };
extern char lbl_80418de0[], lbl_8040e078[];
struct Block { char p0[20]; int size; };
struct Geo { char p0[36]; unsigned short flags; char p26[2]; Ptr32<Store> store; char p2c[4]; Ref<Iface> geom; char p34[4]; Block block; char p6e[32]; int loaded; };
extern "C" int d30j_load_geometry_block_8017ffbc(Ptr32<Geo> self) {
  /* Sin compresión a ARAM (ver d24j_compile_mesh_data) no hay bloque que leer. */
  if ((self->flags & 32) && self->loaded <= 0 && self->block.size) {
    Ptr32<Block> b = &self->block;
    Ptr32<void> mem = tsonnet_c26_temp_alloc_801fe0b8(b->size);
    w3d_buffer_request_read(w3d_buffer_request_service(), b, mem, b->size);
    Ref<Stream> s(w3d_s21_create_80208af8(mem, b->size));
    char hdr[8];
    s->header(hdr);
    Ref<Parser> pr((Ptr32<Parser>)w3d_s10_service_forward_8020b680(lbl_80418de0));
    pr->read(s.p);
    Ref<Iface> res;
    pr->run(&res.p, 0);
    w3d_temporary_release(mem);
    Str name("GeoMoik!!!");
    self->store->put(lbl_8040e078, res.p, name);
    self->geom = res;
  }
  return 0;
}


