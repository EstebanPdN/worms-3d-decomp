/* Target dispatch followed by a per-kind handler. */
typedef struct S20KindSource { char pad[32]; unsigned int word; } S20KindSource;
extern S20KindSource *lbl_80363cf8[];

int w3d_s20_dispatch_target_then_kind_801a49d8(char *self, char *item) {
    char *target = *(char **)(item + 48);
    if (target != 0) {
        int result = ((int (*)(char *, char *))(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
        if (result < 0)
            return result;
    }
    return ((int (*)(char *, char *))(*(void ***)(self + 24))[(lbl_80363cf8[0]->word >> 22) & 1023])(self, item);
}
