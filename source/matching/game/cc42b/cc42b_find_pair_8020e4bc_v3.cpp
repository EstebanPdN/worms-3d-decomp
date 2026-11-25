// Partial ordered-tree views reconstructed from original node offsets and
// lower-bound traversal. Names are inferred; no original class size asserted.
struct cc42b_PairNode {
    unsigned int color;
    cc42b_PairNode *parent, *left, *right;
    unsigned int key, value;
};
struct cc42b_PairIterator {
    cc42b_PairNode *node;
    cc42b_PairIterator(cc42b_PairNode *p):node(p){}
    bool operator==(const cc42b_PairIterator &other) const { return node==other.node; }
    bool operator!=(const cc42b_PairIterator &other) const { return node!=other.node; }
};
struct cc42b_PairLess { bool operator()(const unsigned int &a,const unsigned int &b) const { return a<b; } };
struct cc42b_PairTree {
    unsigned int unknown00;
    cc42b_PairNode *header;
    cc42b_PairIterator end() { return cc42b_PairIterator(header); }
    cc42b_PairIterator find(const unsigned int &key) {
        cc42b_PairNode *best=header;
        cc42b_PairNode *node=header->parent;
        while (node) {
            if (!cc42b_PairLess()(node->key,key)) { best=node; node=node->left; }
            else node=node->right;
        }
        if (best==header || cc42b_PairLess()(key,best->key)) best=header;
        return cc42b_PairIterator(best);
    }
};
struct cc42b_PairOwner { unsigned char unknown00[20]; cc42b_PairTree tree; };
struct cc42b_PairKeyPart { unsigned char unknown00[8]; unsigned short id; };
extern "C" unsigned int cc42b_find_pair_8020e4bc(cc42b_PairOwner *self, cc42b_PairKeyPart *high, cc42b_PairKeyPart *low) {
    unsigned int key=(static_cast<unsigned int>(high->id)<<16)|low->id;
    cc42b_PairIterator found=self->tree.find(key);
    if (found!=self->tree.end()) return found.node->value;
    return 0;
}
