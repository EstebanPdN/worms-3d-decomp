/* Calls built from resolved handles. */
typedef struct S20Object { void **vtable; } S20Object;
extern int fn_80341584(int);
extern char *fn_801797b4(void *);

int w3d_s20_forward_resolved_800e45d0(char *self, int first, int second) {
    char *resolved = fn_801797b4(fn_80341584(*(int *)(self + 156)));
    S20Object *owner = *(S20Object **)(self + 32);
    char *result = ((char *(*)(S20Object *, int))owner->vtable[5])(owner, first);
    void **table = *(void ***)(result + 112);
    return ((int (*)(char *, int, int, char *, int))table[9])(result, *(int *)(self + 36), second, resolved, 0);
}
