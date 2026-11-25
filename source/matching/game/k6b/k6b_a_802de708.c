typedef struct lua_State lua_State;
typedef float lua_Number;
extern lua_Number lua_tonumber(lua_State *L, int index);
extern void luaL_checktype(lua_State *L, int narg, int t);
extern int lua_type(lua_State *L, int index);
extern void lua_pushlstring(lua_State *L, const char *s, unsigned int len);
extern void lua_rawget(lua_State *L, int index);
extern void lua_pushvalue(lua_State *L, int index);
extern void lua_pushnumber(lua_State *L, lua_Number n);
extern void lua_rawgeti(lua_State *L, int index, int n);
int w3d_k6b_lua_ipairs_802de708(lua_State *L)
{
    lua_Number i = lua_tonumber(L, 2);
    luaL_checktype(L, 1, 5);
    if (i == 0 && lua_type(L, 2) == -1) {
        lua_pushlstring(L, "ipairs", sizeof("ipairs") - 1);
        lua_rawget(L, -10001);
        lua_pushvalue(L, 1);
        lua_pushnumber(L, 0);
        return 3;
    } else {
        i++;
        lua_pushnumber(L, i);
        lua_rawgeti(L, 1, (int)i);
        return (lua_type(L, -1) == 0) ? 0 : 2;
    }
}
// desc: w3d_k6b_lua_ipairs_802de708: Appears to be Lua 5.0 lbaselib luaB_ipairs: on the first step push the ipairs generator, table and 0, else push the next index and its raw table value.
