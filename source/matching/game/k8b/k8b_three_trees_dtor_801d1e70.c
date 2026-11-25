typedef struct K8bObject { void **vtable; } K8bObject;
struct K8bNode { int color; struct K8bNode *parent; struct K8bNode *left; struct K8bNode *right; };
struct K8bTree { int pad0; struct K8bNode *header; unsigned int count; };
extern char lbl_80416408[];
extern char lbl_80416468[];
extern void w3d_slot_tree_erase_80355aec(struct K8bTree *tree, struct K8bNode *root);
extern void w3d_handle_storage_release(void *block);
extern void w3d_actor_node_destroy(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

static inline void k8b_tree_destroy(struct K8bTree *tree, int zero)
{
    if (tree->count != 0) {
        w3d_slot_tree_erase_80355aec(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = (struct K8bNode *)zero;
        tree->header->right = tree->header;
        tree->count = zero;
    }
    if (tree->header)
        w3d_handle_storage_release(tree->header);
}

void w3d_k8b_three_trees_dtor_801d1e70(char *self, unsigned int flags)
{
    *(char **)self = lbl_80416408;
    if (*(K8bObject **)(self + 68))
        ((void (*)(K8bObject *))(*(K8bObject **)(self + 68))->vtable[4])(*(K8bObject **)(self + 68));
    {
        int zero = 0;
        k8b_tree_destroy((struct K8bTree *)(self + 52), zero);
        k8b_tree_destroy((struct K8bTree *)(self + 36), zero);
        k8b_tree_destroy((struct K8bTree *)(self + 20), zero);
    }
    *(char **)self = lbl_80416468;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
