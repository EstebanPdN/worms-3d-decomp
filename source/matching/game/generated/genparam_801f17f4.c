/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dMemberPointer { int word0; int word1; } W3dMemberPointer;
void fn_803582b4(int a, int b, int c, W3dMemberPointer first, W3dMemberPointer second);

void w3d_pmf_forward_801f17f4(void *self, int a, int b, int c)
{
    fn_803582b4(a, b, c, FIELD(self, W3dMemberPointer, 28), FIELD(self, W3dMemberPointer, 20));
}

void w3d_pmf_forward_801f1954(void *self, int a, int b, int c)
{
    fn_803582b4(a, b, c, FIELD(self, W3dMemberPointer, 28), FIELD(self, W3dMemberPointer, 20));
}

void w3d_pmf_forward_801f1a5c(void *self, int a, int b, int c)
{
    fn_803582b4(a, b, c, FIELD(self, W3dMemberPointer, 28), FIELD(self, W3dMemberPointer, 20));
}
