/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_80415618[];
extern W3dInterface *lbl_804b05a8;
void *fn_801b8928(void *self, void *);
extern char w3d_vtable_80414c40[];
extern W3dInterface *lbl_804b05ac;
void *fn_801ea0ec(void *self, int);
extern char w3d_vtable_80416398[];
void *fn_801c90c0(void *self, void *);
extern char w3d_vtable_804162d0[];
void *fn_801c9320(void *self, void *);
extern char w3d_vtable_8041a0c8[];
extern char w3d_vtable_8041ad88[];
void *fn_8023b59c(void *self, void *);
extern char w3d_vtable_8041ad10[];
void *fn_8023b738(void *self, void *);
extern char w3d_vtable_8041acc0[];

void *w3d_ctor_held_801b9910(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_801b8928(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_80415618;
    FIELD(self, W3dInterface *, 20) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 24) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

void *w3d_ctor_held_801c3f60(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_801ea0ec(self, arg_r4);
    held = lbl_804b05ac;
    FIELD(self, void *, 0) = w3d_vtable_80414c40;
    FIELD(self, W3dInterface *, 20) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05ac;
    FIELD(self, W3dInterface *, 24) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

void *w3d_ctor_held_801c9320(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_801c90c0(self, arg_r4);
    held = lbl_804b05ac;
    FIELD(self, void *, 0) = w3d_vtable_80416398;
    FIELD(self, W3dInterface *, 28) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05ac;
    FIELD(self, W3dInterface *, 32) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

void *w3d_ctor_held_801ca254(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_801c9320(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_804162d0;
    FIELD(self, W3dInterface *, 36) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 40) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

void *w3d_ctor_held_80229c80(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_801ea0ec(self, arg_r4);
    held = lbl_804b05ac;
    FIELD(self, void *, 0) = w3d_vtable_8041a0c8;
    FIELD(self, W3dInterface *, 20) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05ac;
    FIELD(self, W3dInterface *, 24) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

void *w3d_ctor_held_8023b738(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_8023b59c(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_8041ad88;
    FIELD(self, W3dInterface *, 28) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 32) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

void *w3d_ctor_held_8023befc(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_8023b738(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_8041ad10;
    FIELD(self, W3dInterface *, 36) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 40) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

void *w3d_ctor_held_8023c470(void *self, void * arg_r4)
{
    W3dInterface *held;
    fn_8023b738(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_8041acc0;
    FIELD(self, W3dInterface *, 36) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 40) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}
