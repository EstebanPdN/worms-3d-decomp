typedef struct lua_State lua_State;
extern void lua_pushnumber(lua_State *L, float n);
extern int lua_getgccount(lua_State *L);
extern int lua_getgcthreshold(lua_State *L);
int w3d_k6b_lua_gcinfo_802de504(lua_State *L)
{
    lua_pushnumber(L, (float)lua_getgccount(L));
    lua_pushnumber(L, (float)lua_getgcthreshold(L));
    return 2;
}
// desc: w3d_k6b_lua_gcinfo_802de504: Appears to be Lua 5.0 lbaselib luaB_gcinfo: push the GC count and GC threshold as numbers and return 2.
