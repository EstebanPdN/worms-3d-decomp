#include "w3d_ptr.h"
#line 1 "d30f_create_team_from_properties_8029c4d0.cpp"
// GWMP8P rev0 0x8029c4d0. Reads the team name from the user properties,
// finds the barracks team with that name, then creates it or updates it from
// the properties according to the mode. The count is read directly through
// the embedded list holder and the items through its inline member, so CSE
// keeps a second load that the post-reload pass turns into a register copy.
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
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    template <class W3dU> String_803426b8(Ptr32<W3dU> w3d_p) : String_803426b8((const char *)w3d_p.get()) {}
 String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(Ptr32<unsigned short>)(other.text - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 String;
struct Key { Ptr32<const char> text; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *p) : text(p) {} };
struct ArrayHeader { char pad[4]; unsigned short kind; char pad2[18]; unsigned count; unsigned short locks; char pad3[2]; String items[1]; };
struct ArrayRef { Ptr32<ArrayHeader> header; };
struct Team { char pad[24]; String speech; String flag; int sweapon; int grave; int skill; int field44; char pad2[8]; ArrayRef names; String name; };
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Ptr32<Team> items[1]; };
struct BarracksSub { int a; Ptr32<TeamList> teams; Ptr32<Ptr32<Team>> Items() { return teams->items; } };
struct Barracks { char pad[20]; BarracksSub sub; };
extern char lbl_803d097c[], lbl_803d09ec[], lbl_803d0a0c[], lbl_803d0a54[], lbl_803d0a20[], lbl_803d0a2c[], lbl_803d0a3c[], lbl_803d0a48[], lbl_80419eb8[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Ptr32<Obj> w3d_empty_80341584(Ptr32<Obj>); Ptr32<Obj> w3d_empty_80343744(Ptr32<Obj>); Ptr32<Obj> w3d_constructor_native_c_80342a78(Ptr32<Obj>);
extern "C" Ptr32<Obj> w3d_auto_80179598(Ptr32<Obj>, Ptr32<Descriptor_80178474>);
extern "C" Ptr32<String> w3d_auto_80179170(Ptr32<Obj>);
extern "C" int w3d_auto_80178d1c(Ptr32<Obj>);
extern "C" Ptr32<Team> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_k5b_iface_array_field_append_801ef174(Ptr32<Obj>, int, int, Ptr32<Team>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<String> w3d_k5b_array_ref_lock_801ef048(Ptr32<ArrayRef>, int, int, int);
inline Ptr32<String> Lock(Ptr32<ArrayRef> array) {
    Ptr32<ArrayHeader> header = array->header;
    int count = header->count;
    if (header->kind == 1) {
        ++header->locks;
        return header->items;
    }
    return w3d_k5b_array_ref_lock_801ef048(array, count, 4, 2);
}
extern "C" void d30f_create_team_from_properties_8029c4d0(Ptr32<void>, int mode) {
    Handle barracks;
    Handle store;
    Descriptor_80178474 tag;
    String name;
    Ptr32<Team> team = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, barracks) < 0)
        return;
    w3d_constructor_lookup_name(lbl_803d09ec, store);
    name = *w3d_auto_80179170(w3d_empty_80343744(store.p));
    Handle list;
    list = Handle(w3d_auto_80179598(w3d_empty_80341584(barracks.p), &tag));
    unsigned count = ((Ptr32<Barracks>)list.p)->sub.teams->count;
    Ptr32<Ptr32<Team>> items = ((Ptr32<Barracks>)list.p)->sub.Items();
    unsigned i = 0;
    if (i < count)
        do {
            if (strcmp(items[i]->name.text, name.text) == 0) {
                team = items[i];
                break;
            }
            i++;
        } while (i < count);
    if (team != 0) {
        if (mode != 0)
            goto update;
    } else if (mode != 1)
        goto create;
    return;
create:
    {
        team = w3d_s10_service_forward_8020b680(lbl_80419eb8);
        team->name = name;
        Ptr32<String> names = Lock(&team->names);
        String key;
        for (int k = 0; k < 6; k++) {
            w3d_string_format(&key, lbl_803d0a0c, k + 1);
            w3d_constructor_lookup_name(key.text, store);
            names[k] = *w3d_auto_80179170(w3d_empty_80343744(store.p));
        }
        w3d_constructor_lookup_name(lbl_803d0a54, store);
        team->skill = w3d_auto_80178d1c(w3d_constructor_native_c_80342a78(store.p));
        w3d_constructor_lookup_name(lbl_803d0a20, store);
        team->grave = w3d_auto_80178d1c(w3d_constructor_native_c_80342a78(store.p));
        w3d_constructor_lookup_name(lbl_803d0a2c, store);
        team->sweapon = w3d_auto_80178d1c(w3d_constructor_native_c_80342a78(store.p));
        w3d_constructor_lookup_name(lbl_803d0a3c, store);
        team->flag = *w3d_auto_80179170(w3d_empty_80343744(store.p));
        w3d_constructor_lookup_name(lbl_803d0a48, store);
        team->speech = *w3d_auto_80179170(w3d_empty_80343744(store.p));
        w3d_k5b_iface_array_field_append_801ef174(list.p, 24, 0, team);
    }
    goto done;
update:
    {
        Ptr32<String> names = Lock(&team->names);
        String key;
        for (int k = 0; k < 6; k++) {
            w3d_string_format(&key, lbl_803d0a0c, k + 1);
            w3d_constructor_lookup_name(key.text, store);
            names[k] = *w3d_auto_80179170(w3d_empty_80343744(store.p));
        }
        w3d_constructor_lookup_name(lbl_803d0a20, store);
        team->grave = w3d_auto_80178d1c(w3d_constructor_native_c_80342a78(store.p));
        w3d_constructor_lookup_name(lbl_803d0a2c, store);
        team->sweapon = w3d_auto_80178d1c(w3d_constructor_native_c_80342a78(store.p));
        w3d_constructor_lookup_name(lbl_803d0a3c, store);
        team->flag = *w3d_auto_80179170(w3d_empty_80343744(store.p));
        w3d_constructor_lookup_name(lbl_803d0a48, store);
        team->speech = *w3d_auto_80179170(w3d_empty_80343744(store.p));
    }
done:
    ;
}


