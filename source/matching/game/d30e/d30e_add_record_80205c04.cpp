// (Worms 3D GameCube PAL, 0x80205c04).
//
// Builds a 12-byte record of a counted reference and two strings (default
// constructor 0x803426b8, assignment from text 0x8020bd38) and appends it to
// the vector at +20 through unmodified STLport push_back. Returns 0. Names
// are inferred.

#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_base_init(String *);
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
extern "C" unsigned short *w3d_string_header(String *);
struct String {
  char *p;
  String();
  String(const char *);
  String &operator=(const char *);
  String(const String &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &);
};
struct Iface { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct Ref {
  Iface *p;
  Ref() { p = 0; }
  Ref(const Ref &o) { p = o.p; if (p) p->AddRef(); }
  ~Ref() { if (p) p->Release(); }
  Ref &operator=(Iface *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; }
  Ref &operator=(const Ref &);
};
struct Rec { Ref ref; String a; String b; };
struct S { char q[20]; std::vector<Rec> items; };
extern "C" int w3d_d30e_add_record_80205c04(S *self, Iface *obj, const char *bname, const char *aname) {
  Rec r;
  r.ref = obj;
  r.a = aname;
  r.b = bname;
  self->items.push_back(r);
  return 0;
}
