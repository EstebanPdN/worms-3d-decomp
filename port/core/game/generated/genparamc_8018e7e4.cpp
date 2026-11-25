#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_8018e7e4.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), sixth batch. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<int (Ptr32<void>, int, Ptr32<void>, int)> W3dMethodA;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int, int)> W3dMethodB;
extern char lbl_803abc8c[];
extern char lbl_803abcc4[];
extern char lbl_803abcf4[];
Ptr32<void> fn_801eb834(Ptr32<void>, Ptr32<const char>);
Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<const char>);
void fn_801e8d9c(Ptr32<void>);
extern char lbl_80413ad0[];
extern char lbl_80413a78[];
Ptr32<void> fn_801e81c8(Ptr32<void>);
extern char lbl_80413160[];
extern Ptr32<char> lbl_804b06a0[];
int fn_8018e26c(Ptr32<void>, Ptr32<void>);
void fn_8020c5c0(Ptr32<void>);
Ptr32<unsigned short> fn_80341884(Ptr32<void>);
extern char lbl_803ac314[];
extern char lbl_803ac344[];
extern char lbl_803ac374[];
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const char>);
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const char>);
extern char lbl_80416708[];
extern char lbl_804166c0[];
extern char lbl_80416848[];
extern char lbl_80416800[];
extern char lbl_8041b058[];
int fn_80238d88(Ptr32<void>, Ptr32<void>);
extern char lbl_8041ac20[];
int fn_8023b59c(Ptr32<void>, Ptr32<void>);
extern char lbl_803c4bfc[];
extern char lbl_803c4c2c[];
extern char lbl_803c4c5c[];

Ptr32<void> w3d_construct_with_string_8018e7e4(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<char> name = (Ptr32<char>)self + 28;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_8018e26c(self, arg_r4);
    FIELD(self, void *, 0) = lbl_80413160;
    fn_8020c5c0(name);
    FIELD(self, char *, 28) = *empty;
    ++*fn_80341884(name);
    return self;
}

Ptr32<void> w3d_construct_with_member_801a5334(Ptr32<void> self)
{
    FIELD(self, void *, 0) = lbl_80413ad0;
    fn_801e81c8((Ptr32<char>)self + 4);
    FIELD(self, void *, 0) = lbl_80413a78;
    FIELD(self, int, 40) = 0;
    FIELD(self, int, 88) = 0;
    return self;
}

int w3d_register_properties_801be210(Ptr32<void> self)
{
    fn_801eb834(self, lbl_803abc8c);
    fn_801eb834(self, lbl_803abcc4);
    fn_801ecc6c(self, lbl_803abcf4);
    fn_801e8d9c(self);
    return 0;
}

int w3d_register_properties_801c02a4(Ptr32<void> self)
{
    fn_801ec52c(self, lbl_803ac314);
    fn_801ec52c(self, lbl_803ac344);
    fn_801ec52c(self, lbl_803ac374);
    fn_801e8d9c(self);
    return 0;
}

Ptr32<void> w3d_construct_with_member_801d544c(Ptr32<void> self)
{
    FIELD(self, void *, 0) = lbl_80416708;
    fn_801e81c8((Ptr32<char>)self + 4);
    FIELD(self, void *, 0) = lbl_804166c0;
    FIELD(self, int, 40) = 0;
    FIELD(self, int, 48) = 0;
    return self;
}

Ptr32<void> w3d_construct_with_member_801d9a74(Ptr32<void> self)
{
    FIELD(self, void *, 0) = lbl_80416848;
    fn_801e81c8((Ptr32<char>)self + 4);
    FIELD(self, void *, 0) = lbl_80416800;
    FIELD(self, int, 40) = 0;
    FIELD(self, int, 44) = 0;
    return self;
}

int w3d_forward_by_flag_80201964(Ptr32<void> self, int flag, Ptr32<void> argument)
{
    Ptr32<void> member;
    if (!flag) {
        member = FIELD(self, void *, 20);
        return (*(Ptr32<W3dMethodB>)(*(Ptr32<Ptr32<char>>)member + 28))(member, argument, 1, 0);
    }
    member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethodA>)(*(Ptr32<Ptr32<char>>)member + 20))(member, flag, argument, 0);
}

int w3d_forward_by_flag_802019bc(Ptr32<void> self, int flag, Ptr32<void> argument)
{
    Ptr32<void> member;
    if (!flag) {
        member = FIELD(self, void *, 20);
        return (*(Ptr32<W3dMethodB>)(*(Ptr32<Ptr32<char>>)member + 28))(member, argument, 1, 0);
    }
    member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethodA>)(*(Ptr32<Ptr32<char>>)member + 20))(member, flag, argument, 0);
}

int w3d_forward_by_flag_8020229c(Ptr32<void> self, int flag, Ptr32<void> argument)
{
    Ptr32<void> member;
    if (!flag) {
        member = FIELD(self, void *, 20);
        return (*(Ptr32<W3dMethodB>)(*(Ptr32<Ptr32<char>>)member + 28))(member, argument, 1, 0);
    }
    member = FIELD(self, void *, 20);
    return (*(Ptr32<W3dMethodA>)(*(Ptr32<Ptr32<char>>)member + 20))(member, flag, argument, 0);
}

Ptr32<void> w3d_construct_with_string_80239204(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<char> name = (Ptr32<char>)self + 24;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_80238d88(self, arg_r4);
    FIELD(self, void *, 0) = lbl_8041b058;
    fn_8020c5c0(name);
    FIELD(self, char *, 24) = *empty;
    ++*fn_80341884(name);
    return self;
}

Ptr32<void> w3d_construct_with_string_8023d32c(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<char> name = (Ptr32<char>)self + 28;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    fn_8023b59c(self, arg_r4);
    FIELD(self, void *, 0) = lbl_8041ac20;
    fn_8020c5c0(name);
    FIELD(self, char *, 28) = *empty;
    ++*fn_80341884(name);
    return self;
}

int w3d_register_properties_8024cda8(Ptr32<void> self)
{
    fn_801eb834(self, lbl_803c4bfc);
    fn_801eb834(self, lbl_803c4c2c);
    fn_801eb834(self, lbl_803c4c5c);
    fn_801e8d9c(self);
    return 0;
}

}
