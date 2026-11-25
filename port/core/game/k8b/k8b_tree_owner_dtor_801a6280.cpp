#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_tree_owner_dtor_801a6280.c"
typedef struct K8bObject { Ptr32<Ptr32<void>> vtable; } K8bObject;
struct K8bNode { int color; Ptr32<struct K8bNode> parent; Ptr32<struct K8bNode> left; Ptr32<struct K8bNode> right; };
struct K8bTree { int pad0; Ptr32<struct K8bNode> header; unsigned int count; };
extern char lbl_80413b38[];
extern char lbl_80413b90[];
extern void w3d_auto_80352f34(Ptr32<struct K8bTree> tree, Ptr32<struct K8bNode> root);
extern void w3d_handle_storage_release(Ptr32<void> block);
extern void w3d_destroy_801e828c(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);

static inline void k8b_tree_clear(Ptr32<struct K8bTree> tree)
{
    if (tree->count != 0) {
        w3d_auto_80352f34(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = 0;
        tree->header->right = tree->header;
        tree->count = 0;
    }
}

void w3d_k8b_tree_owner_dtor_801a6280(Ptr32<char> self, unsigned int flags)
{
    Ptr32<struct K8bTree> tree = (Ptr32<struct K8bTree>)(self + 76);
    *(Ptr32<Ptr32<char>>)self = lbl_80413b38;
    k8b_tree_clear(tree);
    if (tree->header)
        w3d_handle_storage_release(tree->header);
    if (*(Ptr32<Ptr32<void>>)(self + 60))
        w3d_handle_storage_release(*(Ptr32<Ptr32<void>>)(self + 60));
    if (*(Ptr32<Ptr32<K8bObject>>)(self + 48))
        ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 48))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 48));
    if (*(Ptr32<Ptr32<K8bObject>>)(self + 40))
        ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 40))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 40));
    *(Ptr32<Ptr32<char>>)self = lbl_80413b90;
    w3d_destroy_801e828c(self + 4, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
