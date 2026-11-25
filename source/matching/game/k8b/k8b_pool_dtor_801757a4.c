typedef struct K8bObject { void **vtable; } K8bObject;
extern char lbl_80412250[];
extern char lbl_80412318[];
extern int lbl_804ab5c4;
extern void w3d_k5b_slot_table_release_all_801758e8(char *self);
extern void w3d_task_array_release(void *block);
extern void w3d_handle_storage_release(void *block);
extern void w3d_actor_node_destroy(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

static inline void k8b_objects_delete(char *self, char *array)
{
    if (array) {
        K8bObject **end = (K8bObject **)(array + *(int *)(array - 8) * 4);
        if ((char *)end != array) {
            do {
                K8bObject *item = *--end;
                if (item)
                    ((void (*)(K8bObject *))item->vtable[4])(item);
                array = *(char **)(self + 24);
            } while (array != (char *)end);
        }
        w3d_task_array_release(array - 8);
    }
}

void w3d_k8b_pool_dtor_801757a4(char *self, unsigned int flags)
{
    void *buffer;
    *(char **)self = lbl_80412250;
    w3d_k5b_slot_table_release_all_801758e8(self);
    buffer = *(void **)(self + 2096);
    lbl_804ab5c4 = 0;
    if (buffer)
        w3d_task_array_release(buffer);
    {
        void *node = self + 4;
        k8b_objects_delete(self, *(char **)(self + 24));
        if (*(void **)(self + 2104))
            w3d_handle_storage_release(*(void **)(self + 2104));
        if (*(void **)(self + 28))
            w3d_handle_storage_release(*(void **)(self + 28));
        *(char **)self = lbl_80412318;
        w3d_actor_node_destroy(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
