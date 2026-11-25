/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), third batch. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*W3dMethod)(void *);
typedef int (*W3dMethod4)(void *, void *, int, int);
#define VCALL(p, o) ((*(W3dMethod *)(*(char **)(p) + (o)))(p))
extern char lbl_803b29c8[];
void fn_8020c510(void *, const char *, ...);
extern char lbl_803b29c4[];
extern char lbl_803b299c[];

void w3d_release_interface_8002b62c(void *self)
{
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    FIELD(self, void *, 32) = 0;
}

void w3d_release_interface_800382a8(void *self)
{
    if (FIELD(self, void *, 96))
        VCALL(FIELD(self, void *, 96), 16);
    FIELD(self, void *, 96) = 0;
}

void w3d_release_interface_8009af9c(void *self)
{
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    FIELD(self, void *, 32) = 0;
}

void w3d_release_interface_800bf2d4(void *self)
{
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    FIELD(self, void *, 32) = 0;
}

int w3d_format_value_801fec2c(void *self, void *out, int *value)
{
    fn_8020c510(out, lbl_803b29c8, *value);
    return 0;
}

int w3d_format_value_801fed48(void *self, void *out, int *value)
{
    fn_8020c510(out, lbl_803b29c4, *value);
    return 0;
}

int w3d_format_value_801ff448(void *self, void *out, int *value)
{
    fn_8020c510(out, lbl_803b29c8, *value);
    return 0;
}

int w3d_format_value_801ff694(void *self, void *out, int *value)
{
    fn_8020c510(out, lbl_803b299c, *value);
    return 0;
}

int w3d_forward_to_member_802013c8(void *self, void *argument)
{
    void *member = FIELD(self, void *, 20);
    return (*(W3dMethod4 *)(*(char **)member + 20))(member, argument, 1, 0);
}

int w3d_forward_to_member_80201400(void *self, void *argument)
{
    void *member = FIELD(self, void *, 20);
    return (*(W3dMethod4 *)(*(char **)member + 20))(member, argument, 1, 0);
}

int w3d_forward_to_member_802015c0(void *self, void *argument)
{
    void *member = FIELD(self, void *, 20);
    return (*(W3dMethod4 *)(*(char **)member + 20))(member, argument, 8, 0);
}

int w3d_forward_to_member_802015f8(void *self, void *argument)
{
    void *member = FIELD(self, void *, 20);
    return (*(W3dMethod4 *)(*(char **)member + 20))(member, argument, 8, 0);
}

int w3d_forward_to_member_80201698(void *self, void *argument)
{
    void *member = FIELD(self, void *, 20);
    return (*(W3dMethod4 *)(*(char **)member + 20))(member, argument, 8, 0);
}
