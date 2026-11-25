#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801b4f60.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10PropertyInfo {
 Ptr32<const char> name;
 unsigned short size;
 unsigned char elementType;
 unsigned char type;
 Ptr32<void> descriptor;
 Ptr32<void> extra;
 int unknown16;
} S10PropertyInfo;
extern S10PropertyInfo lbl_8045cecc;
extern int lbl_804b0360;
extern char lbl_803aace8[];
extern char lbl_8045e004[];
extern char lbl_803fe4c4[];
Ptr32<void> memset(Ptr32<void>, int, unsigned int);
int fn_801eff8c(Ptr32<void>, Ptr32<S10PropertyInfo>);
int fn_801e8d9c(Ptr32<void>);
extern S10PropertyInfo lbl_8045d1d8;
extern int lbl_804b03fc;
extern char lbl_803abd5c[];
extern char lbl_803fe570[];
extern S10PropertyInfo lbl_8045d64c;
extern int lbl_804b04e0;
extern char lbl_803ad870[];
extern char lbl_803fe63c[];

int w3d_s10_register_array_801b4f60(Ptr32<void> self)
{
 if (!lbl_804b0360) {
 Ptr32<S10PropertyInfo> target = &lbl_8045cecc;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803aace8;
 info.size = 44;
 info.elementType = 3;
 info.type = 9;
 info.descriptor = lbl_8045e004;
 info.extra = lbl_803fe4c4;
 *target = info;
 lbl_804b0360 = 1;
 }
 fn_801eff8c(self, &lbl_8045cecc);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801be5a0(Ptr32<void> self)
{
 if (!lbl_804b03fc) {
 Ptr32<S10PropertyInfo> target = &lbl_8045d1d8;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803abd5c;
 info.size = 60;
 info.elementType = 7;
 info.type = 9;
 info.descriptor = lbl_8045e004;
 info.extra = lbl_803fe570;
 *target = info;
 lbl_804b03fc = 1;
 }
 fn_801eff8c(self, &lbl_8045d1d8);
 fn_801e8d9c(self);
 return 0;
}

int w3d_s10_register_array_801c9728(Ptr32<void> self)
{
 if (!lbl_804b04e0) {
 Ptr32<S10PropertyInfo> target = &lbl_8045d64c;
 S10PropertyInfo info;
 memset(&info, 0, sizeof info);
 info.name = lbl_803ad870;
 info.size = 28;
 info.elementType = 2;
 info.type = 9;
 info.descriptor = lbl_8045e004;
 info.extra = lbl_803fe63c;
 *target = info;
 lbl_804b04e0 = 1;
 }
 fn_801eff8c(self, &lbl_8045d64c);
 fn_801e8d9c(self);
 return 0;
}

}
