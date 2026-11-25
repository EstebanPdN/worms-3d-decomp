// GWMP8P rev0 0x80357230. Deleting destructor of a subscriber owning an
// STLport-shaped list of subscriptions. Each subscription yields a registry
// (slot 8) from whose listener set the subscriber is erased by key under the
// registry's scope guard (slots 12 and 16). List iterators convert to const
// iterators inside begin/end wrappers, so one temporary slot is reused.
// Identities are observed use only.
struct D24fRbNode { int color; D24fRbNode *parent; D24fRbNode *left; D24fRbNode *right; void *value; };
extern "C" {
D24fRbNode *w3d_rb_increment_80351ef8(D24fRbNode *node);
D24fRbNode *w3d_rb_rebalance_for_erase_80352010(D24fRbNode *z, D24fRbNode *&root, D24fRbNode *&leftmost, D24fRbNode *&rightmost);
void w3d_auto_80351ea0(void *tree, D24fRbNode *root);
void w3d_handle_storage_release(void *p);
void w3d_actor_member_delete_backend(void *p);
extern char lbl_80417240[];
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
struct D24fRange { D24fIterator first; D24fIterator second; D24fRange(const D24fIterator &a, const D24fIterator &b) : first(a), second(b) {} };
inline unsigned tree_distance(D24fIterator first, const D24fIterator &last) { unsigned n = 0; while (first != last) { ++first; ++n; } return n; }
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
    D24fIterator lower_bound(void *const &k) {
        D24fRbNode *y = header; D24fRbNode *x = header->parent;
        while (x != 0) { if (!((unsigned)x->value < (unsigned)k)) { y = x; x = x->left; } else x = x->right; }
        return D24fIterator(y);
    }
    D24fIterator upper_bound(void *const &k) {
        D24fRbNode *y = header; D24fRbNode *x = header->parent;
        while (x != 0) { if ((unsigned)k < (unsigned)x->value) { y = x; x = x->left; } else x = x->right; }
        return D24fIterator(y);
    }
    D24fRange equal_range(void *const &k) { return D24fRange(lower_bound(k), upper_bound(k)); }
    unsigned erase_key(void *const &k) {
        D24fRange p = equal_range(k);
        unsigned n = tree_distance(p.first, p.second);
        erase(p.first, p.second);
        return n;
    }
};
struct D24fSet {
    D24fTree t;
    D24fConstIterator begin() const { return t.begin(); }
    D24fConstIterator end() const { return t.end(); }
    void erase(D24fConstIterator f, D24fConstIterator l) { t.erase((D24fIterator &)f, (D24fIterator &)l); }
    void clear() { t.clear(); }
};
struct D24fSubscription; struct D24fListNode { D24fListNode *next; D24fListNode *prev; D24fSubscription *data; };
struct D24fListIteratorBase { D24fListNode *node; void incr() { node = node->next; } };
inline bool operator==(const D24fListIteratorBase &a, const D24fListIteratorBase &b) { return a.node == b.node; }
inline bool operator!=(const D24fListIteratorBase &a, const D24fListIteratorBase &b) { return a.node != b.node; }
struct D24fListIterator : D24fListIteratorBase { D24fListIterator(D24fListNode *n) { node = n; } D24fListIterator(const D24fListIterator &o) { node = o.node; }
  D24fListIterator operator++(int) { D24fListIterator tmp = *this; incr(); return tmp; } };
struct D24fListConstIterator : D24fListIteratorBase { D24fListConstIterator(const D24fListIterator &o) { node = o.node; } D24fListConstIterator &operator++() { incr(); return *this; }
  D24fSubscription *const &operator*() const { return node->data; } };
extern "C" void w3d_auto_80356e90(void *list);
struct D24fList { int pad; D24fListNode *header;
  D24fListIterator begin() { return D24fListIterator(header->next); }
  D24fListIterator end() { return D24fListIterator(header); }
  D24fListConstIterator cbegin() { return begin(); }
  D24fListConstIterator cend() { return end(); }
  D24fListIterator erase(D24fListIterator pos) { D24fListNode *c = pos.node; D24fListNode *n = c->next; D24fListNode *p = c->prev; p->next = n; n->prev = p; if (c) w3d_handle_storage_release(c); return D24fListIterator(n); }
  D24fListIterator erase(D24fListIterator first, D24fListIterator last) { while (first != last) erase(first++); return last; }
  void destroy() { w3d_auto_80356e90(this); if (header) w3d_handle_storage_release(header); }
};
struct D24fRegistry;
struct D24fScopeGuard { D24fRegistry *o; D24fScopeGuard(D24fRegistry *p); ~D24fScopeGuard(); };
struct D24fRegistry { void *vtable; D24fSet tree; };
struct D24fSubscriber { void *vtable; D24fList list; };
typedef D24fRegistry *(*D24fGetRegistry)(void *);
inline D24fScopeGuard::D24fScopeGuard(D24fRegistry *p) : o(p) { D24F_VCALL0(o, 12); }
inline D24fScopeGuard::~D24fScopeGuard() { D24F_VCALL0(o, 16); }
inline void unhook(D24fListConstIterator first, D24fListConstIterator last, D24fSubscriber *self) {
    while (first != last) {
        D24fRegistry *r = (*(D24fGetRegistry *)(*(char **)*first + 8))(*first);
        void *key = self;
        {
            D24fScopeGuard g(r);
            r->tree.t.erase_key(key);
        }
        w3d_actor_member_delete_backend(*first);
        ++first;
    }
}
extern "C" void d24f_subscriber_destroy_80357230(D24fSubscriber *self, int flags) {
    self->vtable = lbl_80417240;
    {
        D24fScopeGuard guard((D24fRegistry *)self);
        unhook(self->list.cbegin(), self->list.cend(), self);
        self->list.erase(self->list.begin(), self->list.end());
    }
    self->list.destroy();
    self->vtable = lbl_80413a50;
    if (flags & 1) w3d_actor_member_delete_backend(self);
}
