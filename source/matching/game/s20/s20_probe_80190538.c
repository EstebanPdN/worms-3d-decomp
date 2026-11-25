typedef struct S20Object { void **vtable; } S20Object;
extern char lbl_803a8200[];
extern char lbl_803a820c[];

int w3d_s20_describe_fields_80190538(char *self, S20Object *sink) {
    char *first = self + 20;
    char *second = self + 24;
    ((void (*)(S20Object *, char *, char *))sink->vtable[37])(sink, first, lbl_803a8200);
    ((void (*)(S20Object *, char *, char *))sink->vtable[28])(sink, second, lbl_803a820c);
    return 0;
}

extern int fn_801a4874(char *, char *);

int w3d_s20_dispatch_then_apply_801a4968(char *self, char *item) {
    char *target = *(char **)(item + 92);
    int result;
    if (target == 0)
        result = 0;
    else {
        result = ((int (*)(char *, char *))(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
        if (result >= 0)
            result = fn_801a4874(self, item);
    }
    return result;
}
