#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801a17e4.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef Ptr32<void (void)> S10TypeMethod;
typedef struct S10TypeInfo {
    Ptr32<void> unknown;
    Ptr32<const char> name;
    S10TypeMethod create;
    S10TypeMethod destroy;
    int size;
    Ptr32<void> parent;
} S10TypeInfo;
extern S10TypeInfo lbl_8045cdfc;
extern char lbl_803a9b68[], lbl_8045cea4[];
extern int fn_801a1220(void);
extern int fn_801a118c(void);
extern void fn_80200af8(Ptr32<S10TypeInfo>);
extern S10TypeInfo lbl_8045e17c;
extern char lbl_803b0ecc[], lbl_8045e6bc[];
extern int fn_801f3fbc(void);
extern int fn_801f3f28(void);
extern S10TypeInfo lbl_80462e78;
extern char lbl_803b2ea4[], lbl_80463308[];
extern int fn_80209058(void);
extern int fn_80209050(void);

void w3d_s10_initialize_type_801a17e4(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        Ptr32<S10TypeInfo> type = &lbl_8045cdfc;
        type->name = lbl_803a9b68;
        type->create = fn_801a118c;
        type->destroy = fn_801a1220;
        type->size = 32;
        type->parent = lbl_8045cea4;
        fn_80200af8(type);
    }
}

void w3d_s10_initialize_type_801f4064(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        Ptr32<S10TypeInfo> type = &lbl_8045e17c;
        type->name = lbl_803b0ecc;
        type->create = fn_801f3f28;
        type->destroy = fn_801f3fbc;
        type->size = 32;
        type->parent = lbl_8045e6bc;
        fn_80200af8(type);
    }
}

void w3d_s10_initialize_type_802090b8(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        Ptr32<S10TypeInfo> type = &lbl_80462e78;
        type->name = lbl_803b2ea4;
        type->create = fn_80209050;
        type->destroy = fn_80209058;
        type->size = 120;
        type->parent = lbl_80463308;
        fn_80200af8(type);
    }
}

}
