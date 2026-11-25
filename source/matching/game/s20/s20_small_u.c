/* Cleanup, handler and pool helpers. */
typedef struct S20Object { void **vtable; } S20Object;
extern void fn_801fe2e0(char *);
extern void fn_801fe1f8(char *);
extern int lbl_804b1894;

void w3d_s20_destroy_buffers_8016fa94(char *self, int flags) {
    int zero = 0;
    char *first = *(char **)(self + 84);
    char *second;
    lbl_804b1894 = zero;
    if (first != 0)
        fn_801fe2e0(first);
    second = *(char **)(self + 88);
    *(int *)(self + 84) = zero;
    if (second != 0)
        fn_801fe2e0(second);
    *(int *)(self + 88) = zero;
    *(int *)(self + 92) = zero;
    if (flags & 1)
        fn_801fe1f8(self);
}

void w3d_s20_destroy_owned_80178474(char *self, int flags) {
    S20Object *owned = *(S20Object **)self;
    if (owned != 0) {
        ((void (*)(S20Object *))owned->vtable[16])(owned);
        if (*(int *)self != 0) {
            *(int *)self = 0;
            *(int *)(self + 4) = 0;
        }
    }
    if (flags & 1)
        fn_801fe1f8(self);
}
