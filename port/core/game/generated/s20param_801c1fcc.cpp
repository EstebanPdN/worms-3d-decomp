#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20param_801c1fcc.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S20PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int unknown;
} S20PropertyInfo;
extern S20PropertyInfo lbl_8045d3cc;
extern int lbl_804b0460;
extern char lbl_803ac6a8[];
extern char lbl_803ac6d0[];
extern char lbl_8045e004[];
extern char lbl_803fe464[];
Ptr32<void> memset(Ptr32<void>, int, unsigned int);
Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<char>);
int fn_801eff8c(Ptr32<void>, Ptr32<S20PropertyInfo>);
int fn_801e8d9c(Ptr32<void>);

int w3d_s20desc_801c1fcc(Ptr32<void> self)
{
    fn_801ebf38(self, lbl_803ac6a8);
    if (!lbl_804b0460) {
        Ptr32<S20PropertyInfo> target = &lbl_8045d3cc;
        S20PropertyInfo info;
        memset(&info, 0, sizeof info);
        info.name = lbl_803ac6d0;
        info.size = 20;
        info.elementType = 1;
        info.type = 9;
        info.descriptor = lbl_8045e004;
        info.extra = lbl_803fe464;
        *target = info;
        lbl_804b0460 = 1;
    }
    fn_801eff8c(self, &lbl_8045d3cc);
    fn_801e8d9c(self);
    return 0;
}

}
