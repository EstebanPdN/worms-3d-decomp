#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802de708.c"
typedef struct lua_State lua_State;
typedef float lua_Number;
extern lua_Number lua_tonumber(Ptr32<lua_State> L, int index);
extern void luaL_checktype(Ptr32<lua_State> L, int narg, int t);
extern int lua_type(Ptr32<lua_State> L, int index);
extern void lua_pushlstring(Ptr32<lua_State> L, Ptr32<const char> s, unsigned int len);
extern void lua_rawget(Ptr32<lua_State> L, int index);
extern void lua_pushvalue(Ptr32<lua_State> L, int index);
extern void lua_pushnumber(Ptr32<lua_State> L, lua_Number n);
extern void lua_rawgeti(Ptr32<lua_State> L, int index, int n);
int w3d_k6b_lua_ipairs_802de708(Ptr32<lua_State> L)
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

}
