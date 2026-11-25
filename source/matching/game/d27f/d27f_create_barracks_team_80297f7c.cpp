// GWMP8P rev0 0x80297f7c. Creates a new team named by the by-value string in
// DATA.TeamBarracks. Mode 1 reads the name through a property first. Refuses
// a full list of 20 teams or a duplicate name, otherwise fills language-
// dependent flag and speech defaults, optionally overrides the flag from
// User.Skill, appends the team and stores MCa.Team, then selects it if
// asked. The zero local read by the append call has no direct witness: it
// reproduces the zero kept across the first lookup. Field names are
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
struct Entry { char pad[60]; const char *name; };
struct List { char pad[24]; unsigned count; char pad2[4]; Entry *items[1]; };
struct Data { char pad[24]; List *list; };
struct Team { char pad[24]; String speech; String flag; int pad2[2]; int skill; int custom; char pad3[12]; String name; };
extern char lbl_803d097c[], lbl_803d0ab8[], lbl_803d0a54[], lbl_803d0a00[], lbl_803d0b18[], lbl_803d0ac8[], lbl_803d0acc[], lbl_803d0ad4[], lbl_803d0ad8[], lbl_803d0adc[], lbl_803d0ae4[], lbl_803d0ae8[], lbl_803d0af0[], lbl_803d0af4[], lbl_803d0afc[], lbl_803d0b00[], lbl_803d0b04[], lbl_803d0b08[], lbl_803d0b0c[], lbl_803d0b14[], lbl_80419eb8[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Obj *w3d_auto_80179598(Obj *, Descriptor_80178474 *);
extern "C" int w3d_auto_800fc2b0(const Key &, const char **);
extern "C" int w3d_auto_800fc230(const Key &, int *);
extern "C" int s8_property_read_800fc550(const Key &, const char *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" void w3d_string_assign(String *, const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" Team *w3d_s10_service_forward_8020b680(void *);
extern "C" void w3d_k5b_iface_array_field_801ef174(Obj *, int, int, Team *);
extern "C" void fn_80297620(void *, String);
extern "C" void d27f_create_barracks_team_80297f7c(void *self, String name, int mode, int select) {
    if (name.Length() == 0)
        return;
    if (mode == 1) {
        const char *text;
        if (w3d_auto_800fc2b0(name.text, &text) < 0) {
            DebugNote(name);
            return;
        }
        w3d_string_assign(&name, text);
        if (name.Length() == 0)
            return;
    }
    Handle data;
    int none = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, data) < 0)
        return;
    {
        Descriptor_80178474 descriptor;
        Handle result;
        result = Handle(w3d_auto_80179598(w3d_empty_80341584(data.p), &descriptor));
        List *list = ((Data *)result.p)->list;
        unsigned count = list->count;
        Entry **items = list->items;
        if (count > 19)
            return;
        if (count != 0)
            for (unsigned i = 0; i < count; i++) {
                if (strcmp(items[i]->name, name.text) == 0) {
                    DebugNote(name);
                    return;
                }
            }
        Team *team = w3d_s10_service_forward_8020b680(lbl_80419eb8);
        team->name = String(name.text);
        int custom = 0;
        if (mode) custom = 1;
        team->custom = custom;
        int language;
        w3d_auto_800fc230(lbl_803d0ab8, &language);
        switch (language) {
    case 0:
        team->flag = String(lbl_803d0ac8);
        team->speech = String(lbl_803d0acc);
        break;
    case 1:
        team->flag = String(lbl_803d0ad4);
        team->speech = String(lbl_803d0acc);
        break;
    case 3:
        team->flag = String(lbl_803d0ad8);
        team->speech = String(lbl_803d0adc);
        break;
    case 4:
        team->flag = String(lbl_803d0ae4);
        team->speech = String(lbl_803d0ae8);
        break;
    case 5:
        team->flag = String(lbl_803d0af0);
        team->speech = String(lbl_803d0af4);
        break;
    case 6:
        team->flag = String(lbl_803d0afc);
        team->speech = String(lbl_803d0acc);
        break;
    case 7:
        team->flag = String(lbl_803d0b00);
        team->speech = String(lbl_803d0acc);
        break;
    case 8:
        team->flag = String(lbl_803d0b04);
        team->speech = String(lbl_803d0acc);
        break;
    case 9:
        team->flag = String(lbl_803d0b08);
        team->speech = String(lbl_803d0b0c);
        break;
    case 2:
        team->flag = String(lbl_803d0b14);
        team->speech = String(lbl_803d0acc);
        break;
        }
        int skill;
        w3d_auto_800fc230(lbl_803d0a54, &skill);
        if (skill != 0) {
            String flag;
            w3d_string_format(&flag, lbl_803d0b18, skill + 114);
            team->flag = String(flag.text);
        }
        team->skill = skill;
        none = 0;
        w3d_k5b_iface_array_field_801ef174(result.p, 24, none, team);
        s8_property_read_800fc550(lbl_803d0a00, name.text);
    }
    if (select)
        fn_80297620(self, name);
}
