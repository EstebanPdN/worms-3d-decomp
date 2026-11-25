typedef struct K8bObject { void **vtable; } K8bObject;
typedef struct K8bSlotObject { char pad0[28]; void **secondary; } K8bSlotObject;
extern char lbl_80416cc8[];
extern char lbl_80416d78[];
extern void *lbl_804ab834;
extern void w3d_auto_801e6ec4(char *list, int mode);
extern void w3d_handle_storage_release(void *block);
extern void w3d_actor_node_destroy(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

void w3d_k8b_slot_table_dtor_801dfcb4(char *self, unsigned int flags)
{
    unsigned int i = 0;
    K8bSlotObject **slot = (K8bSlotObject **)(self + 48);
    *(char **)self = lbl_80416cc8;
    do {
        K8bSlotObject *item = *slot++;
        if (item)
            ((void (*)(K8bSlotObject *, int))item->secondary[2])(item, 3);
        i++;
    } while (i <= 31);
    {
        void *zero = 0;
        K8bObject *held = *(K8bObject **)(self + 20);
        if (held)
            ((void (*)(K8bObject *))held->vtable[4])(held);
        *(void **)(self + 20) = zero;
        lbl_804ab834 = zero;
    }
    w3d_auto_801e6ec4(self + 176, 2);
    if (*(void **)(self + 36))
        w3d_handle_storage_release(*(void **)(self + 36));
    if (*(K8bObject **)(self + 20))
        ((void (*)(K8bObject *))(*(K8bObject **)(self + 20))->vtable[4])(*(K8bObject **)(self + 20));
    *(char **)self = lbl_80416d78;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
