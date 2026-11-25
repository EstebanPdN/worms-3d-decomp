typedef struct K8bObject { void **vtable; } K8bObject;
struct K8bNode { int color; struct K8bNode *parent; struct K8bNode *left; struct K8bNode *right; };
struct K8bTree { int pad0; struct K8bNode *header; unsigned int count; };
struct K8bVector { char *begin; char *end; };
extern char lbl_80414040[];
extern char lbl_80414088[];
extern void w3d_auto_801f2758(char *element, int mode);
extern void w3d_auto_80355800(struct K8bTree *tree, struct K8bNode *root);
extern void w3d_handle_storage_release(void *block);
extern void w3d_destroy_801e828c(void *node, int flags);
extern void w3d_actor_member_delete_backend(void *object);

static inline void k8b_tree_clear(struct K8bTree *tree)
{
    int zero = 0;
    if (tree->count != 0) {
        w3d_auto_80355800(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = (struct K8bNode *)zero;
        tree->header->right = tree->header;
        tree->count = zero;
    }
}

void w3d_k8b_tree_vector_dtor_801ac860(char *self, unsigned int flags)
{
    *(char **)self = lbl_80414040;
    if (*(K8bObject **)(self + 132))
        ((void (*)(K8bObject *))(*(K8bObject **)(self + 132))->vtable[4])(*(K8bObject **)(self + 132));
    {
        struct K8bVector *vector = (struct K8bVector *)(self + 116);
        char *cursor = vector->begin;
        char *end = vector->end;
        struct K8bTree *tree = (struct K8bTree *)(self + 100);
        void *node = self + 4;
        for (; cursor != end; cursor += 16)
            w3d_auto_801f2758(cursor, 2);
        if (vector->begin)
            w3d_handle_storage_release(vector->begin);
        k8b_tree_clear(tree);
        if (tree->header)
            w3d_handle_storage_release(tree->header);
        if (*(K8bObject **)(self + 96))
            ((void (*)(K8bObject *))(*(K8bObject **)(self + 96))->vtable[4])(*(K8bObject **)(self + 96));
        if (*(K8bObject **)(self + 40))
            ((void (*)(K8bObject *))(*(K8bObject **)(self + 40))->vtable[4])(*(K8bObject **)(self + 40));
        *(char **)self = lbl_80414088;
        w3d_destroy_801e828c(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
