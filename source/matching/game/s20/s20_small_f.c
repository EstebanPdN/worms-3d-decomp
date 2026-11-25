/* Small handlers touching small-data globals. */
extern int fn_8016ee10(void *, int *);
extern void *lbl_804b1888;
extern void *lbl_804b1884;

int w3d_s20_publish_current_801673f0(char *self) {
    int value = *(int *)(self + 40);
    lbl_804b1884 = self;
    fn_8016ee10(lbl_804b1888, &value);
    return 0;
}

int w3d_s20_dispatch_target_801a3b58(char *self, char *item) {
    char *target = *(char **)(item + 60);
    if (target != 0)
        ((void (*)(char *, char *))(*(void ***)(self + 24))[*(unsigned short *)(target + 6)])(self, target);
    return 0;
}
