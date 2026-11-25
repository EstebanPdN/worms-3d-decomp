// GWMP8P rev0 0x8029a238. Looks up the game object and barracks; unless four
// teams are already in the game, finds the barracks team by name and adds it
// through 0x8029a5b4. The count is read directly through the embedded list
// holder and the items through its inline member, so CSE keeps a second load
// that the post-reload pass turns into a register copy.
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
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *), w3d_string_release_header(void *);
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct GameInfo { char pad[92]; int mode; };
struct Entry { char pad[60]; const char *name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Entry *items[1]; Entry **begin() { return items; } };
struct DataSub { int a; List *list; Entry **Items() { return list->begin(); } };
struct Data { char pad[20]; DataSub sub; };
extern char lbl_803d0bf0[], lbl_803d097c[], lbl_803d09e0[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" int strcmp(const char *, const char *);
extern "C" void fn_8029a5b4(void *, Entry *, const char *);
extern "C" void d30f_add_barracks_team_by_name_8029a238(void *self, const char *name) {
    Descriptor_80178474 first;
    Descriptor_80178474 second;
    Handle game;
    Handle teams;
    unsigned count = 0;
    if (w3d_constructor_lookup_name(lbl_803d0bf0, game) < 0)
        return;
    Handle info;
    info = Handle(w3d_auto_80179598(w3d_empty_80341584(game.p), &first));
    if (((GameInfo *)info.p)->mode == 4)
        return;
    if (w3d_constructor_lookup_name(lbl_803d097c, teams) < 0)
        return;
    Handle barracks;
    barracks = Handle(w3d_auto_80179598(w3d_empty_80341584(teams.p), &second));
    unsigned i = 0;
    Data *data = (Data *)barracks.p;
    count = data->sub.list->count;
    Entry **items = data->sub.Items();
    if (i < count)
        do {
            if (strcmp(name, items[i]->name) == 0) {
                fn_8029a5b4(self, items[i], lbl_803d09e0);
                break;
            }
            i++;
        } while (i < count);
}
