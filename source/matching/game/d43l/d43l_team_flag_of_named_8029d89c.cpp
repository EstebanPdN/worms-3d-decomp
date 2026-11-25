// GWMP8P rev0 0x8029d89c. Reads a named text setting and, when it is non-
// empty and does not start with a space, searches the team list for that
// name and returns whether the matching team's flag is set.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
struct Name {
    char *p; const char *c_str() const { return p; }
    Name();
    ~Name() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned length() const { return *(unsigned short *)(p - 4); }
};
extern "C" void *fn_8020bd38(Name *, const char *);
struct Key { const char *text; };
struct Resource;
struct ResourceVt { char u[16]; void (*destroy)(Resource *); };
struct Resource { ResourceVt *vt; };
struct Handle {
    Resource *r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Team { char u0[44]; int w44; char u48[12]; const char *name; };
struct TeamList { char u0[24]; unsigned count; char u28[4]; Team *items[1]; };
struct TeamData { char u0[24]; TeamList *list; };
extern const char s_803d09ec[], s_803d097c[];
extern "C" int fn_800fc2b0(Key *, const char **);
extern "C" int fn_800fc1b0(Key *, Handle *);
extern "C" void *fn_80341584(Resource *);
extern "C" TeamData *fn_801797b4(void *);
extern "C" int strcmp(const char *, const char *);
extern "C" int d43l_team_flag_of_named_8029d89c() {
    Name name;
    Key k1;
    const char *value;
    k1.text = s_803d09ec;
    fn_800fc2b0(&k1, &value);
    fn_8020bd38(&name, value);
    if (!name.length() || *value == ' ')
        return 1;
    Handle h;
    Key k2;
    k2.text = s_803d097c;
    if (fn_800fc1b0(&k2, &h) < 0) return 0;
{
        TeamList *list = fn_801797b4(fn_80341584(h.r))->list;
        unsigned count = list->count;
        Team **items = list->items;
        for (unsigned i = 0; i < count; i++) {
            if (!strcmp(items[i]->name, name.c_str())) {
                return items[i]->w44 != 0;
            }
        }
    }
    return 0;
}
