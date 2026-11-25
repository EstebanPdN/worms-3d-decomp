/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural.
 * Hand correction: 0x801ed900 converts to unsigned long long (it calls the
 * unsigned conversion helper), so its cast and setter type differ. */

/* Typed setters reached through a pointer to member function (third session of the day). */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
/* A g++ pointer to member function with vtable thunks (see families_u.c). */
#define PMF_FN(m, o, T) (FIELD(m, short, 2) >= 0 ? (T)(*(void ***)((o) + FIELD(m, short, 4)))[FIELD(m, short, 2) - 1] : (T)FIELD(m, void *, 4))
typedef void (*W3dSetFloat)(void *, float);
typedef void (*W3dSetByte)(void *, unsigned char);
typedef void (*W3dSetLong)(void *, long long);
typedef void (*W3dSetULong)(void *, unsigned long long);

void w3d_set_byte_from_float_801ed62c(char *self, char *target, void *unused, const float *value)
{
    W3dSetByte setter = PMF_FN(self + 20, target, W3dSetByte);
    setter(target + FIELD(self, short, 20), (unsigned char)*value);
}

void w3d_set_long_from_float_801ed88c(char *self, char *target, void *unused, const float *value)
{
    W3dSetLong setter = PMF_FN(self + 24, target, W3dSetLong);
    setter(target + FIELD(self, short, 24), (long long)*value);
}

void w3d_set_ulong_from_float_801ed900(char *self, char *target, void *unused, const float *value)
{
    W3dSetULong setter = PMF_FN(self + 24, target, W3dSetULong);
    setter(target + FIELD(self, short, 24), (unsigned long long)*value);
}

void w3d_set_float_member_801ed974(char *self, char *target, void *unused, const float *value)
{
    W3dSetFloat setter = PMF_FN(self + 20, target, W3dSetFloat);
    setter(target + FIELD(self, short, 20), *value);
}

void w3d_set_float_member_801ed9cc(char *self, char *target, void *unused, const float *value)
{
    W3dSetFloat setter = PMF_FN(self + 24, target, W3dSetFloat);
    setter(target + FIELD(self, short, 24), *value);
}
