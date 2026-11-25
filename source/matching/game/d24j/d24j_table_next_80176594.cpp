// Advance a table iterator (Worms 3D GameCube PAL, 0x80176594).
//
// Skips empty slots from *idx up to the count at +2116. Returns 0 at the end;
// otherwise advances *idx, replaces the caller's handle with the slot's item
// (retain new, release old) and returns 1.

struct Ref { void **vtable; void retain() { ((void (*)(Ref *))vtable[3])(this); } void release() { ((void (*)(Ref *))vtable[4])(this); } };
struct Table { char u[24]; Ref **data; char u2[2088]; unsigned count;
  unsigned size() { return count; }
  Ref *get(unsigned i) { return data[i]; }
  Ref *&at(unsigned i) { return data[i]; }
};
extern "C" int d24j_table_next_80176594(Table *t, unsigned *idx, Ref **out) {
 while (*idx < t->count && t->get(*idx) == 0) ++*idx;
 if (*idx >= t->count) return 0;
 Ref **d = t->data;
 unsigned i = (*idx)++;
    if (d[i]) d[i]->retain(); if (*out) (*out)->release(); *out = d[i]; return 1; }
