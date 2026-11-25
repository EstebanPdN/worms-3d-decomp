/* Guarded helper pair. */
extern void fn_803089c8(int, int, void *);
extern int fn_8016ac3c(int, char *, char *);
extern void fn_8016acac(char *, char *, char *);

void w3d_s20_apply_if_enabled_8016b384(int unused, char *a, char *b, char *c) {
    if (*(int *)(c + 188) != 0) {
        fn_803089c8(unused, 0, (void *)b);
        b++;
        b--;
        if (fn_8016ac3c(a, b, c) == 0)
            fn_8016acac(a, b, c);
    }
}
