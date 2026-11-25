/* Vector lookup through a name index. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
extern int fn_80177eb0(char *, char *, unsigned short *);
extern int fn_80342fa4(int);
extern S20V3 *fn_80178ec4(void *);

int w3d_s20_lookup_vector_80176aac(char *self, char *name, S20V3 *out) {
    unsigned short index;
    S20V3 *found;
    if (fn_80177eb0(self, name, &index) < 0)
        return 0x80004005;
    found = fn_80178ec4(fn_80342fa4(*(int *)(*(char **)(self + 24) + index * 4)));
    *out = *found;
    return 0;
}
