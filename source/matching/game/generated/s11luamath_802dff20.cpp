/* Lua random-number modes reconstructed from the local Lua 5.0 source. */
struct S11LuaState;
extern "C" {
int fn_802EE7DC(void);
int fn_802CD7F4(S11LuaState *);
float fn_802DD10C(S11LuaState *,int);
void fn_802CDF40(S11LuaState *,float);
int fn_802DCC74(S11LuaState *,int,const char *);
int fn_802DCE74(S11LuaState *,const char *,...);
double fn_802E75D0(double);
extern const char lbl_803DAE80[],lbl_803DAE94[];
}
struct S11MathFrame {float reserved[4];S11MathFrame(){}~S11MathFrame(){}};
extern "C" int s11_lua_random_802dff20(S11LuaState *state) {
    S11MathFrame frame;
    float random=(float)(fn_802EE7DC()%2147483647)/(float)2147483647;
    switch(fn_802CD7F4(state)) {
    case 0:
        fn_802CDF40(state,random);
        break;
    case 1: {
        int upper=(int)fn_802DD10C(state,1);
        if (upper<1) fn_802DCC74(state,1,lbl_803DAE80);
        fn_802CDF40(state,(float)((int)fn_802E75D0(random*upper)+1));
        break;
    }
    case 2: {
        int lower=(int)fn_802DD10C(state,1);
        int upper=(int)fn_802DD10C(state,2);
        if (lower>upper) fn_802DCC74(state,2,lbl_803DAE80);
        fn_802CDF40(state,(float)((int)fn_802E75D0(random*(upper-lower+1))+lower));
        break;
    }
    default:return fn_802DCE74(state,lbl_803DAE94);
    }
    return 1;
}
