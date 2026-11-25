/* Guarded forwards, list iteration, reference replacement and struct copy. */
extern void fn_800e68f0(char *, int, void *);
extern int fn_800dc740(char *, int, void *, void *);

int w3d_s20_forward_if_enabled_800e6834(char *self, int a, int b, int c) {
    if (*(unsigned char *)(self + 104) != 0) {
        fn_800e68f0(self, a, c);
        return fn_800dc740(self, a, b, c);
    }
    return 0;
}

extern int fn_80161e38(char *, int);

int w3d_s20_apply_list_80161dd4(char *self, int *list) {
    int result = 0;
    if (*list != 0) {
        int *p = list;
        do {
            int status = fn_80161e38(self, *p);
            if (status < 0)
                result = status;
            p++;
        } while (*p != 0);
    }
    return result;
}

typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Replacer { char pad[40]; S20Object *target; } S20Replacer;

void w3d_s20_replace_target_80174820(S20Replacer *self, S20Object *target) {
    if (target != 0)
        ((void (*)(S20Object *))target->vtable[3])(target);
    if (self->target != 0)
        ((void (*)(S20Object *))self->target->vtable[4])(self->target);
    self->target = target;
}

typedef struct S20Block28 { int words[7]; } S20Block28;
extern void fn_801a0b80(char *);

int w3d_s20_set_block_and_notify_801a0910(char *self, S20Block28 *value) {
    *(S20Block28 *)(self + 148) = *value;
    fn_801a0b80(self);
    return 0;
}
