/* Constructors that retain a shared global object. */
typedef struct S20Object { void **vtable; } S20Object;
extern S20Object *lbl_804b05a8;

extern int fn_801bd510(char *, void *);
extern char lbl_80415190[];
extern float lbl_803abba0[];

char *w3d_s20_construct_scaled_801bd6b8(char *self, void * arg_r4) {
    S20Object *shared;
    float value;
    char *sub;
    fn_801bd510(self, arg_r4);
    value = lbl_803abba0[0];
    shared = lbl_804b05a8;
    *(char **)self = lbl_80415190;
    sub = self + 28;
    *(float *)(self + 28) = value;
    *(volatile float *)(sub + 8) = value;
    *(volatile float *)(sub + 4) = value;
    *(S20Object **)(self + 40) = shared;
    if (shared != 0)
        ((void (*)(S20Object *))shared->vtable[3])(shared);
    return self;
}

extern void * fn_801ea0ec(char *, int);
extern char lbl_80415ee8[];

char *w3d_s20_construct_flagged_801cdd48(char *self, void * arg_r4) {
    int zero = 0;
    S20Object *shared;
    fn_801ea0ec(self, arg_r4);
    shared = lbl_804b05a8;
    *(char **)self = lbl_80415ee8;
    *(int *)(self + 20) = 1;
    *(int *)(self + 24) = zero;
    *(S20Object **)(self + 28) = shared;
    if (shared != 0)
        ((void (*)(S20Object *))shared->vtable[3])(shared);
    *(unsigned char *)(self + 32) = zero;
    *(unsigned char *)(self + 33) = zero;
    return self;
}
