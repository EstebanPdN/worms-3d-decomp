// (Worms 3D GameCube PAL, 0x801aecf0).
//
// Reads the entry list from a reader: gets the count through slot 40,
// reserves the vector at +20, then for each entry reads its identifier
// (Type), object (Graph) and name (Name) through slots 36, 6 and 35 and
// appends it with unmodified STLport push_back. Returns the last result; a
// failure stops at once. Names are inferred.

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
  String(const String &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &);
};

struct Guid { int w0, w1, w2, w3; };
struct Entry { void *obj; Guid id; String name;
  Entry() { obj = 0; }
  Entry &operator=(const Entry &);
};
extern char lbl_803aa754[], lbl_803aa75c[], lbl_803aa764[];
struct Reader { virtual void v0(),v1(),v2(),v3(),v4(),v5(); virtual int graph(void *, const char *); virtual void v7(),v8(),v9(),v10(),v11(),v12(),v13(),v14(),v15(),v16(),v17(),v18(),v19(),v20(),v21(),v22(),v23(),v24(),v25(),v26(),v27(),v28(),v29(),v30(),v31(),v32(),v33(),v34(); virtual int name(String *, const char *); virtual int guid(Guid *, const char *); virtual void v37(),v38(),v39(); virtual int count(unsigned *, const char *); };
typedef std::vector<Entry> Items;
template <> void Items::reserve(unsigned);
struct S { char q[20]; Items items; };
extern "C" int w3d_d30e_read_entries_801aecf0(S *self, Reader *r) {
  unsigned n;
  int hr = r->count(&n, lbl_803aa754);
  if (hr < 0) return hr;
  self->items.reserve(n);
  while (n--) {
    Entry e;
    hr = r->guid(&e.id, lbl_803aa754);
    if (hr < 0) return hr;
    hr = r->graph(&e.obj, lbl_803aa75c);
    if (hr < 0) return hr;
    hr = r->name(&e.name, lbl_803aa764);
    if (hr < 0) return hr;
    self->items.push_back(e);
  }
  return hr;
}
