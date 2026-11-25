typedef struct lua_State lua_State;
struct K6bReent {
    int error_number;
    void *stdin_file;
    void *stdout_file;
    void *stderr_file;
};
extern struct K6bReent *_impure_ptr;
extern void lua_pushstring(lua_State *L, const char *s);
extern void lua_gettable(lua_State *L, int index);
extern int lua_type(lua_State *L, int index);
extern void lua_insert(lua_State *L, int index);
extern void lua_call(lua_State *L, int nargs, int nresults);
extern const char *lua_tostring(lua_State *L, int index);
extern int fprintf(void *file, const char *format, ...);
extern void lua_settop(lua_State *L, int index);
extern char lbl_803da898[];
extern char lbl_803da8a0[];
void w3d_k6b_lua_callalert_802ddc0c(lua_State *L, int status)
{
    if (status != 0) {
        lua_pushstring(L, lbl_803da898);
        lua_gettable(L, -10001);
        if (lua_type(L, -1) == 6) {
            lua_insert(L, -2);
            lua_call(L, 1, 0);
        } else {
            fprintf(_impure_ptr->stderr_file, lbl_803da8a0, lua_tostring(L, -2));
            lua_settop(L, -3);
        }
    }
}
// desc: w3d_k6b_lua_callalert_802ddc0c: Appears to be Lua 5.0 lauxlib callalert: on error call the global _ALERT with the message, or print it to stderr and pop two values.
