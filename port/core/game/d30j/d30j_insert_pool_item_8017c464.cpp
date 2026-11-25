#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d30j_insert_pool_item_8017c464.cpp"
// Insert an object into the pool manager's 1920-slot open-addressing table: hash
// its name, probe linearly, note whether an entry of the same name was seen,
// keep the longest and total probe counts, and hold a reference in the free
// slot. GWMP8P rev0 0x8017c464.
extern "C" {
void w3d_string_base_init(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
}
struct Str {
  Ptr32<char> p;
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void use(Str) {}
struct Item {
  void w3d_r_a0() __asm__(W3D_SYM("_ZN4Item2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN4Item3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN4Item7releaseEv"));
  void w3d_r_a3() __asm__(W3D_SYM("_ZN4Item2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN4Item2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Item2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN4Item2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN4Item2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN4Item2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN4Item2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN4Item3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN4Item3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN4Item3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN4Item3a13Ev")); void w3d_r_a14() __asm__(W3D_SYM("_ZN4Item3a14Ev"));
  const Str &w3d_r_text() __asm__(W3D_SYM("_ZN4Item4textEv"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline const Str &text() { return *(const Str *)w3d::g2h(((w3d_u32 (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 17))(w3d::h2g(this))); }  Ptr32<void> w3d_vptr_Item; };
struct Ref {
  Ptr32<Item> p;
  Ptr32<Item> get() { return p; }
  void set(Ptr32<Item> q) { if (q) q->add(); if (p) p->release(); p = q; }
};
struct Cell { char p0[24]; Ref r; };
struct Table { char p0[24]; Ref slots[1920]; 
  char names[8 * 256]; int count; };
extern "C" unsigned int w3d_k1d_hash_name_8017e1c4(Ptr32<Table>, Ptr32<const char>);
extern "C" void w3d_dbg(const char *, ...);
extern unsigned int lbl_804ab5e4, lbl_804ab5ec, lbl_804ab5f0;
template <class T> inline const T &mx(const T &a, const T &b) { return a < b ? b : a; }
#define SLOT(i) (((Ref *)w3d_restab_slots())[i])   /* port (v29): tabla nativa */
extern "C" bool d30j_insert_pool_item_8017c464(Ptr32<Table> self, Ptr32<Item> item) {
  bool found = false;
  unsigned int h = w3d_k1d_hash_name_8017e1c4(self, item->text().p);
  if (SLOT(h).get() == 0) {
    SLOT(h).set(item);
    self->count++;
  } else {
    const Str &a = item->text();
    const Str &a2 = SLOT(h).get()->text();
    if (strcmp(a.p, a2.p) == 0) {
      found = true;
      use(item->text());
    }
    unsigned int probe = 1;
    lbl_804ab5e4++;
    const unsigned int cap = w3d_restab_cap();
    while (SLOT((h + probe) % cap).get()) {
      const Str &b = item->text();
      const Str &b2 = SLOT((h + probe) % cap).get()->text();
      if (strcmp(b.p, b2.p) == 0) {
        found = true;
        use(item->text());
      }
      probe++;
      // Port (v27): con la tabla llena, el original da vueltas sin fin. Con los mapas de Ultimate Mayhem quedan unos 48
      // huecos libres (core/native/mapa_um.cpp): si alguna vez se llena, no se inserta y queda en el registro.
      if (probe >= cap) { w3d_dbg("[tabla] la tabla de %u recursos esta llena: %s no cabe\n", cap, item->text().p.get()); return false; }
    }
    lbl_804ab5ec = mx(lbl_804ab5ec, probe);
    lbl_804ab5f0 += probe;
    SLOT((h + probe) % cap).set(item);
    self->count++;
  }
  return !found;
}


