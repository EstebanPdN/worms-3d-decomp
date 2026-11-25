// Inferred free-tree node: every field is witnessed by 80213d90.
struct FreeNode {
    unsigned previous;
    unsigned size;
    unsigned equal;
    unsigned left;
    unsigned right;
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
        FreeNode* equal = (FreeNode*)block->equal;
        FreeNode* previous = (FreeNode*)block->previous;
        if (equal) equal->previous = (unsigned)previous;
        if (previous) previous->equal = (unsigned)equal;
        else heap->tiny = equal;
        RegionView* region = heap->regions;
        if (region->next) {
            while ((unsigned char*)block <= region->begin || (unsigned char*)block >= region->end)
                region = region->next;
        }
        block->previous = (unsigned)region;
    } else {
    FreeNode temporary;
    FreeNode* upper = &temporary;
    FreeNode* lower = &temporary;
    block = heap->tree;
    if (block) {
        do {
            if (size == block->size) break;
            FreeNode* child;
            if (size < block->size) {
                child = (FreeNode*)block->left;
                if (child) {
                    unsigned childSize = child->size;
                    if (size <= childSize) {
                        block->left = child->right;
                        child->right = (unsigned)block;
                        block = child;
                        if (size == childSize) break;
                        child = (FreeNode*)block->left;
                    } else {
                        lower->right = (unsigned)child;
                        lower = child;
                        child = (FreeNode*)child->right;
                    }
                }
                upper->left = (unsigned)block;
                upper = block;
            } else {
                child = (FreeNode*)block->right;
                if (child) {
                    unsigned childSize = child->size;
                    if (size >= childSize) {
                        block->right = child->left;
                        child->left = (unsigned)block;
                        block = child;
                        if (size == childSize) break;
                        child = (FreeNode*)block->right;
                    } else {
                        upper->left = (unsigned)child;
                        upper = child;
                        child = upper->left;
                    }
                }
                lower->right = (unsigned)block;
                lower = block;
            }
            block = child;
        } while (block);
    }
    if (block) {
        lower->right = block->left;
        upper->left = block->right;
    } else {
        upper->left = (unsigned)block;
        lower->right = (unsigned)block;
        block = (FreeNode*)temporary.left;
        if (block) {
            FreeNode* child;
            while ((child = (FreeNode*)block->left)) {
                block->left = child->right;
                child->right = (unsigned)block;
                block = child;
            }
            temporary.left = block->right;
        }
    }
    FreeNode* root;
    if (block && (root = (FreeNode*)block->equal)) {
        root->left = temporary.right;
        root->right = temporary.left;
    } else {
        root = (FreeNode*)temporary.left;
        if (root) {
            FreeNode* child;
            while ((child = (FreeNode*)root->left)) {
                root->left = child->right;
                child->right = root;
                root = child;
            }
            root->left = temporary.right;
        } else root = (FreeNode*)temporary.right;
    }
    heap->tree = root;
    }
    return block;
}
