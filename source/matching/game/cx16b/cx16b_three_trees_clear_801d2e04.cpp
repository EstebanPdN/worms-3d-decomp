/* Observed emptying of three embedded trees. Sentinel links are deliberately
   reloaded between stores because the tree header can alias its sentinel. */
struct Cx16bTreeNode { unsigned word; Cx16bTreeNode *parent,*left,*right; };
struct Cx16bTree { unsigned word; Cx16bTreeNode *header; unsigned count,unknown; };
struct Cx16bTreeTriple { char pad[20]; Cx16bTree first,second,third; };
extern "C" void fn_80355aec(Cx16bTree *,Cx16bTreeNode *);
static inline void cx16b_tree_empty(Cx16bTree *tree)
{
    if(tree->count){
        fn_80355aec(tree,tree->header->parent);
        tree->header->left=tree->header;
        tree->header->parent=0;
        tree->header->right=tree->header;
        tree->count=0;
    }
}
extern "C" int w3d_cx16b_three_trees_clear_801d2e04(Cx16bTreeTriple *self)
{
    cx16b_tree_empty(&self->first);
    cx16b_tree_empty(&self->second);
    cx16b_tree_empty(&self->third);
    return 0;
}
