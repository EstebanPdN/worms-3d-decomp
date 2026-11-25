#include "w3d_ptr.h"
#line 1 "d29f_select_scheme_8028f4ac.cpp"
// GWMP8P rev0 0x8028f4ac. Selects a scheme by name: an empty by-value name
// just exports the current scheme; otherwise it searches DATA.LockedSchemes
// and DATA.Schemes for the name, copies the matching scheme into
// GM.SchemeData through a fresh tagged object, exports it and posts
// FE.PopulateTable with 'Schemes'. Field names are inferred; the unit owns
// no data.
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
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &);
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
};
typedef String_803426b8 String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
struct CacheBase { int prefix[2]; ~CacheBase() { w3d_auto_8015f558(this, 2); } };
struct Cache_8015f704 : CacheBase { String name __attribute__((aligned(__alignof__(CacheBase)))); template <class W3dU> Cache_8015f704(Ptr32<W3dU> w3d_p) : Cache_8015f704((const char *)w3d_p.get()) {}
 Cache_8015f704(const char *); };
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} Key(const String_803426b8 &s) : text(s.text) {} };
struct Entry { char pad[20]; Ptr32<const char> name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Ptr32<Entry> items[1]; };
struct Data { char pad[20]; Ptr32<List> list; };
struct Message;
extern char lbl_803d0150[], lbl_803d0164[], lbl_803d0174[], lbl_803d01ac[], lbl_803d01c0[], lbl_80413b28[];
extern Ptr32<void> lbl_804b1754;
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Data> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
inline int Same(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) == 0; }
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Obj> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void f3c_propagate_tag_801ea4c8(Ptr32<Obj>, Ptr32<void>);
extern "C" void w3d_export_scheme_8028fb10(Ptr32<void>);
extern "C" Ptr32<Message> tsonnet_b33_arena_801613f0(Ptr32<void>, int); Ptr32<Message> w3d_message_string_init(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" unsigned w3d_cached_message_id(Ptr32<Cache_8015f704>, int);
extern "C" int w3d_message_post_current(Ptr32<Message>);
inline Ptr32<Obj> Create(Ptr32<void> type) { return w3d_s10_service_forward_8020b680(type); }
inline void attach(const Handle &o, const Handle &s, Ptr32<Entry> entry) {
    ((Ptr32<void (Ptr32<Obj>, int)>)s.p->table[14])(s.p, 2);
    ((Ptr32<void (Ptr32<Obj>, Ptr32<Entry>)>)s.p->table[6])(s.p, entry);
    Ptr32<Obj> target = o.p;
    f3c_propagate_tag_801ea4c8(target, ((Ptr32<Ptr32<void> (Ptr32<Obj>)>)s.p->table[16])(s.p));
}
extern "C" void d29f_select_scheme_8028f4ac(Ptr32<void> self, String name) {
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
        Ptr32<List> list = w3d_auto_801797b4(w3d_empty_80341584(data.p))->list;
        unsigned count = list->count;
        Ptr32<Ptr32<Entry>> items = list->items;
        if (count == 0)
            continue;
        for (unsigned j = 0; j < count; j++) {
            if (Same(items[j]->name, name.text)) {
                Ptr32<Entry> entry = items[j];
                {
                    Descriptor_80178474 tag;
                    Handle result;
                    result = Handle(w3d_auto_80179598(w3d_empty_80341584(store.p), &tag));
                    attach(result, Handle(Create(lbl_80413b28)), entry);
                }
                w3d_export_scheme_8028fb10(self);
                Cache_8015f704 cache(lbl_803d01ac);
                Ptr32<Message> m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
                w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d01c0));
                return;
            }
        }
    }
}


