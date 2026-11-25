/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_80413530[];
void fn_801ea138(void *self, int flags);
void fn_801ea740(void *self);
extern char w3d_vtable_80415348[];
void fn_801bbb70(void *self, int flags);
extern char w3d_vtable_80416280[];
void fn_801c9134(void *self, int flags);
extern char w3d_vtable_8041b848[];
void fn_8024c144(void *self, int flags);
extern char w3d_vtable_8041b7a8[];
void fn_801b4c6c(void *self, int flags);

void w3d_dtor_interfaces4_8019b7ac(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80413530;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
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

void w3d_dtor_interfaces4_801bc1a8(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80415348;
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801bbb70(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces4_801cac04(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_80416280;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
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

void w3d_dtor_interfaces4_8024d594(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8041b848;
    held = FIELD(self, W3dInterface *, 464);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 480);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 476);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 472);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8024c144(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces4_8024ea3c(void *self, int flags)
{
    W3dInterface *held;
    FIELD(self, void *, 0) = w3d_vtable_8041b7a8;
    held = FIELD(self, W3dInterface *, 56);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 52);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 48);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 44);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b4c6c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}
