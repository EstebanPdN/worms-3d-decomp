#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_tree_vector_dtor_801ac860.c"
typedef struct K8bObject { Ptr32<Ptr32<void>> vtable; } K8bObject;
struct K8bNode { int color; Ptr32<struct K8bNode> parent; Ptr32<struct K8bNode> left; Ptr32<struct K8bNode> right; };
struct K8bTree { int pad0; Ptr32<struct K8bNode> header; unsigned int count; };
struct K8bVector { Ptr32<char> begin; Ptr32<char> end; };
extern char lbl_80414040[];
extern char lbl_80414088[];
extern void w3d_auto_801f2758(Ptr32<char> element, int mode);
extern void w3d_auto_80355800(Ptr32<struct K8bTree> tree, Ptr32<struct K8bNode> root);
extern void w3d_handle_storage_release(Ptr32<void> block);
extern void w3d_destroy_801e828c(Ptr32<void> node, int flags);
extern void w3d_actor_member_delete_backend(Ptr32<void> object);

static inline void k8b_tree_clear(Ptr32<struct K8bTree> tree)
{
    int zero = 0;
    if (tree->count != 0) {
        w3d_auto_80355800(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = (Ptr32<struct K8bNode>)w3d::G(zero);
        tree->header->right = tree->header;
        tree->count = zero;
    }
}

void w3d_k8b_tree_vector_dtor_801ac860(Ptr32<char> self, unsigned int flags)
{
    *(Ptr32<Ptr32<char>>)self = lbl_80414040;
    if (*(Ptr32<Ptr32<K8bObject>>)(self + 132))
        ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 132))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 132));
    {
        Ptr32<struct K8bVector> vector = (Ptr32<struct K8bVector>)(self + 116);
        Ptr32<char> cursor = vector->begin;
        Ptr32<char> end = vector->end;
        Ptr32<struct K8bTree> tree = (Ptr32<struct K8bTree>)(self + 100);
        Ptr32<void> node = self + 4;
        for (; cursor != end; cursor += 16)
            w3d_auto_801f2758(cursor, 2);
        if (vector->begin)
            w3d_handle_storage_release(vector->begin);
        k8b_tree_clear(tree);
        if (tree->header)
            w3d_handle_storage_release(tree->header);
        if (*(Ptr32<Ptr32<K8bObject>>)(self + 96))
            ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 96))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 96));
        if (*(Ptr32<Ptr32<K8bObject>>)(self + 40))
            ((Ptr32<void (Ptr32<K8bObject>)>)(*(Ptr32<Ptr32<K8bObject>>)(self + 40))->vtable[4])(*(Ptr32<Ptr32<K8bObject>>)(self + 40));
        *(Ptr32<Ptr32<char>>)self = lbl_80414088;
        w3d_destroy_801e828c(node, 0);
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

}
