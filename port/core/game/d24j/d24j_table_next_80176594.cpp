#include "w3d_ptr.h"
#line 1 "d24j_table_next_80176594.cpp"
// Advance a table iterator (Worms 3D GameCube PAL, 0x80176594).
//
// Skips empty slots from *idx up to the count at +2116. Returns 0 at the end;
// otherwise advances *idx, replaces the caller's handle with the slot's item
// (retain new, release old) and returns 1.

struct Ref { Ptr32<Ptr32<void>> vtable; void retain() { ((Ptr32<void (Ptr32<Ref>)>)vtable[3])(this); } void release() { ((Ptr32<void (Ptr32<Ref>)>)vtable[4])(this); } };
struct Table { char u[24]; Ptr32<Ptr32<Ref>> data; char u2[2088]; unsigned count;
  unsigned size() { return count; }
  Ptr32<Ref> get(unsigned i) { return data[i]; }
  Ptr32<Ref> & at(unsigned i) { return data[i]; }
};
extern "C" int d24j_table_next_80176594(Ptr32<Table> t, Ptr32<unsigned int> idx, Ptr32<Ptr32<Ref>> out) {
 while (*idx < t->count && t->get(*idx) == 0) ++*idx;
 if (*idx >= t->count) return 0;
 Ptr32<Ptr32<Ref>> d = t->data;
 unsigned i = (*idx)++;
    if (d[i]) d[i]->retain(); if (*out) (*out)->release(); *out = d[i]; return 1; }


