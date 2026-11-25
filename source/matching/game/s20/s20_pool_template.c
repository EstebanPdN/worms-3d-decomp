extern char *fn_801ef048(char *, int, int, int);

char *w3d_s20pool_80189574(char *self) {
    char *owner = *(char **)(*(char **)(self + 168) + 48);
    char *pool = *(char **)(owner + 88);
    int count = *(int *)(pool + 24);
    char *result;
    if (*(unsigned short *)(pool + 4) == 1) {
        *(unsigned short *)(pool + 28) += 1;
        result = pool + 32;
    } else {
        result = fn_801ef048(owner + 88, count, 4, 2);
    }
    if (count == 0) {
        int other = *(int *)(*(char **)(owner + 96) + 24);
        if (other == 0)
            return 0;
        pool = *(char **)(owner + 88);
        if (*(unsigned short *)(pool + 4) == 1 && other == *(int *)(pool + 24)) {
            *(unsigned short *)(pool + 28) += 1;
            return pool + 32;
        }
        return fn_801ef048(owner + 88, other, 4, 0);
    }
    return result;
}
