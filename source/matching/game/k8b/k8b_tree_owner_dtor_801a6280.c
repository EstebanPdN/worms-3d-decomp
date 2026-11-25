typedef struct K8bObject { void **vtable; } K8bObject;
struct K8bNode { int color; struct K8bNode *parent; struct K8bNode *left; struct K8bNode *right; };
struct K8bTree { int pad0; struct K8bNode *header; unsigned int count; };
extern char lbl_80413b38[];
extern char lbl_80413b90[];
extern void w3d_auto_80352f34(struct K8bTree *tree, struct K8bNode *root);
extern void w3d_handle_storage_release(void *block);
extern void w3d_destroy_801e828c(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

static inline void k8b_tree_clear(struct K8bTree *tree)
{
    if (tree->count != 0) {
        w3d_auto_80352f34(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = 0;
        tree->header->right = tree->header;
        tree->count = 0;
    }
}

void w3d_k8b_tree_owner_dtor_801a6280(char *self, unsigned int flags)
{
    struct K8bTree *tree = (struct K8bTree *)(self + 76);
    *(char **)self = lbl_80413b38;
    k8b_tree_clear(tree);
    if (tree->header)
        w3d_handle_storage_release(tree->header);
    if (*(void **)(self + 60))
        w3d_handle_storage_release(*(void **)(self + 60));
    if (*(K8bObject **)(self + 48))
        ((void (*)(K8bObject *))(*(K8bObject **)(self + 48))->vtable[4])(*(K8bObject **)(self + 48));
    if (*(K8bObject **)(self + 40))
        ((void (*)(K8bObject *))(*(K8bObject **)(self + 40))->vtable[4])(*(K8bObject **)(self + 40));
    *(char **)self = lbl_80413b90;
    w3d_destroy_801e828c(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
