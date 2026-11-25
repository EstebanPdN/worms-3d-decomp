/* Constructor with a retained global and a find-or-create wrapper. */
typedef struct S20Object { void **vtable; } S20Object;
extern void * fn_801ea0ec(char *, int);
extern S20Object *lbl_804b05a8;
extern char lbl_80413558[];

char *w3d_s20_construct_counted_8019b424(char *self, void * arg_r4) {
    int zero;
    int five;
    S20Object *shared;
    fn_801ea0ec(self, arg_r4);
    shared = lbl_804b05a8;
    *(char **)self = lbl_80413558;
    *(S20Object **)(self + 20) = shared;
    if (shared != 0)
        ((void (*)(S20Object *))shared->vtable[3])(shared);
    zero = 0;
    five = 5;
    *(int *)(self + 24) = five;
    *(int *)(self + 32) = zero;
    *(int *)(self + 28) = five;
    *(int *)(self + 36) = zero;
    *(int *)(self + 40) = zero;
    *(int *)(self + 44) = zero;
    return self;
}

extern char *fn_801a688c(char *, char *);
extern char *fn_801a6908(char *, char *);
extern int fn_801a6724(char *, char *, char *);
extern void fn_801a66c0(char *, char *);

int w3d_s20_find_or_create_801a692c(char *self, char *key) {
    char *entry = fn_801a688c(self, key);
    int result;
    if (entry == 0) {
        entry = fn_801a6908(self, key);
        fn_801a6724(self, key, entry);
        fn_801a66c0(self, entry);
        result = 0;
    } else {
        fn_801a66c0(self, entry);
        result = 1;
    }
    return result;
}
