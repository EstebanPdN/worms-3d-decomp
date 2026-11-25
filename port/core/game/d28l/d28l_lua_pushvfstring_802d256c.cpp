#include "w3d_ptr.h"
#line 1 "d28l_lua_pushvfstring_802d256c.cpp"
// GWMP8P rev0 0x802d256c. Lua 5.0 luaO_pushvfstring: expands %s, %c, %d, %f
// and %% from a varargs list onto the Lua stack and concatenates the pieces.
// Quienes la llaman son funciones variádicas del anfitrión (core/lua): en arm64 de Apple
// va_list es un puntero a la pila y cada argumento ocupa 8 bytes.
struct TObject { int tt; union { Ptr32<void> gc; float n; } value; };
struct lua_State { int u0, u4; Ptr32<TObject> top; Ptr32<TObject> base; int u16, u20; Ptr32<char> stack_last; };
extern "C" void pushstr(Ptr32<lua_State>, Ptr32<const char>);
extern "C" Ptr32<void> luaS_newlstr(Ptr32<lua_State>, Ptr32<const char>, int);
extern "C" void luaD_growstack(Ptr32<lua_State>, int);
extern "C" void luaV_concat(Ptr32<lua_State>, int, int);
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern const char s_803d9e18[], s_803d9e1c[];
#define GP(ap) ({ char *p_ = (ap); (ap) += 8; p_; })
#define FP(ap) GP(ap)
extern "C" Ptr32<const char> d28l_lua_pushvfstring_802d256c(Ptr32<lua_State> L, Ptr32<const char> fmt, char *argp) {
    int n = 1;
    pushstr(L, s_803d9e18);
    for (;;) {
        Ptr32<const char> e = strchr(fmt, '%');
        if (e == 0) break;
        { Ptr32<TObject> o = L->top; o->tt = 4; o->value.gc = luaS_newlstr(L, fmt, e - fmt); }
        if ((Ptr32<char>)L->stack_last - (Ptr32<char>)L->top <= 8) luaD_growstack(L, 1);
        L->top++;
        switch (*(e + 1)) {
        case 's':
            pushstr(L, (Ptr32<const char>)*(const char **)GP(argp));
            break;
        case 'c': {
            char buff[2];
            buff[0] = (char)*(int *)GP(argp);
            buff[1] = 0;
            pushstr(L, buff);
            break;
        }
        case 'd':
            { Ptr32<TObject> o = L->top; o->tt = 3; o->value.n = (float)*(int *)GP(argp); }
            if ((Ptr32<char>)L->stack_last - (Ptr32<char>)L->top <= 8) luaD_growstack(L, 1);
            L->top++;
            break;
        case 'f':
            { Ptr32<TObject> o = L->top; o->tt = 3; o->value.n = (float)*(double *)FP(argp); }
            if ((Ptr32<char>)L->stack_last - (Ptr32<char>)L->top <= 8) luaD_growstack(L, 1);
            L->top++;
            break;
        case '%':
            pushstr(L, s_803d9e1c);
            break;
        }
        n += 2;
        fmt = e + 2;
    }
    pushstr(L, fmt);
    luaV_concat(L, n + 1, (L->top - L->base) - 1);
    L->top -= n;
    return (Ptr32<const char>)((L->top - 1)->value.gc) + 16;
}


