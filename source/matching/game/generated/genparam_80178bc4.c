/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct W3dInterface { void **vtable; } W3dInterface;
typedef void (*W3dInterfaceFn)(W3dInterface *self);
extern char w3d_vtable_80412630[];
extern char lbl_80413018[];
void fn_8017892c(void *self);
W3dInterface *fn_8020b680(void *key);
extern char w3d_vtable_804125e0[];
extern char lbl_80413028[];
extern char w3d_vtable_80412590[];
extern char lbl_80413048[];
extern char w3d_vtable_80412540[];
extern char lbl_80413058[];
extern char w3d_vtable_80412400[];
extern char lbl_80413078[];
extern char w3d_vtable_804124f0[];
extern char lbl_80413038[];

void *w3d_ctor_lookup_80178bc4(void *self)
{
    W3dInterface *found, *old;
    fn_8017892c(self);
    FIELD(self, void *, 0) = w3d_vtable_80412630;
    found = fn_8020b680(lbl_80413018);
    if (found)
        ((W3dInterfaceFn)found->vtable[3])(found);
    old = FIELD(self, W3dInterface *, 4);
    if (old)
        ((W3dInterfaceFn)old->vtable[4])(old);
    FIELD(self, W3dInterface *, 4) = found;
    return self;
}

void *w3d_ctor_lookup_80178c98(void *self)
{
    W3dInterface *found, *old;
    fn_8017892c(self);
    FIELD(self, void *, 0) = w3d_vtable_804125e0;
    found = fn_8020b680(lbl_80413028);
    if (found)
        ((W3dInterfaceFn)found->vtable[3])(found);
    old = FIELD(self, W3dInterface *, 4);
    if (old)
        ((W3dInterfaceFn)old->vtable[4])(old);
    FIELD(self, W3dInterface *, 4) = found;
    return self;
}

void *w3d_ctor_lookup_80178d6c(void *self)
{
    W3dInterface *found, *old;
    fn_8017892c(self);
    FIELD(self, void *, 0) = w3d_vtable_80412590;
    found = fn_8020b680(lbl_80413048);
    if (found)
        ((W3dInterfaceFn)found->vtable[3])(found);
    old = FIELD(self, W3dInterface *, 4);
    if (old)
        ((W3dInterfaceFn)old->vtable[4])(old);
    FIELD(self, W3dInterface *, 4) = found;
    return self;
}

void *w3d_ctor_lookup_80178e40(void *self)
{
    W3dInterface *found, *old;
    fn_8017892c(self);
    FIELD(self, void *, 0) = w3d_vtable_80412540;
    found = fn_8020b680(lbl_80413058);
    if (found)
        ((W3dInterfaceFn)found->vtable[3])(found);
    old = FIELD(self, W3dInterface *, 4);
    if (old)
        ((W3dInterfaceFn)old->vtable[4])(old);
    FIELD(self, W3dInterface *, 4) = found;
    return self;
}

void *w3d_ctor_lookup_80178ed0(void *self)
{
    W3dInterface *found, *old;
    fn_8017892c(self);
    FIELD(self, void *, 0) = w3d_vtable_80412400;
    found = fn_8020b680(lbl_80413078);
    if (found)
        ((W3dInterfaceFn)found->vtable[3])(found);
    old = FIELD(self, W3dInterface *, 4);
    if (old)
        ((W3dInterfaceFn)old->vtable[4])(old);
    FIELD(self, W3dInterface *, 4) = found;
    return self;
}

void *w3d_ctor_lookup_80179038(void *self)
{
    W3dInterface *found, *old;
    fn_8017892c(self);
    FIELD(self, void *, 0) = w3d_vtable_804124f0;
    found = fn_8020b680(lbl_80413038);
    if (found)
        ((W3dInterfaceFn)found->vtable[3])(found);
    old = FIELD(self, W3dInterface *, 4);
    if (old)
        ((W3dInterfaceFn)old->vtable[4])(old);
    FIELD(self, W3dInterface *, 4) = found;
    return self;
}
