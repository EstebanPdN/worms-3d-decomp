#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_three_trees_dtor_801d1e70.c"
typedef struct K8bObject { Ptr32<Ptr32<void>> vtable; } K8bObject;
struct K8bNode { int color; Ptr32<struct K8bNode> parent; Ptr32<struct K8bNode> left; Ptr32<struct K8bNode> right; };
struct K8bTree { int pad0; Ptr32<struct K8bNode> header; unsigned int count; };
extern char lbl_80416408[];
extern char lbl_80416468[];
extern void w3d_slot_tree_erase_80355aec(Ptr32<struct K8bTree> tree, Ptr32<struct K8bNode> root);
extern void w3d_handle_storage_release(Ptr32<void> block);
extern void w3d_actor_node_destroy(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);

static inline void k8b_tree_destroy(Ptr32<struct K8bTree> tree, int zero)
{
    if (tree->count != 0) {
        w3d_slot_tree_erase_80355aec(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = (Ptr32<struct K8bNode>)w3d::G(zero);
        tree->header->right = tree->header;
        tree->count = zero;
    }
    if (tree->header)
        w3d_handle_storage_release(tree->header);
}

void w3d_k8b_three_trees_dtor_801d1e70(Ptr32<char> self, unsigned int flags)
{
    *(Ptr32<Ptr32<char>>)self = lbl_80416408;
    if (*(Ptr32<Ptr32<K8bObject>>)(self + 68))
        ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 68))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 68));
    {
        int zero = 0;
        k8b_tree_destroy((Ptr32<struct K8bTree>)(self + 52), zero);
        k8b_tree_destroy((Ptr32<struct K8bTree>)(self + 36), zero);
        k8b_tree_destroy((Ptr32<struct K8bTree>)(self + 20), zero);
    }
    *(Ptr32<Ptr32<char>>)self = lbl_80416468;
    w3d_actor_node_destroy(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
