// GWMP8P rev0 0x80299630. Finds a team name not yet used in the barracks:
// walks the list comparing against the default name with a numeric suffix,
// then creates the team through 0x80297f7c. The count is read directly
// through the embedded list holder and the items through its inline member.
// Observed handle, string and team list views; roles inferred.
struct Obj { void **table; };
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { release(p); }
};
extern "C" void w3d_string_base_finish(void *), w3d_string_release(void *);
struct String_8020bb54 {
    char *text;
    String_8020bb54(const char *);
    String_8020bb54(const String_8020bb54 &);
    ~String_8020bb54() { w3d_string_base_finish(this); w3d_string_release(this); }
};
typedef String_8020bb54 String;
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
inline String_8020bb54::String_8020bb54(const String_8020bb54 &other) {
    w3d_string_base_init(this);
    text = other.text;
    ++*w3d_string_header(this);
}
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Team { char pad[60]; const char *name; int locked; };
struct TeamList { char pad[24]; unsigned count; char pad2[4]; Team *items[1]; };
struct DataSub { int a; TeamList *teams; Team **Items() { return teams->items; } };
struct Data { char pad[20]; DataSub sub; };
extern char lbl_803d097c[], lbl_803d0b90[], lbl_803d0b9c[];
extern "C" int w3d_constructor_lookup_name(const Key &, Handle &);
extern "C" Obj *w3d_empty_80341584(Obj *);
extern "C" Data *w3d_auto_801797b4(Obj *);
extern "C" int strcmp(const char *, const char *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" void fn_80297f7c(void *, String, int, int);
extern "C" void d30f_default_team_name_80299630(void *self) {
    Handle barracks;
    unsigned suffix = 0;
    if (w3d_constructor_lookup_name(lbl_803d097c, barracks) < 0)
        return;
    Data *data = w3d_auto_801797b4(w3d_empty_80341584(barracks.p));
    unsigned count = data->sub.teams->count;
    if (count != 0) {
        Team **items = data->sub.Items();
        {
            String name(lbl_803d0b90);
            for (unsigned i = 0; i < count; i++) {
                if (suffix != 0)
                    w3d_string_format(&name, lbl_803d0b9c, suffix);
                if (strcmp(items[i]->name, name.text) == 0)
                    suffix++;
                if (items[i]->locked == 0)
                    return;
            }
        }
    }
    String name(lbl_803d0b90);
    if (suffix != 0)
        w3d_string_format(&name, lbl_803d0b9c, suffix);
    fn_80297f7c(self, name, 0, 1);
}
