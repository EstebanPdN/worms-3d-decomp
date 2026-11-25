/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dMemberPointer { int word0; int word1; } W3dMemberPointer;
void fn_80358504(int a, int b, int c, W3dMemberPointer first, W3dMemberPointer second);

void w3d_pmf_forward_801f18a4(void *self, int a, int b, int c)
{
    fn_80358504(a, b, c, FIELD(self, W3dMemberPointer, 20), FIELD(self, W3dMemberPointer, 12));
}
