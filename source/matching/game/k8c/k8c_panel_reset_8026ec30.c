struct K8cHeld;
struct K8cHeldVtable { void *slots[4]; void (*release)(struct K8cHeld *self); };
struct K8cHeld { struct K8cHeldVtable *vtable; };
struct K8cPanel {
    char pad00[28];
    char body[184];
    struct K8cHeld *held;
    char pad_d8[72];
    void *handle;
};
extern void fn_8015fd1c(void *handle);
extern void fn_8027035c(struct K8cPanel *self, int a, int b);
extern void fn_802b0fec(void *body);
void w3d_k8c_panel_reset_8026ec30(struct K8cPanel *self)
{
    int zero = 0;
    if (self->held)
        self->held->vtable->release(self->held);
    self->held = (struct K8cHeld *)zero;
    if (self->handle) {
        fn_8015fd1c(self->handle);
        self->handle = (void *)zero;
    }
    fn_8027035c(self, 1, 1);
    fn_802b0fec(self->body);
}
extern char w3d_vtable_8041bdf0[];
extern char w3d_vtable_8041be40[];
extern void fn_802afc40(void *body, int flags);
extern void fn_8015ff2c(struct K8cPanel *self, int flags);
void w3d_k8c_panel_destroy_80270698(struct K8cPanel *self, int flags)
{
    *(void **)((char *)self + 208) = w3d_vtable_8041bdf0;
    *(void **)self = w3d_vtable_8041be40;
    if (self->held)
        self->held->vtable->release(self->held);
    fn_802afc40(self->body, 0);
    fn_8015ff2c(self, flags);
}
