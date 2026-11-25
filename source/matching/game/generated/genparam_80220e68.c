/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern char w3d_vtable_8041a528[];
extern int lbl_804b06a0[];
int fn_8021ef08(void *self, void *);
void fn_8020c5c0(void *string);
unsigned short *fn_80341884(void *string);
extern char w3d_vtable_8041a8d8[];
void * fn_801ea0ec(void *self, int);
extern char w3d_vtable_8041a770[];
extern char w3d_vtable_8041a720[];
extern char w3d_vtable_8041abd0[];
int fn_8023b59c(void *self, void *);
extern char w3d_vtable_8041ab80[];
int fn_8023d32c(void *self, void *);
extern char w3d_vtable_8041ab58[];
int fn_8023d574(void *self, void *);

void *w3d_ctor_strings_80220e68(void *self, void * arg_r4)
{
    fn_8021ef08(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041a528;
    fn_8020c5c0((char *)self + 116);
    FIELD(self, int, 116) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 116))++;
    fn_8020c5c0((char *)self + 120);
    FIELD(self, int, 120) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 120))++;
    return self;
}

void *w3d_ctor_strings_80235bc0(void *self, void * arg_r4)
{
    fn_801ea0ec(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041a8d8;
    fn_8020c5c0((char *)self + 20);
    FIELD(self, int, 20) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 20))++;
    fn_8020c5c0((char *)self + 24);
    FIELD(self, int, 24) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 24))++;
    return self;
}

void *w3d_ctor_strings_80237438(void *self, void * arg_r4)
{
    fn_801ea0ec(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041a770;
    fn_8020c5c0((char *)self + 20);
    FIELD(self, int, 20) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 20))++;
    fn_8020c5c0((char *)self + 24);
    FIELD(self, int, 24) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 24))++;
    return self;
}

void *w3d_ctor_strings_802379a0(void *self, void * arg_r4)
{
    fn_801ea0ec(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041a720;
    fn_8020c5c0((char *)self + 20);
    FIELD(self, int, 20) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 20))++;
    fn_8020c5c0((char *)self + 24);
    FIELD(self, int, 24) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 24))++;
    return self;
}

void *w3d_ctor_strings_8023d6dc(void *self, void * arg_r4)
{
    fn_8023b59c(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041abd0;
    fn_8020c5c0((char *)self + 28);
    FIELD(self, int, 28) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 28))++;
    fn_8020c5c0((char *)self + 32);
    FIELD(self, int, 32) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 32))++;
    return self;
}

void *w3d_ctor_strings_8023db50(void *self, void * arg_r4)
{
    fn_8023d32c(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041ab80;
    fn_8020c5c0((char *)self + 32);
    FIELD(self, int, 32) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 32))++;
    fn_8020c5c0((char *)self + 36);
    FIELD(self, int, 36) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 36))++;
    return self;
}

void *w3d_ctor_strings_8023de5c(void *self, void * arg_r4)
{
    fn_8023d574(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041ab58;
    fn_8020c5c0((char *)self + 28);
    FIELD(self, int, 28) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 28))++;
    fn_8020c5c0((char *)self + 32);
    FIELD(self, int, 32) = lbl_804b06a0[0];
    (*fn_80341884((char *)self + 32))++;
    return self;
}
