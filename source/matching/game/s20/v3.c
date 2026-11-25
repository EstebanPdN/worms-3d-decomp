extern int fn_8016b488(void *self);
int w3d_s20_probe_8016b6d8(void *self, unsigned char *obj) {
    int r = fn_8016b488(self);
    unsigned int n = *(unsigned int *)(obj + 0x54);
    unsigned int i;
    if (!r) {
        for (i = 0; i < n; i++) ;
        r = i - i;
    }
    return r;
}
