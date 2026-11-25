/* Handler-table dispatch variants. */
typedef int (*S20HandlerX)(char *, char *);

static inline int s20_dispatch_all(char *sub, char *record) {
    char **cursor = (char **)(record + 32);
    char **end = cursor + *(unsigned int *)(record + 24);
    for (; cursor != end; cursor++) {
        char *entry = *cursor;
        void **table = *(void ***)(sub + 24);
        int status = ((S20HandlerX)table[*(unsigned short *)(entry + 6)])(sub, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_two_results_801ac41c(char *self, char *item) {
    char *target = *(char **)(item + 52);
    int result = 0;
    if (target != 0)
        result = ((S20HandlerX)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    target = *(char **)(item + 48);
    if (target != 0)
        result = ((S20HandlerX)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    return result;
}

int w3d_s20_dispatch_masked_801a3a44(char *self, char *item) {
    unsigned int mask = *(unsigned int *)(item + 20);
    unsigned int flags = *(unsigned int *)(self + 32);
    char *owner = *(char **)(self + 20);
    if ((flags & mask) != 0)
        return s20_dispatch_all(self, *(char **)(owner + 44));
    return 0;
}

int w3d_s20_dispatch_target_or_record_801a381c(char *self, char *item) {
    char *target = *(char **)(item + 48);
    if (target != 0) {
        *(char **)(self + 20) = item;
        return ((S20HandlerX)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    }
    return s20_dispatch_all(self, *(char **)(item + 44));
}
