/* STLport red-black trees keyed by unsigned int (session b169b320):
 * _Rb_tree::insert_unique and _Rb_tree::_M_insert for one set<unsigned int>
 * and four map<unsigned int, T> instances (T = 4-byte value, or the 16-byte
 * value of the property stores), plus _Rb_global<bool>::_M_decrement.
 * Written in STLport's shape: iterators and pairs declare their copy
 * constructors (no crclr before struct-returning calls), nodes come from
 * __malloc_alloc (game heap with an out-of-memory fallback) and are built
 * with a throw() placement new, which null-checks the value address. */

inline void *operator new(unsigned int, void *place) throw() { return place; }

struct W3dRbNode
{
    int color;                           /* 0 = red */
    W3dRbNode *parent;
    W3dRbNode *left;
    W3dRbNode *right;
};

struct W3dValue16
{
    int words[4];
};

struct W3dUintIntPair
{
    unsigned int first;
    int second;
    W3dUintIntPair(const W3dUintIntPair &o) : first(o.first), second(o.second) {}
};

struct W3dUintValue16Pair
{
    unsigned int first;
    W3dValue16 second;
    W3dUintValue16Pair(const W3dUintValue16Pair &o) : first(o.first), second(o.second) {}
};

extern "C" void *w3d_handle_storage_allocate(unsigned int size);
extern "C" void *w3d_handle_storage_fallback(unsigned int size);
extern "C" void w3d_rb_rebalance_80352404(W3dRbNode *x, W3dRbNode *&root);

/* __malloc_alloc<0>::allocate */
static inline void *w3d_malloc_alloc(unsigned int n)
{
    void *result = w3d_handle_storage_allocate(n);
    if (0 == result)
        result = w3d_handle_storage_fallback(n);
    return result;
}

extern "C" W3dRbNode *w3d_rb_decrement_803526a0(W3dRbNode *node)
{
    if (node->color == 0 && node->parent->parent == node)
        node = node->right;
    else if (node->left != 0) {
        W3dRbNode *y = node->left;
        while (y->right != 0)
            y = y->right;
        node = y;
    }
    else {
        W3dRbNode *y = node->parent;
        while (node == y->left) {
            node = y;
            y = y->parent;
        }
        node = y;
    }
    return node;
}

struct W3dRbIterator
{
    W3dRbNode *node;
    W3dRbIterator() {}
    W3dRbIterator(W3dRbNode *n) : node(n) {}
    W3dRbIterator(const W3dRbIterator &other) : node(other.node) {}
    bool operator==(const W3dRbIterator &other) const { return node == other.node; }
    W3dRbIterator &operator--() { node = w3d_rb_decrement_803526a0(node); return *this; }
};

struct W3dRbInsertResult
{
    W3dRbIterator first;
    bool second;
    W3dRbInsertResult(const W3dRbIterator &a, const bool &b) : first(a), second(b) {}
};

/* CLASS: tree type; VALUE: node value; KEY(v): key of a value. */
#define W3D_UINT_TREE(CLASS, VALUE, KEY) \
struct CLASS \
{ \
    struct Node : W3dRbNode \
    { \
        VALUE value; \
    }; \
    int unknown_00; \
    W3dRbNode *header; \
    unsigned int node_count; \
    W3dRbNode *&root() { return header->parent; } \
    W3dRbNode *&leftmost() { return header->left; } \
    W3dRbNode *&rightmost() { return header->right; } \
    W3dRbIterator begin() { return W3dRbIterator(header->left); } \
    Node *create_node(const VALUE &x) \
    { \
        Node *tmp = (Node *)w3d_malloc_alloc(sizeof(Node)); \
        new (&tmp->value) VALUE(x); \
        return tmp; \
    } \
    W3dRbIterator insert_node(W3dRbNode *x_, W3dRbNode *y_, const VALUE &v, W3dRbNode *w_ = 0); \
    W3dRbInsertResult insert_unique(const VALUE &v); \
}; \
W3dRbIterator CLASS::insert_node(W3dRbNode *x_, W3dRbNode *y_, const VALUE &v, W3dRbNode *w_) \
{ \
    Node *w = (Node *)w_; \
    Node *x = (Node *)x_; \
    Node *y = (Node *)y_; \
    Node *z; \
    if (y == header || (w == 0 && (x != 0 || KEY(v) < KEY(y->value)))) { \
        z = create_node(v); \
        y->left = z; \
        if (y == header) { \
            root() = z; \
            rightmost() = z; \
        } \
        else if (y == leftmost()) \
            leftmost() = z; \
    } \
    else { \
        z = create_node(v); \
        y->right = z; \
        if (y == rightmost()) \
            rightmost() = z; \
    } \
    z->parent = y; \
    z->left = 0; \
    z->right = 0; \
    w3d_rb_rebalance_80352404(z, header->parent); \
    ++node_count; \
    return W3dRbIterator(z); \
} \
W3dRbInsertResult CLASS::insert_unique(const VALUE &v) \
{ \
    W3dRbNode *y = header; \
    W3dRbNode *x = header->parent; \
    bool comp = true; \
    while (x != 0) { \
        y = x; \
        comp = KEY(v) < KEY(((Node *)x)->value); \
        x = comp ? x->left : x->right; \
    } \
    W3dRbIterator j = W3dRbIterator(y); \
    if (comp) \
        if (j == begin()) \
            return W3dRbInsertResult(insert_node(x, y, v), true); \
        else \
            --j; \
    if (KEY(((Node *)j.node)->value) < KEY(v)) \
        return W3dRbInsertResult(insert_node(x, y, v), true); \
    return W3dRbInsertResult(j, false); \
}

#define W3D_KEY_IDENTITY(v) (v)
#define W3D_KEY_FIRST(v) ((v).first)

W3D_UINT_TREE(W3dUintSet_80352710, unsigned int, W3D_KEY_IDENTITY)
W3D_UINT_TREE(W3dUintIntMap_803530d0, W3dUintIntPair, W3D_KEY_FIRST)
W3D_UINT_TREE(W3dUintIntMap_8035bad8, W3dUintIntPair, W3D_KEY_FIRST)
W3D_UINT_TREE(W3dUintValue16Map_8035bf94, W3dUintValue16Pair, W3D_KEY_FIRST)
W3D_UINT_TREE(W3dUintIntMap_8035cdb8, W3dUintIntPair, W3D_KEY_FIRST)
