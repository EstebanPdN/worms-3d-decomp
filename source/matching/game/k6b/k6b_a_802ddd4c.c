typedef struct lua_State lua_State;
struct K6bReent {
    int error_number;
    void *stdin_file;
    void *stdout_file;
    void *stderr_file;
};
extern struct K6bReent *_impure_ptr;
extern int lua_gettop(lua_State *L);
extern void lua_pushstring(lua_State *L, const char *s);
extern void lua_gettable(lua_State *L, int index);
extern void lua_pushvalue(lua_State *L, int index);
extern void lua_call(lua_State *L, int nargs, int nresults);
extern const char *lua_tostring(lua_State *L, int index);
extern int luaL_error(lua_State *L, const char *format, ...);
extern int fputs(const char *s, void *file);
extern void lua_settop(lua_State *L, int index);
extern char lbl_803da8a8[];
extern char lbl_803da8b4[];
extern char lbl_803da8e0[];
extern char lbl_803da8e4[];
int w3d_k6b_lua_print_802ddd4c(lua_State *L)
{
    int n = lua_gettop(L);
    int i;
    lua_pushstring(L, lbl_803da8a8);
    lua_gettable(L, -10001);
    for (i = 1; i <= n; i++) {
        const char *s;
        lua_pushvalue(L, -1);
        lua_pushvalue(L, i);
        lua_call(L, 1, 1);
        s = lua_tostring(L, -1);
        if (s == 0)
            return luaL_error(L, lbl_803da8b4);
        if (i > 1) fputs(lbl_803da8e0, _impure_ptr->stdout_file);
        fputs(s, _impure_ptr->stdout_file);
        lua_settop(L, -2);
    }
    fputs(lbl_803da8e4, _impure_ptr->stdout_file);
    return 0;
}
// desc: w3d_k6b_lua_print_802ddd4c: Appears to be Lua 5.0 lbaselib luaB_print: convert each argument with the global tostring and write it to stdout separated by tabs, ending with a newline.
