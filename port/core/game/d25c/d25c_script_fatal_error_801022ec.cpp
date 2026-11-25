#include "w3d_ptr.h"
#line 1 "d25c_script_fatal_error_801022ec.cpp"
// d25c: 0x801022ec. Report a fatal script error: format and log it, post the failure message, stop the script
// (state 2) and log the first Lua stack frame that has a current line with its source text. Names are
// inferred; Script is a partial view (the line buffer starts at +76).
struct lua_State;
struct lua_Debug {
    int event;
    Ptr32<const char> name;
    Ptr32<const char> namewhat;
    Ptr32<const char> what;
    Ptr32<const char> source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci;
};
extern "C" int lua_getstack(Ptr32<lua_State>, int, Ptr32<lua_Debug>);
extern "C" int lua_getinfo(Ptr32<lua_State>, Ptr32<const char>, Ptr32<lua_Debug>);
struct String {
    Ptr32<char> text;
    String();
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" void string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
struct Script { char u0[68]; Ptr32<lua_State> L; char u72[4]; char line[1]; };
struct Arena;
extern Ptr32<Arena> arena_804b1754;
extern int fail_id_804af164;
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<Arena>, unsigned);
extern "C" int cached_id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<void> message_init_8010a8e0(Ptr32<void>, unsigned short, Ptr32<const char>);
extern "C" int message_post_8016239c(Ptr32<void>);
extern "C" void log_801022b0(Ptr32<Script>, Ptr32<const char>, int);
extern "C" void output_801022e8(Ptr32<Script>, Ptr32<const char>);
extern "C" void set_state_8010272c(Ptr32<Script>, int);
extern "C" int source_line_80102890(Ptr32<Script>, Ptr32<const char>, int, Ptr32<char>);
extern const char info_what_80398da4[];
extern "C" void d25c_script_fatal_error_801022ec(Ptr32<Script> self, Ptr32<const char> text) {
    String message;
    string_format_8020c510(&message, "%s\nscript execution terminated", w3d::VA(text));
    log_801022b0(self, message.text, 1);
    output_801022e8(self, message.text);
    Ptr32<void> m = arena_alloc_801613f0(arena_804b1754, 12);
    message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&fail_id_804af164, 1), "FAIL: Script execution terminated"));
    set_state_8010272c(self, 2);
    if (self->L) {
        lua_Debug ar;
        for (int level = 0; lua_getstack(self->L, level, &ar); level++) {
            lua_getinfo(self->L, info_what_80398da4, &ar);
            if (ar.currentline != -1) {
                String line;
                source_line_80102890(self, ar.source, ar.currentline - 1, self->line);
                string_format_8020c510(&line, "error in %s at line %d: %s", w3d::VA(ar.source), ar.currentline, w3d::VA(self->line));
                log_801022b0(self, line.text, 1);
                output_801022e8(self, line.text);
                break;
            }
        }
    }
}


