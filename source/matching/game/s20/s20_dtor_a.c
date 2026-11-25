/* Deleting destructors of classes with a header sub-object at offset 4. */
typedef struct S20Object { void **vtable; } S20Object;
extern void fn_80210990(char *, int);
extern void fn_801fe1f8(char *);
extern void fn_802134fc(void *);
extern char *lbl_804b1884;
extern char lbl_80411c10[];
extern char lbl_80411c88[];

void w3d_s20_destroy_registered_80166f5c(char *self, int flags) {
    char *registered = lbl_804b1884;
    *(char **)self = lbl_80411c10;
    if (registered == self)
        lbl_804b1884 = 0;
    *(char **)self = lbl_80411c88;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

extern char lbl_80413830[];
extern char lbl_80413858[];
extern void fn_802dd884(void *, int, int);

void w3d_s20_destroy_lua_ref_8019e600(char *self, int flags) {
    int reference = *(int *)(self + 24);
    *(char **)self = lbl_80413830;
    if (reference != 0) {
        S20Object *owner = *(S20Object **)(self + 20);
        void *state = ((void *(*)(S20Object *))owner->vtable[9])(owner);
        fn_802dd884(state, -10000, *(int *)(self + 24));
    }
    *(char **)self = lbl_80413858;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

extern char lbl_80411a30[];
extern char lbl_80411a88[];
extern void fn_8034ba74(char *);

void w3d_s20_destroy_list_owner_80165af0(char *self, int flags) {
    char *list = self + 24;
    S20Object *held;
    *(char **)self = lbl_80411a30;
    fn_8034ba74(list);
    if (*(void **)(list + 4) != 0)
        fn_802134fc(*(void **)(list + 4));
    held = *(S20Object **)(self + 20);
    if (held != 0)
        ((void (*)(S20Object *))held->vtable[4])(held);
    *(char **)self = lbl_80411a88;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}

extern char lbl_804139c0[];
extern char lbl_804139e0[];
extern int fn_801a18f8(char *);
extern void fn_80210120(char *);
extern int lbl_804ab74c;

void w3d_s20_destroy_service_801a1cf0(char *self, int flags) {
    S20Object *held;
    *(char **)self = lbl_804139c0;
    fn_801a18f8(self);
    fn_80210120(self);
    held = *(S20Object **)(self + 32);
    lbl_804ab74c = 0;
    if (held != 0)
        ((void (*)(S20Object *))held->vtable[4])(held);
    if (*(void **)(self + 20) != 0)
        fn_802134fc(*(void **)(self + 20));
    *(char **)self = lbl_804139e0;
    fn_80210990(self + 4, 0);
    if (flags & 1)
        fn_801fe1f8(self);
}
