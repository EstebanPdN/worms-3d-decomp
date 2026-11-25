// Partial view of a deleting destructor of an observer registry: a class
// with a virtual interface that keeps an STLport red-black tree (a set of
// listener pointers). Teardown notifies every listener, clears the tree,
// runs the owner's shutdown hook, and releases the tree header node.
// Several template instantiations share this shape; vtables are original
// addresses. Virtual calls are written through explicit vtable slots.
struct K11bRbNode {
    bool color;
    K11bRbNode *parent;
    K11bRbNode *left;
    K11bRbNode *right;
    void *value;
};

extern "C" {
K11bRbNode *w3d_rb_increment_80351ef8(K11bRbNode *node);
K11bRbNode *w3d_rb_rebalance_for_erase_80352010(K11bRbNode *z, K11bRbNode *&root,
                                              K11bRbNode *&leftmost, K11bRbNode *&rightmost);
void w3d_auto_80351ea0(void *tree, K11bRbNode *root);
void w3d_handle_storage_release(void *p);
void w3d_actor_member_delete_backend(void *p);
extern char lbl_80413a38[];
extern char lbl_80413a50[];
}

typedef void (*K11bMethod0)(void *);
typedef void (*K11bMethod1)(void *, void *);
#define K11B_VCALL0(obj, slot) ((*(K11bMethod0 *)(*(char **)(obj) + (slot)))(obj))
#define K11B_VCALL1(obj, slot, a) ((*(K11bMethod1 *)(*(char **)(obj) + (slot)))((obj), (a)))

struct K11bIterator {
    K11bRbNode *node;
    K11bIterator() {}
    K11bIterator(K11bRbNode *n) : node(n) {}
    K11bIterator(const K11bIterator &o) : node(o.node) {}
    K11bIterator &operator++() { node = w3d_rb_increment_80351ef8(node); return *this; }
    K11bIterator operator++(int) { K11bIterator tmp = *this; ++*this; return tmp; }
    bool operator==(const K11bIterator &o) const { return node == o.node; }
    bool operator!=(const K11bIterator &o) const { return node != o.node; }
};

struct K11bTree {
    int compare_pad;
    K11bRbNode *header;
    unsigned count;
    K11bIterator begin() { return K11bIterator(header->left); }
    K11bIterator end() { return K11bIterator(header); }
    void clear() {
        if (count != 0) {
            w3d_auto_80351ea0(this, header->parent);
            header->left = header;
            header->parent = 0;
            header->right = header;
            count = 0;
        }
    }
    void erase(K11bIterator pos) {
        K11bRbNode *y = w3d_rb_rebalance_for_erase_80352010(pos.node, header->parent, header->left, header->right);
        if (y)
            w3d_handle_storage_release(y);
        --count;
    }
    void erase(K11bIterator first, K11bIterator last) {
        if (first == begin() && last == end())
            clear();
        else
            while (first != last) {
                erase(first++);
            }
    }
};

struct K11bRegistry {
    void *vtable;
    K11bTree tree;
};

extern "C" void w3d_k11b_registry_destroy_80352ae8(K11bRegistry *self, int flags) {
    self->vtable = lbl_80413a38;
    K11B_VCALL0(self, 12);
    K11bIterator it = self->tree.begin();
    K11bIterator last = self->tree.end();
    while (it != last) {
        K11B_VCALL1(it.node->value, 20, self);
        ++it;
    }
    self->tree.erase(self->tree.begin(), self->tree.end());
    K11B_VCALL0(self, 16);
    self->tree.clear();
    if (self->tree.header)
        w3d_handle_storage_release(self->tree.header);
    self->vtable = lbl_80413a50;
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}
