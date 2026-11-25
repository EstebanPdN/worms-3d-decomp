/* Deleting destructors synthesized by tools/gen_dtor_units.py and verified
 * identical to the original after linking. Offsets are literal and externs are
 * named by original address; member types and class names are pending. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_8041a810[];
void fn_8020c5c4(void *);
void fn_80341588(void *);
void fn_801ea138(void *, int);
void fn_801ea740(void *);
extern char w3d_vtable_8041ae50[];
void fn_8020803c(void *, int);
extern char w3d_vtable_8041ac48[];
void fn_8023b5f0(void *, int);
extern char w3d_vtable_8041b7d0[];
void fn_801b4ef0(void *, int);
extern char w3d_vtable_8041b780[];
extern char w3d_vtable_8041ba18[];
void fn_8025518c(void *, int);
extern char w3d_vtable_8041b9f0[];
void fn_802523b4(void *, int);
extern char w3d_vtable_8041b9c8[];

void w3d_dtor_802367cc(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041a810;
    fn_8020c5c4((char *)self + 52);
    fn_80341588((char *)self + 52);
    fn_8020c5c4((char *)self + 48);
    fn_80341588((char *)self + 48);
    fn_8020c5c4((char *)self + 44);
    fn_80341588((char *)self + 44);
    fn_8020c5c4((char *)self + 28);
    fn_80341588((char *)self + 28);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8023a934(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041ae50;
    if (FIELD(self, void *, 36)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 36)->vtable[4])(FIELD(self, W3dInterface *, 36));
    }
    fn_8020803c((char *)self + 76, 2);
    fn_8020c5c4((char *)self + 68);
    fn_80341588((char *)self + 68);
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8023cc94(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041ac48;
    if (FIELD(self, void *, 264)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 264)->vtable[4])(FIELD(self, W3dInterface *, 264));
    }
    fn_8020c5c4((char *)self + 260);
    fn_80341588((char *)self + 260);
    fn_8020c5c4((char *)self + 256);
    fn_80341588((char *)self + 256);
    fn_8023b5f0(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8024e108(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041b7d0;
    fn_8020c5c4((char *)self + 188);
    fn_80341588((char *)self + 188);
    if (FIELD(self, void *, 184)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 184)->vtable[4])(FIELD(self, W3dInterface *, 184));
    }
    if (FIELD(self, void *, 172)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 172)->vtable[4])(FIELD(self, W3dInterface *, 172));
    }
    if (FIELD(self, void *, 168)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 168)->vtable[4])(FIELD(self, W3dInterface *, 168));
    }
    if (FIELD(self, void *, 148)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 148)->vtable[4])(FIELD(self, W3dInterface *, 148));
    }
    if (FIELD(self, void *, 144)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 144)->vtable[4])(FIELD(self, W3dInterface *, 144));
    }
    fn_801b4ef0(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_8024eee4(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041b780;
    fn_8020c5c4((char *)self + 24);
    fn_80341588((char *)self + 24);
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    fn_801ea138(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80255770(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041ba18;
    fn_8020c5c4((char *)self + 604);
    fn_80341588((char *)self + 604);
    fn_8020c5c4((char *)self + 600);
    fn_80341588((char *)self + 600);
    fn_8020c5c4((char *)self + 596);
    fn_80341588((char *)self + 596);
    fn_8020c5c4((char *)self + 592);
    fn_80341588((char *)self + 592);
    fn_8020c5c4((char *)self + 588);
    fn_80341588((char *)self + 588);
    fn_8020c5c4((char *)self + 584);
    fn_80341588((char *)self + 584);
    fn_8020c5c4((char *)self + 580);
    fn_80341588((char *)self + 580);
    fn_8025518c(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80256050(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041b9f0;
    fn_8020c5c4((char *)self + 280);
    fn_80341588((char *)self + 280);
    fn_8020c5c4((char *)self + 276);
    fn_80341588((char *)self + 276);
    fn_8020c5c4((char *)self + 272);
    fn_80341588((char *)self + 272);
    fn_8020c5c4((char *)self + 268);
    fn_80341588((char *)self + 268);
    fn_8020c5c4((char *)self + 264);
    fn_80341588((char *)self + 264);
    fn_8020c5c4((char *)self + 260);
    fn_80341588((char *)self + 260);
    fn_8020c5c4((char *)self + 256);
    fn_80341588((char *)self + 256);
    fn_8020c5c4((char *)self + 252);
    fn_80341588((char *)self + 252);
    fn_8020c5c4((char *)self + 248);
    fn_80341588((char *)self + 248);
    fn_802523b4(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}

void w3d_dtor_80256a98(void *self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041b9c8;
    fn_8020c5c4((char *)self + 228);
    fn_80341588((char *)self + 228);
    fn_8020c5c4((char *)self + 224);
    fn_80341588((char *)self + 224);
    fn_8020c5c4((char *)self + 220);
    fn_80341588((char *)self + 220);
    fn_8020c5c4((char *)self + 216);
    fn_80341588((char *)self + 216);
    fn_802523b4(self, 0);
    if (flags & 1) {
        fn_801ea740(self);
    }
}
