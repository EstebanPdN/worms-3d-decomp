struct K8bIface { void (**vtable)(struct K8bIface *); };
struct K8bList { int count; int capacity; struct K8bIface **items; };
extern char lbl_80416a10[];
extern char lbl_80411590[];
extern void w3d_string_base_finish(void *string);
extern void w3d_string_release(void *string);
extern void w3d_auto_80210abc(void *list, int mode);
extern void w3d_actor_node_destroy(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

void w3d_k8b_holder_dtor_801dde90(char *self, unsigned int flags)
{
    int i;
    *(void **)self = lbl_80416a10;
    for (i = ((struct K8bList *)(self + 20))->count - 1; i >= 0; i--) {
        struct K8bList *list = (struct K8bList *)(self + 20);
        struct K8bIface **items = list->items;
        struct K8bIface *item = items[i];
        void *zero = 0;
        if (item)
            item->vtable[4](item);
        items[i] = zero;
    }
    {
        void *name = self + 32;
        void *storage = self + 20;
        w3d_string_base_finish(name);
        w3d_string_release(name);
        w3d_auto_80210abc(storage, 2);
    }
    *(void **)self = lbl_80411590;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
