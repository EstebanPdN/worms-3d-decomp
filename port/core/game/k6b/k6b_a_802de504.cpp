#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802de504.c"
typedef struct lua_State lua_State;
extern void lua_pushnumber(Ptr32<lua_State> L, float n);
extern int lua_getgccount(Ptr32<lua_State> L);
extern int lua_getgcthreshold(Ptr32<lua_State> L);
int w3d_k6b_lua_gcinfo_802de504(Ptr32<lua_State> L)
{
    lua_pushnumber(L, (float)lua_getgccount(L));
    lua_pushnumber(L, (float)lua_getgcthreshold(L));
    return 2;
}
// desc: w3d_k6b_lua_gcinfo_802de504: Appears to be Lua 5.0 lbaselib luaB_gcinfo: push the GC count and GC threshold as numbers and return 2.

}
