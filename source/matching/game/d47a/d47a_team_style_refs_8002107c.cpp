// GWMP8P rev0 0x8002107c. Loads style resources 1 to 5 by formatted name,
// then for each of 16 teams applies the team's style, defaulting an unset
// style to 5 when the global flag is set.
struct Object { void **table; };
typedef void (*Slot)(Object *);
struct Ref { Object *p; Ref() : p(0) {} ~Ref() { if (p) ((Slot)p->table[4])(p); } };
extern "C" void w3d_string_finish_8020c5c4(void *);
extern "C" void w3d_string_release_80341588(void *);
struct String_803426b8 {
    const char *text;
    String_803426b8();
    ~String_803426b8() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
typedef String_803426b8 String;
struct Key { const char *text; };
struct Descriptor_80178474 {
    int value;
    unsigned tag;
    Descriptor_80178474(int v) : value(v), tag(58280) {}
    ~Descriptor_80178474();
};
struct TeamEntry { char unknown00[213]; unsigned char team; };
struct TeamInfo { char unknown00[36]; unsigned char style; };
struct Handle { char unknown00[52]; int value; };
extern "C" void string_format_8020c510(String *, const char *, ...);
extern "C" int w3d_resource_property_800fc1b0(Key *, Ref *);
extern "C" TeamEntry *team_entry_800fc6dc(unsigned);
extern "C" TeamInfo *team_info_800fc7f8(unsigned);
extern "C" Handle *handle_800fc82c(unsigned, Descriptor_80178474 *);
extern "C" Object *handle_800fcb80(unsigned, Descriptor_80178474 *);
extern "C" Object *w3d_empty_80341584(Object *);
extern "C" int w3d_auto_801797b4(Object *);
extern "C" void propagate_tag_801ea4c8(Object *, int);
extern int g_804aa7a0;
extern const char s_format_8036bd2c[];
extern "C" void w3d_d47a_team_style_refs_8002107c(void *self)
{
    String name;
    Ref refs[6];
    for (int i = 1; i <= 5; i++) {
        String s;
        string_format_8020c510(&s, s_format_8036bd2c, i);
        Key key = { s.text };
        w3d_resource_property_800fc1b0(&key, &refs[i]);
    }
    for (unsigned team = 0; team <= 15; team++) {
        unsigned id = team_entry_800fc6dc(team)->team;
        int style = team_info_800fc7f8(id)->style;
        int was = style;
        if (g_804aa7a0 != 0 && style == 0) {
            style = 5;
            Descriptor_80178474 d(was);
            handle_800fc82c(id, &d)->value = 1;
        }
        if (style != 0) {
            Descriptor_80178474 d(0);
            int tag = w3d_auto_801797b4(w3d_empty_80341584((refs + style)->p));
            propagate_tag_801ea4c8(handle_800fcb80(team, &d), tag);
        }
    }
}
