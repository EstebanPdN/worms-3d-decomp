// GWMP8P rev0 0x80298abc. Deletes the current human team named by
// User.HumanTeam from DATA.TeamBarracks. With check equal to 1, a team whose
// +44 flag is not 1 is kept. After a removal, selects a default team through
// 0x80297620. The goto keeps the original's shared cleanup. Field names are
// inferred; the unit owns no data.
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
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Team { char pad[44]; int custom; char pad2[12]; const char *name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Team *items[1]; };
struct Data { char pad[24]; List *list; };
extern char lbl_803d09ec[], lbl_803d097c[], lbl_803d0b1c[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" int w3d_auto_800fc2b0(const Key &, const char **);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" void fn_801ef380(Obj *, int, int, unsigned, int);
extern "C" void fn_80297620(void *, String);
extern "C" void d27f_delete_barracks_team_80298abc(void *self, int check) {
    String name;
    const char *text;
    w3d_auto_800fc2b0(lbl_803d09ec, &text);
    w3d_string_assign(&name, text);
    if (name.Length() == 0)
        return;
    int removed = 0;
    Handle data;
    if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
        return;
    {
        Descriptor_80178474 descriptor;
        Handle result;
        result = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &descriptor));
        List *list = ((Data *)result.p)->list;
        unsigned count = list->count;
        Team **items = list->items;
        if (count != 0)
            for (unsigned i = 0; i < count; i++) {
                if (strcmp(items[i]->name, name.text) == 0) {
                    if (check == 1 && items[i]->custom != 1)
                        goto done;
                    fn_801ef380(result.p, 24, 0, i, 1);
                    removed = 1;
                    break;
                }
            }
    }
    if (removed == 1) {
        {
            String fallback(lbl_803d0b1c);
            fn_80297620(self, fallback);
        }
    done:
        return;
    }
    DebugNote(name);
}
