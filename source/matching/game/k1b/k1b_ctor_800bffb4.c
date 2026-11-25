// func: w3d_k1b_ctor_800bffb4 0x800bffb4
// desc: Appears to construct an object of a class derived from the base at 0x801628b0, installing its vtable and clearing two fields.
struct K1bObj800bffb4 { void *vt; int pad4[6]; int f28; int f32; };
extern unsigned char lbl_8040f8a8[];
extern int lbl_804aada8;
extern short lbl_804b185c;
extern int w3d_ctor_801628b0(void *);
struct K1bObj800bffb4 *w3d_k1b_ctor_800bffb4(struct K1bObj800bffb4 *p)
{
    int c;
    w3d_ctor_801628b0(p);
    c = lbl_804aada8;
    p->vt = (void *)lbl_8040f8a8;
    p->f28 = 0;
    p->f32 = 0;
    if (c == 0) lbl_804b185c = c;
    return p;
}
