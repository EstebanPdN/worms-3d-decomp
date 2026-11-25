typedef struct S20Obj { void **vtable; } S20Obj;
typedef int (*S20Call0R)(S20Obj *);
extern void fn_8017a07c(char *, unsigned int);

int w3d_s20_process_children_8017b64c(S20Obj *self) {
    int result;
    unsigned int i;
    char *list;
    *(int *)((char *)self + 164) = 0;
    i = 0;
    result = ((S20Call0R)self->vtable[37])(self);
    list = (char *)self + 104;
    for (; i < (unsigned int)((*(int *)(list + 4) - *(int *)((char *)self + 104)) >> 2); i++)
        fn_8017a07c((char *)self, i);
    return result;
}
