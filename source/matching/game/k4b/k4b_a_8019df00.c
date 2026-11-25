typedef struct lua_State lua_State;
extern int luaL_loadbuffer(lua_State *L, const char *buff, unsigned int size, const char *name);
extern void lua_call(lua_State *L, int nargs, int nresults);
struct K4bScriptHost {
    char pad0[20];
    lua_State *L;
};
int w3d_k4b_script_run_buffer_8019df00(struct K4bScriptHost *self, const char *buffer, unsigned int size)
{
    int status = luaL_loadbuffer(self->L, buffer, size, "inputchunk");
    if (status == 0)
        lua_call(self->L, 0, 0);
    return status != 0 ? 0x80004005 : 0;
}
// desc: w3d_k4b_script_run_buffer_8019df00: Appears to load a Lua chunk named inputchunk from a buffer and call it with no arguments, returning E_FAIL when loading fails.
