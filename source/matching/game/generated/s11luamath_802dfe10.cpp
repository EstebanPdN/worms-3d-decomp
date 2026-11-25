struct S11LuaState;
extern "C" {
int fn_802CD7F4(S11LuaState *);
float fn_802DD10C(S11LuaState *,int);
void fn_802CDF40(S11LuaState *,float);
}
struct S11MathFrame {float reserved[2];S11MathFrame(){}~S11MathFrame(){}};
extern "C" int s11_lua_extreme_802dfe10(S11LuaState *state) {
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
