// (Worms 3D GameCube PAL, 0x801d25ec).
//
// Sets the entry for key (id, object) in a map to a value holding a copy of the
// given array of object references. The map is real STLport: operator[] is
// inlined, with the hinted tree insert out of line at 0x80355fa0. Returns 0.
// Names are inferred.

#pragma interface
#include "compat/stlport_sn_oom.h"
#include <map>
struct Obj { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct Ref {
    Obj *p;
    Ref() : p(0) { }
    bool operator<(const Ref &o) const { return p < o.p; }
    Ref(const Ref &o) : p(o.p) { if (p) p->AddRef(); }
    ~Ref() { if (p) p->Release(); }
    Ref &operator=(Obj *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; }
};
struct Key {
    unsigned id;
    Ref ref;
};
inline bool operator<(const Key &a, const Key &b) {
    return a.id < b.id || (a.id == b.id && a.ref < b.ref);
}
struct Refs; extern "C" void * w3d_copy_refs_801f2698(Refs *, const Refs *);
struct Refs {
    int n; int cap; Ref *data;
    Refs();
    Refs(const Refs &o) { w3d_copy_refs_801f2698(this, &o); }
    ~Refs();
    Refs &operator=(const Refs &o);
    void resize(unsigned c);
};
struct Triple { int x, y, z; Triple() { } void set(int a, int b, int c) { x = a; y = b; z = c; } Triple(const Triple &o) { set(o.x, o.y, o.z); } };
struct Block { int w[9]; Block() { } };
struct Inner { Block b; Triple v; };
struct Value { Refs refs; Inner in; };
typedef std::map<Key, Value> Map;
template <> Map::_Rep_type::iterator Map::_Rep_type::insert_unique(iterator, const Map::value_type &);
extern "C" int w3d_d40e_keyed_refs_entry_801d25ec(void *self, Obj *object, unsigned id, Obj **refs, unsigned count, Map *entries) {
    Key k;
    k.ref = object;
    k.id = id;
    Value v;
    v.refs.resize(count);
    for (unsigned i = 0; i < count; i++) v.refs.data[i] = refs[i];
    (*entries)[k] = v;
    return 0;
}
