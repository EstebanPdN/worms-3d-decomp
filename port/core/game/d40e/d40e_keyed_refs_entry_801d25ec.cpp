#include "w3d_ptr.h"
#line 1 "d40e_keyed_refs_entry_801d25ec.cpp"
// (Worms 3D GameCube PAL, 0x801d25ec).
//
// Sets the entry for key (id, object) in a map to a value holding a copy of the
// given array of object references. The map is real STLport: operator[] is
// inlined, with the hinted tree insert out of line at 0x80355fa0. Returns 0.
// Names are inferred.

#pragma interface
#include "compat/stlport_sn_oom.h"
#include <map>
struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Ref {
    Ptr32<Obj> p;
    Ref() : p(0) { }
    bool operator<(const Ref &o) const { return p < o.p; }
    Ref(const Ref &o) : p(o.p) { if (p) p->AddRef(); }
    ~Ref() { if (p) p->Release(); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; }
};
struct Key {
    unsigned id;
    Ref ref;
};
inline bool operator<(const Key &a, const Key &b) {
    return a.id < b.id || (a.id == b.id && a.ref < b.ref);
}
struct Refs; extern "C" Ptr32<void> w3d_copy_refs_801f2698(Ptr32<Refs>, Ptr32<const Refs>);
struct Refs {
    int n; int cap; Ptr32<Ref> data;
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
extern "C" int w3d_d40e_keyed_refs_entry_801d25ec(Ptr32<void> self, Ptr32<Obj> object, unsigned id, Ptr32<Ptr32<Obj>> refs, unsigned count, Ptr32<Map> entries) {
    Key k;
    k.ref = object;
    k.id = id;
    Value v;
    v.refs.resize(count);
    for (unsigned i = 0; i < count; i++) v.refs.data[i] = refs[i];
    (*entries)[k] = v;
    return 0;
}


