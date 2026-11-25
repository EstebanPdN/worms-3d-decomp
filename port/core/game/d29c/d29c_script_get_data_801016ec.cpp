#include "w3d_ptr.h"
#line 1 "d29c_script_get_data_801016ec.cpp"
// d29c: 0x801016ec. Script binding GetData(name): looks up the named data entry and pushes its int, unsigned, float or string value, reporting errors through the script log. Names are inferred; classes are partial views.
struct lua_State;
extern "C" int lua_gettop(Ptr32<lua_State>);
extern "C" void lua_settop(Ptr32<lua_State>, int);
extern "C" int lua_isstring(Ptr32<lua_State>, int);
extern "C" Ptr32<const char> lua_tostring(Ptr32<lua_State>, int);
extern "C" void lua_pushnumber(Ptr32<lua_State>, float);
extern "C" void lua_pushstring(Ptr32<lua_State>, Ptr32<const char>);
extern "C" void str_finish_8020c5c4(Ptr32<void>);
extern "C" void str_release_80341588(Ptr32<void>);
struct Header { unsigned short refs; };
extern "C" void str_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<Header> str_header_80341884(Ptr32<void>);
extern "C" Ptr32<void> str_append_8020bf2c(Ptr32<void>, Ptr32<const char>);
struct String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);
    String_8020bb54(const String_8020bb54 &o) { str_init_8020c5c0(this); text = o.text; str_header_80341884(this)->refs++; }
    Ptr32<const char> c_str() const { return text; }
    ~String_8020bb54() { str_finish_8020c5c4(this); str_release_80341588(this); }
    void append(Ptr32<const char> t) { str_append_8020bf2c(this, t); }
};
typedef String_8020bb54 String;
inline String operator+(const String &a, const char *b) { String r(a); r.append(b); return r; }
inline String operator+(const String &a, const String &b) { String r = a; str_append_8020bf2c(&r, b.text); return r; }
struct Object;
struct ObjectVt { char u0[12]; Ptr32<void (Ptr32<Object>)> add; Ptr32<void (Ptr32<Object>)> release; Ptr32<int (Ptr32<Object>)> type; Ptr32<int (Ptr32<Object>)> kind; };
struct Object { Ptr32<ObjectVt> vt; };
struct Ref {
    Ptr32<Object> p;
    Ref() { p = 0; }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
};
struct Key { Ptr32<const char> text; };
struct Script { char u0[68]; Ptr32<lua_State> L; };
extern char s1_80398be0[], s2_80398c14[], s3_80398c40[], s4_80398c68[], s5_80398c74[];
extern "C" {
void error_801022ec(Ptr32<Script>, Ptr32<const char>);
int lookup_800fc1b0(Ptr32<Key>, Ptr32<Ref>);
Ptr32<void> asInt_803426b4(Ptr32<void>);
Ptr32<void> asInt2_80342a78(Ptr32<void>);
Ptr32<void> asFloat_80342a74(Ptr32<void>);
Ptr32<void> asText_80343744(Ptr32<void>);
int getInt_80178c48(Ptr32<void>);
unsigned getInt2_80178d1c(Ptr32<void>);
float getFloat_80178df0(Ptr32<void>);
Ptr32<const String> getText_80179170(Ptr32<void>);
}
extern "C" int d29c_script_get_data_801016ec(Ptr32<Script> self) {
    int n = lua_gettop(self->L);
    if (n != 1) {
        error_801022ec(self, s1_80398be0);
        lua_settop(self->L, -n - 1);
        return 0;
    }
    if (!lua_isstring(self->L, -1)) {
        error_801022ec(self, s2_80398c14);
        lua_settop(self->L, -3);
        return 0;
    }
    String name(lua_tostring(self->L, -1));
    Ref r;
    Key k;
    k.text = name.c_str();
    if (lookup_800fc1b0(&k, &r) < 0) {
        error_801022ec(self, s3_80398c40);
        lua_settop(self->L, -3);
        return 0;
    }
    switch (r.p->vt->kind(r.p)) {
    case 0: {
        float v = getInt_80178c48(asInt_803426b4(r.p));
        lua_settop(self->L, -3);
        lua_pushnumber(self->L, v);
        break;
    }
    case 1: {
        unsigned v = getInt2_80178d1c(asInt2_80342a78(r.p));
        lua_settop(self->L, -3);
        lua_pushnumber(self->L, v);
        break;
    }
    case 2: {
        float v = getFloat_80178df0(asFloat_80342a74(r.p));
        lua_settop(self->L, -3);
        lua_pushnumber(self->L, v);
        break;
    }
    case 4: {
        String s(*getText_80179170(asText_80343744(r.p)));
        lua_settop(self->L, -3);
        lua_pushstring(self->L, s.text);
        break;
    }
    default: {
        String m = String(s4_80398c68) + name + s5_80398c74;
        error_801022ec(self, m.text);
        lua_settop(self->L, -3);
        return 0;
    }
    }
    return 1;
}


