extern void fn_801fcb64(char *);
extern char lbl_803a50c4[];
struct K8bArena { char pad0[224]; unsigned int used; char *base; unsigned int limit; };

char *w3d_k8b_alloc_aligned_8016a21c(struct K8bArena *self, int size) {
    unsigned int old = self->used;
    unsigned int rounded = (size + 127) & ~127;
    char *block;
    self->used = old + rounded;
    block = self->base + old;
    if (self->used > self->limit)
        fn_801fcb64(lbl_803a50c4);
    return block;
}
