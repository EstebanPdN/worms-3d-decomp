#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_80026a90.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family template, 2026-10-22 (third session): destructor releasing
 * thirteen interface members in reverse declaration order. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
extern char lbl_8040e008[];
void fn_80161050(Ptr32<void>, int);
extern char lbl_8040e208[];
void fn_8015ff2c(Ptr32<void>, int);
extern char lbl_8040e650[];

void w3d_destroy_interfaces_80026a90(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040e008;
    if (FIELD(self, void *, 100))
        VCALL(FIELD(self, void *, 100), 16);
    if (FIELD(self, void *, 72))
        VCALL(FIELD(self, void *, 72), 16);
    if (FIELD(self, void *, 68))
        VCALL(FIELD(self, void *, 68), 16);
    if (FIELD(self, void *, 64))
        VCALL(FIELD(self, void *, 64), 16);
    if (FIELD(self, void *, 60))
        VCALL(FIELD(self, void *, 60), 16);
    if (FIELD(self, void *, 56))
        VCALL(FIELD(self, void *, 56), 16);
    if (FIELD(self, void *, 52))
        VCALL(FIELD(self, void *, 52), 16);
    if (FIELD(self, void *, 48))
        VCALL(FIELD(self, void *, 48), 16);
    if (FIELD(self, void *, 44))
        VCALL(FIELD(self, void *, 44), 16);
    if (FIELD(self, void *, 40))
        VCALL(FIELD(self, void *, 40), 16);
    if (FIELD(self, void *, 36))
        VCALL(FIELD(self, void *, 36), 16);
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    fn_80161050(self, flags);
}

void w3d_destroy_interfaces_800282e4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040e208;
    if (FIELD(self, void *, 116))
        VCALL(FIELD(self, void *, 116), 16);
    if (FIELD(self, void *, 112))
        VCALL(FIELD(self, void *, 112), 16);
    if (FIELD(self, void *, 108))
        VCALL(FIELD(self, void *, 108), 16);
    if (FIELD(self, void *, 104))
        VCALL(FIELD(self, void *, 104), 16);
    if (FIELD(self, void *, 100))
        VCALL(FIELD(self, void *, 100), 16);
    if (FIELD(self, void *, 96))
        VCALL(FIELD(self, void *, 96), 16);
    if (FIELD(self, void *, 92))
        VCALL(FIELD(self, void *, 92), 16);
    if (FIELD(self, void *, 88))
        VCALL(FIELD(self, void *, 88), 16);
    if (FIELD(self, void *, 80))
        VCALL(FIELD(self, void *, 80), 16);
    if (FIELD(self, void *, 64))
        VCALL(FIELD(self, void *, 64), 16);
    if (FIELD(self, void *, 60))
        VCALL(FIELD(self, void *, 60), 16);
    if (FIELD(self, void *, 44))
        VCALL(FIELD(self, void *, 44), 16);
    if (FIELD(self, void *, 40))
        VCALL(FIELD(self, void *, 40), 16);
    fn_8015ff2c(self, flags);
}

void w3d_destroy_interfaces_800379fc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040e650;
    if (FIELD(self, void *, 104))
        VCALL(FIELD(self, void *, 104), 16);
    if (FIELD(self, void *, 100))
        VCALL(FIELD(self, void *, 100), 16);
    if (FIELD(self, void *, 96))
        VCALL(FIELD(self, void *, 96), 16);
    if (FIELD(self, void *, 76))
        VCALL(FIELD(self, void *, 76), 16);
    if (FIELD(self, void *, 60))
        VCALL(FIELD(self, void *, 60), 16);
    if (FIELD(self, void *, 56))
        VCALL(FIELD(self, void *, 56), 16);
    if (FIELD(self, void *, 52))
        VCALL(FIELD(self, void *, 52), 16);
    if (FIELD(self, void *, 48))
        VCALL(FIELD(self, void *, 48), 16);
    if (FIELD(self, void *, 44))
        VCALL(FIELD(self, void *, 44), 16);
    if (FIELD(self, void *, 40))
        VCALL(FIELD(self, void *, 40), 16);
    if (FIELD(self, void *, 36))
        VCALL(FIELD(self, void *, 36), 16);
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    fn_8015ff2c(self, flags);
}

}
