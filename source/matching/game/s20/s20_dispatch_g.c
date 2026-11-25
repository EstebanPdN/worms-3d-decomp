/* Record dispatch followed by two fixed targets. */
typedef int (*S20HandlerA)(char *, char *);

int w3d_s20_dispatch_record_two_targets_801a3cc4(char *self, char *item) {
    void **table = *(void ***)(self + 24);
    char *record = *(char **)(item + 28);
    char **cursor = (char **)(record + 32);
    char **end = cursor + *(unsigned int *)(record + 24);
    void **later;
    char *target;
    int status;
    for (; cursor != end; cursor++) {
        char *entry = *cursor;
        status = ((S20HandlerA)table[*(unsigned short *)(entry + 6)])(self, entry);
        if (status < 0)
            return status;
    }
    target = *(char **)(item + 36);
    later = *(void ***)(self + 24);
    status = ((S20HandlerA)later[*(unsigned short *)(target + 6)])(self, target);
    if (status < 0)
        return status;
    target = *(char **)(item + 32);
    status = ((S20HandlerA)later[*(unsigned short *)(target + 6)])(self, target);
    if (status < 0)
        return status;
    return 0;
}
