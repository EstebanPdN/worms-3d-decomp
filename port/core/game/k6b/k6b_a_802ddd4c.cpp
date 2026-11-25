#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802ddd4c.c"
typedef struct lua_State lua_State;
struct K6bReent {
    int error_number;
    Ptr32<void> stdin_file;
    Ptr32<void> stdout_file;
    Ptr32<void> stderr_file;
};
extern Ptr32<struct K6bReent> _impure_ptr;
extern int lua_gettop(Ptr32<lua_State> L);
extern void lua_pushstring(Ptr32<lua_State> L, Ptr32<const char> s);
extern void lua_gettable(Ptr32<lua_State> L, int index);
extern void lua_pushvalue(Ptr32<lua_State> L, int index);
extern void lua_call(Ptr32<lua_State> L, int nargs, int nresults);
extern Ptr32<const char> lua_tostring(Ptr32<lua_State> L, int index);
extern int luaL_error(Ptr32<lua_State> L, Ptr32<const char> format, ...);
extern int fputs(Ptr32<const char> s, Ptr32<void> file);
extern void lua_settop(Ptr32<lua_State> L, int index);
extern char lbl_803da8a8[];
extern char lbl_803da8b4[];
extern char lbl_803da8e0[];
extern char lbl_803da8e4[];
int w3d_k6b_lua_print_802ddd4c(Ptr32<lua_State> L)
{
    int n = lua_gettop(L);
    int i;
    lua_pushstring(L, lbl_803da8a8);
    lua_gettable(L, -10001);
    for (i = 1; i <= n; i++) {
        Ptr32<const char> s;
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

}
