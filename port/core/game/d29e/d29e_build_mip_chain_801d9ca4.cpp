#include "w3d_ptr.h"
#line 1 "d29e_build_mip_chain_801d9ca4.cpp"
// (Worms 3D GameCube PAL, 0x801d9ca4).
//
// Rebuilds a texture's mip levels: counts the levels from the larger of
// width and height; if the owner does not force a rebuild (+44 of self minus
// 4) and the count is unchanged returns 0; otherwise stores the count,
// reallocates through 0x801afac0, makes the pixels writable and downsamples
// each level from the previous one through 0x801b0a14. Returns 0. Names are
// inferred.

struct Array {
  Ptr32<void> vt;
  unsigned short references;
  char p6[18];
  unsigned count;
  unsigned short locks;
  char q[2];
  unsigned char data[1];
};
struct WordArray { char p[32]; unsigned data[1]; };
extern "C" Ptr32<unsigned char> w3d_k5b_array_ref_lock_801ef048(Ptr32<Ptr32<Array>>, unsigned, unsigned, unsigned);
inline Ptr32<unsigned char> lock_for_write(Ptr32<Ptr32<Array>> ref) {
  Ptr32<Array> a = *ref;
  unsigned n = a->count;
  if (a->references == 1) { a->locks++; return a->data; }
  return w3d_k5b_array_ref_lock_801ef048(ref, n, 1, 2);
}
inline const unsigned &v_max(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
struct Texture {
  char p0[24];
  int mode;
  Ptr32<WordArray> offsets;
  Ptr32<WordArray> formats;
  char p36[6];
  unsigned short levels;
  unsigned short width;
  unsigned short height;
  Ptr32<Array> pixels;
};
struct Owner { char p[44]; int force; };
struct Second { int x; };
extern "C" void fn_801afac0(Ptr32<Texture>);
extern "C" void fn_801b0a14(Ptr32<unsigned char>, int, int, int, Ptr32<unsigned char>, int, int, int, int);
extern "C" int w3d_d29e_build_mip_chain_801d9ca4(Ptr32<Second> base, Ptr32<Texture> t) {
  Ptr32<Owner> o = base ? w3d::R((Ptr32<Owner>)((Ptr32<char>)base - 4)) : 0;
  unsigned h = t->height, w = t->width;
  unsigned m = v_max(h, w);
  unsigned levels = 0;
  int force = o->force;
  while (m) { levels++; m >>= 1; }
  if (force == 0 && t->levels == levels) return 0;
  t->levels = levels;
  fn_801afac0(t);
  Ptr32<unsigned int> formats = t->formats->data;
  Ptr32<unsigned int> offsets = t->offsets->data;
  Ptr32<unsigned char> dst = lock_for_write(&t->pixels);
  for (unsigned i = 1; i < levels; i++) {
    unsigned nw = w >> 1, nh = h >> 1;
    if (!nw) nw = 1;
    if (!nh) nh = 1;
    fn_801b0a14(dst + offsets[i - 1], formats[i - 1], h, w, dst + offsets[i], formats[i], nh, nw, t->mode);
    h = nh;
    w = nw;
  }
  return 0;
}


