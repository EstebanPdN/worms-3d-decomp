// d25c: 0x801022ec. Report a fatal script error: format and log it, post the failure message, stop the script
// (state 2) and log the first Lua stack frame that has a current line with its source text. Names are
// inferred; Script is a partial view (the line buffer starts at +76).
struct lua_State;
struct lua_Debug {
    int event;
    const char *name;
    const char *namewhat;
    const char *what;
    const char *source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci;
};
extern "C" int lua_getstack(lua_State *, int, lua_Debug *);
extern "C" int lua_getinfo(lua_State *, const char *, lua_Debug *);
struct String {
    char *text;
    String();
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" void string_format_8020c510(String *, const char *, ...);
struct Script { char u0[68]; lua_State *L; char u72[4]; char line[1]; };
struct Arena;
extern Arena *arena_804b1754;
extern int fail_id_804af164;
extern "C" void *arena_alloc_801613f0(Arena *, unsigned);
extern "C" int cached_id_8015f5a0(int *, int);
extern "C" void *message_init_8010a8e0(void *, unsigned short, const char *);
extern "C" int message_post_8016239c(void *);
extern "C" void log_801022b0(Script *, const char *, int);
extern "C" void output_801022e8(Script *, const char *);
extern "C" void set_state_8010272c(Script *, int);
extern "C" int source_line_80102890(Script *, const char *, int, char *);
extern const char info_what_80398da4[];
extern "C" void d25c_script_fatal_error_801022ec(Script *self, const char *text) {
    String message;
    string_format_8020c510(&message, "%s\nscript execution terminated", text);
    log_801022b0(self, message.text, 1);
    output_801022e8(self, message.text);
    void *m = arena_alloc_801613f0(arena_804b1754, 12);
    message_post_8016239c(message_init_8010a8e0(m, cached_id_8015f5a0(&fail_id_804af164, 1), "FAIL: Script execution terminated"));
    set_state_8010272c(self, 2);
    if (self->L) {
        lua_Debug ar;
        for (int level = 0; lua_getstack(self->L, level, &ar); level++) {
            lua_getinfo(self->L, info_what_80398da4, &ar);
            if (ar.currentline != -1) {
                String line;
                source_line_80102890(self, ar.source, ar.currentline - 1, self->line);
                string_format_8020c510(&line, "error in %s at line %d: %s", ar.source, ar.currentline, self->line);
                log_801022b0(self, line.text, 1);
                output_801022e8(self, line.text);
                break;
            }
        }
    }
}
