struct K7bTreeNode { int color; struct K7bTreeNode *parent; struct K7bTreeNode *left; struct K7bTreeNode *right; };
struct K7bTree { int compare; struct K7bTreeNode *header; int node_count; };
struct K7bRecord { int words[4]; };
struct K7bRecordVector { struct K7bRecord *begin; struct K7bRecord *end; };
struct K7bRegistry { char pad[100]; struct K7bTree tree; char pad70[4]; struct K7bRecordVector records; };
extern void w3d_auto_80355800(struct K7bTree *tree, struct K7bTreeNode *root);
extern void w3d_auto_801f2758(struct K7bRecord *record, int flags);
static inline void k7b_tree_clear(struct K7bTree *tree)
{
    if (tree->node_count != 0) {
        w3d_auto_80355800(tree, tree->header->parent);
        tree->header->left = tree->header;
        tree->header->parent = 0;
        tree->header->right = tree->header;
        tree->node_count = 0;
    }
}
static inline void k7b_records_clear(struct K7bRecordVector *v)
{
    struct K7bRecord *first = v->begin;
    struct K7bRecord *last = v->end;
    struct K7bRecord *p;
    for (p = first; p != last; p++)
        w3d_auto_801f2758(p, 2);
    v->end = first;
}
int w3d_k7b_registry_clear_801acc48(struct K7bRegistry *self)
{
    k7b_tree_clear(&self->tree);
    k7b_records_clear(&self->records);
    return 0;
}
