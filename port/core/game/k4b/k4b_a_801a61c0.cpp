#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801a61c0.c"
struct K4bTreeNode {
    int color;
    Ptr32<struct K4bTreeNode> parent;
    Ptr32<struct K4bTreeNode> left;
    Ptr32<struct K4bTreeNode> right;
    int value[2];
};
struct K4bTree {
    int base;
    Ptr32<struct K4bTreeNode> header;
    int count;
    unsigned char compare;
};
struct K4bTriple { int first; int second; int third; };
struct K4bIndexedComponent {
    Ptr32<Ptr32<void>> vtable;
    char base[36];
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    char pad38[4];
    struct K4bTriple triple;
    char pad48[4];
    struct K4bTree tree;
    int field_5c;
};
extern Ptr32<void> lbl_80413b90[];
extern Ptr32<void> lbl_80413b38[];
extern Ptr32<void> fn_801e81c8(Ptr32<void> member);
extern Ptr32<void> w3d_handle_storage_allocate(unsigned int bytes);
extern Ptr32<void> w3d_handle_storage_fallback(unsigned int bytes);
static inline void k4b_triple_init(Ptr32<struct K4bTriple> t)
{
    t->third = 0;
    t->second = 0;
    t->first = 0;
}
static inline Ptr32<void> k4b_node_allocate(unsigned int bytes)
{
    Ptr32<void> p = w3d_handle_storage_allocate(bytes);
    if (p == 0)
        p = w3d_handle_storage_fallback(bytes);
    return p;
}
static inline void k4b_tree_init(Ptr32<struct K4bTree> tree)
{
    tree->header = 0;
    tree->header = (Ptr32<struct K4bTreeNode>)k4b_node_allocate(sizeof(struct K4bTreeNode));
    tree->count = 0;
    tree->compare = 0;
    tree->header->color = 0;
    tree->header->parent = 0;
    tree->header->left = tree->header;
    tree->header->right = tree->header;
}
Ptr32<struct K4bIndexedComponent> w3d_k4b_indexed_component_construct_801a61c0(Ptr32<struct K4bIndexedComponent> self)
{
    volatile char pad[16];
    self->vtable = lbl_80413b90;
    fn_801e81c8(self->base);
    self->vtable = lbl_80413b38;
    self->field_28 = 0;
    self->field_30 = 0;
    k4b_triple_init(&self->triple);
    k4b_tree_init(&self->tree);
    self->field_2c = 0;
    self->field_34 = 0;
    self->field_5c = 0;
    return self;
}
// desc: w3d_k4b_indexed_component_construct_801a61c0: Appears to construct a component with a zeroed triple and an ordered tree whose 24-byte header node is allocated through handle storage.

}
