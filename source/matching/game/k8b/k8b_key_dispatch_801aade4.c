typedef int (*K8bHandler)(char *, char *);
extern int *fn_801d0858(char *, int *);

int w3d_k8b_key_dispatch_801aade4(char *self, unsigned int key)
{
    char *base = self ? self - 4 : 0;
    int found;
    int *slot;
    char *target;
    *(unsigned short *)(base + 230) = key ^ (key >> 16);
    slot = fn_801d0858((char *)key, &found);
    target = 0;
    if (found != 0)
        target = *(char **)slot;
    if (target != 0) {
        void **table = *(void ***)(base + 28);
        return ((K8bHandler)table[*(unsigned short *)(target + 6)])(base ? base + 4 : 0, target);
    }
    return 0;
}
