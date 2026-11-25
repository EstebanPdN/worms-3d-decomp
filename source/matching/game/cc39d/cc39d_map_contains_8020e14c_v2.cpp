// Variant trials for 0x8020e14c: STLport map::count (find == end ? 0 : 1).
struct cc39d_RbNode { int color; cc39d_RbNode *parent; cc39d_RbNode *left; cc39d_RbNode *right; };
struct cc39d_KeyNode : cc39d_RbNode { unsigned int key; };
struct cc39d_BaseIterator { cc39d_RbNode *node; };
inline bool operator==(const cc39d_BaseIterator &x, const cc39d_BaseIterator &y) { return x.node == y.node; }
struct cc39d_RbIterator : cc39d_BaseIterator {
    cc39d_RbIterator(cc39d_RbNode *n) { node = n; }
};
struct cc39d_UintLess { bool operator()(const unsigned int &x, const unsigned int &y) const { return x < y; } };
struct cc39d_UintMap {
    cc39d_UintLess compare;
    cc39d_RbNode *header;
    unsigned int node_count;
    cc39d_RbNode *find_node(const unsigned int &k) const {
        cc39d_RbNode *y = header;
        cc39d_RbNode *x = header->parent;
        while (x != 0)
            if (!compare(((cc39d_KeyNode *)x)->key, k)) y = x, x = x->left;
            else x = x->right;
        if (y == header || compare(k, ((cc39d_KeyNode *)y)->key)) y = header;
        return y;
    }
    cc39d_RbIterator find(const unsigned int &k) const { return cc39d_RbIterator(find_node(k)); }
    cc39d_RbIterator end() const { return cc39d_RbIterator(header); }
    unsigned int count(const unsigned int &k) const { return find(k) == end() ? 0 : 1; }
};
struct cc39d_MapOwner { unsigned char unknown00[20]; cc39d_UintMap map; };
struct cc39d_Keyed { unsigned char unknown00[8]; unsigned short id; };
extern "C" bool cc39d_map_h(cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    return self->map.count(key) != 0;
}
extern "C" bool cc39d_map_i(cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    return self->map.count(((unsigned int)a->id << 16) | b->id) != 0;
}
extern "C" bool cc39d_map_j(cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    return self->map.count(key);
}
extern "C" bool cc39d_map_k(cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    return self->map.count((a->id << 16) | b->id);
}
