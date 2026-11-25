// Type pair conversion (Worms 3D GameCube PAL, 0x8020e220).
//
// When both types are the same object, copies count elements (0x80200050 gives
// the element size, memcpy 0x802eee50). It then always looks up the converter
// for the packed type pair in the tree at +20 (see d24k_type_pair_lookup_8020e4bc)
// and calls it with source, from, destination, to and count, or returns
// 0x80004001 when no converter is registered. Iterators are one word with a
// user copy constructor: the original stores the found and end iterators at sp+8
// and sp+16 and the key at sp+24, with sp+12 and sp+20 never written. Names are
// inferred.
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
    Iterator(const Iterator &other) : node(other.node) {}
    bool operator==(const Iterator &other) const { return node == other.node; }
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
extern "C" unsigned int element_size_80200050(Part *);
extern "C" void *memcpy_802eee50(void *, const void *, unsigned int);
typedef int (*Converter)(const void *, Part *, void *, Part *, unsigned int);
extern "C" int w3d_d24k_type_pair_convert_8020e220(Owner *self, const void *source, Part *from, void *destination, Part *to, unsigned int count) {
    if (from == to) {
        memcpy_802eee50(destination, source, element_size_80200050(to) * count);
    }
    Key k(from->id, to->id);
    const Key &key = k;
    Tree *t = &self->tree;
    Iterator found = t->find(key);
    if (found == self->tree.end()) {
        return (int)0x80004001;
    }
    return ((Converter)found.node->value)(source, from, destination, to, count);
}
