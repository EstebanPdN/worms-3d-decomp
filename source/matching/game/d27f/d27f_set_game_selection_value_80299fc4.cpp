// GWMP8P rev0 0x80299fc4. Stores a value of 0 to 3 into the game info field
// paired with the name read from the frontend selection property. Later
// modes test more name fields, falling through from mode 4 to mode 2 and
// then the default field. Field names are inferred; the unit owns no data.
// Observed handle, descriptor, string and team record views; roles inferred.
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
struct GameInfo { char pad[64]; const char *name0; char pad1[24]; unsigned mode; char pad2[48]; const char *name1; char pad3[4]; int value0; char pad4[60]; const char *name2; char pad5[4]; int value1; int value2; char pad6[4]; int value3; char pad7[52]; const char *name3; };
extern char lbl_803d092c[], lbl_803d0bf0[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" int w3d_auto_800fc2b0(const Key &, const char **);
extern "C" int strcmp(const char *, const char *);
extern "C" void d27f_set_game_selection_value_80299fc4(void *, unsigned value) {
    if (value > 3)
        return;
    Descriptor_80178474 descriptor;
    Handle game;
    const char *text;
    w3d_auto_800fc2b0(lbl_803d092c, &text);
    if (w3d_constructor_lookup_name(lbl_803d0bf0, game) < 0)
        return;
    Handle info;
    info = Handle(w3d_auto_80179598(w3d_empty_80341584(game.p), &descriptor));
    GameInfo *g = (GameInfo *)info.p;
    switch (g->mode) {
    case 4:
        if (strcmp(g->name3, text) == 0) {
            ((GameInfo *)info.p)->value3 = value;
            return;
        }
    case 3:
        if (strcmp(((GameInfo *)info.p)->name2, text) == 0) {
            ((GameInfo *)info.p)->value2 = value;
            return;
        }
    case 2:
        if (strcmp(((GameInfo *)info.p)->name1, text) == 0) {
            ((GameInfo *)info.p)->value1 = value;
            return;
        }
    default:
        if (strcmp(((GameInfo *)info.p)->name0, text) == 0) {
            ((GameInfo *)info.p)->value0 = value;
            return;
        }
    }
}
