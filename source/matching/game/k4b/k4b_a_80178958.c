struct K4bIface { void **vtable; };
struct K4bHolder {
    void **vtable;
    struct K4bIface *held;
    unsigned char slot;
};
extern void *w3d_vtable_80412680[];
extern void w3d_actor_member_delete_backend(void *p);
void w3d_k4b_holder_delete_80178958(struct K4bHolder *self, int flags)
{
    struct K4bIface *held;
    struct K4bIface *none;
    self->vtable = w3d_vtable_80412680;
    held = self->held;
    none = 0;
    if (held != none)
        ((void (*)(struct K4bIface *))held->vtable[4])(held);
    self->held = none;
    self->slot = 255;
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
// desc: w3d_k4b_holder_delete_80178958: Appears to be a deleting destructor that releases a held interface through its fifth slot, clears it, marks the slot byte 255 and frees the object when flag bit one is set.
