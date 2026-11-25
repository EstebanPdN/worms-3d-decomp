extern int fn_801a3190(char *, int, int);
int w3d_s20_apply_indexed_801a3164(char *self, int index) {
    return fn_801a3190(self, index, *(int *)(*(char **)(self + 48) + index * 4));
}

