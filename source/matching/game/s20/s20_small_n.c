/* Pool acquisition, quad copy with forward, and dispatch of a stored record. */
extern char *fn_801ef048(char *, int, int, int);

char *w3d_s20_acquire_pooled_80171fa0(char *self) {
    char *owner = *(char **)(self + 76);
    char *list = owner + 40;
    char *pool = *(char **)list;
    int arg = *(int *)(pool + 24);
    if (*(unsigned short *)(pool + 4) != 1)
        return fn_801ef048(list, arg, 8, 2);
    *(unsigned short *)(pool + 28) += 1;
    return pool + 32;
}

char *w3d_s20_acquire_pooled_80171ff8(char *self) {
    char *owner = *(char **)(self + 76);
    char *list = owner + 36;
    char *pool = *(char **)list;
    int arg = *(int *)(pool + 24);
    if (*(unsigned short *)(pool + 4) != 1)
        return fn_801ef048(list, arg, 8, 2);
    *(unsigned short *)(pool + 28) += 1;
    return pool + 32;
}

typedef struct S20Quad { int a; int b; int c; int d; } S20Quad;
extern void fn_801f5724(char *, char *);

int w3d_s20_set_quad_and_forward_801a55f0(char *self, S20Quad *value) {
    *(S20Quad *)(self + 44) = *value;
    fn_801f5724(self + 60, self + 44);
    return 0;
}

typedef int (*S20DispatchN)(char *, char *);

int w3d_s20_dispatch_stored_801a3c6c(char *self, char *item) {
    char *record = *(char **)(item + 28);
    if (*(int *)(record + 24) != 0) {
        char *target = *(char **)(record + 32);
        void **table = *(void ***)(self + 24);
        unsigned short slot = *(unsigned short *)(target + 6);
        int result = ((S20DispatchN)table[slot])(self, target);
        if (result < 0)
            return result;
    }
    return 0;
}
