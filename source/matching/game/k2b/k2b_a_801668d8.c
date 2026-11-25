struct K2bInterface { void **vtable; };
struct K2bHolder { unsigned char pad0[40]; struct K2bInterface *held; };
extern unsigned char w3d_obj_80411a20[];
extern struct K2bInterface *w3d_auto_8020b648(void);
int w3d_k2b_replace_held_interface_801668d8(struct K2bHolder *self)
{
    struct K2bInterface *replacement;
    struct K2bInterface *registry;
    void *type = w3d_obj_80411a20;
    registry = w3d_auto_8020b648();
    replacement = ((struct K2bInterface *(*)(struct K2bInterface *, void *))registry->vtable[23])(registry, type);
    if (replacement)
        ((void (*)(struct K2bInterface *))replacement->vtable[3])(replacement);
    if (self->held)
        ((void (*)(struct K2bInterface *))self->held->vtable[4])(self->held);
    self->held = replacement;
    return 0;
}
// desc: Appears to look up an interface by type, retain it and replace the held interface after releasing the old one.
