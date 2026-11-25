typedef struct K8bIface { void (**vtable)(struct K8bIface *); } K8bIface;
struct K8bMatrix { int words[16]; };
struct K8bObject { void *vtable; char pad4[16]; struct K8bMatrix matrix; K8bIface *held; };
extern struct K8bObject *w3d_ctor_801b529c(struct K8bObject *self, void *);
extern char lbl_80414e70[];
extern struct K8bMatrix lbl_8045e708[];
extern K8bIface *lbl_804b05ac;

struct K8bObject *w3d_k8b_matrix_object_801c03bc(struct K8bObject *self, void * arg_r4)
{
    w3d_ctor_801b529c(self, arg_r4);
    self->vtable = lbl_80414e70;
    self->matrix = lbl_8045e708[0];
    {
        K8bIface *held = lbl_804b05ac;
        self->held = held;
        if (held)
            held->vtable[3](held);
    }
    return self;
}
