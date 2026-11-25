#include "w3d_ptr.h"
#line 1 "d27f_commit_team_store_80298e84.cpp"
// GWMP8P rev0 0x80298e84. Reloads the temporary team store from the user
// properties, then finds the barracks team with the store's name and copies
// the store into it through a new tagged object. An unknown name only copies
// the string for an empty debug note. Field names are inferred; the unit
// owns no data.
// Observed handle, tag, cache and team list views; roles inferred.
struct Obj { Ptr32<Ptr32<void>> table; };
inline void retain(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[3])(p); }
inline void release(Ptr32<Obj> p) { if (p) ((Ptr32<void (Ptr32<Obj>)>)p->table[4])(p); }
struct Handle {
    Ptr32<Obj> p;
    Handle() : p(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Obj *)w3d_p.get()) {}
 Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Ptr32<Obj> next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>), w3d_auto_8015f558(Ptr32<void>, int);
struct String { Ptr32<char> text; String(const String &); ~String() { w3d_string_base_finish(this); w3d_string_release(this); } };
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name __attribute__((aligned(__alignof__(CacheBase)))); template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char *); };
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct Team { char pad[60]; String name; };
struct Entry { char pad[60]; Ptr32<const char> name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Ptr32<Entry> items[1]; };
struct Data { char pad[24]; Ptr32<List> list; };
extern char lbl_803d097c[], lbl_803d0940[], lbl_80413b28[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Team> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Obj> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void f3c_propagate_tag_801ea4c8(Ptr32<Entry>, Ptr32<void>);
extern "C" void fn_80297b8c(Ptr32<void>);
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
inline String::String(const String &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
inline Ptr32<Obj> Create(Ptr32<void> type) { return w3d_s10_service_forward_8020b680(type); }
inline void attach(Ptr32<Entry> o, const Handle &s, Ptr32<Team> team) {
    ((Ptr32<void (Ptr32<Obj>, int)>)s.p->table[14])(s.p, 2);
    ((Ptr32<void (Ptr32<Obj>, Ptr32<Team>)>)s.p->table[6])(s.p, team);
    f3c_propagate_tag_801ea4c8(o, ((Ptr32<Ptr32<void> (Ptr32<Obj>)>)s.p->table[16])(s.p));
}
inline int Same(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) == 0; }
extern "C" void d27f_commit_team_store_80298e84(Ptr32<void> self) {
    fn_80297b8c(self);
    Handle data;
    Handle store;
    Descriptor_80178474 descriptor;
    Ptr32<Entry> entry = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
        return;
    if (w3d_constructor_lookup_name(lbl_803d0940, store) < 0)
        return;
    Handle result;
    result = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &descriptor));
    Ptr32<Team> team = w3d_auto_801797b4(w3d_empty_80341584(store.p));
    Ptr32<List> list = ((Ptr32<Data>)result.p)->list;
    unsigned count = list->count;
    Ptr32<Ptr32<Entry>> items = list->items;
    for (unsigned i = 0; i < count; i++) {
        if (Same(items[i]->name, team->name.text)) {
            entry = items[i];
            Descriptor_80178474 local;
            attach(entry, Handle(Create(lbl_80413b28)), team);
            return;
        }
    }
    DebugNote(team->name);
}


