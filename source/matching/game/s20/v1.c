extern int fn_8016b488(void *self);
int w3d_s20_probe_8016b6d8(void *self, unsigned char *obj) {
    int r = fn_8016b488(self);
    if (r == 0) {
        unsigned int i = 0;
        while (i < *(unsigned int *)(obj + 0x54)) i++;
    }
    return r ? r : 0;
}
