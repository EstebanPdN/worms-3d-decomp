#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_8002b62c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), third batch. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<void (Ptr32<void>)> W3dMethod;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int, int)> W3dMethod4;
#define VCALL(p, o) ((*(W3dMethod *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o)))(p))
extern char lbl_803b29c8[];
void fn_8020c510(Ptr32<void>, Ptr32<const char>, ...);
extern char lbl_803b29c4[];
extern char lbl_803b299c[];

void w3d_release_interface_8002b62c(Ptr32<void> self)
{
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    FIELD(self, void *, 32) = 0;
}

void w3d_release_interface_800382a8(Ptr32<void> self)
{
    if (FIELD(self, void *, 96))
        VCALL(FIELD(self, void *, 96), 16);
    FIELD(self, void *, 96) = 0;
}

void w3d_release_interface_8009af9c(Ptr32<void> self)
{
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    FIELD(self, void *, 32) = 0;
}

void w3d_release_interface_800bf2d4(Ptr32<void> self)
{
    if (FIELD(self, void *, 32))
        VCALL(FIELD(self, void *, 32), 16);
    FIELD(self, void *, 32) = 0;
}

int w3d_format_value_801fec2c(Ptr32<void> self, Ptr32<void> out, Ptr32<int> value)
{
    fn_8020c510(out, lbl_803b29c8, *value);
    return 0;
}

int w3d_format_value_801fed48(Ptr32<void> self, Ptr32<void> out, Ptr32<int> value)
{
    fn_8020c510(out, lbl_803b29c4, *value);
    return 0;
}

int w3d_format_value_801ff448(Ptr32<void> self, Ptr32<void> out, Ptr32<int> value)
{
    fn_8020c510(out, lbl_803b29c8, *value);
    return 0;
}

int w3d_format_value_801ff694(Ptr32<void> self, Ptr32<void> out, Ptr32<int> value)
{
    fn_8020c510(out, lbl_803b299c, *value);
    return 0;
}

int w3d_forward_to_member_802013c8(Ptr32<void> self, Ptr32<void> argument)
{
    Ptr32<void> member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethod4>)(*(Ptr32<Ptr32<char>>)member + 20))(member, argument, 1, 0);
}

int w3d_forward_to_member_80201400(Ptr32<void> self, Ptr32<void> argument)
{
    Ptr32<void> member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethod4>)(*(Ptr32<Ptr32<char>>)member + 20))(member, argument, 1, 0);
}

int w3d_forward_to_member_802015c0(Ptr32<void> self, Ptr32<void> argument)
{
    Ptr32<void> member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethod4>)(*(Ptr32<Ptr32<char>>)member + 20))(member, argument, 8, 0);
}

int w3d_forward_to_member_802015f8(Ptr32<void> self, Ptr32<void> argument)
{
    Ptr32<void> member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethod4>)(*(Ptr32<Ptr32<char>>)member + 20))(member, argument, 8, 0);
}

int w3d_forward_to_member_80201698(Ptr32<void> self, Ptr32<void> argument)
{
    Ptr32<void> member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethod4>)(*(Ptr32<Ptr32<char>>)member + 20))(member, argument, 8, 0);
}

}
