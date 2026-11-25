#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_8009f4bc.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), eighth batch. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dBlock12 { int words[12 / 4]; } W3dBlock12;
int fn_8020db88(Ptr32<void>, int, int);
extern char lbl_804131d8[];
extern Ptr32<char> lbl_804b06a0[];
Ptr32<void> fn_801ea0ec(Ptr32<void>, int);
void fn_8020c5c0(Ptr32<void>);
Ptr32<unsigned short> fn_80341884(Ptr32<void>);
extern char lbl_803aad38[];
extern char lbl_803aad68[];
extern char lbl_803aad98[];
extern char lbl_803aadc4[];
Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<const char>);
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<const char>);
void fn_801e8d9c(Ptr32<void>);
extern char lbl_803ab73c[];
extern char lbl_803ab770[];
extern char lbl_803ab7a4[];
extern char lbl_803ab7d8[];

void w3d_get_block12_8009f4bc(Ptr32<void> self, Ptr32<void> unused, Ptr32<void> out)
{
    *(Ptr32<W3dBlock12>)out = FIELD(self, W3dBlock12, 320);
}

void w3d_get_block12_800ed34c(Ptr32<void> self, Ptr32<void> unused, Ptr32<void> out)
{
    *(Ptr32<W3dBlock12>)out = FIELD(self, W3dBlock12, 36);
}

void w3d_get_block12_800ed36c(Ptr32<void> self, Ptr32<void> unused, Ptr32<void> out)
{
    *(Ptr32<W3dBlock12>)out = FIELD(self, W3dBlock12, 48);
}

int w3d_get_indexed_80186864(Ptr32<void> self, int index)
{
    Ptr32<int> table = FIELD(self, int *, 104);
    return *(Ptr32<int>)((Ptr32<char>)table + (index << 2));
}

Ptr32<void> w3d_construct_named_8018e26c(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<char> name = (Ptr32<char>)self + 24;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_801ea0ec(self, w3d::H(arg_r4));
    FIELD(self, int, 20) = 0;
    FIELD(self, void *, 0) = lbl_804131d8;
    fn_8020c5c0(name);
    FIELD(self, char *, 24) = *empty;
    ++*fn_80341884(name);
    return self;
}

int w3d_set_block12_801a0974(Ptr32<void> self, Ptr32<const void> source)
{
    FIELD(self, W3dBlock12, 176) = *(Ptr32<const W3dBlock12>)source;
    FIELD(self, int, 212) = 1;
    return 0;
}

int w3d_set_block12_801a09a4(Ptr32<void> self, Ptr32<const void> source)
{
    FIELD(self, W3dBlock12, 188) = *(Ptr32<const W3dBlock12>)source;
    FIELD(self, int, 212) = 1;
    return 0;
}

int w3d_set_block12_801a09d4(Ptr32<void> self, Ptr32<const void> source)
{
    FIELD(self, W3dBlock12, 200) = *(Ptr32<const W3dBlock12>)source;
    FIELD(self, int, 212) = 1;
    return 0;
}

int w3d_set_slot_801ab5f0(Ptr32<void> self, int index, int value)
{
    struct W3dSlots { char pad[124]; int slots[1]; };
    ((Ptr32<struct W3dSlots>)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab604(Ptr32<void> self, int index)
{
    struct W3dSlots { char pad[124]; int slots[1]; };
    return ((Ptr32<struct W3dSlots>)self)->slots[index];
}

int w3d_set_slot_801ab740(Ptr32<void> self, int index, int value)
{
    struct W3dSlots { char pad[228]; int slots[1]; };
    ((Ptr32<struct W3dSlots>)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab754(Ptr32<void> self, int index)
{
    struct W3dSlots { char pad[228]; int slots[1]; };
    return ((Ptr32<struct W3dSlots>)self)->slots[index];
}

int w3d_set_slot_801ab8b4(Ptr32<void> self, int index, int value)
{
    struct W3dSlots { char pad[248]; int slots[1]; };
    ((Ptr32<struct W3dSlots>)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab8c8(Ptr32<void> self, int index)
{
    struct W3dSlots { char pad[248]; int slots[1]; };
    return ((Ptr32<struct W3dSlots>)self)->slots[index];
}

int w3d_set_slot_801ab8d8(Ptr32<void> self, int index, int value)
{
    struct W3dSlots { char pad[264]; int slots[1]; };
    ((Ptr32<struct W3dSlots>)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab8ec(Ptr32<void> self, int index)
{
    struct W3dSlots { char pad[264]; int slots[1]; };
    return ((Ptr32<struct W3dSlots>)self)->slots[index];
}

int w3d_set_slot_801ab8fc(Ptr32<void> self, int index, int value)
{
    struct W3dSlots { char pad[280]; int slots[1]; };
    ((Ptr32<struct W3dSlots>)self)->slots[index] = value;
    return 0;
}

int w3d_get_slot_801ab910(Ptr32<void> self, int index)
{
    struct W3dSlots { char pad[280]; int slots[1]; };
    return ((Ptr32<struct W3dSlots>)self)->slots[index];
}

int w3d_register_bindings_801b54e0(Ptr32<void> self)
{
    fn_801ebf38(self, lbl_803aad38);
    fn_801ecc6c(self, lbl_803aad68);
    fn_801ecc6c(self, lbl_803aad98);
    fn_801ebf38(self, lbl_803aadc4);
    fn_801e8d9c(self);
    return 0;
}

int w3d_register_bindings_801bc26c(Ptr32<void> self)
{
    fn_801ecc6c(self, lbl_803ab73c);
    fn_801ecc6c(self, lbl_803ab770);
    fn_801ecc6c(self, lbl_803ab7a4);
    fn_801ecc6c(self, lbl_803ab7d8);
    fn_801e8d9c(self);
    return 0;
}

}
