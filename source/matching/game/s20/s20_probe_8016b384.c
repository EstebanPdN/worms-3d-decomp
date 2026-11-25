typedef struct S20Object { void **vtable; } S20Object;
extern void fn_803089c8(int, int);
extern int fn_8016ac3c(char *, char *, char *);
extern void fn_8016acac(char *, char *, char *);

void w3d_s20_apply_if_enabled_8016b384(int unused, char *a, char *b, char *c) {
    if (*(int *)(c + 188) != 0) {
        fn_803089c8(unused, 0);
        if (fn_8016ac3c(a, b, c) == 0)
            fn_8016acac(a, b, c);
    }
}

typedef struct S20Owner20 { char pad[20]; S20Object *provider; } S20Owner20;

int w3d_s20_lookup_entry_80166404(S20Owner20 *self, char *key, int index) {
    S20Object *provider = self->provider;
    char *sub = key ? key + 4 : 0;
    int *table = ((int *(*)(S20Object *, char *))provider->vtable[13])(provider, sub);
    if (table == 0)
        return 0;
    return *(int *)((char *)table + 16 + index * 4);
}
