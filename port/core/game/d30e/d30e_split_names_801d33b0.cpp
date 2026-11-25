#include "w3d_ptr.h"
#line 1 "d30e_split_names_801d33b0.cpp"
// (Worms 3D GameCube PAL, 0x801d33b0).
//
// Parses a list of names separated by vertical bars: clears the string
// vector at +48, then appends each name through unmodified STLport push_back
// using a 64-byte copy buffer and sets the multiple flag at +64; a text with
// no bar is assigned to the single string at +40 and clears the flag.
// Returns 0. Names are inferred.

#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
struct String {
  Ptr32<char> p;
  template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 String &operator=(const char *);
  String(const String &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &);
};
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
#include <string.h>
struct S { char q[40]; String single; int x44; std::vector<String> names; int multi; };
extern "C" int w3d_d30e_split_names_801d33b0(Ptr32<S> self, Ptr32<const char> text) {
  self->names.clear();
  Ptr32<const char> bar = strchr(text, '|');
  if (bar) {
    Ptr32<const char> p = text;
    char buf[64];
    do {
      int n = bar - p;
      memcpy(buf, p, n);
      buf[n] = 0;
      self->names.push_back(String(buf));
      p = bar + 1;
      bar = strchr(p, '|');
    } while (bar);
    self->names.push_back(String(p));
    self->multi = 1;
  } else {
    self->single = text;
    self->multi = 0;
  }
  return 0;
}


