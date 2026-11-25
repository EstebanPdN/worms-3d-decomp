#include "w3d_ptr.h"
#line 1 "d29e_remove_entry_801f9c60.cpp"
// (Worms 3D GameCube PAL, 0x801f9c60).
//
// Removes from a vector of 24-byte entries the first one equal to a key and
// a 20-byte descriptor (the sibling of the append at 0x801f99d8; the
// descriptor's constructor writes defaults 3, 4, 0, 0 before the copy
// overwrites them), shifting later entries down. Returns 0, or 0x80004005 if
// not found. Names are inferred.

struct Desc {
  int a, b, c, d, e;
  Desc() : a(3), b(4), c(0), d(0) { }
  bool operator==(const Desc &o) const { if (a != o.a) return false; if (d != o.d) return false; if (b != o.b) return false; return c == o.c; }
  int operator!=(const Desc &o) const { return !(*this == o); }
};
struct Entry {
  Ptr32<void> key;
  Desc desc;
  Entry() { key = 0; }
  ~Entry() { }
  int operator==(const Entry &o) const { if (key != o.key) return 0; return !(desc != o.desc); }
};
template<class T> inline Ptr32<T> v_copy(T *first, T *last, T *out) {
    int n = last - first;
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
struct Vec {
  Ptr32<Entry> start; Ptr32<Entry> finish;
};
extern "C" int w3d_d29e_remove_entry_801f9c60(Ptr32<Vec> self, Ptr32<void> key, Ptr32<const Desc> d) {
  Entry e;
  e.desc = *d;
  e.key = key;
  for (Ptr32<Entry> it = self->start; it != self->finish; ++it) {
    if (*it == e) {
      if (it + 1 != self->finish) v_copy(w3d::R(it + 1), w3d::R(self->finish), w3d::R(it));
      self->finish--;
      return 0;
    }
  }
  return 0x80004005;
}


