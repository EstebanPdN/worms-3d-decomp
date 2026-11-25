/* Inferred tree subtree erase, original 0x8035b8fc. Node links at +8/+12;
 * an embedded vector starts +24. Its trivial 8-byte elements are visited,
 * buffer freed, then node freed. Right recursion and iterative left descent
 * bound recursion depth; no whole-table count/header updates happen here.
 */
extern "C" void cx7c_deallocate_802134fc(void *);
struct Cx7cEraseTrivialValue {unsigned int words[2];};
struct Cx7cEraseVector {
    Cx7cEraseTrivialValue *begin,*end;unsigned int allocator;Cx7cEraseTrivialValue *capacity_end;
    ~Cx7cEraseVector() {
        for (Cx7cEraseTrivialValue *p=begin;p!=end;++p) p->~Cx7cEraseTrivialValue();
        if (begin) cx7c_deallocate_802134fc(begin);
    }
};
struct Cx7cEraseTreeNode {
    int color;Cx7cEraseTreeNode *parent,*left,*right;
    unsigned int key[2];Cx7cEraseVector values;
};
struct Cx7cEraseTree;
extern "C" void w3d_cx7c_tree_erase_vector_8035b8fc(Cx7cEraseTree *self,Cx7cEraseTreeNode *node)
{
    while (node) {
        w3d_cx7c_tree_erase_vector_8035b8fc(self,node->right);
        Cx7cEraseTreeNode *left=node->left;
        node->~Cx7cEraseTreeNode();
        if (node) cx7c_deallocate_802134fc(node);
        node=left;
    }
}
