// (Worms 3D GameCube PAL, 0x801af118).
//
// Appends a 24-byte entry (interface pointer, 16-byte identifier, name
// string) to the vector at +20 with unmodified STLport push_back, then adds
// a reference to the interface. Returns 0. Names are inferred.

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
struct Base { virtual void v0(); virtual void AddRef(); };
struct Guid { int w0, w1, w2, w3; };
struct Entry { Base *obj; Guid id; String name;
  Entry(Base *o, const Guid &g, const String &n) : obj(o), id(g), name(n) {}
  Entry &operator=(const Entry &);
};
struct S { char q[20]; std::vector<Entry> items; };
extern "C" int w3d_d30e_add_named_entry_801af118(S *self, const Guid *id, Base *obj, const String *name) {
  self->items.push_back(Entry(obj, *id, *name));
  obj->AddRef();
  return 0;
}
