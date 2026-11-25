// Observed lazy descriptor registration. The inline zeroing constructor
// preserves the stack descriptor address across memset and the later copy.
// Field widths follow the original stores; original memset uses crclr ABI.
extern "C" {
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

void *memset(...);
typedef struct Cc18bPropertyInfo {
 Cc18bPropertyInfo() { memset(this, 0, sizeof(*this)); }
 const char *name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 void *descriptor;
 void *extra;
 int unknown16;
} Cc18bPropertyInfo;
extern Cc18bPropertyInfo lbl_80464fe0;
extern int lbl_804b08f4;
extern char lbl_803c5614[];
extern char lbl_8045e004[];
extern char lbl_80401060[];
// Original uses the unprototyped-call ABI (crclr before memset).

int fn_801eff8c(void *, Cc18bPropertyInfo *);
int fn_801e8d9c(void *);

int w3d_cc18b_register_array_8024f4a0(void *self)
{
 if (!lbl_804b08f4) {
 Cc18bPropertyInfo *target = &lbl_80464fe0;
 Cc18bPropertyInfo info;

 info.name = lbl_803c5614;
 info.size = 44;
 info.elementType = 3;
 info.type = 9;
 info.descriptor = lbl_8045e004;
 info.extra = lbl_80401060;
 *target = info;
 lbl_804b08f4 = 1;
 }
 fn_801eff8c(self, &lbl_80464fe0);
 fn_801e8d9c(self);
 return 0;
}
}
