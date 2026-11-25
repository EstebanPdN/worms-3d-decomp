/* Methods on the secondary base subobject (this - 4, null-checked). */
typedef int (*S20HandlerN)(char *, char *);
extern int fn_801a9cbc(char *, char *);

static inline int s20_dispatch_all(char *sub, char *record) {
    char **cursor = (char **)(record + 32);
    char **end = cursor + *(unsigned int *)(record + 24);
    for (; cursor != end; cursor++) {
        char *entry = *cursor;
        void **table = *(void ***)(sub + 24);
        int status = ((S20HandlerN)table[*(unsigned short *)(entry + 6)])(sub, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_all_targets_801aa79c(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int saved = *(int *)(base + 44);
    int result;
    if (saved != 0) {
        char *sub;
        if (fn_801a9cbc(base, item + 20) == 0)
            return 0;
        sub = base ? base + 4 : 0;
        result = s20_dispatch_all(sub, *(char **)(item + 44));
        *(int *)(base + 44) = saved;
        return result;
    }
    {
        char *sub = base ? base + 4 : 0;
        return s20_dispatch_all(sub, *(char **)(item + 44));
    }
}

int w3d_s20_dispatch_item_targets_801aa8cc(char *self, char *item) {
    char *base = self ? self - 4 : 0;
    int saved;
    int result;
    char *target;
    if (((*(unsigned char *)(item + 11) ^ 4) & 4) == 0)
        return 0;
    saved = *(int *)(base + 44);
    if (saved != 0) {
        if (fn_801a9cbc(base, item + 20) == 0)
            return 0;
    }
    target = *(char **)(item + 48);
    if (target != 0) {
        char *sub = base + 4;
        *(char **)(sub + 20) = item;
        result = ((S20HandlerN)(*(void ***)(sub + 24))[*(unsigned short *)(target + 6)])(sub, target);
    } else {
        char *sub = base ? base + 4 : 0;
        result = s20_dispatch_all(sub, *(char **)(item + 44));
    }
    *(int *)(base + 44) = saved;
    return result;
}
