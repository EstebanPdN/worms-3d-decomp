typedef struct S10TreeNode { void *unknown; struct S10TreeNode *parent, *left, *right; } S10TreeNode;
typedef struct S10Tree { void *unknown; S10TreeNode *sentinel; unsigned int count; } S10Tree;
typedef struct S10TreeOwner { char reserved[76]; S10Tree tree; } S10TreeOwner;
extern void fn_80352f34(S10Tree *, S10TreeNode *);
int w3d_s10_tree_clear_801a6458(S10TreeOwner *object)
{
    S10Tree *tree = &object->tree;
    if (tree->count) {
        fn_80352f34(tree, tree->sentinel->parent);
        tree->sentinel->left = tree->sentinel;
        tree->sentinel->parent = 0;
        tree->sentinel->right = tree->sentinel;
        tree->count = 0;
    }
    return 0;
}
