/* Pool entry acquisition with reference counting. */
extern char *fn_801ef048(char *, int, int, int);

int w3d_s20_acquire_pair_entry_801a91e8(char *self, int count) {
    if (*(int *)(self + 160) == 0) {
        char *owner = *(char **)(self + 176);
        char *pool;
        char *list;
        count = count + count;
        list = owner + 20;
        pool = *(char **)list;
        if (*(unsigned short *)(pool + 4) == 1 && count == *(int *)(pool + 24))
            *(unsigned short *)(pool + 28) += 1;
        else
            fn_801ef048(list, count, 4, 1);
    }
    return 0;
}
