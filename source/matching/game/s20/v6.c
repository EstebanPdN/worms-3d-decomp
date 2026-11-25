extern int fn_8016b488(void *self);
int w3d_s20_probe_8016b6d8(void *self, unsigned char *obj) {
    int r = fn_8016b488(self);
    if (r == 0) {
        int i;
        for (i = 0; (unsigned)i < *(unsigned int *)(obj + 0x54); i++) ;
        return i * 0;
    }
    return r;
}
