struct K2bInputOwner { void **vtable; unsigned char pad4[24]; void *service; float a; float b; float c; float d; float e; };
extern void *w3d_vtable_804116a8[];
extern struct K2bInputOwner *w3d_input_804b17f0;
extern int w3d_ctor_801628b0(struct K2bInputOwner *self);
struct K2bInputOwner *w3d_k2b_input_owner_construct_8016030c(struct K2bInputOwner *self)
{
    w3d_ctor_801628b0(self);
    self->vtable = w3d_vtable_804116a8;
    self->service = 0;
    w3d_input_804b17f0 = self;
    self->d = 0.003125f;
    self->e = 0.004166667f;
    self->c = 0.01f;
    self->a = 0.0f;
    self->b = 0.0f;
    return self;
}
// desc: Appears to construct an input owner on its base constructor, register it as the global input owner and set default tuning values.
