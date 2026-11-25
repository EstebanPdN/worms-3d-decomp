/* Releases, global forwarding and flag clearing. */
typedef struct S20Object { void **vtable; } S20Object;
extern int fn_800df684(char *);

int w3d_s20_release_held_800e41d8(char *self) {
    S20Object *held = *(S20Object **)(self + 348);
    if (held != 0)
        ((void (*)(S20Object *))held->vtable[4])(held);
    *(int *)(self + 348) = 0;
    return fn_800df684(self + 28);
}

extern int fn_800e61b8(void *, int, int, int, void *);
extern void *lbl_804aaecc;

int w3d_s20_forward_global4_800e5d4c(int a, int b, int c, int d) {
    if (lbl_804aaecc == 0)
        return 0;
    return fn_800e61b8(lbl_804aaecc, a, b, c, d);
}

extern int fn_800fddd8(void *, int, int, int, int);
extern void *lbl_804aaf64;

int w3d_s20_forward_global4_800fdd80(int a, int b, int c, int d) {
    if (lbl_804aaf64 == 0)
        return 0x80004005;
    return fn_800fddd8(lbl_804aaf64, a, b, c, d);
}

extern void fn_800b0824(char *, char *, char *, int, int);
extern int lbl_804b1764;

int w3d_s20_check_limit_800e6ec8(char *self) {
    fn_800b0824(self + 116, self + 12, self + 24, *(int *)(self + 92), 1);
    return lbl_804b1764 <= *(int *)(self + 92);
}

extern int fn_800fdf5c(char *, int, int, int);

int w3d_s20_clear_top_flags_800fdecc(char *self) {
    *(unsigned int *)(self + 92) &= 0x3fffffff;
    fn_800fdf5c(self, 0, 0, 0);
    return fn_800fdf5c(self, 1, 0, 0);
}
