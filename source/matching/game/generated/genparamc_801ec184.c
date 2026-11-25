/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): counted reference array destructor, 64-bit
 * property copy through pointers to member functions, clipped block copy. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
/* A g++ pointer to member function with vtable thunks (see families_u.c). */
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (T)(*(void ***)((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (T)FIELD(m, void *, 4))
typedef long long (*W3dGetLong)(void *);
typedef void (*W3dSetLong)(void *, long long);

void w3d_copy_long_property_801ec184(char *self, char *target, char *source, char *from)
{
    W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
    char *setter_this = target + FIELD(self, short, 24);
    W3dGetLong getter = PMF_FN(from + 16, source, W3dGetLong);
    setter(setter_this, getter(source + FIELD(from, short, 16)));
}

void w3d_copy_long_property_801ec2c0(char *self, char *target, char *source, char *from)
{
    W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
    char *setter_this = target + FIELD(self, short, 24);
    W3dGetLong getter = PMF_FN(from + 16, source, W3dGetLong);
    setter(setter_this, getter(source + FIELD(from, short, 16)));
}
