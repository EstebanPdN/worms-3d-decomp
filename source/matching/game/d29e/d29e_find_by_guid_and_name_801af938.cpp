// (Worms 3D GameCube PAL, 0x801af938).
//
// Searches the 24-byte-ish entries at +20 for one matching a 16-byte id and
// a name held in a temporary String; on a hit stores the entry's object
// through out, adds a reference and returns 0, otherwise stores null and
// returns 0x80004005. As in the original the search loop has no advance: a
// non-matching first entry never ends. Names are inferred.

struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
  char *p;
  String(const char *);
  String(const String &);
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
extern "C" int memcmp(const void *, const void *, unsigned);
extern "C" int strcmp(const char *, const char *);
struct Iface { virtual void v0(); virtual void add(); virtual void release(); };
struct Entry { Iface *obj; char guid[16]; const char *name; };
struct Range { Entry *first, *last; };
struct Registry { char p[20]; Range entries; };
extern "C" int w3d_d29e_find_by_guid_and_name_801af938(Registry *self, const void *guid, const char *name, Iface **out) {
  Entry *it = self->entries.first;
  String s(name);
  Range &r = self->entries;
  for (;;) {
    goto test;
next:
    if (memcmp(it->guid, guid, 16) == 0 && strcmp(s.p, it->name) == 0) break;
test:
    if (it != r.last) goto next;
    break;
  }
  if (it == self->entries.last) {
    *out = 0;
    return 0x80004005;
  }
  Iface *o = it->obj;
  *out = o;
  o->add();
  return 0;
}
