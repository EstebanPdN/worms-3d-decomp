#include "w3d_ptr.h"
#line 1 "d30f_add_barracks_team_by_name_8029a238.cpp"
// GWMP8P rev0 0x8029a238. Looks up the game object and barracks; unless four
// teams are already in the game, finds the barracks team by name and adds it
// through 0x8029a5b4. The count is read directly through the embedded list
// holder and the items through its inline member, so CSE keeps a second load
// that the post-reload pass turns into a register copy.
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
struct GameInfo { char pad[92]; int mode; };
struct Entry { char pad[60]; Ptr32<const char> name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Ptr32<Entry> items[1]; Ptr32<Ptr32<Entry>> begin() { return items; } };
struct DataSub { int a; Ptr32<List> list; Ptr32<Ptr32<Entry>> Items() { return list->begin(); } };
struct Data { char pad[20]; DataSub sub; };
extern char lbl_803d0bf0[], lbl_803d097c[], lbl_803d09e0[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void fn_8029a5b4(Ptr32<void>, Ptr32<Entry>, Ptr32<const char>);
extern "C" void d30f_add_barracks_team_by_name_8029a238(Ptr32<void> self, Ptr32<const char> name) {
    Descriptor_80178474 first;
    Descriptor_80178474 second;
    Handle game;
    Handle teams;
    unsigned count = 0;
    if (w3d_constructor_lookup_name(lbl_803d0bf0, game) < 0)
        return;
    Handle info;
    info = Handle(w3d_auto_80179598(w3d_empty_80341584(game.p), &first));
    if (((Ptr32<GameInfo>)info.p)->mode == 4)
        return;
    if (w3d_constructor_lookup_name(lbl_803d097c, teams) < 0)
        return;
    Handle barracks;
    barracks = Handle(w3d_auto_80179598(w3d_empty_80341584(teams.p), &second));
    unsigned i = 0;
    Ptr32<Data> data = (Ptr32<Data>)barracks.p;
    count = data->sub.list->count;
    Ptr32<Ptr32<Entry>> items = data->sub.Items();
    if (i < count)
        do {
            if (strcmp(name, items[i]->name) == 0) {
                fn_8029a5b4(self, items[i], lbl_803d09e0);
                break;
            }
            i++;
        } while (i < count);
}


