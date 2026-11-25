// GWMP8P rev0 0x80356a04. Deleting destructor of an observer registry
// holding an STLport-shaped set of listeners. The set wraps a tree: its
// begin/end return const iterators with a trivial copy, and erase casts them
// to the tree iterator whose user copy constructor forces its arguments and
// temporaries into stack slots. The notify guard is a scoped object whose
// constructor and destructor call slots 12 and 16. Identities are observed
// use only.
struct D24fRbNode { int color; D24fRbNode *parent; D24fRbNode *left; D24fRbNode *right; void *value; };
extern "C" {
D24fRbNode *w3d_rb_increment_80351ef8(D24fRbNode *node);
D24fRbNode *w3d_rb_rebalance_for_erase_80352010(D24fRbNode *z, D24fRbNode *&root, D24fRbNode *&leftmost, D24fRbNode *&rightmost);
void w3d_auto_80351ea0(void *tree, D24fRbNode *root);
void w3d_handle_storage_release(void *p);
void w3d_actor_member_delete_backend(void *p);
extern char lbl_80413a38[];
extern char lbl_80413a50[];
}
typedef void (*D24fMethod0)(void *);
typedef void (*D24fMethod1)(void *, void *);
#define D24F_VCALL0(obj, slot) ((*(D24fMethod0 *)(*(char **)(obj) + (slot)))(obj))
#define D24F_VCALL1(obj, slot, a) ((*(D24fMethod1 *)(*(char **)(obj) + (slot)))((obj), (a)))
struct D24fTreeIteratorBase { D24fRbNode *node; void increment() { node = w3d_rb_increment_80351ef8(node); } };
inline bool operator==(const D24fTreeIteratorBase &a, const D24fTreeIteratorBase &b) { return a.node == b.node; }
inline bool operator!=(const D24fTreeIteratorBase &a, const D24fTreeIteratorBase &b) { return a.node != b.node; }
struct D24fIterator : D24fTreeIteratorBase {
    D24fIterator() {}
    D24fIterator(D24fRbNode *n) { node = n; }
    D24fIterator(const D24fIterator &o) { node = o.node; }
    D24fIterator &operator++() { increment(); return *this; }
    D24fIterator operator++(int) { D24fIterator tmp = *this; increment(); return tmp; }
};
struct D24fConstIterator : D24fTreeIteratorBase {
    D24fConstIterator() {}
    D24fConstIterator(D24fRbNode *n) { node = n; }
    D24fConstIterator(const D24fIterator &o) { node = o.node; }
    void *const &operator*() const { return node->value; }
    D24fConstIterator &operator++() { increment(); return *this; }
};
struct D24fTree {
    int compare_pad;
    D24fRbNode *header;
    unsigned count;
    D24fIterator begin() { return D24fIterator(header->left); }
    D24fConstIterator begin() const { return D24fConstIterator(header->left); }
    D24fConstIterator end() const { return D24fConstIterator(header); }
    D24fIterator end() { return D24fIterator(header); }
    void clear() {
        if (count != 0) {
            w3d_auto_80351ea0(this, header->parent);
            header->left = header;
            header->parent = 0;
            header->right = header;
            count = 0;
        }
    }
    void destroy() {
        clear();
        if (header) w3d_handle_storage_release(header);
    }
    void erase(D24fIterator pos) {
        D24fRbNode *y = w3d_rb_rebalance_for_erase_80352010(pos.node, header->parent, header->left, header->right);
        if (y) w3d_handle_storage_release(y);
        --count;
    }
    void erase(D24fIterator first, D24fIterator last) {
        if (first == begin() && last == end()) clear();
        else while (first != last) erase(first++);
    }
};
struct D24fSet {
    D24fTree t;
    D24fConstIterator begin() const { return t.begin(); }
    D24fConstIterator end() const { return t.end(); }
    void erase(D24fConstIterator f, D24fConstIterator l) { t.erase((D24fIterator &)f, (D24fIterator &)l); }
    void clear() { t.clear(); }
};
struct D24fRegistry;
struct D24fNotifyGuard { D24fRegistry *o; D24fNotifyGuard(D24fRegistry *p); ~D24fNotifyGuard(); };
struct D24fRegistry { void *vtable; D24fSet tree; };
inline D24fNotifyGuard::D24fNotifyGuard(D24fRegistry *p) : o(p) { D24F_VCALL0(o, 12); }
inline D24fNotifyGuard::~D24fNotifyGuard() { D24F_VCALL0(o, 16); }
inline void notify(D24fConstIterator first, D24fConstIterator last, D24fRegistry *self) {
    while (first != last) { D24F_VCALL1(*first, 20, self); ++first; }
}
extern "C" void d24f_registry_destroy_80356a04(D24fRegistry *self, int flags) {
    self->vtable = lbl_80413a38;
    {
        D24fNotifyGuard guard(self);
        notify(self->tree.begin(), self->tree.end(), self);
        self->tree.erase(self->tree.begin(), self->tree.end());
    }
    self->tree.t.destroy();
    self->vtable = lbl_80413a50;
    if (flags & 1) w3d_actor_member_delete_backend(self);
}
