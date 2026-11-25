#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_holder_dtor_801dde90.c"
struct K8bIface { Ptr32<Ptr32<void (Ptr32<struct K8bIface>)>> vtable; };
struct K8bList { int count; int capacity; Ptr32<Ptr32<struct K8bIface>> items; };
extern char lbl_80416a10[];
extern char lbl_80411590[];
extern void w3d_string_base_finish(Ptr32<void> string);
extern void w3d_string_release(Ptr32<void> string);
extern void w3d_auto_80210abc(Ptr32<void> list, int mode);
extern void w3d_actor_node_destroy(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);

void w3d_k8b_holder_dtor_801dde90(Ptr32<char> self, unsigned int flags)
{
    int i;
    *(Ptr32<Ptr32<void>>)self = lbl_80416a10;
    for (i = ((Ptr32<struct K8bList>)(self + 20))->count - 1; i >= 0; i--) {
        Ptr32<struct K8bList> list = (Ptr32<struct K8bList>)(self + 20);
        Ptr32<Ptr32<struct K8bIface>> items = list->items;
        Ptr32<struct K8bIface> item = items[i];
        Ptr32<void> zero = 0;
        if (item)
            item->vtable[4](item);
        items[i] = zero;
    }
    {
        Ptr32<void> name = self + 32;
        Ptr32<void> storage = self + 20;
        w3d_string_base_finish(name);
        w3d_string_release(name);
        w3d_auto_80210abc(storage, 2);
    }
    *(Ptr32<Ptr32<void>>)self = lbl_80411590;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
