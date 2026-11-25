/* Handler-table dispatch over the targets of a record. */
typedef int (*S20HandlerV)(char *, char *);

static inline int s20_dispatch_all(char *sub, char *record) {
    char **cursor = (char **)(record + 32);
    char **end = cursor + *(unsigned int *)(record + 24);
    for (; cursor != end; cursor++) {
        char *entry = *cursor;
        void **table = *(void ***)(sub + 24);
        int status = ((S20HandlerV)table[*(unsigned short *)(entry + 6)])(sub, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_item_record_801a37a0(char *self, char *item) {
    return s20_dispatch_all(self, *(char **)(item + 44));
}

int w3d_s20_dispatch_owner_record_801a3944(char *self) {
    return s20_dispatch_all(self, *(char **)(*(char **)(self + 20) + 44));
}

int w3d_s20_dispatch_owner_record_801a39c4(char *self) {
    return s20_dispatch_all(self, *(char **)(*(char **)(self + 20) + 44));
}

int w3d_s20_dispatch_two_targets_801a3adc(char *self, char *item) {
    char *target = *(char **)(item + 52);
    if (target != 0)
        ((void (*)(char *, char *))(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    target = *(char **)(item + 48);
    if (target != 0)
        ((void (*)(char *, char *))(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    return 0;
}
