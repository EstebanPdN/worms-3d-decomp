#include "w3d_ptr.h"
#line 1 "d24f_subscriber_destroy_80357958.cpp"
// GWMP8P rev0 0x80357958. Deleting destructor of a subscriber owning an
// STLport-shaped list of subscriptions. Each subscription yields a registry
// (slot 8) from whose listener set the subscriber is erased by key under the
// registry's scope guard (slots 12 and 16). List iterators convert to const
// iterators inside begin/end wrappers, so one temporary slot is reused.
// Identities are observed use only.
struct D24fRbNode { int color; Ptr32<D24fRbNode> parent; Ptr32<D24fRbNode> left; Ptr32<D24fRbNode> right; Ptr32<void> value; };
extern "C" {
Ptr32<D24fRbNode> w3d_rb_increment_80351ef8(Ptr32<D24fRbNode> node);
Ptr32<D24fRbNode> w3d_rb_rebalance_for_erase_80352010(Ptr32<D24fRbNode> z, Ptr32<D24fRbNode> &root, Ptr32<D24fRbNode> &leftmost, Ptr32<D24fRbNode> &rightmost);
void w3d_auto_80351ea0(Ptr32<void> tree, Ptr32<D24fRbNode> root);
void w3d_handle_storage_release(Ptr32<void> p);
void w3d_actor_member_delete_backend(Ptr32<void> p);
extern char lbl_80417240[];
extern char lbl_80413a50[];
}
typedef Ptr32<void (Ptr32<void>)> D24fMethod0;
typedef Ptr32<void (Ptr32<void>, Ptr32<void>)> D24fMethod1;
#define D24F_VCALL0(obj, slot) ((*(D24fMethod0 *)w3d::AG(*(Ptr32<char> *)w3d::AG(obj) + (slot)))(obj))
#define D24F_VCALL1(obj, slot, a) ((*(D24fMethod1 *)w3d::AG(*(Ptr32<char> *)w3d::AG(obj) + (slot)))((obj), (a)))
struct D24fTreeIteratorBase { Ptr32<D24fRbNode> node; void increment() { node = w3d_rb_increment_80351ef8(node); } };
inline bool operator==(const D24fTreeIteratorBase &a, const D24fTreeIteratorBase &b) { return a.node == b.node; }
inline bool operator!=(const D24fTreeIteratorBase &a, const D24fTreeIteratorBase &b) { return a.node != b.node; }
struct D24fIterator : D24fTreeIteratorBase {
    D24fIterator() {}
    template <class W3dU> D24fIterator(Ptr32<W3dU> w3d_p) : D24fIterator((D24fRbNode *)w3d_p.get()) {}
 D24fIterator(D24fRbNode *n) { node = n; }
    D24fIterator(const D24fIterator &o) { node = o.node; }
    D24fIterator &operator++() { increment(); return *this; }
    D24fIterator operator++(int) { D24fIterator tmp = *this; increment(); return tmp; }
};
struct D24fConstIterator : D24fTreeIteratorBase {
    D24fConstIterator() {}
    template <class W3dU> D24fConstIterator(Ptr32<W3dU> w3d_p) : D24fConstIterator((D24fRbNode *)w3d_p.get()) {}
 D24fConstIterator(D24fRbNode *n) { node = n; }
    D24fConstIterator(const D24fIterator &o) { node = o.node; }
    Ptr32<void> const & operator*() const { return node->value; }
    D24fConstIterator &operator++() { increment(); return *this; }
};
struct D24fRange { D24fIterator first; D24fIterator second; D24fRange(const D24fIterator &a, const D24fIterator &b) : first(a), second(b) {} };
inline unsigned tree_distance(D24fIterator first, const D24fIterator &last) { unsigned n = 0; while (first != last) { ++first; ++n; } return n; }
struct D24fTree {
    int compare_pad;
    Ptr32<D24fRbNode> header;
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
        Ptr32<D24fRbNode> y = w3d_rb_rebalance_for_erase_80352010(pos.node, header->parent, header->left, header->right);
        if (y) w3d_handle_storage_release(y);
        --count;
    }
    void erase(D24fIterator first, D24fIterator last) {
        if (first == begin() && last == end()) clear();
        else while (first != last) erase(first++);
    }
    D24fIterator lower_bound(Ptr32<void> const &k) {
        Ptr32<D24fRbNode> y = header; Ptr32<D24fRbNode> x = header->parent;
        while (x != 0) { if (!((unsigned)w3d::H(x->value) < (unsigned)w3d::H(k))) { y = x; x = x->left; } else x = x->right; }
        return D24fIterator(y);
    }
    D24fIterator upper_bound(Ptr32<void> const &k) {
        Ptr32<D24fRbNode> y = header; Ptr32<D24fRbNode> x = header->parent;
        while (x != 0) { if ((unsigned)w3d::H(k) < (unsigned)w3d::H(x->value)) { y = x; x = x->left; } else x = x->right; }
        return D24fIterator(y);
    }
    D24fRange equal_range(Ptr32<void> const &k) { return D24fRange(lower_bound(k), upper_bound(k)); }
    unsigned erase_key(Ptr32<void> const &k) {
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
struct D24fSubscription; struct D24fListNode { Ptr32<D24fListNode> next; Ptr32<D24fListNode> prev; Ptr32<D24fSubscription> data; };
struct D24fListIteratorBase { Ptr32<D24fListNode> node; void incr() { node = node->next; } };
inline bool operator==(const D24fListIteratorBase &a, const D24fListIteratorBase &b) { return a.node == b.node; }
inline bool operator!=(const D24fListIteratorBase &a, const D24fListIteratorBase &b) { return a.node != b.node; }
struct D24fListIterator : D24fListIteratorBase { template <class W3dU> D24fListIterator(Ptr32<W3dU> w3d_p) : D24fListIterator((D24fListNode *)w3d_p.get()) {}
 D24fListIterator(D24fListNode *n) { node = n; } D24fListIterator(const D24fListIterator &o) { node = o.node; }
  D24fListIterator operator++(int) { D24fListIterator tmp = *this; incr(); return tmp; } };
struct D24fListConstIterator : D24fListIteratorBase { D24fListConstIterator(const D24fListIterator &o) { node = o.node; } D24fListConstIterator &operator++() { incr(); return *this; }
  Ptr32<D24fSubscription> const & operator*() const { return node->data; } };
extern "C" void w3d_auto_80356e90(Ptr32<void> list);
struct D24fList { int pad; Ptr32<D24fListNode> header;
  D24fListIterator begin() { return D24fListIterator(header->next); }
  D24fListIterator end() { return D24fListIterator(header); }
  D24fListConstIterator cbegin() { return begin(); }
  D24fListConstIterator cend() { return end(); }
  D24fListIterator erase(D24fListIterator pos) { Ptr32<D24fListNode> c = pos.node; Ptr32<D24fListNode> n = c->next; Ptr32<D24fListNode> p = c->prev; p->next = n; n->prev = p; if (c) w3d_handle_storage_release(c); return D24fListIterator(n); }
  D24fListIterator erase(D24fListIterator first, D24fListIterator last) { while (first != last) erase(first++); return last; }
  void destroy() { w3d_auto_80356e90(this); if (header) w3d_handle_storage_release(header); }
};
struct D24fRegistry;
struct D24fScopeGuard { Ptr32<D24fRegistry> o; template <class W3dU> D24fScopeGuard(Ptr32<W3dU> w3d_p) : D24fScopeGuard((D24fRegistry *)w3d_p.get()) {}
 D24fScopeGuard(D24fRegistry *p); ~D24fScopeGuard(); };
struct D24fRegistry { Ptr32<void> vtable; D24fSet tree; };
struct D24fSubscriber { Ptr32<void> vtable; D24fList list; };
typedef Ptr32<Ptr32<D24fRegistry> (Ptr32<void>)> D24fGetRegistry;
inline D24fScopeGuard::D24fScopeGuard(D24fRegistry *p) : o(p) { D24F_VCALL0(o, 12); }
inline D24fScopeGuard::~D24fScopeGuard() { D24F_VCALL0(o, 16); }
inline void unhook(D24fListConstIterator first, D24fListConstIterator last, Ptr32<D24fSubscriber> self) {
    while (first != last) {
        Ptr32<D24fRegistry> r = (*(Ptr32<D24fGetRegistry>)(*(Ptr32<Ptr32<char>>)*first + 8))(*first);
        Ptr32<void> key = self;
        {
            D24fScopeGuard g(r);
            r->tree.t.erase_key(key);
        }
        w3d_actor_member_delete_backend(*first);
        ++first;
    }
}
extern "C" void d24f_subscriber_destroy_80357958(Ptr32<D24fSubscriber> self, int flags) {
    self->vtable = lbl_80417240;
    {
        D24fScopeGuard guard((Ptr32<D24fRegistry>)self);
        unhook(self->list.cbegin(), self->list.cend(), self);
        self->list.erase(self->list.begin(), self->list.end());
    }
    self->list.destroy();
    self->vtable = lbl_80413a50;
    if (flags & 1) w3d_actor_member_delete_backend(self);
}


