/* Handler-table dispatch loops over a record's targets. */
typedef int (*S20HandlerW)(char *, char *);

int w3d_s20_dispatch_early_table_801a38c8(char *self, char *item) {
    void **table = *(void ***)(self + 24);
    char *record = *(char **)(item + 20);
    char **cursor = (char **)(record + 32);
    char **end = cursor + *(unsigned int *)(record + 24);
    for (; cursor != end; cursor++) {
        char *entry = *cursor;
        int status = ((S20HandlerW)table[*(unsigned short *)(entry + 6)])(self, entry);
        if (status < 0)
            return status;
    }
    return 0;
}

int w3d_s20_dispatch_counted_801a4b4c(char *self, char *item) {
    char *record = *(char **)(item + 20);
    unsigned int count = *(unsigned int *)(record + 24);
    char **items = (char **)(record + 32);
    unsigned int i = 0;
    if (i < count) {
        char **cursor = items;
        do {
            char *entry = *cursor;
            i++;
            cursor++;
            ((S20HandlerW)(*(void ***)(self + 24))[*(unsigned short *)(entry + 6)])(self, entry);
        } while (i < count);
    }
    return 0;
}

int w3d_s20_dispatch_counted_801a4bc4(char *self, char *item) {
    char *record = *(char **)(item + 20);
    unsigned int count = *(unsigned int *)(record + 24);
    char **items = (char **)(record + 32);
    unsigned int i = 0;
    if (i < count) {
        char **cursor = items;
        do {
            char *entry = *cursor;
            i++;
            cursor++;
            ((S20HandlerW)(*(void ***)(self + 24))[*(unsigned short *)(entry + 6)])(self, entry);
        } while (i < count);
    }
    return 0;
}
