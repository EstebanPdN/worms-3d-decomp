// (Worms 3D GameCube PAL, 0x8020777c).
//
// Slot table allocation: acquires a cleared record, reuses the head of the
// free list when one is available, otherwise appends to the slot array,
// growing it by half through malloc, and returns the slot index.

extern "C" void *w3d_s21_acquire_cleared_80207490();
extern "C" void *memcpy(void *, const void *, unsigned, ...);
extern "C" void *malloc(unsigned);
extern "C" void free_802134fc(void *);
inline const int &v_max(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &v_min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
struct Slots {
  char *begin, *end, *cap;
  int size() const { return (int *)end - (int *)begin; }
  int &operator[](unsigned i) { return ((int *)begin)[i]; }
  void push_back(const int &x) {
    if (end == cap) {
      unsigned used = end - begin;
      unsigned bytes = v_max((int)(used + 1), (int)(used + (used >> 1))) * sizeof(int);
      char *data = (char *)malloc(bytes);
      if (begin) { memcpy(data, begin, v_min(bytes, used)); free_802134fc(begin); }
      begin = data; end = data + used; cap = data + bytes;
    }
    *(int *)end = x;
    end += sizeof(int);
  }
};
struct Table { char p[36]; Slots slots; int free; };
extern "C" int w3d_d42e_slot_table_acquire_8020777c(Table *self) {
  int v = (int)w3d_s21_acquire_cleared_80207490();
  int idx = self->free;
  if (idx != 0) {
    int &item = self->slots[idx];
    self->free = item;
    item = v;
    return idx;
  }
  int n = self->slots.size();
  self->slots.push_back(v);
  return n;
}
