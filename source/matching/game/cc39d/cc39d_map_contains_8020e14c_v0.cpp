// Variant trials for 0x8020e14c: STLport map<unsigned int, T>::find(key) != end().
struct cc39d_RbNode { int color; cc39d_RbNode *parent; cc39d_RbNode *left; cc39d_RbNode *right; };
struct cc39d_KeyNode : cc39d_RbNode { unsigned int key; };
struct cc39d_RbIterator {
    cc39d_RbNode *node;
    cc39d_RbIterator(cc39d_RbNode *n) : node(n) {}
    cc39d_RbIterator(const cc39d_RbIterator &o) : node(o.node) {}
    bool operator==(const cc39d_RbIterator &o) const { return node == o.node; }
    bool operator!=(const cc39d_RbIterator &o) const { return node != o.node; }
};
struct cc39d_UintMap {
    int unknown00;
    cc39d_RbNode *header;
    unsigned int node_count;
    cc39d_RbNode *find_node(const unsigned int &k) const {
        cc39d_RbNode *y = header;
        cc39d_RbNode *x = header->parent;
        while (x != 0)
            if (!(((cc39d_KeyNode *)x)->key < k)) y = x, x = x->left;
            else x = x->right;
        if (y == header || k < ((cc39d_KeyNode *)y)->key) y = header;
        return y;
    }
    cc39d_RbIterator find(const unsigned int &k) { return cc39d_RbIterator(find_node(k)); }
    cc39d_RbIterator end() { return cc39d_RbIterator(header); }
};
struct cc39d_MapOwner { unsigned char unknown00[20]; cc39d_UintMap map; };
struct cc39d_Keyed { unsigned char unknown00[8]; unsigned short id; };
extern "C" bool cc39d_map_a(cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = ((unsigned int)a->id << 16) | b->id;
    return self->map.find(key) != self->map.end();
}
inline bool operator!=(const cc39d_RbIterator &x, int) { return false; }
extern "C" bool cc39d_map_b(cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = (a->id << 16) | b->id;
    return !(self->map.find(key) == self->map.end());
}
extern "C" int cc39d_map_c(cc39d_MapOwner *self, const cc39d_Keyed *a, const cc39d_Keyed *b) {
    unsigned int key = (a->id << 16) | b->id;
    return self->map.find(key) != self->map.end();
}
