// GWMP8P rev0 0x8029c4d0. Reads the team name from the user properties,
// finds the barracks team with that name, then creates it or updates it from
// the properties according to the mode. The count is read directly through
// the embedded list holder and the items through its inline member, so CSE
// keeps a second load that the post-reload pass turns into a register copy.
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
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(unsigned short *)(other.text - 6);
        char *old = text;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
};
typedef String_803426b8 String;
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct ArrayHeader { char pad[4]; unsigned short kind; char pad2[18]; unsigned count; unsigned short locks; char pad3[2]; String items[1]; };
struct ArrayRef { ArrayHeader *header; };
struct Team { char pad[24]; String speech; String flag; int sweapon; int grave; int skill; int field44; char pad2[8]; ArrayRef names; String name; };
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Team *items[1]; };
struct BarracksSub { int a; TeamList *teams; Team **Items() { return teams->items; } };
struct Barracks { char pad[20]; BarracksSub sub; };
extern char lbl_803d097c[], lbl_803d09ec[], lbl_803d0a0c[], lbl_803d0a54[], lbl_803d0a20[], lbl_803d0a2c[], lbl_803d0a3c[], lbl_803d0a48[], lbl_80419eb8[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *), *w3d_empty_80343744(Obj *), *w3d_constructor_native_c_80342a78(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" String *w3d_auto_80179170(Obj *);
extern "C" int w3d_auto_80178d1c(Obj *);
extern "C" Team *w3d_s10_service_forward_8020b680(void *);
extern "C" void w3d_k5b_iface_array_field_append_801ef174(Obj *, int, int, Team *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" int strcmp(const char *, const char *);
extern "C" String *w3d_k5b_array_ref_lock_801ef048(ArrayRef *, int, int, int);
inline String *Lock(ArrayRef *array) {
    ArrayHeader *header = array->header;
    int count = header->count;
    if (header->kind == 1) {
        ++header->locks;
        return header->items;
    }
    return w3d_k5b_array_ref_lock_801ef048(array, count, 4, 2);
}
extern "C" void d30f_create_team_from_properties_8029c4d0(void *, int mode) {
    Handle barracks;
    Handle store;
    Descriptor_80178474 tag;
    String name;
    Team *team = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, barracks) < 0)
        return;
    w3d_constructor_lookup_name(lbl_803d09ec, store);
    name = *w3d_auto_80179170(w3d_empty_80343744(store.p));
    Handle list;
    list = Handle(w3d_auto_80179598(w3d_empty_80341584(barracks.p), &tag));
    unsigned count = ((Barracks *)list.p)->sub.teams->count;
    Team **items = ((Barracks *)list.p)->sub.Items();
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
        String *names = Lock(&team->names);
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
        String *names = Lock(&team->names);
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
