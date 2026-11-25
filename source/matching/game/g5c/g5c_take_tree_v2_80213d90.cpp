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
extern "C" void* g5c_take_tree_80213d90(HeapView* heap, unsigned size, FreeNode* block) {
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
                child = block->left;
                if (child) {
                    unsigned childSize = child->size;
                    if (size <= childSize) {
                        block->left = child->right;
                        child->right = block;
                        block = child;
                        if (size == childSize) break;
                        child = block->left;
                    } else {
                        lower->right = child;
                        lower = child;
                        child = child->right;
                    }
                }
                upper->left = block;
                upper = block;
            } else {
                child = block->right;
                if (child) {
                    unsigned childSize = child->size;
                    if (size >= childSize) {
                        block->right = child->left;
                        child->left = block;
                        block = child;
                        if (size == childSize) break;
                        child = block->right;
                    } else {
                        upper->left = child;
                        upper = child;
                        child = upper->left;
                    }
                }
                lower->right = block;
                lower = block;
            }
            block = child;
        } while (block);
    }
    if (block) {
        lower->right = block->left;
        upper->left = block->right;
    } else {
        upper->left = block;
        lower->right = block;
        block = temporary.left;
        if (block) {
            FreeNode* child;
            while ((child = block->left)) {
                block->left = child->right;
                child->right = block;
                block = child;
            }
            temporary.left = block->right;
        }
    }
    FreeNode* root;
    if (block && (root = block->equal)) {
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
    }
    return block;
}
