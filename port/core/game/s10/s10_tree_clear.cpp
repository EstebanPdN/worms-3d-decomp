#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10_tree_clear.c"
typedef struct S10TreeNode { Ptr32<void> unknown; Ptr32<struct S10TreeNode> parent; Ptr32<struct S10TreeNode> left; Ptr32<struct S10TreeNode> right; } S10TreeNode;
typedef struct S10Tree { Ptr32<void> unknown; Ptr32<S10TreeNode> sentinel; unsigned int count; } S10Tree;
typedef struct S10TreeOwner { char reserved[76]; S10Tree tree; } S10TreeOwner;
extern void fn_80352f34(Ptr32<S10Tree>, Ptr32<S10TreeNode>);
int w3d_s10_tree_clear_801a6458(Ptr32<S10TreeOwner> object)
{
    Ptr32<S10Tree> tree = &object->tree;
    if (tree->count) {
        fn_80352f34(tree, tree->sentinel->parent);
        tree->sentinel->left = tree->sentinel;
        tree->sentinel->parent = 0;
        tree->sentinel->right = tree->sentinel;
        tree->count = 0;
    }
    return 0;
}

}
