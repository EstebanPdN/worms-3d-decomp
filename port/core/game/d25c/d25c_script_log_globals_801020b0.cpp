#include "w3d_ptr.h"
#line 1 "d25c_script_log_globals_801020b0.cpp"
// d25c: 0x801020b0. Script console: print 'globals:' and one 'name: value' line per global that is not a
// function (Lua 5.0 type 6) and whose name does not start with an underscore.
// operator+ is 'return String(a) += b', two temporaries each; names are inferred.
struct lua_State;
extern "C" void lua_pushnil(Ptr32<lua_State>);
extern "C" int lua_type(Ptr32<lua_State>, int);
extern "C" Ptr32<const char> lua_tostring(Ptr32<lua_State>, int);
extern "C" void lua_settop(Ptr32<lua_State>, int);
extern "C" int lua_next(Ptr32<lua_State>, int);
struct String;
extern "C" Ptr32<String> string_append_8020bf2c(Ptr32<String>, Ptr32<const char>);
struct String {
    Ptr32<char> text;
    char &operator[](int i) { return text[i]; }
    String &operator+=(const char *s) { string_append_8020bf2c(this, s); return *this; }
    String &operator+=(const String &o) { string_append_8020bf2c(this, o.text); return *this; }
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String>);
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    ++*string_header_80341884(this);
}
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
inline String operator+(const String &a, const char *b) {
    return String(a) += b;
}
inline String operator+(const String &a, const String &b) {
    return String(a) += b;
}
struct Script { char u0[68]; Ptr32<lua_State> L; };
extern "C" int log_801022b0(Ptr32<Script>, Ptr32<const char>, int);
extern "C" int d25c_script_log_globals_801020b0(Ptr32<Script> self) {
    log_801022b0(self, "globals:", 9);
    lua_pushnil(self->L);
    while (lua_next(self->L, -10001)) {
        if (lua_type(self->L, -1) != 6) {
            String key(lua_tostring(self->L, -2));
            if (key[0] != '_') {
                String value(lua_tostring(self->L, -1));
                String line = key + ": " + value;
                log_801022b0(self, line.text, 9);
            }
        }
        lua_settop(self->L, -2);
    }
    lua_settop(self->L, -2);
    return 0;
}


