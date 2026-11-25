/* Converts a NUL-terminated byte string into 16-bit units through a
   per-character decoder; releases the buffer and returns 0 on decoder failure.
   The inline helper reproduces the original's copy of the string pointer. */
extern unsigned int strlen(const char *);
extern void *fn_801fe0b8(unsigned int);
extern unsigned int fn_8018b360(const char *, int *);
extern void fn_801fe160(void *);
static inline unsigned short *run(const char *s, unsigned short *result) {
    unsigned short *out = result;
    int length;
    while (*s) {
        *out++ = fn_8018b360(s, &length);
        if (length == 0) { fn_801fe160(result); return 0; }
        s += length;
    }
    *out = 0;
    return result;
}
unsigned short *tsonnet_b27_utf_8018a864(const char *s) {
    return run(s, (unsigned short *)fn_801fe0b8((strlen(s) + 1) * 2));
}
