// d26c: 0x800e5f98. Spawn one object per name of a resource record (or one for a plain record), tag them with a new
// group id and register each with the owner. Names are inferred; String is one word; same family as d25c 0x800e61b8
// and 0x800e5da0.
struct Type { unsigned char unknown00[20]; const Type *parent; };
struct Words { int a, b, c; };
struct Key { const char *text; };
struct Names { unsigned char u[24]; unsigned count; unsigned char u28[4]; const char *names[1]; };
struct Record {
    struct V { void *u[5]; const Type *(*type)(Record *); } *vtable;
    unsigned char u4[16];
    Names *names;       // +20
    unsigned char u24[390];
    unsigned short kind; // +414
};
struct Spawn {
    unsigned char u0[68];
    Words pos;          // +68
    unsigned char u80[24];
    int group;          // +104
    unsigned char u108[120];
    struct V { void *u[5]; void *(*owner)(Spawn *); } *vtable;  // +228
};
struct Owner { unsigned char u[20]; int id; };
extern "C" int read_800fc330(const char **, Record **);
extern "C" void *forward_8020b680(const void *);
extern "C" void load_800df6a4(Spawn *, const char *);
extern "C" void init_800dfddc(Spawn *, int, int);
struct String {
    char *text;
    String(const String &);
    String(const char *);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" void attach_800e2118(void *, void *, String *, int);
extern "C" int fn_80164514(void *, void *, int);
extern void *service_804b178c;
extern int counter_804aaec8;
extern const Type type_803678d8[];
extern const unsigned char key_80410048[], key_8040ffa8[];
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
inline void make(Spawn *&s, const void *k) { s = 0; void *m = forward_8020b680(k); if (m) s = (Spawn *)((char *)m + 28); }
extern "C" int d26c_spawn_group_list_800e5f98(Owner *self, int attach, const char *text, const char *name, int arg, int extra) {
    Spawn *s = 0;
    int group = ++counter_804aaec8;
    Record *record;
    record = (Record *)s;
    unsigned count = 1;
    int status = read_800fc330(&name, &record);
    const char **list = 0;
    if (status < 0 || attach == 0) return 0;
    if (is_a(record->vtable->type(record), type_803678d8)) {
        count = record->names->count;
        list = record->names->names;
    }
    for (unsigned i = 0; i < count; i++) {
        Record *r;
        if (list) {
            const char *k2 = list[i];
            Record *found;
            read_800fc330(&k2, &found);
            r = found;
        } else {
            r = record;
        }
        if (r->kind || attach == 0) {
            make(s, key_80410048);
            init_800dfddc(s, arg, 0);
        } else {
            make(s, key_8040ffa8);
            void *owner = s ? (char *)s - 28 : 0;
            String label(text);
            attach_800e2118(owner, (void *)attach, &label, extra);
        }
        if (list) load_800df6a4(s, list[i]);
        else load_800df6a4(s, name);
        s->group = group;
        void *o = s->vtable->owner(s);
        fn_80164514(service_804b178c, o, self->id);
    }
    return group;
}
