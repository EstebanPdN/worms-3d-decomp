#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k7b_a_801acc48.c"
struct K7bTreeNode { int color; Ptr32<struct K7bTreeNode> parent; Ptr32<struct K7bTreeNode> left; Ptr32<struct K7bTreeNode> right; };
struct K7bTree { int compare; Ptr32<struct K7bTreeNode> header; int node_count; };
struct K7bRecord { int words[4]; };
struct K7bRecordVector { Ptr32<struct K7bRecord> begin; Ptr32<struct K7bRecord> end; };
struct K7bRegistry { char pad[100]; struct K7bTree tree; char pad70[4]; struct K7bRecordVector records; };
extern void w3d_auto_80355800(Ptr32<struct K7bTree> tree, Ptr32<struct K7bTreeNode> root);
extern void w3d_auto_801f2758(Ptr32<struct K7bRecord> record, int flags);
static inline void k7b_tree_clear(Ptr32<struct K7bTree> tree)
{
    if (tree->node_count != 0) {
        w3d_auto_80355800(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = 0;
        tree->header->right = tree->header;
        tree->node_count = 0;
    }
}
static inline void k7b_records_clear(Ptr32<struct K7bRecordVector> v)
{
    Ptr32<struct K7bRecord> first = v->begin;
    Ptr32<struct K7bRecord> last = v->end;
    Ptr32<struct K7bRecord> p;
    for (p = first; p != last; p++)
        w3d_auto_801f2758(p, 2);
    v->end = first;
}
int w3d_k7b_registry_clear_801acc48(Ptr32<struct K7bRegistry> self)
{
    k7b_tree_clear(&self->tree);
    k7b_records_clear(&self->records);
    return 0;
}

}
