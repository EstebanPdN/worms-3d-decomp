// GWMP8P rev0 0x802d256c. Lua 5.0 luaO_pushvfstring: expands %s, %c, %d, %f
// and %% from a varargs list onto the Lua stack and concatenates the pieces.
// The varargs reads are written out as the ProDG expansion over a partial
// view of the list (gpr, fpr, overflow, register save area) because the
// build's stdarg header does not reproduce it. Built with -mps-float.
struct TObject { int tt; union { void *gc; float n; } value; };
struct lua_State { int u0, u4; TObject *top; TObject *base; int u16, u20; char *stack_last; };
struct VaList { signed char gpr, fpr; char *overflow; char *save; };
extern "C" void pushstr(lua_State *, const char *);
extern "C" void *luaS_newlstr(lua_State *, const char *, int);
extern "C" void luaD_growstack(lua_State *, int);
extern "C" void luaV_concat(lua_State *, int, int);
extern "C" char *strchr(const char *, int);
extern const char s_803d9e18[], s_803d9e1c[];
#define GP(ap) ({ char *p_; \
    if ((unsigned)((ap)->gpr + 1) <= 8) { p_ = (ap)->save + (ap)->gpr * 4; (ap)->gpr++; } \
    else { if ((ap)->gpr <= 7) { p_ = (ap)->overflow; (ap)->gpr = 8; } else { p_ = (ap)->overflow; } (ap)->overflow = p_ + 4; } p_; })
#define FP(ap) ({ char *p_; \
    if ((ap)->fpr <= 7) { p_ = (ap)->save + ((ap)->fpr * 8 + 32); (ap)->fpr++; } \
    else { p_ = (ap)->overflow; (ap)->overflow = p_ + 8; } p_; })
extern "C" const char *d28l_lua_pushvfstring_802d256c(lua_State *L, const char *fmt, VaList *argp) {
    int n = 1;
    pushstr(L, s_803d9e18);
    for (;;) {
        const char *e = strchr(fmt, '%');
        if (e == 0) break;
        { TObject *o = L->top; o->tt = 4; o->value.gc = luaS_newlstr(L, fmt, e - fmt); }
        if ((char *)L->stack_last - (char *)L->top <= 8) luaD_growstack(L, 1);
        L->top++;
        switch (*(e + 1)) {
        case 's':
            pushstr(L, *(char **)GP(argp));
            break;
        case 'c': {
            char buff[2];
            buff[0] = (char)*(int *)GP(argp);
            buff[1] = 0;
            pushstr(L, buff);
            break;
        }
        case 'd':
            { TObject *o = L->top; o->tt = 3; o->value.n = (float)*(int *)GP(argp); }
            if ((char *)L->stack_last - (char *)L->top <= 8) luaD_growstack(L, 1);
            L->top++;
            break;
        case 'f':
            { TObject *o = L->top; o->tt = 3; o->value.n = (float)*(double *)FP(argp); }
            if ((char *)L->stack_last - (char *)L->top <= 8) luaD_growstack(L, 1);
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
    return (const char *)((L->top - 1)->value.gc) + 16;
}
