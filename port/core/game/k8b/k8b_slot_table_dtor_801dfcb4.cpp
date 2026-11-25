#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_slot_table_dtor_801dfcb4.c"
typedef struct K8bObject { Ptr32<Ptr32<void>> vtable; } K8bObject;
typedef struct K8bSlotObject { char pad0[28]; Ptr32<Ptr32<void>> secondary; } K8bSlotObject;
extern char lbl_80416cc8[];
extern char lbl_80416d78[];
extern Ptr32<void> lbl_804ab834;
extern void w3d_auto_801e6ec4(Ptr32<char> list, int mode);
extern void w3d_handle_storage_release(Ptr32<void> block);
extern void w3d_actor_node_destroy(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);

void w3d_k8b_slot_table_dtor_801dfcb4(Ptr32<char> self, unsigned int flags)
{
    unsigned int i = 0;
    Ptr32<Ptr32<K8bSlotObject>> slot = (Ptr32<Ptr32<K8bSlotObject>>)(self + 48);
    *(Ptr32<Ptr32<char>>)self = lbl_80416cc8;
    do {
        Ptr32<K8bSlotObject> item = *slot++;
        if (item)
            ((Ptr32<void (Ptr32<K8bSlotObject>, int)>)item->secondary[2])(item, 3);
        i++;
    } while (i <= 31);
    {
        Ptr32<void> zero = 0;
        Ptr32<K8bObject> held = *(Ptr32<Ptr32<K8bObject>>)(self + 20);
        if (held)
            ((Ptr32<void (Ptr32<K8bObject>)>)held->vtable[4])(held);
        *(Ptr32<Ptr32<void>>)(self + 20) = zero;
        lbl_804ab834 = zero;
    }
    w3d_auto_801e6ec4(self + 176, 2);
    if (*(Ptr32<Ptr32<void>>)(self + 36))
        w3d_handle_storage_release(*(Ptr32<Ptr32<void>>)(self + 36));
    if (*(Ptr32<Ptr32<K8bObject>>)(self + 20))
        ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 20))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 20));
    *(Ptr32<Ptr32<char>>)self = lbl_80416d78;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
