// GWMP8P rev0 0x8020cc90. Adds or updates a named value in a string hash
// table with chained 16-bit indices, using real STLport 4.5.3 vector growth.
// Names are inferred; the Str and entry classes are partial views.
#include "compat/stlport_sn_oom.h"
#include <vector>
#include <cstring>
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *);
struct D32kStrHeader { unsigned short refs, length, capacity; };
extern "C" D32kStrHeader *fn_80341884(void *);
struct D32kStr {
 char *p;
 D32kStr(const D32kStr &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~D32kStr() { fn_8020c5c4(this); fn_80341588(this); }
};
struct D32kEntry {
 D32kStr name; unsigned short value, next;
 D32kEntry(const D32kStr &n, unsigned short v) : name(n), value(v), next(0) {}
 D32kEntry(const D32kEntry &o) : name(o.name) { value = o.value; next = o.next; }
};
struct D32kStringTable {
 unsigned short *buckets; unsigned mask; int u8;
 _STL::vector<D32kEntry> entries;
 int Insert(const D32kStr &name, unsigned short value);
};
inline unsigned Hash(const char *p) {
 unsigned h = 5381;
 const unsigned char *s = (const unsigned char *)p; unsigned char c;
 for (; (c = *s++) != 0; ) h = ((h << 5) + h) ^ c;
 return h;
}
int D32kStringTable::Insert(const D32kStr &name, unsigned short value) {
 unsigned h = Hash(name.p);
 unsigned short idx = buckets[h & mask];
 if (idx != 0) {
  for (;;) {
   D32kEntry *e = &entries[idx - 1];
   if (strcmp(e->name.p, name.p) == 0) { e->value = value; return 0; }
   unsigned short n = e->next;
   if (n != 0) { idx = n; continue; }
   e->next = entries.size() + 1;
   entries.push_back(D32kEntry(name, value));
  }
 }
 buckets[h & mask] = entries.size() + 1;
 entries.push_back(D32kEntry(name, value));
 return 1;
}
