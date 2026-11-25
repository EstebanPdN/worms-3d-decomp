struct K8bEntry { char pad0[20]; char name[4]; };
struct K8bEntryVector { struct K8bEntry *begin; struct K8bEntry *end; };
extern char lbl_80414170[];
extern char lbl_804141b8[];
extern void w3d_auto_80355a14(struct K8bEntry *entry);
extern void w3d_string_base_finish(void *string);
extern void w3d_string_release(void *string);
extern void w3d_handle_storage_release(void *block);
extern void w3d_actor_node_destroy(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

static inline void k8b_for_each(struct K8bEntry *first, struct K8bEntry *last, void (*fn)(struct K8bEntry *))
{
    while (first != last)
        fn(first++);
}

void w3d_k8b_entries_dtor_801aeb28(char *self, unsigned int flags)
{
    struct K8bEntryVector *entries = (struct K8bEntryVector *)(self + 20);
    *(void **)self = lbl_80414170;
    k8b_for_each(entries->begin, entries->end, w3d_auto_80355a14);
    {
        struct K8bEntryVector *vector = (struct K8bEntryVector *)(self + 20);
        struct K8bEntry *cursor = vector->begin;
        struct K8bEntry *end = vector->end;
        void *node = self + 4;
        for (; cursor != end;) {
            char *name = cursor->name;
            cursor++;
            w3d_string_base_finish(name);
            w3d_string_release(name);
        }
        if (vector->begin)
            w3d_handle_storage_release(vector->begin);
        *(void **)self = lbl_804141b8;
        w3d_actor_node_destroy(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
