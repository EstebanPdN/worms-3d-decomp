#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_8002f6dc.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), second batch. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
int fn_8015fb34(Ptr32<void>, Ptr32<void>);
void fn_802707f0(Ptr32<void>);
void fn_80270bdc(Ptr32<void>);
int fn_802b264c(Ptr32<void>);
void fn_802aff9c(Ptr32<void>, Ptr32<void>);

void w3d_assign_interface_arg_8002f6dc(Ptr32<void> self, Ptr32<Ptr32<void>> source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    FIELD(self, void *, 28) = *source;
}

void w3d_assign_interface_arg_8009afe8(Ptr32<void> self, Ptr32<Ptr32<void>> source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    FIELD(self, void *, 28) = *source;
}

void w3d_assign_interface_arg_800e8fb4(Ptr32<void> self, Ptr32<Ptr32<void>> source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 28))
        VCALL(FIELD(self, void *, 28), 16);
    FIELD(self, void *, 28) = *source;
}

void w3d_assign_interface_arg_800eb65c(Ptr32<void> self, Ptr32<Ptr32<void>> source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 192))
        VCALL(FIELD(self, void *, 192), 16);
    FIELD(self, void *, 192) = *source;
}

void w3d_assign_interface_arg_802c0c24(Ptr32<void> self, Ptr32<Ptr32<void>> source)
{
    if (*source)
        VCALL(*source, 12);
    if (FIELD(self, void *, 100))
        VCALL(FIELD(self, void *, 100), 16);
    FIELD(self, void *, 100) = *source;
}

}
