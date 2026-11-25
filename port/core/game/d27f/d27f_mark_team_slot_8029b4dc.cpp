#include "w3d_ptr.h"
#line 1 "d27f_mark_team_slot_8029b4dc.cpp"
// GWMP8P rev0 0x8029b4dc. Marks the game setup slot whose name equals the
// given team name: looks up GM.GameInitData and, when the mode is not 0,
// sets the flag beside the matching slot name (+300, +312, +308, or +304;
// the last name is compared twice as in the original). Field names are
// inferred; the unit owns no data.
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
    char pad0[64]; Ptr32<const char> name0; char pad1[24]; int mode; char pad2[48]; Ptr32<const char> name1; char pad3[68]; Ptr32<const char> name2; char pad4[72]; Ptr32<const char> name3;
    char pad5[4]; int set0; int set3; int set2; int set1;
};
extern char lbl_803d0bf0[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void d27f_mark_team_slot_8029b4dc(Ptr32<void>, Ptr32<const char> name) {
    Descriptor_80178474 descriptor;
    Handle game;
    Ptr32<Descriptor_80178474> d = &descriptor;
    int r = w3d_constructor_lookup_name(lbl_803d0bf0, game);
    do {
        if (r < 0)
            return;
    } while (0);
    Handle info;
    info = Handle(w3d_auto_80179598(w3d_empty_80341584(game.p), d));
    Ptr32<GameInfo> g = (Ptr32<GameInfo>)info.p;
    if (g->mode == 0)
        return;
    if (strcmp(g->name0, name) == 0)
        ((Ptr32<GameInfo>)info.p)->set0 = 1;
    else if (strcmp(((Ptr32<GameInfo>)info.p)->name1, name) == 0)
        ((Ptr32<GameInfo>)info.p)->set1 = 1;
    else if (strcmp(((Ptr32<GameInfo>)info.p)->name2, name) == 0)
        ((Ptr32<GameInfo>)info.p)->set2 = 1;
    else if (strcmp(((Ptr32<GameInfo>)info.p)->name3, name) == 0 || strcmp(((Ptr32<GameInfo>)info.p)->name3, name) == 0)
        ((Ptr32<GameInfo>)info.p)->set3 = 1;
}


