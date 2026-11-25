#include "w3d_ptr.h"
#line 1 "s11luamath_802dfda4.cpp"
/* Lua ldexp wrapper with the original retained temporary frame slot. */
struct S11LuaState;
extern "C" {
float fn_802DD10C(Ptr32<S11LuaState>,int);
double fn_802E77F4(double,int);
void fn_802CDF40(Ptr32<S11LuaState>,float);
}
struct S11MathFrame {float reserved[2];S11MathFrame(){}~S11MathFrame(){}};
extern "C" int s11_lua_ldexp_802dfda4(Ptr32<S11LuaState> state) {
    S11MathFrame frame;
    fn_802CDF40(state,(float)fn_802E77F4(fn_802DD10C(state,1),(int)fn_802DD10C(state,2)));
    return 1;
}


