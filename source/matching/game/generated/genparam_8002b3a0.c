/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_8040e368[];
void fn_8015ff2c(void *self, int flags);
extern char w3d_vtable_8040e6d8[];
extern char w3d_vtable_8040e878[];
extern char w3d_vtable_8040fcc8[];
extern char w3d_vtable_8040fe00[];
extern char w3d_vtable_804102a8[];
void fn_801628ec(void *self, int flags);
extern char w3d_vtable_804103a8[];
extern char w3d_vtable_80410560[];
void fn_8002a978(void *self, int flags);
extern char w3d_vtable_80412120[];
void fn_80190384(void *self, int flags);
extern char w3d_vtable_80419cb0[];

void w3d_dtor_forward_8002b3a0(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8040e368;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_8003a4e0(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8040e6d8;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_8003d3cc(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8040e878;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800d53ac(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8040fcc8;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800da2a0(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8040fe00;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800efbb4(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_804102a8;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801628ec(self, flags);
}

void w3d_dtor_forward_800f1e88(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_804103a8;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800fe3a8(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80410560;
    held = FIELD(self, W3dInterface *, 64);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8002a978(self, flags);
}

void w3d_dtor_forward_80174354(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80412120;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_80190384(self, flags);
}

void w3d_dtor_forward_8021cc18(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80419cb0;
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801628ec(self, flags);
}
