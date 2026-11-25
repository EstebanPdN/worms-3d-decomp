#include "w3d_ptr.h"
#line 1 "cx7c_tree_erase_vector.cpp"
/* Inferred tree subtree erase, original 0x8035b8fc. Node links at +8/+12;
 * an embedded vector starts +24. Its trivial 8-byte elements are visited,
 * buffer freed, then node freed. Right recursion and iterative left descent
 * bound recursion depth; no whole-table count/header updates happen here.
 */
extern "C" void cx7c_deallocate_802134fc(Ptr32<void>);
struct Cx7cEraseTrivialValue {unsigned int words[2];};
struct Cx7cEraseVector {
    Ptr32<Cx7cEraseTrivialValue> begin; Ptr32<Cx7cEraseTrivialValue> end;unsigned int allocator;Ptr32<Cx7cEraseTrivialValue> capacity_end;
    ~Cx7cEraseVector() {
        for (Ptr32<Cx7cEraseTrivialValue> p=begin;p!=end;++p) p->~Cx7cEraseTrivialValue();
        if (begin) cx7c_deallocate_802134fc(begin);
    }
};
struct Cx7cEraseTreeNode {
    int color;Ptr32<Cx7cEraseTreeNode> parent; Ptr32<Cx7cEraseTreeNode> left; Ptr32<Cx7cEraseTreeNode> right;
    unsigned int key[2];Cx7cEraseVector values;
};
struct Cx7cEraseTree;
extern "C" void w3d_cx7c_tree_erase_vector_8035b8fc(Ptr32<Cx7cEraseTree> self,Ptr32<Cx7cEraseTreeNode> node)
{
    while (node) {
        w3d_cx7c_tree_erase_vector_8035b8fc(self,node->right);
        Ptr32<Cx7cEraseTreeNode> left=node->left;
        node->~Cx7cEraseTreeNode();
        if (node) cx7c_deallocate_802134fc(node);
        node=left;
    }
}


