/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_80414528[];
void fn_801b4c6c(void *self, int flags);
void fn_801ea740(void *self);
extern char w3d_vtable_80415618[];
void fn_801b8964(void *self, int flags);
extern char w3d_vtable_80414ce0[];
extern char w3d_vtable_80414c40[];
void fn_801ea138(void *self, int flags);
extern char w3d_vtable_80416398[];
void fn_801c9134(void *self, int flags);
extern char w3d_vtable_804162d0[];
void fn_801c939c(void *self, int flags);
extern char w3d_vtable_8041a0c8[];
extern char w3d_vtable_8041ae28[];
extern char w3d_vtable_8041ad88[];
void fn_8023b5f0(void *self, int flags);
extern char w3d_vtable_8041ad10[];
void fn_8023b7b4(void *self, int flags);
extern char w3d_vtable_8041acc0[];

void w3d_dtor_interfaces_801b5454(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80414528;
    held = FIELD(self, W3dInterface *, 52);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 48);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b4c6c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801b998c(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80415618;
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 20);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b8964(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801c33c8(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80414ce0;
    held = FIELD(self, W3dInterface *, 60);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 44);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b4c6c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801c3fdc(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80414c40;
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 20);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801ea138(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801c939c(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80416398;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801c9134(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801ca2d0(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_804162d0;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801c939c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_80229cfc(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8041a0c8;
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 20);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801ea138(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023ac9c(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8041ae28;
    held = FIELD(self, W3dInterface *, 56);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 60);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801ea138(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023b7b4(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8041ad88;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8023b5f0(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023bf78(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8041ad10;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8023b7b4(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023c4ec(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8041acc0;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8023b7b4(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}
