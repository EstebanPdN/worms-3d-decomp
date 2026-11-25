// Type pair lookup (Worms 3D GameCube PAL, 0x8020e4bc).
//
// Packs the 16-bit ids at +8 of two type objects into one unsigned key (first
// id high), finds it in the red-black tree at +20 of the owner (std::map
// lower-bound walk: parent +4, left +8, right +12, key +16, value +20) and
// returns the node's value, or 0 when absent. The key is an addressable class
// object bound to a const reference, and the tree is a local pointer: both are
// needed for the original's register and scheduling order. Names are inferred.
struct Key {
    unsigned value;
    Key(unsigned short a, unsigned short b) : value((unsigned(a) << 16) | b) {}
};
inline bool operator<(const Key &a, const Key &b) { return a.value < b.value; }
struct Node {
    unsigned color;
    Node *parent, *left, *right;
    Key key;
    void *value;
};
struct Iterator {
    Node *node;
    Iterator(Node *p) : node(p) {}
    bool operator!=(const Iterator &other) const { return node != other.node; }
};
struct Tree {
    unsigned allocator;
    Node *header;
    Iterator end() const { return Iterator(header); }
    Iterator find(const Key &key) const {
        Node *candidate = header;
        Node *current = header->parent;
        while (current) {
            if (!(current->key < key)) {
                candidate = current;
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        if (candidate == header || key < candidate->key) {
            candidate = header;
        }
        return Iterator(candidate);
    }
};
struct Owner {
    unsigned prefix[5];
    Tree tree;
};
struct Part {
    unsigned prefix[2];
    unsigned short id;
};
extern "C" void *w3d_d24k_type_pair_lookup_8020e4bc(Owner *self, Part *first, Part *second) {
    Key k(first->id, second->id);
    const Key &key = k;
    Tree *t = &self->tree;
    Iterator found = t->find(key);
    if (found != self->tree.end()) {
        return found.node->value;
    }
    return 0;
}
