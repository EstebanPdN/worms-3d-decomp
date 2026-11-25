#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802ddc0c.c"
typedef struct lua_State lua_State;
struct K6bReent {
    int error_number;
    Ptr32<void> stdin_file;
    Ptr32<void> stdout_file;
    Ptr32<void> stderr_file;
};
extern Ptr32<struct K6bReent> _impure_ptr;
extern void lua_pushstring(Ptr32<lua_State> L, Ptr32<const char> s);
extern void lua_gettable(Ptr32<lua_State> L, int index);
extern int lua_type(Ptr32<lua_State> L, int index);
extern void lua_insert(Ptr32<lua_State> L, int index);
extern void lua_call(Ptr32<lua_State> L, int nargs, int nresults);
extern Ptr32<const char> lua_tostring(Ptr32<lua_State> L, int index);
extern int fprintf(Ptr32<void> file, Ptr32<const char> format, ...);
extern void lua_settop(Ptr32<lua_State> L, int index);
extern char lbl_803da898[];
extern char lbl_803da8a0[];
void w3d_k6b_lua_callalert_802ddc0c(Ptr32<lua_State> L, int status)
{
    if (status != 0) {
        lua_pushstring(L, lbl_803da898);
        lua_gettable(L, -10001);
        if (lua_type(L, -1) == 6) {
            lua_insert(L, -2);
            lua_call(L, 1, 0);
        } else {
            fprintf(_impure_ptr->stderr_file, lbl_803da8a0, w3d::VA(lua_tostring(L, -2)));
            lua_settop(L, -3);
        }
    }
}
// desc: w3d_k6b_lua_callalert_802ddc0c: Appears to be Lua 5.0 lauxlib callalert: on error call the global _ALERT with the message, or print it to stderr and pop two values.

}
