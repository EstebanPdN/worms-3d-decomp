/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), second batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*W3dMethod)(void *);
#define VCALL(p, o) ((*(W3dMethod *)(*(char **)(p) + (o)))(p))
int fn_8015fb34(void *, void *);
void fn_802707f0(void *);
void fn_80270bdc(void *);
int fn_802b264c(void *);
void fn_802aff9c(void *, void *);

void w3d_assign_interface_arg_8002f6dc(void *self, void **source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    FIELD(self, void *, 28) = *source;
    if (*source)
        VCALL(*source, 16);
}

void w3d_assign_interface_arg_8009afe8(void *self, void **source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    FIELD(self, void *, 28) = *source;
    if (*source)
        VCALL(*source, 16);
}

void w3d_assign_interface_arg_800e8fb4(void *self, void **source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    FIELD(self, void *, 28) = *source;
    if (*source)
        VCALL(*source, 16);
}

void w3d_assign_interface_arg_800eb65c(void *self, void **source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 192))
        VCALL(FIELD(self, void *, 192), 16);
    FIELD(self, void *, 192) = *source;
    if (*source)
        VCALL(*source, 16);
}

void w3d_assign_interface_arg_802c0c24(void *self, void **source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 100))
        VCALL(FIELD(self, void *, 100), 16);
    FIELD(self, void *, 100) = *source;
    if (*source)
        VCALL(*source, 16);
}
