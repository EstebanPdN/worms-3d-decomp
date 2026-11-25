typedef struct K8bObject { void **vtable; } K8bObject;
extern void w3d_actor_node_destroy(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);
extern int w3d_task_deferred_clear(char *list);
extern void w3d_auto_80210abc(char *list, int mode);
extern void lua_close(void *state);
extern char lbl_80413760[];
extern char lbl_804137b0[];

void w3d_k8b_lua_owner_dtor_8019dafc(char *self, int flags)
{
    K8bObject *held = *(K8bObject **)(self + 36);
    *(char **)self = lbl_80413760;
    if (held != 0)
        ((void (*)(K8bObject *))held->vtable[4])(held);
    {
        int zero = 0;
        char *list = self + 24;
        *(int *)(self + 36) = zero;
        w3d_task_deferred_clear(list);
        if (*(void **)(self + 20) != 0)
            lua_close(*(void **)(self + 20));
        if (*(K8bObject **)(self + 36) != 0)
            ((void (*)(K8bObject *))(*(K8bObject **)(self + 36))->vtable[4])(*(K8bObject **)(self + 36));
        w3d_auto_80210abc(list, 2);
    }
    *(char **)self = lbl_804137b0;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
