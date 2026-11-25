/* Lua global-function caller with a float argument. */
typedef struct S20LuaOwner { char pad[20]; void *L; } S20LuaOwner;
extern void fn_802cdfd4(void *, char *);
extern void fn_802ce264(void *, int);
extern int fn_802cd9e8(void *, int);
extern void fn_802cd808(void *, int);
extern void fn_802cdf40(void *, float);
extern void fn_802ce6e4(void *, int, int);

int w3d_s20_call_lua_number_8019dfec(S20LuaOwner *self, char *name, float value) {
    int result;
    fn_802cdfd4(self->L, name);
    fn_802ce264(self->L, -10001);
    if (fn_802cd9e8(self->L, -1) == 0) {
        fn_802cd808(self->L, -2);
        result = 0x80004005;
    } else {
        fn_802cdf40(self->L, value);
        fn_802ce6e4(self->L, 1, 0);
        result = 0;
    }
    return result;
}
