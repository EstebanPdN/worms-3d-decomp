#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "gendtor_800e06fc.c"
/* Deleting destructors synthesized by tools/gen_dtor_units.py and verified
 * identical to the original after linking. Offsets are literal and externs are
 * named by original address; member types and class names are pending. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_8040ffb8[];
extern char w3d_vtable_8040ffd8[];
void fn_800deb44(Ptr32<void>, int);
void fn_8015ff2c(Ptr32<void>, int);
void fn_800de958(Ptr32<void>);
extern char w3d_vtable_80411908[];
int fn_801632ac(Ptr32<void>);
extern int lbl_804b178c;
void fn_8016132c(Ptr32<void>, int);
extern char w3d_vtable_80411940[];
void fn_80210990(Ptr32<void>, int);
void fn_801fe1f8(Ptr32<void>);
extern char w3d_vtable_80411b50[];
extern char w3d_vtable_80411ba8[];
void fn_801e828c(Ptr32<void>, int);
extern char w3d_vtable_80411d00[];
extern char w3d_vtable_80411d70[];
void fn_801f2758(Ptr32<void>, int);
extern char w3d_vtable_80411de0[];
extern char w3d_vtable_80411e60[];
extern int lbl_804b1888;
void fn_8016fa94(Ptr32<void>, int);
void fn_80210abc(Ptr32<void>, int);
extern char w3d_vtable_80411ea0[];
extern char w3d_vtable_80411ef8[];
extern char w3d_vtable_80411f40[];
extern char w3d_vtable_804135e0[];
extern char w3d_vtable_80413628[];
extern char w3d_vtable_80413a78[];
extern char w3d_vtable_80413ad0[];
extern char w3d_vtable_80413bf8[];
void fn_80353930(Ptr32<void>, int);
extern char w3d_vtable_80413c38[];
extern char w3d_vtable_80413dc0[];
extern char w3d_vtable_80413eb8[];
extern char w3d_vtable_804140e0[];
void fn_802134fc(Ptr32<void>);
extern char w3d_vtable_80414120[];
extern char w3d_vtable_80414220[];
extern char w3d_vtable_804136c0[];
extern char w3d_vtable_80414270[];
extern char w3d_vtable_804142c0[];
extern char w3d_vtable_80414320[];
void fn_8020c5c4(Ptr32<void>);
void fn_80341588(Ptr32<void>);
extern char w3d_vtable_80414378[];
extern char w3d_vtable_80414488[];
extern char w3d_vtable_804144b0[];
extern char w3d_vtable_80416570[];
extern char w3d_vtable_804165a8[];
extern char w3d_vtable_804166c0[];
extern char w3d_vtable_80416708[];
extern char w3d_vtable_80416760[];
extern char w3d_vtable_804167a8[];
extern char w3d_vtable_80416800[];
extern char w3d_vtable_80416848[];
extern char w3d_vtable_80416bb0[];
extern char w3d_vtable_80416bf8[];
extern char w3d_vtable_80416c48[];
void fn_801fe240(Ptr32<void>);
extern char w3d_vtable_80416c80[];
extern char w3d_vtable_80417d10[];
extern char w3d_vtable_80417d40[];
extern char w3d_vtable_804180d8[];
void fn_801f804c(Ptr32<void>, Ptr32<void>);
void fn_801fe288(Ptr32<void>);
extern char w3d_vtable_80418110[];
extern char w3d_vtable_80418140[];
extern char w3d_vtable_80418168[];
extern char w3d_vtable_80418190[];
extern char w3d_vtable_804181c0[];
extern char w3d_vtable_80419238[];
int fn_8020810c(Ptr32<void>);
extern char w3d_vtable_80419268[];
extern char w3d_vtable_80419318[];
extern char w3d_vtable_80419348[];
extern char w3d_vtable_80419810[];
extern char w3d_vtable_804197a8[];
void fn_801fe2e0(Ptr32<void>);

void w3d_dtor_800e06fc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 256) = w3d_vtable_8040ffb8;
    FIELD(self, void *, 0) = w3d_vtable_8040ffd8;
    if (FIELD(self, void *, 300)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 300)->vtable[4])(FIELD(self, W3dInterface *, 300));
    }
    if (FIELD(self, void *, 288)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 288)->vtable[4])(FIELD(self, W3dInterface *, 288));
    }
    if (FIELD(self, void *, 280)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 280)->vtable[4])(FIELD(self, W3dInterface *, 280));
    }
    if (FIELD(self, void *, 276)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 276)->vtable[4])(FIELD(self, W3dInterface *, 276));
    }
    if (FIELD(self, void *, 272)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 272)->vtable[4])(FIELD(self, W3dInterface *, 272));
    }
    if (FIELD(self, void *, 268)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 268)->vtable[4])(FIELD(self, W3dInterface *, 268));
    }
    if (FIELD(self, void *, 260)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 260)->vtable[4])(FIELD(self, W3dInterface *, 260));
    }
    fn_800deb44((Ptr32<char>)self + 28, 0);
    fn_8015ff2c(self, 0);
    if (flags & 1) {
        fn_800de958(self);
    }
}

void w3d_dtor_80162e94(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80411908;
    fn_801632ac(self);
    lbl_804b178c = 0;
    fn_8016132c((Ptr32<char>)self + 32, 2);
    FIELD(self, void *, 0) = w3d_vtable_80411940;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8016675c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80411b50;
    if (FIELD(self, void *, 48)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 48)->vtable[4])(FIELD(self, W3dInterface *, 48));
    }
    if (FIELD(self, void *, 44)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 44)->vtable[4])(FIELD(self, W3dInterface *, 44));
    }
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80411ba8;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_80169dec(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80411d00;
    if (FIELD(self, void *, 148)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 148)->vtable[4])(FIELD(self, W3dInterface *, 148));
    }
    FIELD(self, void *, 0) = w3d_vtable_80411d70;
    fn_801f2758((Ptr32<char>)self + 136, 2);
    if (FIELD(self, void *, 120)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 120)->vtable[4])(FIELD(self, W3dInterface *, 120));
    }
    if (FIELD(self, void *, 116)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 116)->vtable[4])(FIELD(self, W3dInterface *, 116));
    }
    FIELD(self, void *, 0) = w3d_vtable_80411de0;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8016ec44(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80411e60;
    lbl_804b1888 = 0;
    fn_8016fa94((Ptr32<char>)self + 104, 2);
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    fn_80210abc((Ptr32<char>)self + 20, 2);
    FIELD(self, void *, 0) = w3d_vtable_80411ea0;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8016f338(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80411ef8;
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    FIELD(self, void *, 0) = w3d_vtable_80411f40;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8019c3c4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804135e0;
    if (FIELD(self, void *, 44)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 44)->vtable[4])(FIELD(self, W3dInterface *, 44));
    }
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80413628;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801a538c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80413a78;
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80413ad0;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801a734c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80413bf8;
    fn_80353930((Ptr32<char>)self + 96, 2);
    fn_80353930((Ptr32<char>)self + 48, 2);
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80413c38;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801ab364(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80413dc0;
    if (FIELD(self, void *, 44)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 44)->vtable[4])(FIELD(self, W3dInterface *, 44));
    }
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80413eb8;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801ac2a4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80411d70;
    fn_801f2758((Ptr32<char>)self + 136, 2);
    if (FIELD(self, void *, 120)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 120)->vtable[4])(FIELD(self, W3dInterface *, 120));
    }
    if (FIELD(self, void *, 116)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 116)->vtable[4])(FIELD(self, W3dInterface *, 116));
    }
    FIELD(self, void *, 0) = w3d_vtable_80411de0;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801ae440(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804140e0;
    if (FIELD(self, void *, 48)) {
        fn_802134fc(FIELD(self, void *, 48));
    }
    if (FIELD(self, void *, 44)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 44)->vtable[4])(FIELD(self, W3dInterface *, 44));
    }
    FIELD(self, void *, 0) = w3d_vtable_80414120;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801b10b8(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80414220;
    if (FIELD(self, void *, 60)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 60)->vtable[4])(FIELD(self, W3dInterface *, 60));
    }
    if (FIELD(self, void *, 56)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 56)->vtable[4])(FIELD(self, W3dInterface *, 56));
    }
    if (FIELD(self, void *, 52)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 52)->vtable[4])(FIELD(self, W3dInterface *, 52));
    }
    if (FIELD(self, void *, 48)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 48)->vtable[4])(FIELD(self, W3dInterface *, 48));
    }
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_804136c0;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801b1838(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80414270;
    if (FIELD(self, void *, 76)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 76)->vtable[4])(FIELD(self, W3dInterface *, 76));
    }
    if (FIELD(self, void *, 72)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 72)->vtable[4])(FIELD(self, W3dInterface *, 72));
    }
    if (FIELD(self, void *, 68)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 68)->vtable[4])(FIELD(self, W3dInterface *, 68));
    }
    if (FIELD(self, void *, 64)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 64)->vtable[4])(FIELD(self, W3dInterface *, 64));
    }
    fn_801f2758((Ptr32<char>)self + 52, 2);
    if (FIELD(self, void *, 40)) {
        fn_802134fc(FIELD(self, void *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_804142c0;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801b230c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80414320;
    fn_8020c5c4((Ptr32<char>)self + 60);
    fn_80341588((Ptr32<char>)self + 60);
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80414378;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801b4460(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80414488;
    if (FIELD(self, void *, 24)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 24)->vtable[4])(FIELD(self, W3dInterface *, 24));
    }
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_804144b0;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801d42a0(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80416570;
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_804165a8;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801d54a4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804166c0;
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80416708;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801d5e1c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80416760;
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_804167a8;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801d9acc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80416800;
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    FIELD(self, void *, 0) = w3d_vtable_80416848;
    fn_801e828c((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801ded9c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80416bb0;
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    FIELD(self, int, 28) = 0;
    fn_8020c5c4((Ptr32<char>)self + 80);
    fn_80341588((Ptr32<char>)self + 80);
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    FIELD(self, void *, 0) = w3d_vtable_80416bf8;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801df4ec(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80416c48;
    if (FIELD(self, void *, 24)) {
        fn_801fe240(FIELD(self, void *, 24));
    }
    if (FIELD(self, void *, 28)) {
        fn_801fe240(FIELD(self, void *, 28));
    }
    FIELD(self, void *, 0) = w3d_vtable_80416c80;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801f2db4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80417d10;
    if (FIELD(self, void *, 52)) {
        fn_802134fc(FIELD(self, void *, 52));
    }
    if (FIELD(self, void *, 40)) {
        fn_802134fc(FIELD(self, void *, 40));
    }
    if (FIELD(self, void *, 36)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 36)->vtable[4])(FIELD(self, W3dInterface *, 36));
    }
    if (FIELD(self, void *, 20)) {
        fn_802134fc(FIELD(self, void *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_80417d40;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801f84a0(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804180d8;
    fn_801f804c(FIELD(self, void *, 24), self);
    if (FIELD(self, void *, 36)) {
        fn_801fe288(FIELD(self, void *, 36));
    }
    if (FIELD(self, void *, 24)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 24)->vtable[4])(FIELD(self, W3dInterface *, 24));
    }
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_80418110;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801f8fbc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80418140;
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_80418168;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_801f92e4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80418190;
    if (FIELD(self, void *, 24)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 24)->vtable[4])(FIELD(self, W3dInterface *, 24));
    }
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_804181c0;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8020803c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419238;
    fn_8020810c(self);
    FIELD(self, void *, 0) = w3d_vtable_80419268;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_80208c64(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419318;
    if (FIELD(self, void *, 36)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 36)->vtable[4])(FIELD(self, W3dInterface *, 36));
    }
    FIELD(self, void *, 0) = w3d_vtable_80419348;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8021837c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419810;
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_80418110;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_80218874(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804197a8;
    fn_801fe2e0(FIELD(self, void *, 88));
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_804181c0;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

}
