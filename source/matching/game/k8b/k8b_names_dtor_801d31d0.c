struct K8bNameVector { void **begin; void **end; };
extern char lbl_804164d0[];
extern char lbl_80416518[];
extern void w3d_string_base_finish(void *string);
extern void w3d_string_release(void *string);
extern void w3d_handle_storage_release(void *block);
extern void w3d_destroy_801e828c(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

void w3d_k8b_names_dtor_801d31d0(char *self, unsigned int flags)
{
    *(void **)self = lbl_804164d0;
    if (*(void **)(self + 72))
        w3d_handle_storage_release(*(void **)(self + 72));
    {
        struct K8bNameVector *names = (struct K8bNameVector *)(self + 48);
        void **cursor = names->begin;
        void **end = names->end;
        void *text = self + 40;
        void *node = self + 4;
        for (; cursor != end; cursor++) {
            w3d_string_base_finish(cursor);
            w3d_string_release(cursor);
        }
        if (names->begin)
            w3d_handle_storage_release(names->begin);
        w3d_string_base_finish(text);
        w3d_string_release(text);
        *(void **)self = lbl_80416518;
        w3d_destroy_801e828c(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
