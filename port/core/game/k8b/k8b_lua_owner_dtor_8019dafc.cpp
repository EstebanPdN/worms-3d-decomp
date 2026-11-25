#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_lua_owner_dtor_8019dafc.c"
typedef struct K8bObject { Ptr32<Ptr32<void>> vtable; } K8bObject;
extern void w3d_actor_node_destroy(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);
extern int w3d_task_deferred_clear(Ptr32<char> list);
extern void w3d_auto_80210abc(Ptr32<char> list, int mode);
extern void lua_close(Ptr32<void> state);
extern char lbl_80413760[];
extern char lbl_804137b0[];

void w3d_k8b_lua_owner_dtor_8019dafc(Ptr32<char> self, int flags)
{
    Ptr32<K8bObject> held = *(Ptr32<Ptr32<K8bObject>>)(self + 36);
    *(Ptr32<Ptr32<char>>)self = lbl_80413760;
    if (held != 0)
        ((Ptr32<void (Ptr32<K8bObject>)>)held->vtable[4])(held);
    {
        int zero = 0;
        Ptr32<char> list = self + 24;
        *(Ptr32<int>)(self + 36) = zero;
        w3d_task_deferred_clear(list);
        if (*(Ptr32<Ptr32<void>>)(self + 20) != 0)
            lua_close(*(Ptr32<Ptr32<void>>)(self + 20));
        if (*(Ptr32<Ptr32<K8bObject>>)(self + 36) != 0)
            ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 36))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 36));
        w3d_auto_80210abc(list, 2);
    }
    *(Ptr32<Ptr32<char>>)self = lbl_804137b0;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
