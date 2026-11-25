#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802dd9a0.c"
typedef struct lua_State lua_State;
extern Ptr32<const char> lua_tostring(Ptr32<lua_State> L, int index);
extern Ptr32<const char> lua_pushfstring(Ptr32<lua_State> L, Ptr32<const char> format, ...);
extern void lua_remove(Ptr32<lua_State> L, int index);
extern Ptr32<int> w3d_heap_errno(void);
extern Ptr32<char> fn_802ef3f0(int code);
extern char lbl_803da870[];
int w3d_k6b_lua_errfile_802dd9a0(Ptr32<lua_State> L, int name_index)
{
    Ptr32<const char> filename = lua_tostring(L, name_index) + 1;
    lua_pushfstring(L, lbl_803da870, w3d::VA(filename), w3d::VA(fn_802ef3f0(*w3d_heap_errno())));
    lua_remove(L, name_index);
    return 2;
}
// desc: w3d_k6b_lua_errfile_802dd9a0: Appears to be Lua 5.0 lauxlib errfile: push "cannot read %s: %s" with the chunk name and the errno text, remove the name and return LUA_ERRFILE.

}
