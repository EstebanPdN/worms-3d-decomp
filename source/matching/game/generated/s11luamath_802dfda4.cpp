/* Lua ldexp wrapper with the original retained temporary frame slot. */
struct S11LuaState;
extern "C" {
float fn_802DD10C(S11LuaState *,int);
double fn_802E77F4(double,int);
void fn_802CDF40(S11LuaState *,float);
}
struct S11MathFrame {float reserved[2];S11MathFrame(){}~S11MathFrame(){}};
extern "C" int s11_lua_ldexp_802dfda4(S11LuaState *state) {
    S11MathFrame frame;
    fn_802CDF40(state,(float)fn_802E77F4(fn_802DD10C(state,1),(int)fn_802DD10C(state,2)));
    return 1;
}
