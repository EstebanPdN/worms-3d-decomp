#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c26_lookup_int_80206920.c"
struct Entry { Ptr32<const char> name; Ptr32<const char> value; };
extern Ptr32<struct Entry> fn_802068fc(Ptr32<const char>, Ptr32<int>);
extern int fn_802ef074(Ptr32<const char>, Ptr32<const char>);
extern int atoi(Ptr32<const char>);
int tsonnet_c26_lookup_int_80206920(Ptr32<const char> key, Ptr32<int> out) {
 Ptr32<struct Entry> e = fn_802068fc(key, out);
 if (e == 0) return 0x80004005;
 while (e->name) {
  if (fn_802ef074(e->name, key) == 0) { *out = atoi(e->value); return 0; }
  e++;
 }
 return 0x80004005;
}

}
