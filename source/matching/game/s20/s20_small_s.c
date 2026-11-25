/* Per-kind handler dispatch, block copy, referenced constructor and a warning wrapper. */
typedef struct S20KindSource { char pad[32]; unsigned int word; } S20KindSource;
extern S20KindSource *lbl_80363938[];
extern void fn_801a4278(char *);

int w3d_s20_dispatch_kind_801a42fc(char *self, char *item) {
    if (*(unsigned char *)(item + 11) & 2)
        fn_801a4278(item);
    return ((int (*)(char *, char *))(*(void ***)(self + 24))[(lbl_80363938[0]->word >> 22) & 1023])(self, item);
}

typedef struct S20Block24 { int words[6]; } S20Block24;
extern void * fn_801f55ec(char *, char *);

int w3d_s20_set_block_and_forward_801a5650(char *self, S20Block24 *value) {
    *(S20Block24 *)(self + 60) = *value;
    fn_801f55ec(self + 44, self + 60);
    return 0;
}

typedef struct S20Object { void **vtable; } S20Object;
extern int fn_801c90c0(char *, void *);
extern S20Object *lbl_804b05ac;
extern char lbl_80416348[];

char *w3d_s20_construct_with_global_801c98b8(char *self, void * arg_r4) {
    S20Object *global;
    fn_801c90c0(self, arg_r4);
    global = lbl_804b05ac;
    *(char **)self = lbl_80416348;
    *(S20Object **)(self + 28) = global;
    if (global != 0)
        ((void (*)(S20Object *))global->vtable[3])(global);
    *(int *)(self + 32) = 0;
    *(int *)(self + 36) = 0;
    return self;
}

extern void fn_801d6000(char *, char *, ...);
extern int fn_801d6644(char *, char *);
extern char lbl_803af55c[];

int w3d_s20_warn_if_empty_801d66d8(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    if (*(int *)(*(char **)(item + 60) + 24) == 0)
        fn_801d6000(base, lbl_803af55c, item);
    return fn_801d6644(self, item);
}
