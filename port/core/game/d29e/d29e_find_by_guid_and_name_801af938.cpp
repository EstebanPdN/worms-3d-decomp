#include "w3d_ptr.h"
#line 1 "d29e_find_by_guid_and_name_801af938.cpp"
// (Worms 3D GameCube PAL, 0x801af938).
//
// Searches the 24-byte-ish entries at +20 for one matching a 16-byte id and
// a name held in a temporary String; on a hit stores the entry's object
// through out, adds a reference and returns 0, otherwise stores null and
// returns 0x80004005. As in the original the search loop has no advance: a
// non-matching first entry never ends. Names are inferred.

struct String;
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
struct String {
  Ptr32<char> p;
  template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
  String(const String &);
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" int memcmp(Ptr32<const void>, Ptr32<const void>, unsigned);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
struct Iface { void w3d_r_v0() __asm__(W3D_SYM("_ZN5Iface2v0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
struct Entry { Ptr32<Iface> obj; char guid[16]; Ptr32<const char> name; };
struct Range { Ptr32<Entry> first; Ptr32<Entry> last; };
struct Registry { char p[20]; Range entries; };
extern "C" int w3d_d29e_find_by_guid_and_name_801af938(Ptr32<Registry> self, Ptr32<const void> guid, Ptr32<const char> name, Ptr32<Ptr32<Iface>> out) {
  Ptr32<Entry> it = self->entries.first;
  String s(name);
  Range &r = self->entries;
  for (;;) {
    goto test;
next:
    if (memcmp(it->guid, guid, 16) == 0 && strcmp(s.p, it->name) == 0) break;
test:
    if (it != r.last) goto next;
    break;
  }
  if (it == self->entries.last) {
    *out = 0;
    return 0x80004005;
  }
  Ptr32<Iface> o = it->obj;
  *out = o;
  o->add();
  return 0;
}


