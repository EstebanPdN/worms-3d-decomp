/* Table store with owner dispatch and a global forwarder. */
typedef int (*S20DispatchL)(char *, char *);

int w3d_s20_store_and_dispatch_801a3190(char *self, int index, char *object) {
    char *owner;
    char *table = *(char **)(self + 72);
    int offset = index * 4;
    char *sub;
    *(char **)(table + offset) = object;
    owner = *(char **)(self + 20);
    sub = owner ? owner + 4 : 0;
    return ((S20DispatchL)(*(void ***)(sub + 24))[*(unsigned short *)(object + 6)])(sub, object);
}

extern int fn_800e5f98(void *, int, int, int, int, int);
extern void *lbl_804aaecc;

int w3d_s20_forward_global5_800e5cf0(int a, int b, int c, int d, int e) {
    if (lbl_804aaecc == 0)
        return 0;
    return fn_800e5f98(lbl_804aaecc, a, b, c, d, e);
}
