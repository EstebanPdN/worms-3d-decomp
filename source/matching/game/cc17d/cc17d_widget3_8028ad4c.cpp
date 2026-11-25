// cc17d: widget constructor at 0x8028ad4c (family of cc17d 0x80285610 and
// cx12b 0x8025f1b8).  Observed: base constructor 0x8015fef0, member
// constructor 0x802afb20 at +28, vtables 0x8041c090 at +208 and 0x8041c0e0 at
// +0, 100 at +308 and zeroed words/arrays elsewhere.  The statement order was
// chosen by a local search over store orders (the scheduler reorders them).
struct Cc17dWidget3 { void *vtable; unsigned char opaque[204]; void *second; int w[27]; };
extern "C" void base_8015fef0(Cc17dWidget3 *);
extern "C" void member_802afb20(void *);
extern "C" unsigned char table_8041c0e0[], table_8041c090[];
extern "C" Cc17dWidget3 *w3d_cc17d_widget3_construct_8028ad4c(Cc17dWidget3 *self)
{
    base_8015fef0(self);
    member_802afb20((unsigned char *)self + 28);
    self->second = table_8041c090;
    self->vtable = table_8041c0e0;
    self->w[4] = 0;
    self->w[3] = 0;
    { int *p = &self->w[5]; int n = 3; do { *p++ = 0; } while (--n); }
    self->w[8] = 0;
    self->w[9] = 0;
    self->w[10] = 0;
    self->w[11] = 0;
    self->w[12] = 0;
    self->w[13] = 0;
    self->w[14] = 0;
    self->w[15] = 0;
    self->w[16] = 0;
    self->w[19] = 0;
    self->w[25] = 0;
    self->w[17] = 0;
    self->w[24] = 100;
    self->w[18] = 0;
    { int *p = &self->w[0]; int n = 3; do { *p++ = 0; } while (--n); }
    return self;
}
