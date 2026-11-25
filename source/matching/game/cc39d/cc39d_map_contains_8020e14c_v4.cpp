// Test whether a composite id is present in an STLport map keyed by unsigned
// int (0x8020e14c). The key is the first object's 16-bit id at +8 in the high
// half and the second object's id at +8 in the low half. The lookup is
// STLport's _Rb_tree::_M_find through the const find()/end() overloads:
// const_iterator copies are trivial, and the link accessors are STLport's
// reference casts ((_Link_type &) node->_M_parent etc.).
// Partial observed views only: the tree starts at owner +20 with its header
// at tree +4 (an allocator byte precedes it); node key at +16. The owner type,
// mapped type, real class names and sizeof are unknown.
struct cc39d_RbNodeBase { int color; cc39d_RbNodeBase *parent; cc39d_RbNodeBase *left; cc39d_RbNodeBase *right; };
struct cc39d_RbNode : cc39d_RbNodeBase { unsigned int key; };
struct cc39d_RbBaseIterator { cc39d_RbNodeBase *node; };
inline bool operator!=(const cc39d_RbBaseIterator &x, const cc39d_RbBaseIterator &y) { return x.node != y.node; }
struct cc39d_RbConstIterator : cc39d_RbBaseIterator {
    cc39d_RbConstIterator(cc39d_RbNode *n) { node = n; }
};
struct cc39d_UintLess { bool operator()(const unsigned int &x, const unsigned int &y) const { return x < y; } };
struct cc39d_UintTree {
    char allocator;
    cc39d_RbNode *header;
    unsigned int node_count;
    cc39d_UintLess key_compare;
    cc39d_RbNode *&root() const { return (cc39d_RbNode *&)header->parent; }
    static cc39d_RbNode *&left(cc39d_RbNode *x) { return (cc39d_RbNode *&)(x->left); }
    static cc39d_RbNode *&right(cc39d_RbNode *x) { return (cc39d_RbNode *&)(x->right); }
    static const unsigned int &key(cc39d_RbNode *x) { return x->key; }
    cc39d_RbNode *find_node(const unsigned int &k) const {
        cc39d_RbNode *y = header;
        cc39d_RbNode *x = root();
        while (x != 0)
            if (!key_compare(key(x), k)) y = x, x = left(x);
            else x = right(x);
        if (y == header || key_compare(k, key(y))) y = header;
        return y;
    }
    cc39d_RbConstIterator find(const unsigned int &k) const { return cc39d_RbConstIterator(find_node(k)); }
    cc39d_RbConstIterator end() const { return cc39d_RbConstIterator(header); }
};
struct cc39d_MapOwner { unsigned char unknown00[20]; cc39d_UintTree map; };
struct cc39d_Keyed { unsigned char unknown00[8]; unsigned short id; };
extern "C" bool cc39d_map_contains_8020e14c(const cc39d_MapOwner *self, const cc39d_Keyed *high, const cc39d_Keyed *low) {
    unsigned int key = ((unsigned int)high->id << 16) | low->id;
    if (self->map.find(key) != self->map.end()) return true;
    return false;
}
