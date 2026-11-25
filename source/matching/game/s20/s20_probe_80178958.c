typedef struct S20Object { void **vtable; } S20Object;
extern void fn_801fe1f8(char *);
extern char lbl_80412680[];

void w3d_s20_destroy_holder_80178958(char *self, int flags) {
    S20Object *held = *(S20Object **)(self + 4);
    *(char **)self = lbl_80412680;
    if (held != 0)
        ((void (*)(S20Object *))held->vtable[4])(held);
    {
        int mark = 255;
        *(int *)(self + 4) = 0;
        *(unsigned char *)(self + 8) = mark;
    }
    if (flags & 1)
        fn_801fe1f8(self);
}

