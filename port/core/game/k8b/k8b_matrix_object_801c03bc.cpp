#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_matrix_object_801c03bc.c"
typedef struct K8bIface { Ptr32<Ptr32<void (Ptr32<struct K8bIface>)>> vtable; } K8bIface;
struct K8bMatrix { int words[16]; };
struct K8bObject { Ptr32<void> vtable; char pad4[16]; struct K8bMatrix matrix; Ptr32<K8bIface> held; };
extern Ptr32<struct K8bObject> w3d_ctor_801b529c(Ptr32<struct K8bObject> self, Ptr32<void>);
extern char lbl_80414e70[];
extern struct K8bMatrix lbl_8045e708[];
extern Ptr32<K8bIface> lbl_804b05ac;

Ptr32<struct K8bObject> w3d_k8b_matrix_object_801c03bc(Ptr32<struct K8bObject> self, Ptr32<void> arg_r4)
{
    w3d_ctor_801b529c(self, arg_r4);
    self->vtable = lbl_80414e70;
    self->matrix = lbl_8045e708[0];
    {
        Ptr32<K8bIface> held = lbl_804b05ac;
        self->held = held;
        if (held)
            held->vtable[3](held);
    }
    return self;
}

}
