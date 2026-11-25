struct K4bIface { void **vtable; };
struct K4bService {
    void **vtable;
    char base[16];
    struct K4bIface *shared;
    unsigned short count;
};
extern struct K4bIface *lbl_804b05a8;
extern void *lbl_80415410[];
extern struct K4bService *w3d_ctor_801b87c0(struct K4bService *object, void *);
struct K4bService *w3d_k4b_service_construct_801bb678(struct K4bService *self, void * arg_r4)
{
    struct K4bIface *shared;
    w3d_ctor_801b87c0(self, arg_r4);
    shared = lbl_804b05a8;
    self->vtable = lbl_80415410;
    self->shared = shared;
    if (shared != 0)
        ((void (*)(struct K4bIface *))shared->vtable[3])(shared);
    self->count = 0;
    return self;
}
// desc: w3d_k4b_service_construct_801bb678: Appears to construct an object over base 0x801b87c0, install vtable 0x80415410, retain a shared global interface into +20 and clear the 16-bit count at +24.
