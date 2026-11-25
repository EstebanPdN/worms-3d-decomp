// GWMP8P rev0 0x8028f4ac. Selects a scheme by name: an empty by-value name
// just exports the current scheme; otherwise it searches DATA.LockedSchemes
// and DATA.Schemes for the name, copies the matching scheme into
// GM.SchemeData through a fresh tagged object, exports it and posts
// FE.PopulateTable with 'Schemes'. Field names are inferred; the unit owns
// no data.
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
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const String_803426b8 &);
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
};
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name; Cache_8015f704(const char *); };
struct Key { const char *text; Key(const char *p) : text(p) {} Key(const String_803426b8 &s) : text(s.text) {} };
struct Entry { char pad[20]; const char *name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Entry *items[1]; };
struct Data { char pad[20]; List *list; };
struct Message;
extern char lbl_803d0150[], lbl_803d0164[], lbl_803d0174[], lbl_803d01ac[], lbl_803d01c0[], lbl_80413b28[];
extern void *lbl_804b1754;
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Data *w3d_auto_801797b4(Obj *);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" int strcmp(const char *, const char *);
inline int Same(const char *a, const char *b) { return strcmp(a, b) == 0; }
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" Obj *w3d_s10_service_forward_8020b680(void *);
extern "C" void f3c_propagate_tag_801ea4c8(Obj *, void *);
extern "C" void w3d_export_scheme_8028fb10(void *);
extern "C" Message *tsonnet_b33_arena_801613f0(void *, int), *w3d_message_string_init(Message *, unsigned short, const char *);
extern "C" unsigned w3d_cached_message_id(Cache_8015f704 *, int);
extern "C" int w3d_message_post_current(Message *);
inline Obj *Create(void *type) { return w3d_s10_service_forward_8020b680(type); }
inline void attach(const Handle &o, const Handle &s, Entry *entry) {
    ((void (*)(Obj *, int))s.p->table[14])(s.p, 2);
    ((void (*)(Obj *, Entry *))s.p->table[6])(s.p, entry);
    Obj *target = o.p;
    f3c_propagate_tag_801ea4c8(target, ((void *(*)(Obj *))s.p->table[16])(s.p));
}
extern "C" void d29f_select_scheme_8028f4ac(void *self, String name) {
    if (name.Length() == 0) {
        w3d_export_scheme_8028fb10(self);
        return;
    }
    Handle data;
    String names[2];
    w3d_string_assign(&names[0], lbl_803d0150);
    w3d_string_assign(&names[1], lbl_803d0164);
    Handle store;
    if (w3d_constructor_lookup_name(lbl_803d0174, store) < 0)
        return;
    for (unsigned i = 0; i <= 1; i++) {
        if (w3d_constructor_lookup_name(names[i], data) < 0) {
            DebugNote(names[i]);
            continue;
        }
        List *list = w3d_auto_801797b4(w3d_empty_80341584(data.p))->list;
        unsigned count = list->count;
        Entry **items = list->items;
        if (count == 0)
            continue;
        for (unsigned j = 0; j < count; j++) {
            if (Same(items[j]->name, name.text)) {
                Entry *entry = items[j];
                {
                    Descriptor_80178474 tag;
                    Handle result;
                    result = Handle(w3d_auto_80179598(w3d_empty_80341584(store.p), &tag));
                    attach(result, Handle(Create(lbl_80413b28)), entry);
                }
                w3d_export_scheme_8028fb10(self);
                Cache_8015f704 cache(lbl_803d01ac);
                Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
                w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d01c0));
                return;
            }
        }
    }
}
