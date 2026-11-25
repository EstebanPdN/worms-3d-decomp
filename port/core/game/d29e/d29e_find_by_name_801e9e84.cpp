#include "w3d_ptr.h"
#line 1 "d29e_find_by_name_801e9e84.cpp"
// (Worms 3D GameCube PAL, 0x801e9e84).
//
// Finds a registered item by name: builds the name hash table at +72 on
// first use (32-byte object from 0x801fe1d8, 16 buckets) from the vector at
// +60, then looks the name up through 0x8020cbcc and returns the vector
// element (0x801e9db8) or null. Names are inferred.

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
struct HashTable;
extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned);
extern "C" Ptr32<HashTable> w3d_k6b_hash_table_construct_8020cab0(Ptr32<void>, int);
extern "C" int w3d_cx9b_hashed_string_index_8020cbcc(Ptr32<HashTable>, Ptr32<const char>, Ptr32<void>);
extern "C" int fn_8020cc90(Ptr32<HashTable>, String &, unsigned short);
struct Item { Ptr32<const char> name; };
struct Set { char p[60]; Ptr32<Ptr32<void>> b; Ptr32<Ptr32<void>> e; char q[4]; Ptr32<HashTable> hash; };
extern "C" Ptr32<Ptr32<void>> w3d_s21_vector_get_801e9db8(Ptr32<Set>, unsigned);
extern "C" Ptr32<Ptr32<void>> w3d_d29e_find_by_name_801e9e84(Ptr32<Set> self, Ptr32<const char> name) {
  unsigned short idx[4];
  if (!self->hash) {
    unsigned i = 0;
    self->hash = w3d_k6b_hash_table_construct_8020cab0(w3d_heap_allocate_entry_a(32), 16);
    unsigned n = self->e - self->b;
    for (; i < n; i++) {
      Ptr32<Item> item = *(Ptr32<Ptr32<Item>>)w3d_s21_vector_get_801e9db8(self, i);
      Ptr32<HashTable> h = self->hash;
      String s(item->name);
      fn_8020cc90(h, s, i);
    }
  }
  Ptr32<Ptr32<void>> r;
  if (w3d_cx9b_hashed_string_index_8020cbcc(self->hash, name, idx) < 0) r = 0;
  else r = w3d_s21_vector_get_801e9db8(self, idx[0]);
  return r;
}


