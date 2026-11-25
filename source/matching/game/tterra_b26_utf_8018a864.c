extern unsigned int strlen(const char *);
extern void *fn_801fe0b8(unsigned int);
extern unsigned int fn_8018b360(const char *, int *);
extern void fn_801fe160(void *);
unsigned short *tterra_b26_utf_8018a864(const char *s) {
    unsigned short *result = fn_801fe0b8((strlen(s) + 1) * 2);
    unsigned short *out = result;
    while (*s) {
        int length;
        *out++ = fn_8018b360(s, &length);
        if (!length) { fn_801fe160(result); return 0; }
        s += length;
    }
    *out = 0;
    return result;
}
