/* Counted object construction and destruction. */
extern void * fn_8017990c(void *);
extern int fn_801799d4(void *, void *);
extern char lbl_80412180[];
extern int lbl_804ab5a0;

void *w3d_s20_construct_counted_80174b38(void *self) {
    int count;
    fn_8017990c(self);
    count = lbl_804ab5a0;
    *(char **)self = lbl_80412180;
    lbl_804ab5a0 = count + 1;
    return self;
}

int w3d_s20_destruct_counted_80174b80(void *self, void * arg_r4) {
    int count = lbl_804ab5a0;
    *(char **)self = lbl_80412180;
    lbl_804ab5a0 = count - 1;
    return fn_801799d4(self, arg_r4);
}
