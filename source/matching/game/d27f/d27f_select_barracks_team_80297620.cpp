// GWMP8P rev0 0x80297620. Copies a barracks team into the temporary team
// store: finds the team named by the by-value string, or the first unlocked
// team when the name is empty, attaches a fresh object to the store's tagged
// value, then repopulates the frontend table. Field names are inferred from
// the observed offsets and the strings; the unit owns no data.
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
struct Team { char pad[60]; const char *name; int locked; };
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Team *items[1]; };
struct Data { char pad[24]; TeamList *teams; };
struct Message;
extern char lbl_803d0940[], lbl_803d097c[], lbl_803d09c4[], lbl_803d09d8[], lbl_803d09e0[], lbl_80413b28[];
extern void *lbl_804b1754;
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Data *w3d_auto_801797b4(Obj *);
extern "C" int strcmp(const char *, const char *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" Obj *w3d_s10_service_forward_8020b680(void *);
extern "C" void f3c_propagate_tag_801ea4c8(Obj *, void *);
extern "C" void fn_80299630(void *), fn_802979b8(void *), w3d_auto_80299a74(void *);
extern "C" Message *tsonnet_b33_arena_801613f0(void *, int), *w3d_message_string_init(Message *, unsigned short, const char *);
extern "C" unsigned w3d_cached_message_id(Cache_8015f704 *, int);
extern "C" int w3d_message_post_current(Message *);
inline void post(Cache_8015f704 *cache, const char *text) { Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12); w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(cache, 1), text)); }
inline Obj *Create(void *type) { return w3d_s10_service_forward_8020b680(type); }
inline void attach(const Handle &o, const Handle &s, Team *team) {
    ((void (*)(Obj *, int))s.p->table[14])(s.p, 2);
    ((void (*)(Obj *, Team *))s.p->table[6])(s.p, team);
    Obj *target = o.p;
    f3c_propagate_tag_801ea4c8(target, ((void *(*)(Obj *))s.p->table[16])(s.p));
}
extern "C" void d27f_select_barracks_team_80297620(void *self, String name) {
    fn_80299630(self);
    Handle barracks;
    Team *team = 0;
    Handle store;
    if (w3d_constructor_lookup_name(lbl_803d0940, store) < 0)
        return;
    if (w3d_constructor_lookup_name(lbl_803d097c, barracks) >= 0) {
        TeamList *list = w3d_auto_801797b4(w3d_empty_80341584(barracks.p))->teams;
        unsigned count = list->count;
        Team **items = list->items;
        if (count != 0)
            for (unsigned i = 0; i < count; i++) {
                if (strcmp(items[i]->name, name.text) == 0 || (((unsigned short *)name.text)[-2] == 0 && items[i]->locked == 0)) {
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
                    Message *m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
                    w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d09d8));
                    m = tsonnet_b33_arena_801613f0(lbl_804b1754, 12);
                    w3d_message_post_current(w3d_message_string_init(m, w3d_cached_message_id(&cache, 1), lbl_803d09e0));
                    return;
                }
            }
    }
}
