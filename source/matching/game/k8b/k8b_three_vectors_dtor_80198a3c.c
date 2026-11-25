typedef struct K8bObject { void **vtable; } K8bObject;
struct K8bVector { char *begin; char *end; };
extern char lbl_80413428[];
extern char lbl_80413470[];
extern int w3d_k8b_release_all_80199c70(char *self, int mode);
extern void w3d_auto_801907d0(void *block);
extern void w3d_actor_node_destroy(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

void w3d_k8b_three_vectors_dtor_80198a3c(char *self, unsigned int flags)
{
    *(char **)self = lbl_80413428;
    w3d_k8b_release_all_80199c70(self, -1);
    if (*(K8bObject **)(self + 20))
        ((void (*)(K8bObject *))(*(K8bObject **)(self + 20))->vtable[4])(*(K8bObject **)(self + 20));
    {
        int zero = 0;
        struct K8bVector *items = (struct K8bVector *)(self + 68);
        struct K8bVector *middle = (struct K8bVector *)(self + 48);
        struct K8bVector *last = (struct K8bVector *)(self + 32);
        char *cursor;
        char *end;
        void *node;
        *(int *)(self + 20) = zero;
        cursor = items->begin;
        end = items->end;
        node = self + 4;
        for (; cursor != end; cursor += 16) {
            if (*(void **)cursor)
                w3d_auto_801907d0(*(void **)cursor);
        }
        if (items->begin)
            w3d_auto_801907d0(items->begin);
        {
            char *tail = middle->end;
            char *walk;
            for (walk = *(char **)(self + 48); walk != tail; walk += 24)
                ;
        }
        if (middle->begin)
            w3d_auto_801907d0(middle->begin);
        {
            char *tail = last->end;
            char *walk;
            for (walk = *(char **)(self + 32); walk != tail; walk += 24)
                ;
        }
        if (last->begin)
            w3d_auto_801907d0(last->begin);
        if (*(K8bObject **)(self + 20))
            ((void (*)(K8bObject *))(*(K8bObject **)(self + 20))->vtable[4])(*(K8bObject **)(self + 20));
        *(char **)self = lbl_80413470;
        w3d_actor_node_destroy(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
