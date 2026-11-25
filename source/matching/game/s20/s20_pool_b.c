/* Pool entry acquisition with reference counting. */
extern char *fn_801ef048(char *, int, int, int);

int w3d_s20_acquire_two_entries_80171ee0(char *self, int count) {
    char *owner = *(char **)(self + 76);
    char *list;
    char *pool;
    list = owner + 40;
    pool = *(char **)list;
    if (*(unsigned short *)(pool + 4) == 1 && count == *(int *)(pool + 24))
        *(unsigned short *)(pool + 28) += 1;
    else
        fn_801ef048(list, count, 8, 1);
    list = owner + 36;
    pool = *(char **)list;
    if (*(unsigned short *)(pool + 4) == 1 && count == *(int *)(pool + 24))
        *(unsigned short *)(pool + 28) += 1;
    else
        fn_801ef048(list, count, 8, 1);
    return 0;
}

extern void * fn_8034435c(int);

char *w3d_s20_acquire_sized_8018d5b8(char *self, int *out) {
    *out = (*(int *)(self + 184) - *(int *)(self + 180)) >> 1;
    fn_8034435c(*(int *)(self + 116));
    if (*(int *)(self + 240) != 0) {
        char *owner = *(char **)(self + 172);
        char *list = owner + 72;
        char *pool = *(char **)list;
        int count = *out + *out;
        if (*(unsigned short *)(pool + 4) == 1 && count == *(int *)(pool + 24)) {
            *(unsigned short *)(pool + 28) += 1;
            return pool + 32;
        }
        return fn_801ef048(list, count, 4, 0);
    }
    return 0;
}
