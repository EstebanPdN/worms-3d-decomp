struct K4bIface { void **vtable; };
struct K4bService {
    void **vtable;
    char base[16];
    struct K4bIface *shared;
    int count;
};
extern struct K4bIface *lbl_804b05ac;
extern void *lbl_80414d80[];
extern struct K4bService *w3d_tagged_construct_801ea0ec(struct K4bService *object, int);
struct K4bService *w3d_k4b_service_construct_801c1ef8(struct K4bService *self, void * arg_r4)
{
    struct K4bIface *shared;
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    shared = lbl_804b05ac;
    self->vtable = lbl_80414d80;
    self->shared = shared;
    if (shared != 0)
        ((void (*)(struct K4bIface *))shared->vtable[3])(shared);
    self->count = 0;
    return self;
}
// desc: w3d_k4b_service_construct_801c1ef8: Appears to construct an object over base 0x801ea0ec, install vtable 0x80414d80, retain a shared global interface into +20 and clear the word at +24.
