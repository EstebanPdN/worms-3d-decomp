#include "w3d_ptr.h"
#line 1 "d27f_select_barracks_team_80297620.cpp"
// GWMP8P rev0 0x80297620. Copies a barracks team into the temporary team
// store: finds the team named by the by-value string, or the first unlocked
// team when the name is empty, attaches a fresh object to the store's tagged
// value, then repopulates the frontend table. Field names are inferred from
// the observed offsets and the strings; the unit owns no data.
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
struct Team { char pad[60]; Ptr32<const char> name; int locked; };
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Ptr32<Team> items[1]; };
struct Data { char pad[24]; Ptr32<TeamList> teams; };
struct Message;
extern char lbl_803d0940[], lbl_803d097c[], lbl_803d09c4[], lbl_803d09d8[], lbl_803d09e0[], lbl_80413b28[];
extern Ptr32<void> lbl_804b1754;
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Data> w3d_auto_801797b4(Ptr32<Obj>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<Obj> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void f3c_propagate_tag_801ea4c8(Ptr32<Obj>, Ptr32<void>);
extern "C" void fn_80299630(Ptr32<void>), fn_802979b8(Ptr32<void>), w3d_auto_80299a74(Ptr32<void>);
extern "C" Ptr32<Message> tsonnet_b33_arena_801613f0(Ptr32<void>, int); Ptr32<Message> w3d_message_string_init(Ptr32<Message>, unsigned short, Ptr32<const char>);
extern "C" unsigned w3d_cached_message_id(Ptr32<Cache_8015f704>, int);
extern "C" int w3d_message_post_current(Ptr32<Message>);
inline void post(Ptr32<Cache_8015f704> cache, Ptr32<const char> text) { Ptr32<Message> m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12); w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(cache, 1), text)); }
inline Ptr32<Obj> Create(Ptr32<void> type) { return w3d_s10_service_forward_8020b680(type); }
inline void attach(const Handle &o, const Handle &s, Ptr32<Team> team) {
    ((Ptr32<void (Ptr32<Obj>, int)>)s.p->table[14])(s.p, 2);
    ((Ptr32<void (Ptr32<Obj>, Ptr32<Team>)>)s.p->table[6])(s.p, team);
    Ptr32<Obj> target = o.p;
    f3c_propagate_tag_801ea4c8(target, ((Ptr32<Ptr32<void> (Ptr32<Obj>)>)s.p->table[16])(s.p));
}
extern "C" void d27f_select_barracks_team_80297620(Ptr32<void> self, String name) {
    fn_80299630(self);
    Handle barracks;
    Ptr32<Team> team = 0;
    Handle store;
    if (w3d_constructor_lookup_name(lbl_803d0940, store) < 0)
        return;
    if (w3d_constructor_lookup_name(lbl_803d097c, barracks) >= 0) {
        Ptr32<TeamList> list = w3d_auto_801797b4(w3d_empty_80341584(barracks.p))->teams;
        unsigned count = list->count;
        Ptr32<Ptr32<Team>> items = list->items;
        if (count != 0)
            for (unsigned i = 0; i < count; i++) {
                if (strcmp(items[i]->name, name.text) == 0 || (((Ptr32<unsigned short>)name.text)[-2] == 0 && items[i]->locked == 0)) {
                    team = items[i];
                    {
                        Descriptor_80178474 tag;
                        Handle result;
                        result = Handle(w3d_auto_80179598(w3d_empty_80341584(store.p), &tag));
                        attach(result, Handle(Create(lbl_80413b28)), team);
                    }
                    fn_802979b8(self);
                    w3d_auto_80299a74(self);
                    Cache_8015f704 cache(lbl_803d09c4);
                    Ptr32<Message> m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
                    w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d09d8));
                    m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
                    w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d09e0));
                    return;
                }
            }
    }
}


