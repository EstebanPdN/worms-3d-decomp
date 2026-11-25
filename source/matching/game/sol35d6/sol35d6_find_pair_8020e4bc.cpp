// Unsigned pair key and observed native tree offsets; names inferred.
namespace Sol35d6FindPair {
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
            if(current->key<key) current=current->right;
            else { candidate=current; current=current->left; }
        }
        if(candidate==header || key<candidate->key) candidate=header;
        return Iterator(candidate);
    }
};
struct Owner { unsigned prefix[5]; Tree tree; };
struct Part { unsigned prefix[2]; unsigned short id; };
}
extern "C" void *sol35d6_find_pair_8020e4bc(
    Sol35d6FindPair::Owner *self,Sol35d6FindPair::Part *first,Sol35d6FindPair::Part *second) {
    using namespace Sol35d6FindPair;
    unsigned key=(unsigned(first->id)<<16)|second->id;
    Iterator found=self->tree.find(key);
    if(found!=self->tree.end()) return found.node->value;
    return 0;
}
