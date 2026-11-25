#include "w3d_ptr.h"
#line 1 "d27f_set_team_worm_count_80299ca4.cpp"
// GWMP8P rev0 0x80299ca4. Stores a worm count of 1 to 6 for the selected
// team in the game setup. Sums the other teams' counts for the current mode,
// clamps the new count to the 16 worm total and to 6, and ignores the
// request when no worms are left. Field names are inferred; the unit owns no
// data.
// Observed handle, descriptor, string and team record views; roles inferred.
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
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>), w3d_string_release_header(Ptr32<void>);
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct GameInfo {
    char pad0[56]; unsigned count0; char pad1[4]; Ptr32<const char> name0; char pad2[24]; unsigned mode;
    char pad3[40]; unsigned count1; char pad4[4]; Ptr32<const char> name1; char pad5[60]; unsigned count2; char pad6[4]; Ptr32<const char> name2;
    char pad7[64]; unsigned count3; char pad8[4]; Ptr32<const char> name3;
};
extern char lbl_803d092c[], lbl_803d0bf0[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int w3d_auto_800fc2b0(const Key &, Ptr32<Ptr32<const char>>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void d27f_set_team_worm_count_80299ca4(Ptr32<void>, unsigned value) {
    if (value - 1 > 5)
        return;
    Descriptor_80178474 descriptor;
    Handle game;
    Ptr32<const char> text;
    w3d_auto_800fc2b0(lbl_803d092c, &text);
    unsigned total = 0;
    if (w3d_constructor_lookup_name(lbl_803d0bf0, game) < 0)
        return;
    Handle info;
    info = Handle(w3d_auto_80179598(w3d_empty_80341584(game.p), &descriptor));
    unsigned which = 10;
    Ptr32<GameInfo> g = (Ptr32<GameInfo>)info.p;
    switch (g->mode) {
    case 4:
        if (strcmp(g->name3, text) == 0)
            which = 3;
        else
            total += ((Ptr32<GameInfo>)info.p)->count3;
    case 3:
        if (strcmp(((Ptr32<GameInfo>)info.p)->name2, text) == 0)
            which = 2;
        else
            total += ((Ptr32<GameInfo>)info.p)->count2;
    case 2:
        if (strcmp(((Ptr32<GameInfo>)info.p)->name1, text) == 0)
            which = 1;
        else
            total += ((Ptr32<GameInfo>)info.p)->count1;
    default:
        if (strcmp(((Ptr32<GameInfo>)info.p)->name0, text) == 0)
            which = 0;
        else
            total += ((Ptr32<GameInfo>)info.p)->count0;
    }
    unsigned limit = 16 - total;
    if (limit > 6)
        limit = 6;
    if (limit == 0)
        return;
    if (value > limit)
        value = limit;
    if (which <= 3)
    switch (which) {
    case 0: ((Ptr32<GameInfo>)info.p)->count0 = value; break;
    case 1: ((Ptr32<GameInfo>)info.p)->count1 = value; break;
    case 2: ((Ptr32<GameInfo>)info.p)->count2 = value; break;
    case 3: ((Ptr32<GameInfo>)info.p)->count3 = value; break;
    }
}


