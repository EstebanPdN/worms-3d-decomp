#include "w3d_ptr.h"
#line 1 "s11luamath_802dfe10.cpp"
struct S11LuaState;
extern "C" {
int fn_802CD7F4(Ptr32<S11LuaState>);
float fn_802DD10C(Ptr32<S11LuaState>,int);
void fn_802CDF40(Ptr32<S11LuaState>,float);
}
struct S11MathFrame {float reserved[2];S11MathFrame(){}~S11MathFrame(){}};
extern "C" int s11_lua_extreme_802dfe10(Ptr32<S11LuaState> state) {
    S11MathFrame frame;
    int count=fn_802CD7F4(state);
    float result=fn_802DD10C(state,1);
    int i;
    for(i=2;i<=count;i++) {
        float value=fn_802DD10C(state,i);
        if(value < result) result=value;
    }
    fn_802CDF40(state,result);
    return 1;
}


