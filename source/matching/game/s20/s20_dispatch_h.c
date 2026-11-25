/* Record and fixed-target dispatch through the handler table. */
typedef int (*S20HandlerB)(char *, char *);

int w3d_s20_dispatch_two_records_801a3d90(char *self, char *item) {
    {
        void **table = *(void ***)(self + 24);
        char *record = *(char **)(item + 32);
        char **cursor = (char **)(record + 32);
        char **end = cursor + *(unsigned int *)(record + 24);
        for (; cursor != end; cursor++) {
            char *entry = *cursor;
            int status = ((S20HandlerB)table[*(unsigned short *)(entry + 6)])(self, entry);
            if (status < 0)
                return status;
        }
    }
    {
        void **table = *(void ***)(self + 24);
        char *record = *(char **)(item + 28);
        char **cursor = (char **)(record + 32);
        char **end = cursor + *(unsigned int *)(record + 24);
        for (; cursor != end; cursor++) {
            char *entry = *cursor;
            int status = ((S20HandlerB)table[*(unsigned short *)(entry + 6)])(self, entry);
            if (status < 0)
                return status;
        }
    }
    return 0;
}

int w3d_s20_dispatch_five_targets_801a4874(char *self, char *item) {
    char *target;
    target = *(char **)(item + 80);
    if (target != 0)
        ((S20HandlerB)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    target = *(char **)(item + 72);
    if (target != 0)
        ((S20HandlerB)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    target = *(char **)(item + 76);
    if (target != 0)
        ((S20HandlerB)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    target = *(char **)(item + 68);
    if (target != 0)
        ((S20HandlerB)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    target = *(char **)(item + 64);
    if (target != 0)
        ((S20HandlerB)(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    return 0;
}
