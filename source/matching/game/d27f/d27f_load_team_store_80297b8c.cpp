// GWMP8P rev0 0x80297b8c. Reads the team settings back from the user
// properties into the temporary team store: numbered team member names (an
// all-blank name gets a formatted default), flag, speech, super weapon,
// skill and grave. Field names are inferred from the property strings; the
// unit owns no data.
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
struct Team { char pad[24]; String speech; String flag; int sweapon; int grave; int skill; int field44; char pad2[8]; ArrayRef names; };
extern char lbl_803d0940[], lbl_803d0a0c[], lbl_803d0a60[], lbl_803d0a6c[], lbl_803d0a20[], lbl_803d0a2c[], lbl_803d0a3c[], lbl_803d0a48[], lbl_803d0a54[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Team *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" int w3d_auto_800fc2b0(const Key &, const char **);
extern "C" int w3d_auto_800fc230(const Key &, int *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" char *strchr(const char *, int);
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
extern "C" void d27f_load_team_store_80297b8c(void *) {
    Descriptor_80178474 descriptor;
    Handle store;
    if (w3d_constructor_lookup_name(lbl_803d0940, store) < 0)
        return;
    Handle result;
    result = Handle((Obj *)w3d_auto_80179598(w3d_empty_80341584(store.p), &descriptor));
    Team *team = (Team *)result.p;
    unsigned count = team->names.header->count;
    String *names = Lock(&team->names);
    String key;
    for (unsigned i = 0; i < count; i++) {
        w3d_string_format(&key, lbl_803d0a0c, i + 1);
        const char *text;
        w3d_auto_800fc2b0(key.text, &text);
        const char *p = text;
        while (*p && strchr(lbl_803d0a60, *p))
            p++;
        if (*p == 0)
            w3d_string_format(&names[i], lbl_803d0a6c, text);
        else
            w3d_string_assign(&names[i], text);
    }
    const char *value;
    w3d_auto_800fc2b0(lbl_803d0a3c, &value);
    { Team *t = (Team *)result.p; t->flag = String(value); }
    ((Team *)result.p)->field44 = 0;
    w3d_auto_800fc2b0(lbl_803d0a48, &value);
    { Team *t = (Team *)result.p; t->speech = String(value); }
    int number;
    w3d_auto_800fc230(lbl_803d0a2c, &number);
    ((Team *)result.p)->sweapon = number;
    w3d_auto_800fc230(lbl_803d0a54, &number);
    ((Team *)result.p)->skill = number;
    w3d_auto_800fc230(lbl_803d0a20, &number);
    ((Team *)result.p)->grave = number;
}
