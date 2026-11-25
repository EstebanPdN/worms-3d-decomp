// Variant trials for 0x8020e14c: STLport-shaped tree with reference-cast
// link accessors (_M_root/_S_left/_S_right) and const_iterator comparisons.
struct cc39d_RbNodeBase { int color; cc39d_RbNodeBase *parent; cc39d_RbNodeBase *left; cc39d_RbNodeBase *right; };
struct cc39d_RbNode : cc39d_RbNodeBase { unsigned int key; };
struct cc39d_RbBaseIterator { cc39d_RbNodeBase *node; };
inline bool operator==(const cc39d_RbBaseIterator &x, const cc39d_RbBaseIterator &y) { return x.node == y.node; }
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
extern "C" bool cc39d_map_l(const cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    return self->map.find(key) != self->map.end();
}
extern "C" bool cc39d_map_m(const cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    return (self->map.find(key) != self->map.end()) ? true : false;
}
extern "C" bool cc39d_map_n(const cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    if (self->map.find(key) != self->map.end()) return true;
    return false;
}
inline int cc39d_differs(const cc39d_RbBaseIterator &x, const cc39d_RbBaseIterator &y) { return x.node != y.node; }
extern "C" bool cc39d_map_o(const cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    return cc39d_differs(self->map.find(key), self->map.end());
}
extern "C" bool cc39d_map_p(const cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    bool found = self->map.find(key) != self->map.end();
    return found != false;
}
