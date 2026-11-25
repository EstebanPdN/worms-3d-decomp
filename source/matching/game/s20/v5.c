extern int fn_8016b488(void *self);
int w3d_s20_probe_8016b6d8(void *self, unsigned char *obj) {
    unsigned int i;
    unsigned int n;
    int r = fn_8016b488(self);
    if (r != 0) return r;
    n = *(unsigned int *)(obj + 0x54);
    for (i = 0; i < n; i++) ;
    return 0;
}
