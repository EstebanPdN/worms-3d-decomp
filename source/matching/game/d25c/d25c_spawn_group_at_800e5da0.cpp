// d25c: 0x800e5da0. Sibling of 0x800e61b8: spawn one object per name of a record (or one), placed at a position.
// Modes 1 and 2 of the record (+304) use their own type; otherwise the +414 flag chooses. Each spawn also
// gets the flag bits at +152 and the float at +36. Names are inferred.
struct Type { unsigned char unknown00[20]; const Type *parent; };
struct Words { int a, b, c; };
struct Key { const char *text; };
struct Names { unsigned char u[24]; unsigned count; unsigned char u28[4]; const char *names[1]; };
struct Record {
    struct V { void *u[5]; const Type *(*type)(Record *); } *vtable;
    unsigned char u4[16];
    Names *names;       // +20
    unsigned char u24[280];
    int mode;            // +304
    unsigned char u308[106];
    unsigned short kind; // +414
};
struct Spawn {
    unsigned char u0[36];
    float value;        // +36
    unsigned char u40[28];
    Words pos;          // +68
    unsigned char u80[24];
    int group;          // +104
    unsigned char u108[44];
    unsigned flags;     // +152
    unsigned char u156[72];
    struct V { void *u[5]; void *(*owner)(Spawn *); } *vtable;  // +228
};
struct Owner { unsigned char u[20]; int id; };
extern "C" int read_800fc330(const char **, Record **);
extern "C" void *forward_8020b680(const void *);
extern "C" void load_800df6a4(Spawn *, const char *);
extern "C" void init_800dfddc(Spawn *, int, int);
extern "C" int fn_80164514(void *, void *, int);
extern void *service_804b178c;
extern int counter_804aaec8;
extern const Type type_803678d8[];
extern const unsigned char key_80410048[], key_8040ffa8[], key_804106c0[];
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
inline Spawn *make(const void *k) { Spawn *s = 0; void *m = forward_8020b680(k); if (m) s = (Spawn *)((char *)m + 28); return s; }
extern "C" int d25c_spawn_group_at_800e5da0(Owner *self, const Words *pos, const char *name, unsigned flags, float value) {
    const char **list = 0;
    Record *record;
    record = 0;
    int group = ++counter_804aaec8;
    int status = read_800fc330(&name, &record);
    unsigned count = 1;
    if (status < 0) return 0;
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
        Spawn *s;
        if (r->mode == 1) goto named;
        if (r->mode == 2) {
        named:
            s = make(key_804106c0);
        } else if (r->kind) s = make(key_80410048);
        else s = make(key_8040ffa8);
        if (list) load_800df6a4(s, list[i]);
        else load_800df6a4(s, name);
        s->pos = *pos;
        s->group = group;
        s->flags |= flags;
        s->value = value;
        void *o = s->vtable->owner(s);
        fn_80164514(service_804b178c, o, self->id);
    }
    return group;
}
