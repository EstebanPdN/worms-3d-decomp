#include "w3d_ptr.h"
#line 1 "cc18b_register_array_80250378.cpp"
// Observed lazy descriptor registration. The inline zeroing constructor
// preserves the stack descriptor address across memset and the later copy.
// Field widths follow the original stores; original memset uses crclr ABI.
extern "C" {
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

Ptr32<void> memset(...);
typedef struct Cc18bPropertyInfo {
 Cc18bPropertyInfo() { memset(w3d::VA(this), 0, sizeof(*this)); }
 Ptr32<const char> name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 Ptr32<void> descriptor;
 int unknown12;
 int unknown16;
} Cc18bPropertyInfo;
extern Cc18bPropertyInfo lbl_80465030;
extern int lbl_804b0904;
extern char lbl_803c59d8[];
extern char lbl_8045ed1c[];
// Original uses the unprototyped-call ABI (crclr before memset).

int fn_801efd34(Ptr32<void>, Ptr32<Cc18bPropertyInfo>);
int fn_801e8d9c(Ptr32<void>);
extern char lbl_8045ed1c[];
int fn_801efd34(Ptr32<void>, Ptr32<Cc18bPropertyInfo>);
int fn_801f2100(Ptr32<void>, Ptr32<Cc18bPropertyInfo>);
int fn_801efff0(Ptr32<void>, Ptr32<Cc18bPropertyInfo>);
int fn_801efe60(Ptr32<void>, Ptr32<Cc18bPropertyInfo>);
int fn_801efec4(Ptr32<void>, Ptr32<Cc18bPropertyInfo>);

int w3d_cc18b_register_array_80250378(Ptr32<void> self)
{
 if (!lbl_804b0904) {
 Ptr32<Cc18bPropertyInfo> target = &lbl_80465030;
 Cc18bPropertyInfo info;

 info.name = lbl_803c59d8;
 info.size = 44;
 info.elementType = 3;
 info.type = 9;
 info.descriptor = lbl_8045ed1c;
 *target = info;
 lbl_804b0904 = 1;
 }
 fn_801efd34(self, &lbl_80465030);
 fn_801e8d9c(self);
 return 0;
}
}


