struct K7aTriple
{
    int first;
    int second;
    int third;
    void clear() { third = 0; second = 0; first = 0; }
};

struct K7aComponent
{
    const void *vtable;          // +0
    char pad4[24];
    int link_28;                 // +28
    char pad32[4];
    int field_36;                // +36
    int field_40;                // +40
    char pad44[12];
    int field_56;                // +56
    int slot;                    // +60
    K7aTriple counts;            // +64
    int mode;                    // +76
};

extern "C" const void *w3d_vtable_8040f310[];
extern "C" K7aComponent *w3d_component_instance_804aabd4;
extern "C" int w3d_ctor_801628b0(void *object);

extern "C" K7aComponent *w3d_k7a_component_construct_80098bb8(K7aComponent *self)
{
    w3d_ctor_801628b0(self);
    self->vtable = w3d_vtable_8040f310;
    self->counts.clear();
    w3d_component_instance_804aabd4 = self;
    self->slot = -1;
    self->field_40 = 0;
    self->field_36 = 0;
    self->field_56 = 0;
    self->link_28 = 0;
    self->mode = 7;
    return self;
}
