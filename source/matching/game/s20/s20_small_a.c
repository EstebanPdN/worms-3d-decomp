/* Small accessors and forwarding wrappers. */
extern int fn_801ad8c0(char *);
extern int fn_8020b680(void *);
extern void fn_8020c3a0(char *, int);
typedef struct S20Holder { char pad[12]; void *held; } S20Holder;
typedef struct S20Pair { int first; int second; } S20Pair;

int w3d_s20_forward_derived_801ad934(char *self) {
    char *base = self ? self - 4 : 0;
    char *sub = base ? base + 4 : 0;
    return fn_801ad8c0(sub);
}

int w3d_s20_forward_held_8019013c(char *self) {
    if (!((S20Holder *)self)->held)
        return 0;
    return fn_8020b680(((S20Holder *)self)->held);
}

void w3d_s20_copy_pair_801c83e8(char *self, S20Pair *source) {
    *(S20Pair *)(self + 24) = *source;
}

int w3d_s20_reset_range_801b2464(char *self) {
    *(int *)(self + 56) = 0;
    fn_8020c3a0(self + 60, 0);
    return 0;
}
