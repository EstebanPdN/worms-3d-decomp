/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (third session of the day). */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
/* A g++ pointer to member function with vtable thunks (see families_u.c). */
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (T)(*(void ***)((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (T)FIELD(m, void *, 4))
typedef void (*W3dSetLong)(void *, long long);
typedef int (*W3dGetLong)(void *, long long *, void *, int);
typedef struct W3dArg20 { int words[5]; } W3dArg20;
typedef int (*W3dForward)(void *, void *, W3dArg20 *);
int fn_801f9fbc(void *, int, int);

int w3d_apply_long_property_801ec224(char *self, void *argument, char *target)
{
    long long value;
    void *source = FIELD(*(char **)self, void *, 8);
    int result = (*(W3dGetLong *)(*(char **)source + 72))(source, &value, argument, 0);
    if (result >= 0) {
        W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
        setter(target + FIELD(self, short, 24), value);
    }
    return result;
}

int w3d_apply_long_property_801ec360(char *self, void *argument, char *target)
{
    long long value;
    void *source = FIELD(*(char **)self, void *, 8);
    int result = (*(W3dGetLong *)(*(char **)source + 72))(source, &value, argument, 0);
    if (result >= 0) {
        W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
        setter(target + FIELD(self, short, 24), value);
    }
    return result;
}

int w3d_forward_indexed_801fb824(char *self, void *argument, W3dArg20 *request)
{
    int index = fn_801f9fbc(self + 36, request->words[0], request->words[2]);
    W3dArg20 copy = *request;
    void *entry;
    copy.words[2] = index;
    entry = *(void **)(FIELD(self, char *, 36) + (index << 2));
    return (*(W3dForward *)(*(char **)entry + 28))(entry, argument, &copy);
}

int w3d_forward_indexed_801fb8b8(char *self, void *argument, W3dArg20 *request)
{
    int index = fn_801f9fbc(self + 36, request->words[0], request->words[2]);
    W3dArg20 copy = *request;
    void *entry;
    copy.words[2] = index;
    entry = *(void **)(FIELD(self, char *, 36) + (index << 2));
    return (*(W3dForward *)(*(char **)entry + 32))(entry, argument, &copy);
}
