/* Record dispatch followed by an optional looked-up target. */
typedef int (*S20HandlerZ)(char *, char *);
extern int *fn_801d0858(char *, int *);

int w3d_s20_dispatch_record_then_lookup_801a3ba0(char *self, char *item) {
    void **table = *(void ***)(self + 24);
    char *record = *(char **)(item + 28);
    char **cursor = (char **)(record + 32);
    char **end = cursor + *(unsigned int *)(record + 24);
    int found;
    int *slot;
    char *target;
    for (; cursor != end; cursor++) {
        char *entry = *cursor;
        int status = ((S20HandlerZ)table[*(unsigned short *)(entry + 6)])(self, entry);
        if (status < 0)
            return status;
    }
    slot = fn_801d0858(item, &found);
    target = 0;
    if (found != 0)
        target = *(char **)slot;
    if (target != 0) {
        void **later = *(void ***)(self + 24);
        int status = ((S20HandlerZ)later[*(unsigned short *)(target + 6)])(self, target);
        if (status < 0)
            return status;
    }
    return 0;
}
