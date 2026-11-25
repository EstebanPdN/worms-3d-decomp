// GWMP8P rev0 0x80291b90. Creates a new game scheme: looks up the scheme
// list and the current scheme data, rejects a name already in use, then
// resets the fields of the new scheme. Handle, string, list and scheme views
// are observed; roles are inferred. The empty do/while after the second
// early return emits nothing: see the caveat in d34f.json.
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
    Handle &operator=(Obj *next) { retain(next); release(p); p = next; return *this; }
    Handle &operator=(const Handle &o) { Obj *next = o.p; if (next) { retain(next); release(p); p = next; } return *this; }
};
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *), w3d_string_release_header(void *);
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const char *);
    String_803426b8(const String_803426b8 &);
    const char *c_str() const { return text; }
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
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
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String_803426b8::String_803426b8(const String_803426b8 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
inline void DebugNote(String) {}
struct Slot { char pad[20]; int v20; char pad2[4]; int v28; int v32; };
struct Named { char pad[20]; const char *name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Named *items[1]; };
struct Data { char pad[20]; List *list; };
struct Scheme {
    char pad0[20];
    String name;
    Slot *slot24;
    Slot *slot28;
    Slot *slot32;
    Slot *slot36;
    Slot *slot40;
    Slot *slot44;
    char pad48[12];
    Slot *slot60;
    char pad64[20];
    String title;
    char pad88[20];
    Slot *slot108;
    Slot *slot112;
    char pad116[4];
    Slot *slot120;
    Slot *slot124;
    Slot *slot128;
    char pad132[32];
    Slot *slot164;
    char pad168[16];
    Slot *slot184;
    char pad188[16];
    Slot *slot204;
    Slot *slot208;
    char pad212[4];
    Slot *slot216;
    char pad220[8];
    Slot *slot228;
    Slot *slot232;
    char pad236[56];
    Slot *slot292;
    char pad296[36];
    int locked;
};
extern char lbl_803d02ac[], lbl_803d0164[], lbl_803d0174[], lbl_803d0588[], lbl_803d02b4[], lbl_80413b28[];
extern "C" int w3d_constructor_lookup_name(const char *const &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" int w3d_auto_800fc2b0(const char *const &, const char **);
extern "C" int s8_property_write_800fc3b0(const char *const &, int);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" Obj *w3d_s10_service_forward_8020b680(void *);
extern "C" void w3d_k5b_iface_array_field_801ef174(Obj *, int, int, Obj *);
extern "C" void w3d_export_scheme_8028fb10(void *);
extern "C" void w3d_empty_8029301c(void *);
inline Obj *Create(void *type) { return w3d_s10_service_forward_8020b680(type); }
inline Obj *Clone(const Handle &s, const Handle &from) {
    ((void (*)(Obj *, int))s.p->table[14])(s.p, 2);
    ((void (*)(Obj *, Obj *))s.p->table[6])(s.p, from.p);
    return ((Obj *(*)(Obj *))s.p->table[16])(s.p);
}
extern "C" void d34f_scheme_new_from_current_80291b90(void *self) {
    Handle data;
    Handle store;
    Descriptor_80178474 first;
    Descriptor_80178474 second;
    Handle copy;
    String name;
    const char *text;
    w3d_auto_800fc2b0(lbl_803d02ac, &text);
    w3d_string_assign(&name, text);
    if (w3d_constructor_lookup_name(lbl_803d0164, data) < 0)
        return;
    if (w3d_constructor_lookup_name(lbl_803d0174, store) < 0)
        { return; do { } while (0); }
    Handle schemes;
    schemes = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &first));
    Handle current;
    current = Handle(w3d_auto_80179598(w3d_empty_80341584(store.p), &second));
    List *list = ((Data *)schemes.p)->list;
    unsigned count = list->count;
    Named **items = list->items;
    for (unsigned i = 0; i < count; i++) {
        if (strcmp(items[i]->name, name.text) != 0)
            continue;
        DebugNote(((Scheme *)current.p)->name);
        return;
    }
    { Scheme *t = (Scheme *)current.p; t->name = name; }
    int zero = 0;
    ((Scheme *)current.p)->locked = zero;
    { Scheme *t = (Scheme *)current.p; t->title = String(lbl_803d0588); }
    ((Scheme *)current.p)->slot60->v32 = zero;
    ((Scheme *)current.p)->slot60->v28 = 1;
    ((Scheme *)current.p)->slot60->v20 = zero;
    ((Scheme *)current.p)->slot292->v32 = zero;
    ((Scheme *)current.p)->slot292->v28 = 1;
    ((Scheme *)current.p)->slot292->v20 = zero;
    ((Scheme *)current.p)->slot44->v32 = zero;
    ((Scheme *)current.p)->slot44->v28 = 1;
    ((Scheme *)current.p)->slot44->v20 = zero;
    ((Scheme *)current.p)->slot40->v32 = zero;
    ((Scheme *)current.p)->slot40->v28 = 1;
    ((Scheme *)current.p)->slot40->v20 = zero;
    ((Scheme *)current.p)->slot36->v32 = zero;
    ((Scheme *)current.p)->slot36->v28 = 1;
    ((Scheme *)current.p)->slot36->v20 = zero;
    ((Scheme *)current.p)->slot32->v32 = zero;
    ((Scheme *)current.p)->slot32->v28 = 1;
    ((Scheme *)current.p)->slot32->v20 = zero;
    ((Scheme *)current.p)->slot28->v32 = zero;
    ((Scheme *)current.p)->slot28->v28 = 1;
    ((Scheme *)current.p)->slot28->v20 = zero;
    ((Scheme *)current.p)->slot24->v32 = zero;
    ((Scheme *)current.p)->slot24->v28 = 1;
    ((Scheme *)current.p)->slot24->v20 = zero;
    ((Scheme *)current.p)->slot164->v32 = zero;
    ((Scheme *)current.p)->slot164->v28 = 1;
    ((Scheme *)current.p)->slot164->v20 = zero;
    ((Scheme *)current.p)->slot216->v32 = zero;
    ((Scheme *)current.p)->slot216->v28 = 1;
    ((Scheme *)current.p)->slot216->v20 = zero;
    ((Scheme *)current.p)->slot124->v32 = zero;
    ((Scheme *)current.p)->slot124->v28 = 1;
    ((Scheme *)current.p)->slot124->v20 = zero;
    ((Scheme *)current.p)->slot120->v32 = zero;
    ((Scheme *)current.p)->slot120->v28 = 1;
    ((Scheme *)current.p)->slot120->v20 = zero;
    ((Scheme *)current.p)->slot112->v32 = zero;
    ((Scheme *)current.p)->slot112->v28 = 1;
    ((Scheme *)current.p)->slot112->v20 = zero;
    ((Scheme *)current.p)->slot108->v32 = zero;
    ((Scheme *)current.p)->slot108->v28 = 1;
    ((Scheme *)current.p)->slot108->v20 = zero;
    ((Scheme *)current.p)->slot232->v32 = zero;
    ((Scheme *)current.p)->slot232->v28 = 1;
    ((Scheme *)current.p)->slot232->v20 = zero;
    ((Scheme *)current.p)->slot184->v32 = zero;
    ((Scheme *)current.p)->slot184->v28 = 1;
    ((Scheme *)current.p)->slot184->v20 = zero;
    ((Scheme *)current.p)->slot228->v32 = zero;
    ((Scheme *)current.p)->slot228->v28 = 1;
    ((Scheme *)current.p)->slot228->v20 = zero;
    ((Scheme *)current.p)->slot128->v32 = zero;
    ((Scheme *)current.p)->slot128->v28 = 1;
    ((Scheme *)current.p)->slot128->v20 = zero;
    ((Scheme *)current.p)->slot208->v32 = -1;
    ((Scheme *)current.p)->slot208->v28 = zero;
    ((Scheme *)current.p)->slot208->v20 = zero;
    ((Scheme *)current.p)->slot204->v32 = zero;
    ((Scheme *)current.p)->slot204->v28 = 1;
    ((Scheme *)current.p)->slot204->v20 = zero;
    {
        Descriptor_80178474 tag;
        copy = Clone(Handle(Create(lbl_80413b28)), current);
    }
    ((Scheme *)copy.p)->locked = zero;
    { Scheme *t = (Scheme *)copy.p; t->title = String(lbl_803d0588); }
    { Scheme *t = (Scheme *)copy.p; t->name = name; }
    s8_property_write_800fc3b0(lbl_803d02b4, 0);
    w3d_k5b_iface_array_field_801ef174(schemes.p, 20, 0, copy.p);
    w3d_export_scheme_8028fb10(self);
    w3d_empty_8029301c(self);
}
