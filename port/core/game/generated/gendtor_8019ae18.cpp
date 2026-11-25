#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "gendtor_8019ae18.c"
/* Deleting destructors synthesized by tools/gen_dtor_units.py and verified
 * identical to the original after linking. Offsets are literal and externs are
 * named by original address; member types and class names are pending. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_804135a8[];
void fn_8020c5c4(Ptr32<void>);
void fn_80341588(Ptr32<void>);
void fn_801ea138(Ptr32<void>, int);
void fn_801ea740(Ptr32<void>);
extern char w3d_vtable_80413580[];
extern char w3d_vtable_80414d58[];
extern char w3d_vtable_80415f38[];
extern char w3d_vtable_80419bc8[];
void fn_80210990(Ptr32<void>, int);
void fn_801fe1f8(Ptr32<void>);
extern char w3d_vtable_80419b08[];
extern char w3d_vtable_80419a48[];
extern char w3d_vtable_80419988[];
extern char w3d_vtable_804198c8[];
extern char w3d_vtable_8041a5f0[];
extern char w3d_vtable_8041a5c8[];
void fn_8021f234(Ptr32<void>, int);
extern char w3d_vtable_8041a5a0[];
void fn_8021fe20(Ptr32<void>, int);
extern char w3d_vtable_8041a578[];
extern char w3d_vtable_8041a500[];
extern char w3d_vtable_8041a4b0[];
extern char w3d_vtable_8041a488[];
extern char w3d_vtable_8041a438[];
extern char w3d_vtable_8041a410[];
extern char w3d_vtable_8041a3e8[];
extern char w3d_vtable_8041a3c0[];
extern char w3d_vtable_8041a398[];
extern char w3d_vtable_8041a370[];
void fn_802224f8(Ptr32<void>, int);
extern char w3d_vtable_8041a2d0[];
extern char w3d_vtable_8041a280[];
extern char w3d_vtable_8041a1b8[];
extern char w3d_vtable_8041a168[];
extern char w3d_vtable_8041a0f0[];
extern char w3d_vtable_8041a000[];
extern char w3d_vtable_80419fd8[];
extern char w3d_vtable_80419f88[];

void w3d_dtor_8019ae18(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804135a8;
    if (FIELD(self, void *, 24)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 24)->vtable[4])(FIELD(self, W3dInterface *, 24));
    }
    fn_8020c5c4((Ptr32<char>)self + 28);
    fn_80341588((Ptr32<char>)self + 28);
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8019b178(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80413580;
    fn_8020c5c4((Ptr32<char>)self + 28);
    fn_80341588((Ptr32<char>)self + 28);
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_801c21dc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80414d58;
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_801cd750(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80415f38;
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    if (FIELD(self, void *, 48)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 48)->vtable[4])(FIELD(self, W3dInterface *, 48));
    }
    fn_8020c5c4((Ptr32<char>)self + 36);
    fn_80341588((Ptr32<char>)self + 36);
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80219edc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419bc8;
    fn_80210990((Ptr32<char>)self + 20, 0);
    fn_8020c5c4((Ptr32<char>)self + 4);
    fn_80341588((Ptr32<char>)self + 4);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_80219fc8(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419b08;
    fn_80210990((Ptr32<char>)self + 20, 0);
    fn_8020c5c4((Ptr32<char>)self + 4);
    fn_80341588((Ptr32<char>)self + 4);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8021a0b4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419a48;
    fn_80210990((Ptr32<char>)self + 20, 0);
    fn_8020c5c4((Ptr32<char>)self + 4);
    fn_80341588((Ptr32<char>)self + 4);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8021a11c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419988;
    fn_80210990((Ptr32<char>)self + 20, 0);
    fn_8020c5c4((Ptr32<char>)self + 4);
    fn_80341588((Ptr32<char>)self + 4);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8021a208(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804198c8;
    fn_80210990((Ptr32<char>)self + 20, 0);
    fn_8020c5c4((Ptr32<char>)self + 4);
    fn_80341588((Ptr32<char>)self + 4);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_8021f234(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a5f0;
    fn_8020c5c4((Ptr32<char>)self + 104);
    fn_80341588((Ptr32<char>)self + 104);
    fn_8020c5c4((Ptr32<char>)self + 100);
    fn_80341588((Ptr32<char>)self + 100);
    fn_8020c5c4((Ptr32<char>)self + 96);
    fn_80341588((Ptr32<char>)self + 96);
    fn_8020c5c4((Ptr32<char>)self + 92);
    fn_80341588((Ptr32<char>)self + 92);
    fn_8020c5c4((Ptr32<char>)self + 88);
    fn_80341588((Ptr32<char>)self + 88);
    fn_8020c5c4((Ptr32<char>)self + 84);
    fn_80341588((Ptr32<char>)self + 84);
    fn_8020c5c4((Ptr32<char>)self + 80);
    fn_80341588((Ptr32<char>)self + 80);
    fn_8020c5c4((Ptr32<char>)self + 76);
    fn_80341588((Ptr32<char>)self + 76);
    fn_8020c5c4((Ptr32<char>)self + 72);
    fn_80341588((Ptr32<char>)self + 72);
    fn_8020c5c4((Ptr32<char>)self + 68);
    fn_80341588((Ptr32<char>)self + 68);
    fn_8020c5c4((Ptr32<char>)self + 60);
    fn_80341588((Ptr32<char>)self + 60);
    fn_8020c5c4((Ptr32<char>)self + 56);
    fn_80341588((Ptr32<char>)self + 56);
    fn_8020c5c4((Ptr32<char>)self + 52);
    fn_80341588((Ptr32<char>)self + 52);
    fn_8020c5c4((Ptr32<char>)self + 48);
    fn_80341588((Ptr32<char>)self + 48);
    fn_8020c5c4((Ptr32<char>)self + 44);
    fn_80341588((Ptr32<char>)self + 44);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8021fe20(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a5c8;
    fn_8020c5c4((Ptr32<char>)self + 136);
    fn_80341588((Ptr32<char>)self + 136);
    fn_8020c5c4((Ptr32<char>)self + 132);
    fn_80341588((Ptr32<char>)self + 132);
    fn_8020c5c4((Ptr32<char>)self + 128);
    fn_80341588((Ptr32<char>)self + 128);
    fn_8020c5c4((Ptr32<char>)self + 124);
    fn_80341588((Ptr32<char>)self + 124);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_802202cc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a5a0;
    fn_8020c5c4((Ptr32<char>)self + 168);
    fn_80341588((Ptr32<char>)self + 168);
    fn_8020c5c4((Ptr32<char>)self + 164);
    fn_80341588((Ptr32<char>)self + 164);
    fn_8020c5c4((Ptr32<char>)self + 160);
    fn_80341588((Ptr32<char>)self + 160);
    fn_8020c5c4((Ptr32<char>)self + 156);
    fn_80341588((Ptr32<char>)self + 156);
    fn_8021fe20(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80220758(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a578;
    fn_8020c5c4((Ptr32<char>)self + 128);
    fn_80341588((Ptr32<char>)self + 128);
    fn_8020c5c4((Ptr32<char>)self + 124);
    fn_80341588((Ptr32<char>)self + 124);
    fn_8020c5c4((Ptr32<char>)self + 120);
    fn_80341588((Ptr32<char>)self + 120);
    fn_8020c5c4((Ptr32<char>)self + 116);
    fn_80341588((Ptr32<char>)self + 116);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80221398(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a500;
    fn_8020c5c4((Ptr32<char>)self + 156);
    fn_80341588((Ptr32<char>)self + 156);
    fn_8020c5c4((Ptr32<char>)self + 152);
    fn_80341588((Ptr32<char>)self + 152);
    fn_8020c5c4((Ptr32<char>)self + 148);
    fn_80341588((Ptr32<char>)self + 148);
    fn_8020c5c4((Ptr32<char>)self + 144);
    fn_80341588((Ptr32<char>)self + 144);
    fn_8020c5c4((Ptr32<char>)self + 140);
    fn_80341588((Ptr32<char>)self + 140);
    fn_8020c5c4((Ptr32<char>)self + 136);
    fn_80341588((Ptr32<char>)self + 136);
    fn_8020c5c4((Ptr32<char>)self + 132);
    fn_80341588((Ptr32<char>)self + 132);
    fn_8020c5c4((Ptr32<char>)self + 128);
    fn_80341588((Ptr32<char>)self + 128);
    fn_8020c5c4((Ptr32<char>)self + 124);
    fn_80341588((Ptr32<char>)self + 124);
    fn_8020c5c4((Ptr32<char>)self + 120);
    fn_80341588((Ptr32<char>)self + 120);
    fn_8020c5c4((Ptr32<char>)self + 116);
    fn_80341588((Ptr32<char>)self + 116);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80221fa4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a4b0;
    fn_8020c5c4((Ptr32<char>)self + 136);
    fn_80341588((Ptr32<char>)self + 136);
    fn_8020c5c4((Ptr32<char>)self + 132);
    fn_80341588((Ptr32<char>)self + 132);
    fn_8020c5c4((Ptr32<char>)self + 128);
    fn_80341588((Ptr32<char>)self + 128);
    fn_8020c5c4((Ptr32<char>)self + 124);
    fn_80341588((Ptr32<char>)self + 124);
    fn_8020c5c4((Ptr32<char>)self + 120);
    fn_80341588((Ptr32<char>)self + 120);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_802224f8(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a488;
    fn_8020c5c4((Ptr32<char>)self + 140);
    fn_80341588((Ptr32<char>)self + 140);
    fn_8020c5c4((Ptr32<char>)self + 136);
    fn_80341588((Ptr32<char>)self + 136);
    fn_8020c5c4((Ptr32<char>)self + 132);
    fn_80341588((Ptr32<char>)self + 132);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80222d14(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a438;
    fn_8020c5c4((Ptr32<char>)self + 144);
    fn_80341588((Ptr32<char>)self + 144);
    fn_8020c5c4((Ptr32<char>)self + 140);
    fn_80341588((Ptr32<char>)self + 140);
    fn_8020c5c4((Ptr32<char>)self + 136);
    fn_80341588((Ptr32<char>)self + 136);
    fn_8020c5c4((Ptr32<char>)self + 132);
    fn_80341588((Ptr32<char>)self + 132);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_802232cc(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a410;
    fn_8020c5c4((Ptr32<char>)self + 168);
    fn_80341588((Ptr32<char>)self + 168);
    fn_8020c5c4((Ptr32<char>)self + 164);
    fn_80341588((Ptr32<char>)self + 164);
    fn_8020c5c4((Ptr32<char>)self + 160);
    fn_80341588((Ptr32<char>)self + 160);
    fn_8020c5c4((Ptr32<char>)self + 156);
    fn_80341588((Ptr32<char>)self + 156);
    fn_8020c5c4((Ptr32<char>)self + 152);
    fn_80341588((Ptr32<char>)self + 152);
    fn_8020c5c4((Ptr32<char>)self + 124);
    fn_80341588((Ptr32<char>)self + 124);
    fn_8020c5c4((Ptr32<char>)self + 120);
    fn_80341588((Ptr32<char>)self + 120);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_802239d4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a3e8;
    fn_8020c5c4((Ptr32<char>)self + 156);
    fn_80341588((Ptr32<char>)self + 156);
    fn_8020c5c4((Ptr32<char>)self + 152);
    fn_80341588((Ptr32<char>)self + 152);
    fn_8020c5c4((Ptr32<char>)self + 148);
    fn_80341588((Ptr32<char>)self + 148);
    fn_8020c5c4((Ptr32<char>)self + 144);
    fn_80341588((Ptr32<char>)self + 144);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80223fd8(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a3c0;
    fn_8020c5c4((Ptr32<char>)self + 152);
    fn_80341588((Ptr32<char>)self + 152);
    fn_8020c5c4((Ptr32<char>)self + 148);
    fn_80341588((Ptr32<char>)self + 148);
    fn_8020c5c4((Ptr32<char>)self + 144);
    fn_80341588((Ptr32<char>)self + 144);
    fn_8020c5c4((Ptr32<char>)self + 140);
    fn_80341588((Ptr32<char>)self + 140);
    fn_8020c5c4((Ptr32<char>)self + 136);
    fn_80341588((Ptr32<char>)self + 136);
    fn_8020c5c4((Ptr32<char>)self + 132);
    fn_80341588((Ptr32<char>)self + 132);
    fn_8020c5c4((Ptr32<char>)self + 128);
    fn_80341588((Ptr32<char>)self + 128);
    fn_8020c5c4((Ptr32<char>)self + 120);
    fn_80341588((Ptr32<char>)self + 120);
    fn_8020c5c4((Ptr32<char>)self + 116);
    fn_80341588((Ptr32<char>)self + 116);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_802247c4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a398;
    fn_8020c5c4((Ptr32<char>)self + 148);
    fn_80341588((Ptr32<char>)self + 148);
    fn_8020c5c4((Ptr32<char>)self + 144);
    fn_80341588((Ptr32<char>)self + 144);
    fn_8020c5c4((Ptr32<char>)self + 140);
    fn_80341588((Ptr32<char>)self + 140);
    fn_8020c5c4((Ptr32<char>)self + 136);
    fn_80341588((Ptr32<char>)self + 136);
    fn_8020c5c4((Ptr32<char>)self + 120);
    fn_80341588((Ptr32<char>)self + 120);
    fn_8020c5c4((Ptr32<char>)self + 116);
    fn_80341588((Ptr32<char>)self + 116);
    fn_8021f234(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80224e00(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a370;
    fn_8020c5c4((Ptr32<char>)self + 180);
    fn_80341588((Ptr32<char>)self + 180);
    fn_8020c5c4((Ptr32<char>)self + 176);
    fn_80341588((Ptr32<char>)self + 176);
    fn_8020c5c4((Ptr32<char>)self + 172);
    fn_80341588((Ptr32<char>)self + 172);
    fn_8020c5c4((Ptr32<char>)self + 168);
    fn_80341588((Ptr32<char>)self + 168);
    fn_8020c5c4((Ptr32<char>)self + 156);
    fn_80341588((Ptr32<char>)self + 156);
    fn_802224f8(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_802259e4(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a2d0;
    fn_8020c5c4((Ptr32<char>)self + 40);
    fn_80341588((Ptr32<char>)self + 40);
    fn_8020c5c4((Ptr32<char>)self + 36);
    fn_80341588((Ptr32<char>)self + 36);
    fn_8020c5c4((Ptr32<char>)self + 32);
    fn_80341588((Ptr32<char>)self + 32);
    fn_8020c5c4((Ptr32<char>)self + 28);
    fn_80341588((Ptr32<char>)self + 28);
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80226224(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a280;
    fn_8020c5c4((Ptr32<char>)self + 40);
    fn_80341588((Ptr32<char>)self + 40);
    if (FIELD(self, void *, 24)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 24)->vtable[4])(FIELD(self, W3dInterface *, 24));
    }
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80226eb8(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a1b8;
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80227560(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a168;
    fn_8020c5c4((Ptr32<char>)self + 60);
    fn_80341588((Ptr32<char>)self + 60);
    if (FIELD(self, void *, 56)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 56)->vtable[4])(FIELD(self, W3dInterface *, 56));
    }
    if (FIELD(self, void *, 52)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 52)->vtable[4])(FIELD(self, W3dInterface *, 52));
    }
    fn_8020c5c4((Ptr32<char>)self + 28);
    fn_80341588((Ptr32<char>)self + 28);
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    fn_8020c5c4((Ptr32<char>)self + 20);
    fn_80341588((Ptr32<char>)self + 20);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80229944(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a0f0;
    fn_8020c5c4((Ptr32<char>)self + 40);
    fn_80341588((Ptr32<char>)self + 40);
    fn_8020c5c4((Ptr32<char>)self + 32);
    fn_80341588((Ptr32<char>)self + 32);
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8022c414(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a000;
    fn_8020c5c4((Ptr32<char>)self + 40);
    fn_80341588((Ptr32<char>)self + 40);
    fn_8020c5c4((Ptr32<char>)self + 36);
    fn_80341588((Ptr32<char>)self + 36);
    fn_8020c5c4((Ptr32<char>)self + 32);
    fn_80341588((Ptr32<char>)self + 32);
    fn_8020c5c4((Ptr32<char>)self + 28);
    fn_80341588((Ptr32<char>)self + 28);
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8022c92c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419fd8;
    fn_8020c5c4((Ptr32<char>)self + 28);
    fn_80341588((Ptr32<char>)self + 28);
    fn_8020c5c4((Ptr32<char>)self + 24);
    fn_80341588((Ptr32<char>)self + 24);
    fn_8020c5c4((Ptr32<char>)self + 20);
    fn_80341588((Ptr32<char>)self + 20);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8022d0c0(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419f88;
    fn_8020c5c4((Ptr32<char>)self + 72);
    fn_80341588((Ptr32<char>)self + 72);
    fn_8020c5c4((Ptr32<char>)self + 68);
    fn_80341588((Ptr32<char>)self + 68);
    fn_8020c5c4((Ptr32<char>)self + 64);
    fn_80341588((Ptr32<char>)self + 64);
    fn_8020c5c4((Ptr32<char>)self + 60);
    fn_80341588((Ptr32<char>)self + 60);
    fn_8020c5c4((Ptr32<char>)self + 56);
    fn_80341588((Ptr32<char>)self + 56);
    fn_8020c5c4((Ptr32<char>)self + 52);
    fn_80341588((Ptr32<char>)self + 52);
    fn_8020c5c4((Ptr32<char>)self + 48);
    fn_80341588((Ptr32<char>)self + 48);
    fn_8020c5c4((Ptr32<char>)self + 40);
    fn_80341588((Ptr32<char>)self + 40);
    fn_8020c5c4((Ptr32<char>)self + 36);
    fn_80341588((Ptr32<char>)self + 36);
    fn_8020c5c4((Ptr32<char>)self + 28);
    fn_80341588((Ptr32<char>)self + 28);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

}
