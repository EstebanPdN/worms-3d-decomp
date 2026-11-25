#include "w3d_ptr.h"
#line 1 "d29c_script_set_data_80101b00.cpp"
// d29c: 0x80101b00. Script binding SetData(name, value): looks up the named data entry and stores the Lua value according to the entry kind (int, int, float, string), reporting errors through the script log. Names are inferred; classes are partial views.
struct lua_State;
extern "C" int lua_gettop(Ptr32<lua_State>);
extern "C" void lua_settop(Ptr32<lua_State>, int);
extern "C" int lua_isstring(Ptr32<lua_State>, int);
extern "C" Ptr32<const char> lua_tostring(Ptr32<lua_State>, int);
extern "C" void lua_pushlightuserdata(Ptr32<lua_State>, Ptr32<void>);
extern "C" void str_finish_8020c5c4(Ptr32<void>);
extern "C" void str_release_80341588(Ptr32<void>);
struct String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);
    Ptr32<const char> c_str() const { return text; }
    String_8020bb54(const String_8020bb54 &);
    ~String_8020bb54() { str_finish_8020c5c4(this); str_release_80341588(this); }
};
typedef String_8020bb54 String;
struct Object;
struct ObjectVt { char u0[12]; Ptr32<void (Ptr32<Object>)> add; Ptr32<void (Ptr32<Object>)> release; Ptr32<int (Ptr32<Object>)> type; Ptr32<int (Ptr32<Object>)> kind; };
struct Object { Ptr32<ObjectVt> vt; };
struct Ref {
    Ptr32<Object> p;
    Ref() { p = 0; }
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *q) { p = q; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Object *)w3d_p.get()); }
 Ref &operator=(Object *q) { if (q) q->vt->add(q); if (p) p->vt->release(p); p = q; return *this; }
};
struct Key { Ptr32<const char> text; };
struct Script;
struct Registry { struct V { char u0[28]; Ptr32<void (Ptr32<Registry>, Ptr32<Object>)> add; }; Ptr32<struct V> vt; };
struct Script { char u0[64]; Ptr32<Registry> registry; Ptr32<lua_State> L; char u72[284]; int containers; };
extern char s1_80398ca0[], s2_80398cd4[], s3_80398d00[], s4_80398d28[], s5_80398d54[], s6_80398d80[];
extern "C" {
void error_801022ec(Ptr32<Script>, Ptr32<const char>);
int lookup_800fc1b0(Ptr32<Key>, Ptr32<Ref>);
int lua_isnumber(Ptr32<lua_State>, int);
float lua_tonumber(Ptr32<lua_State>, int);
Ptr32<void> asInt_803426b4(Ptr32<void>);
Ptr32<void> asInt2_80342a78(Ptr32<void>);
Ptr32<void> asFloat_80342a74(Ptr32<void>);
Ptr32<void> asText_80343744(Ptr32<void>);
int setInt_80178c54(Ptr32<void>, Ptr32<int>);
int setInt2_80178d28(Ptr32<void>, Ptr32<int>);
int setFloat_80178dfc(Ptr32<void>, Ptr32<float>);
int setText_801790bc(Ptr32<void>, Ptr32<const char>);
Ptr32<void> str_default_803426b8(Ptr32<void>);
void str_format_8020c510(Ptr32<void>, Ptr32<const char>, ...);
}
struct Msg {
    Ptr32<char> text;
    Msg() { }
    Msg(const Msg &);
    ~Msg() { str_finish_8020c5c4(this); str_release_80341588(this); }
};
extern "C" int d29c_script_set_data_80101b00(Ptr32<Script> self) {
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
                Ptr32<const char> t = lua_tostring(self->L, -1);
                setText_801790bc(asText_80343744(r.p), t);
            }
            break;
        default: {
            Msg m;
            str_default_803426b8(&m);
            str_format_8020c510(&m, s6_80398d80, w3d::VA(name.text));
            error_801022ec(self, m.text);
            lua_settop(self->L, -3);
            return 0;
        }
        }
    }
    lua_settop(self->L, -3);
    return 0;
}


