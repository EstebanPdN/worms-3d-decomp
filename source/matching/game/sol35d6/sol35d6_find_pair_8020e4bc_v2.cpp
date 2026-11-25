// Unsigned pair key and observed native tree offsets; names inferred.
namespace Sol35d6FindPairV2 {
struct Node { unsigned color; Node *parent,*left,*right; unsigned key; void *value; };
struct Iterator {
    Node *node;
    Iterator(Node *p):node(p) {}
    bool operator!=(const Iterator &other) const { return node!=other.node; }
};
struct Tree {
    unsigned allocator; Node *header;
    Iterator end() const { return Iterator(header); }
    Iterator find(const unsigned &key) const {
        Node *candidate=header;
        Node *current=header->parent;
        while(current) {
            if(!(current->key<key)) { candidate=current; current=current->left; }
            else current=current->right;
        }
        if(candidate==header || key<candidate->key) candidate=header;
        return Iterator(candidate);
    }
};
struct Owner { unsigned prefix[5]; Tree tree; };
struct Part { unsigned prefix[2]; unsigned short id; };
}
extern "C" void *sol35d6_find_pair_8020e4bc_v2(
    Sol35d6FindPairV2::Owner *self,Sol35d6FindPairV2::Part *first,Sol35d6FindPairV2::Part *second) {
    using namespace Sol35d6FindPairV2;
    Iterator found=self->tree.find((unsigned(first->id)<<16)|second->id);
    if(found!=self->tree.end()) return found.node->value;
    return 0;
}
