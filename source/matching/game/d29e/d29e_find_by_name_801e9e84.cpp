// (Worms 3D GameCube PAL, 0x801e9e84).
//
// Finds a registered item by name: builds the name hash table at +72 on
// first use (32-byte object from 0x801fe1d8, 16 buckets) from the vector at
// +60, then looks the name up through 0x8020cbcc and returns the vector
// element (0x801e9db8) or null. Names are inferred.

struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
  char *p;
  String(const char *);
  String(const String &);
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct HashTable;
extern "C" void *w3d_heap_allocate_entry_a(unsigned);
extern "C" HashTable *w3d_k6b_hash_table_construct_8020cab0(void *, int);
extern "C" int w3d_cx9b_hashed_string_index_8020cbcc(HashTable *, const char *, void *);
extern "C" int fn_8020cc90(HashTable *, String &, unsigned short);
struct Item { const char *name; };
struct Set { char p[60]; void **b, **e; char q[4]; HashTable *hash; };
extern "C" void **w3d_s21_vector_get_801e9db8(Set *, unsigned);
extern "C" void **w3d_d29e_find_by_name_801e9e84(Set *self, const char *name) {
  unsigned short idx[4];
  if (!self->hash) {
    unsigned i = 0;
    self->hash = w3d_k6b_hash_table_construct_8020cab0(w3d_heap_allocate_entry_a(32), 16);
    unsigned n = self->e - self->b;
    for (; i < n; i++) {
      Item *item = *(Item **)w3d_s21_vector_get_801e9db8(self, i);
      HashTable *h = self->hash;
      String s(item->name);
      fn_8020cc90(h, s, i);
    }
  }
  void **r;
  if (w3d_cx9b_hashed_string_index_8020cbcc(self->hash, name, idx) < 0) r = 0;
  else r = w3d_s21_vector_get_801e9db8(self, idx[0]);
  return r;
}
