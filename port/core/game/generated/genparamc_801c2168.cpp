#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801c2168.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), eighth batch. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dBlock12 { int words[12 / 4]; } W3dBlock12;
int fn_8020db88(Ptr32<void>, int, int);
extern char lbl_80414d58[];
extern Ptr32<char> lbl_804b06a0[];
Ptr32<void> fn_801ea0ec(Ptr32<void>, int);
void fn_8020c5c0(Ptr32<void>);
Ptr32<unsigned short> fn_80341884(Ptr32<void>);
extern char lbl_803aad38[];
extern char lbl_803aad68[];
extern char lbl_803aad98[];
extern char lbl_803aadc4[];
void fn_801ebf38(Ptr32<void>, Ptr32<const char>);
void fn_801ecc6c(Ptr32<void>, Ptr32<const char>);
void fn_801e8d9c(Ptr32<void>);
extern char lbl_804131d8[];
extern char lbl_803b9544[];
extern char lbl_803b9574[];
extern char lbl_803b95a4[];
extern char lbl_803b95d4[];
Ptr32<void> fn_801ec0f8(Ptr32<void>, Ptr32<const char>);
Ptr32<void> fn_801ec0f8(Ptr32<void>, Ptr32<const char>);

Ptr32<void> w3d_construct_named_801c2168(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<char> name = (Ptr32<char>)self + 24;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_801ea0ec(self, w3d::H(arg_r4));
    FIELD(self, int, 20) = 0;
    FIELD(self, void *, 0) = lbl_80414d58;
    fn_8020c5c0(name);
    FIELD(self, char *, 24) = *empty;
    ++*fn_80341884(name);
    return self;
}

int w3d_get_indexed_801fbe9c(Ptr32<void> self, int index)
{
    Ptr32<int> table = FIELD(self, int *, 52);
    return *(Ptr32<int>)((Ptr32<char>)table + (index << 2));
}

int w3d_get_indexed_8020a7f8(Ptr32<void> self, int index)
{
    Ptr32<int> table = FIELD(self, int *, 20);
    return *(Ptr32<int>)((Ptr32<char>)table + (index << 2));
}

int w3d_register_bindings_8022a058(Ptr32<void> self)
{
    fn_801ec0f8(self, lbl_803b9544);
    fn_801ec0f8(self, lbl_803b9574);
    fn_801ec0f8(self, lbl_803b95a4);
    fn_801ec0f8(self, lbl_803b95d4);
    fn_801e8d9c(self);
    return 0;
}

}
