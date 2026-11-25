// (Worms 3D GameCube PAL, 0x801b2fc0).
//
// Appends a name string to the vector at +28 and an interface pointer to the
// vector at +44 through unmodified STLport push_back, then adds a reference.
// Returns 0x80070057 for a null name or interface, otherwise 0. Names are
// inferred.

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
struct S { char q[28]; std::vector<String> names; std::vector<Iface *> items; };
extern "C" int w3d_d30e_add_named_item_801b2fc0(S *self, const char *name, Iface *obj) {
  if (!obj || !name) return 0x80070057;
  self->names.push_back(String(name));
  self->items.push_back(obj);
  obj->AddRef();
  return 0;
}
