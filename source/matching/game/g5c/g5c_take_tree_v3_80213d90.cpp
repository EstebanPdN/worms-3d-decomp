// Inferred free-tree node: every field is witnessed by 80213d90.
struct FreeNode {
    FreeNode* previous;
    unsigned size;
    FreeNode* equal;
    FreeNode* left;
    FreeNode* right;
};
struct RegionView {
    unsigned unknown;
    RegionView* next;
    unsigned char* begin;
    unsigned unknown12;
    unsigned char* end;
};
struct HeapView {
    unsigned flags;
    unsigned unknown4;
    unsigned unknown8;
    RegionView* regions;
    unsigned unknown16;
    unsigned unknown20;
    FreeNode* tree;
    FreeNode* tiny;
};
extern "C" FreeNode* g5c_take_tree_80213d90(HeapView* heap, unsigned size, FreeNode* block) {
    if (block && size == 8) {
        FreeNode* equal = block->equal;
        FreeNode* previous = block->previous;
        if (equal) equal->previous = previous;
        if (previous) previous->equal = equal;
        else heap->tiny = equal;
        RegionView* region = heap->regions;
        if (region->next) {
            while ((unsigned char*)block <= region->begin || (unsigned char*)block >= region->end)
                region = region->next;
        }
        block->previous = (FreeNode*)region;
        return block;
    }
    FreeNode temporary;
    FreeNode* upper = &temporary;
    FreeNode* lower = &temporary;
    FreeNode* node = heap->tree;
    if (node) {
        do {
            if (size == node->size) break;
            FreeNode* child;
            if (size < node->size) {
                child = node->left;
                if (child) {
                    unsigned childSize = child->size;
                    if (size <= childSize) {
                        node->left = child->right;
                        child->right = node;
                        node = child;
                        if (size == childSize) break;
                        child = node->left;
                    } else {
                        lower->right = child;
                        lower = child;
                        child = child->right;
                    }
                }
                upper->left = node;
                upper = node;
            } else {
                child = node->right;
                if (child) {
                    unsigned childSize = child->size;
                    if (size >= childSize) {
                        node->right = child->left;
                        child->left = node;
                        node = child;
                        if (size == childSize) break;
                        child = node->right;
                    } else {
                        upper->left = child;
                        upper = child;
                        child = upper->left;
                    }
                }
                lower->right = node;
                lower = node;
            }
            node = child;
        } while (node);
    }
    if (node) {
        lower->right = node->left;
        upper->left = node->right;
    } else {
        upper->left = node;
        lower->right = node;
        node = temporary.left;
        if (node) {
            FreeNode* child;
            while ((child = node->left)) {
                node->left = child->right;
                child->right = node;
                node = child;
            }
            temporary.left = node->right;
        }
    }
    FreeNode* root;
    if (node && (root = node->equal)) {
        root->left = temporary.right;
        root->right = temporary.left;
    } else {
        root = temporary.left;
        if (root) {
            FreeNode* child;
            while ((child = root->left)) {
                root->left = child->right;
                child->right = root;
                root = child;
            }
            root->left = temporary.right;
        } else root = temporary.right;
    }
    heap->tree = root;
    return node;
}
