/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef struct S20Object { void **vtable; } S20Object;
extern int fn_801ad0e4(char *);
extern int fn_801ad168(char *, char *, int);
extern void fn_801ace68(char *, char *);
extern void fn_801ad060(char *);

int w3d_s20_commit_item_801ad590(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int result;
    if (((int (*)(char *))(*(void ***)base)[15])(base) & 1) {
        if (fn_801ad0e4(base) != 0)
            return fn_801ad168(base, item, 1);
        fn_801ace68(base, item);
        result = fn_801ad168(base, item, 0);
        fn_801ad060(base);
        return result;
    }
    return fn_801ad168(base, item, 0);
}

typedef void (*S20HandlerH)(char *, char *);
extern S20Object *lbl_804b1884;

int w3d_s20_apply_item_targets_8016bafc(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    char *record;
    unsigned int count;
    unsigned int i;
    char **targets;
    *(unsigned short *)(base + 196) = 0;
    *(int *)(base + 200) = 1;
    *(int *)(base + 204) = 1;
    record = *(char **)(item + 84);
    count = *(unsigned int *)(record + 24);
    targets = (char **)(record + 32);
    ((void (*)(S20Object *, char *))lbl_804b1884->vtable[23])(lbl_804b1884, item + 20);
    for (i = 0; i < count; i++) {
        char *sub = base + 4;
        char *target = *targets;
        targets++;
        ((S20HandlerH)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    }
    *(int *)(base + 200) = 0;
    *(int *)(base + 204) = 0;
    return 0;
}
