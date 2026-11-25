// d29c: 0x80101b00. Script binding SetData(name, value): looks up the named data entry and stores the Lua value according to the entry kind (int, int, float, string), reporting errors through the script log. Names are inferred; classes are partial views.
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
struct Key { const char *text; };
struct Script;
struct Registry { struct V { char u0[28]; void (*add)(Registry *, Object *); } *vt; };
struct Script { char u0[64]; Registry *registry; lua_State *L; char u72[284]; int containers; };
extern char s1_80398ca0[], s2_80398cd4[], s3_80398d00[], s4_80398d28[], s5_80398d54[], s6_80398d80[];
extern "C" {
void error_801022ec(Script *, const char *);
int lookup_800fc1b0(Key *, Ref *);
int lua_isnumber(lua_State *, int);
float lua_tonumber(lua_State *, int);
void *asInt_803426b4(void *);
void *asInt2_80342a78(void *);
void *asFloat_80342a74(void *);
void *asText_80343744(void *);
int setInt_80178c54(void *, int *);
int setInt2_80178d28(void *, int *);
int setFloat_80178dfc(void *, float *);
int setText_801790bc(void *, const char *);
void * str_default_803426b8(void *);
void str_format_8020c510(void *, const char *, ...);
}
struct Msg {
    char *text;
    Msg() { }
    Msg(const Msg &);
    ~Msg() { str_finish_8020c5c4(this); str_release_80341588(this); }
};
extern "C" int d29c_script_set_data_80101b00(Script *self) {
    int n = lua_gettop(self->L);
    if (n != 2) {
        error_801022ec(self, s1_80398ca0);
        lua_settop(self->L, -n - 1);
        return 0;
    }
    if (!lua_isstring(self->L, -2)) {
        error_801022ec(self, s2_80398cd4);
        lua_settop(self->L, -3);
        return 0;
    }
    String name(lua_tostring(self->L, -2));
    Ref r;
    Key k;
    k.text = name.c_str();
    if (lookup_800fc1b0(&k, &r) < 0) {
        error_801022ec(self, s3_80398d00);
        lua_settop(self->L, -3);
        return 0;
    } else {
        switch (r.p->vt->kind(r.p)) {
        case 0:
            if (!lua_isnumber(self->L, -1)) {
            bad:
                error_801022ec(self, s4_80398d28);
                break;
            }
            {
                int v = (int)lua_tonumber(self->L, -1);
                setInt_80178c54(asInt_803426b4(r.p), &v);
            }
            break;
        case 1:
            if (!lua_isnumber(self->L, -1)) goto bad;
            {
                int v = (int)lua_tonumber(self->L, -1);
                setInt2_80178d28(asInt2_80342a78(r.p), &v);
            }
            break;
        case 2:
            if (!lua_isnumber(self->L, -1)) goto bad;
            {
                float v = lua_tonumber(self->L, -1);
                setFloat_80178dfc(asFloat_80342a74(r.p), &v);
            }
            break;
        case 4:
            if (!lua_isstring(self->L, -1)) {
                error_801022ec(self, s5_80398d54);
                break;
            }
            {
                const char *t = lua_tostring(self->L, -1);
                setText_801790bc(asText_80343744(r.p), t);
            }
            break;
        default: {
            Msg m;
            str_default_803426b8(&m);
            str_format_8020c510(&m, s6_80398d80, name.text);
            error_801022ec(self, m.text);
            lua_settop(self->L, -3);
            return 0;
        }
        }
    }
    lua_settop(self->L, -3);
    return 0;
}
