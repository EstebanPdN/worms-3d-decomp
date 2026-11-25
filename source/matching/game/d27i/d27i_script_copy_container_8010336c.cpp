// GWMP8P rev0 0x8010336c. Script binding CopyContainer(source, target):
// looks up two data entries by name, checks both are containers of the same
// type and copies one into the other.
struct lua_State;
extern "C" int lua_gettop(lua_State *);
extern "C" void lua_settop(lua_State *, int);
extern "C" int lua_isstring(lua_State *, int);
extern "C" const char *lua_tostring(lua_State *, int);
extern "C" void str_finish_8020c5c4(void *);
extern "C" void str_release_80341588(void *);
struct String_8020bb54 {
    char *text;
    String_8020bb54(const char *);
    String_8020bb54(const String_8020bb54 &);
    ~String_8020bb54() { str_finish_8020c5c4(this); str_release_80341588(this); }
};
typedef String_8020bb54 String;
struct Object;
struct ObjectVt { char u0[12]; void (*add)(Object *); void (*release)(Object *); int (*type)(Object *); int (*kind)(Object *); };
struct Object { ObjectVt *vt; };
struct Ref {
    Object *p;
    Ref() { p = 0; }
    Ref(Object *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    Ref &operator=(Object *q) { if (q) q->vt->add(q); if (p) p->vt->release(p); p = q; return *this; }
};
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Key; extern "C" int lookup_800fc1b0(Key *, Ref *);
struct Key { const char *text; Key() {} Key(const String &o) { text = o.text; } };
inline int find(const String &o, Ref &r) { Key k; k.text = o.text; return lookup_800fc1b0(&k, &r); }
inline int find2(const String &o, Ref &r) { Key k(o); return lookup_800fc1b0(&k, &r); }
struct Script { char u0[68]; lua_State *L; };

extern char s_80399288[], s_803992c4[], s_803992f4[], s_80399324[], s_80399358[];
extern "C" {
void error_801022ec(Script *, const char *);
int lookup_800fc1b0(Key *, Ref *);
void *ref_80341584(void *);
Object *cfg_801797b4(void *);
Object *as_80179598(void *, Descriptor_80178474 *);
void copy_801ea4c8(Object *, Object *);
}
extern "C" int d27i_script_copy_container_8010336c(Script *self) {
    int n = lua_gettop(self->L);
    if (n != 2) {
        error_801022ec(self, s_80399288);
        lua_settop(self->L, -n - 1);
        return 0;
    }
    if (!lua_isstring(self->L, -2) || !lua_isstring(self->L, -1)) {
        error_801022ec(self, s_803992c4);
        lua_settop(self->L, -3);
        return 0;
    }
    Ref a;
    Ref b;
    String n1(lua_tostring(self->L, -2));
    Key k1;
    k1.text = n1.text;
    int r1 = lookup_800fc1b0(&k1, &a);
    String n2(lua_tostring(self->L, -1));
    Key k2;
    k2.text = n2.text;
    int r2 = lookup_800fc1b0(&k2, &b);
    if (r1 < 0 || r2 < 0) {
        error_801022ec(self, s_803992f4);
        lua_settop(self->L, -3);
        return 0;
    }
    if (a.p->vt->kind(a.p) != 5 || b.p->vt->kind(b.p) != 5) {
        error_801022ec(self, s_80399324);
        lua_settop(self->L, -3);
        return 0;
    }
    Object *src = cfg_801797b4(ref_80341584(a.p));
    Descriptor_80178474 desc;
    Ref d;
    {
        Ref tmp(as_80179598(ref_80341584(b.p), &desc));
        Object *q = tmp.p;
        if (q) d = q;
    }
    if (src->vt->type(src) != d.p->vt->type(d.p)) {
        error_801022ec(self, s_80399358);
        lua_settop(self->L, -3);
    } else {
        lua_settop(self->L, -3);
        copy_801ea4c8(d.p, src);
    }
    return 0;
}
