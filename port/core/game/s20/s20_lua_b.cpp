#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_lua_b.c"
/* Lua global-function callers. */
typedef struct S20LuaOwner { char pad[20]; Ptr32<void> L; } S20LuaOwner;
extern void fn_802cdfd4(Ptr32<void>, Ptr32<char>);
extern void fn_802ce264(Ptr32<void>, int);
extern int fn_802cd9e8(Ptr32<void>, int);
extern void fn_802cd808(Ptr32<void>, int);
extern void fn_802cdf40(Ptr32<void>, float);
extern void fn_802ce244(Ptr32<void>, Ptr32<void>);
extern void fn_802ce6e4(Ptr32<void>, int, int);

int w3d_s20_call_lua_pointers_8019e10c(Ptr32<S20LuaOwner> self, Ptr32<char> name, Ptr32<void> first, Ptr32<void> second) {
    int result;
    fn_802cdfd4(self->L, name);
    fn_802ce264(self->L, -10001);
    if (fn_802cd9e8(self->L, -1) == 0) {
        fn_802cd808(self->L, -2);
        result = 0x80004005;
    } else {
        fn_802ce244(self->L, first);
        fn_802ce244(self->L, second);
        fn_802ce6e4(self->L, 2, 0);
        result = 0;
    }
    return result;
}

}
