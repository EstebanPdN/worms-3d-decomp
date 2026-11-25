extern void fn_801fcb64(char *);
extern char lbl_803a50c4[];

char *w3d_s20_allocate_aligned_8016a21c(char *self, int size) {
    unsigned int used = *(unsigned int *)(self + 224);
    char *base = *(char **)(self + 228);
    unsigned int limit = *(unsigned int *)(self + 232);
    unsigned int end = used + ((size + 127) & ~127);
    char *block;
    *(unsigned int *)(self + 224) = end;
    block = base + used;
    if (end > limit)
        fn_801fcb64(lbl_803a50c4);
    return block;
}

