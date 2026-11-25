// GWMP8P rev0 0x80298e84. Reloads the temporary team store from the user
// properties, then finds the barracks team with the store's name and copies
// the store into it through a new tagged object. An unknown name only copies
// the string for an empty debug note. Field names are inferred; the unit
// owns no data.
// Observed handle, tag, cache and team list views; roles inferred.
struct Obj { void **table; };
inline void retain(Obj *p) { if (p) ((void (*)(Obj *))p->table[3])(p); }
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(Obj *x) : p(x) { retain(p); }
    Handle(const Handle &o) : p(o.p) { retain(p); }
    ~Handle() { release(p); }
    Handle &operator=(const Handle &o) { Obj *next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *), w3d_auto_8015f558(void *, int);
struct String { char *text; String(const String &); ~String() { w3d_string_base_finish(this); w3d_string_release(this); } };
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name; Cache_8015f704(const char *); };
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Team { char pad[60]; String name; };
struct Entry { char pad[60]; const char *name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Entry *items[1]; };
struct Data { char pad[24]; List *list; };
extern char lbl_803d097c[], lbl_803d0940[], lbl_80413b28[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Team *w3d_auto_801797b4(Obj *);
extern "C" int strcmp(const char *, const char *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" Obj *w3d_s10_service_forward_8020b680(void *);
extern "C" void f3c_propagate_tag_801ea4c8(Entry *, void *);
extern "C" void fn_80297b8c(void *);
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String::String(const String &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
inline Obj *Create(void *type) { return w3d_s10_service_forward_8020b680(type); }
inline void attach(Entry *o, const Handle &s, Team *team) {
    ((void (*)(Obj *, int))s.p->table[14])(s.p, 2);
    ((void (*)(Obj *, Team *))s.p->table[6])(s.p, team);
    f3c_propagate_tag_801ea4c8(o, ((void *(*)(Obj *))s.p->table[16])(s.p));
}
inline int Same(const char *a, const char *b) { return strcmp(a, b) == 0; }
extern "C" void d27f_commit_team_store_80298e84(void *self) {
    fn_80297b8c(self);
    Handle data;
    Handle store;
    Descriptor_80178474 descriptor;
    Entry *entry = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
        return;
    if (w3d_constructor_lookup_name(lbl_803d0940, store) < 0)
        return;
    Handle result;
    result = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &descriptor));
    Team *team = w3d_auto_801797b4(w3d_empty_80341584(store.p));
    List *list = ((Data *)result.p)->list;
    unsigned count = list->count;
    Entry **items = list->items;
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
