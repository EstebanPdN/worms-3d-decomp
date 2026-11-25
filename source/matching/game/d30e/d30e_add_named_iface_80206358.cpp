// (Worms 3D GameCube PAL, 0x80206358).
//
// Grows the compact array at +36 by one, stores the interface in the new
// slot with reference counting and appends its name string to the vector at
// +48 through unmodified STLport push_back. Returns 0. Names are inferred.

#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_base_init(String *);
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
extern "C" unsigned short *w3d_string_header(String *);
struct String {
  char *p;
  String(const char *);
  String(const String &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &);
};
struct Iface { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct Slots { unsigned n; int cap; Iface **d; Iface *&at(unsigned i) { return d[i]; } };
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(Slots *, unsigned);
struct S { char q[36]; Slots slots; std::vector<String> names; };
extern "C" int w3d_d30e_add_named_iface_80206358(S *self, Iface *obj, const char *name) {
  Slots &sl = self->slots;
  w3d_cx11b_compact_vector_grow_80210d54(&sl, self->slots.n + 1);
  Iface *&slot = *(Iface **)(self->slots.n * 4 + (int)sl.d);
  if (obj) obj->AddRef();
  if (slot) slot->Release();
  slot = obj;
  self->slots.n++;
  self->names.push_back(String(name));
  return 0;
}
