// (Worms 3D GameCube PAL, 0x801dd7a8).
//
// Adds a gain entry for a ready source: returns 0x80004005 for a null or
// unready source; otherwise builds a 16-byte entry (constructor 0x801daf38,
// bind 0x801dafbc taking the reference by value) and appends it to the
// vector at +60 with unmodified STLport push_back. Returns 0. Names are
// inferred.

#include "compat/stlport_sn_oom.h"
#include <vector>
struct Unk { virtual void v0(); virtual void AddRef(); virtual void Release(); virtual void v3(),v4(),v5(),v6(); virtual int ready(); };
struct URef {
  Unk *p;
  URef(const URef &o) { p = o.p; if (p) p->AddRef(); }
};
struct Gain {
  Unk *p; int a; int b; float g;
  Gain();
  Gain(const Gain &o) { p = o.p; if (p) p->AddRef(); a = o.a; b = o.b; g = o.g; }
  ~Gain();
  Gain &operator=(const Gain &);
  void bind(URef, int);
};
struct S { char q[60]; std::vector<Gain> gains; };
extern "C" int w3d_d30e_add_gain_801dd7a8(S *self, URef *src, int t) {
  if (!src->p || !src->p->ready()) return 0x80004005;
  Gain g;
  g.bind(*src, t);
  self->gains.push_back(g);
  return 0;
}
