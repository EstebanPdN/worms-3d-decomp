/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair templates (later batch): grid cell lookup, message dispatch through a
 * handler table, and a binding with a copied range. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*W3dMethodP)(void *, void *);
typedef void *(*W3dGet)(void *);
typedef int (*W3dHandler2)(void *, void *);

int w3d_dispatch_by_kind_80168c08(void *iface, void *message)
{
    char *self = iface ? (char *)iface - 4 : 0;
    void *target;
    (*(W3dMethodP *)(*(char **)self + 68))(self, message);
    target = (*(W3dGet *)(*(char **)message + 20))(message);
    return FIELD(iface, W3dHandler2 *, 24)[(FIELD(FIELD(target, char *, 20), unsigned int, 32) >> 22) & 0x3ff](iface, message);
}

int w3d_dispatch_by_kind_801ac49c(void *iface, void *message)
{
    char *self = iface ? (char *)iface - 4 : 0;
    void *target;
    (*(W3dMethodP *)(*(char **)self + 68))(self, message);
    target = (*(W3dGet *)(*(char **)message + 20))(message);
    return FIELD(iface, W3dHandler2 *, 24)[(FIELD(FIELD(target, char *, 20), unsigned int, 32) >> 22) & 0x3ff](iface, message);
}
