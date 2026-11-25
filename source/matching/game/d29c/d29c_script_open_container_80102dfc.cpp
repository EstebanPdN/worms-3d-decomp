// d29c: 0x80102dfc. Script binding: takes a data entry name, checks it names a container, makes a heap descriptor bound to it, pushes the descriptor as light user data and registers the container. Names are inferred; classes are partial views.
struct lua_State;
extern "C" int lua_gettop(lua_State *);
extern "C" void lua_settop(lua_State *, int);
extern "C" int lua_isstring(lua_State *, int);
extern "C" const char *lua_tostring(lua_State *, int);
extern "C" void lua_pushlightuserdata(lua_State *, void *);
extern "C" void str_finish_8020c5c4(void *);
extern "C" void str_release_80341588(void *);
struct String_8020bb54 {
    char *text;
    String_8020bb54(const char *);
    const char *c_str() const { return text; }
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
};
struct Key { const char *text; };
struct Script;
struct Registry { struct V { char u0[28]; void (*add)(Registry *, Object *); } *vt; };
struct Script { char u0[64]; Registry *registry; lua_State *L; char u72[284]; int containers; };
extern char s1_8039904c[], s2_80399088[], s3_803990b8[], s4_803990e8[];
extern "C" {
void error_801022ec(Script *, const char *);
int lookup_800fc1b0(Key *, Ref *);
void *ref_80341584(void *);
Object *as_80179598(void *, Descriptor_80178474 *);
}
extern "C" int d29c_script_open_container_80102dfc(Script *self) {
    if (lua_gettop(self->L) != 1) {
        error_801022ec(self, s1_8039904c);
        lua_settop(self->L, -2);
        return 0;
    }
    if (!lua_isstring(self->L, -1)) {
        error_801022ec(self, s2_80399088);
        lua_settop(self->L, -2);
        return 0;
    }
    String name(lua_tostring(self->L, -1));
    Ref r;
    Key k;
    k.text = name.c_str();
    if (lookup_800fc1b0(&k, &r) < 0) {
        error_801022ec(self, s3_803990b8);
        lua_settop(self->L, -2);
        return 0;
    }
    if (r.p->vt->kind(r.p) != 5) {
        error_801022ec(self, s4_803990e8);
        lua_settop(self->L, -2);
        return 0;
    }
    Descriptor_80178474 *d = new Descriptor_80178474;
    Ref held;
    {
        Ref tmp(as_80179598(ref_80341584(r.p), d));
        Object *q = tmp.p;
        if (q) held = q;
    }
    lua_settop(self->L, -2);
    lua_pushlightuserdata(self->L, d);
    self->registry->vt->add(self->registry, held.p);
    self->containers++;
    return 2;
}
