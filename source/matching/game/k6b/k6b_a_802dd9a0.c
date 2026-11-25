typedef struct lua_State lua_State;
extern const char *lua_tostring(lua_State *L, int index);
extern const char *lua_pushfstring(lua_State *L, const char *format, ...);
extern void lua_remove(lua_State *L, int index);
extern int *w3d_heap_errno(void);
extern char *fn_802ef3f0(int code);
extern char lbl_803da870[];
int w3d_k6b_lua_errfile_802dd9a0(lua_State *L, int name_index)
{
    const char *filename = lua_tostring(L, name_index) + 1;
    lua_pushfstring(L, lbl_803da870, filename, fn_802ef3f0(*w3d_heap_errno()));
    lua_remove(L, name_index);
    return 2;
}
// desc: w3d_k6b_lua_errfile_802dd9a0: Appears to be Lua 5.0 lauxlib errfile: push "cannot read %s: %s" with the chunk name and the errno text, remove the name and return LUA_ERRFILE.
