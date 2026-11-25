/* Deleting destructor of a Lua-owning object with a header sub-object at offset 4. */
typedef struct S20Object { void **vtable; } S20Object;
extern void fn_80210990(char *, int);
extern void fn_801fe1f8(char *);
extern void fn_80210afc(char *);
extern void fn_80210abc(char *, int);
extern void fn_802d5bb0(void *);
extern char lbl_80413760[];
extern char lbl_804137b0[];

void w3d_s20_destroy_lua_owner_8019dafc(char *self, int flags) {
    S20Object *held = *(S20Object **)(self + 36);
    int zero = 0;
    char *list = self + 24;
    *(char **)self = lbl_80413760;
    if (held != 0)
        ((void (*)(S20Object *))held->vtable[4])(held);
    *(int *)(self + 36) = zero;
    fn_80210afc(list);
    if (*(void **)(self + 20) != 0)
        fn_802d5bb0(*(void **)(self + 20));
    if (*(S20Object **)(self + 36) != 0)
        ((void (*)(S20Object *))(*(S20Object **)(self + 36))->vtable[4])(*(S20Object **)(self + 36));
    fn_80210abc(list, 2);
    *(char **)self = lbl_804137b0;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}
