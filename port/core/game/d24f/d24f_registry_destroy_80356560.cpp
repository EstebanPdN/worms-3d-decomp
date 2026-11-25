#include "w3d_ptr.h"
#line 1 "d24f_registry_destroy_80356560.cpp"
// GWMP8P rev0 0x80356560. Deleting destructor of an observer registry
// holding an STLport-shaped set of listeners. The set wraps a tree: its
// begin/end return const iterators with a trivial copy, and erase casts them
// to the tree iterator whose user copy constructor forces its arguments and
// temporaries into stack slots. The notify guard is a scoped object whose
// constructor and destructor call slots 12 and 16. Identities are observed
// use only.
struct D24fRbNode { int color; Ptr32<D24fRbNode> parent; Ptr32<D24fRbNode> left; Ptr32<D24fRbNode> right; Ptr32<void> value; };
extern "C" {
Ptr32<D24fRbNode> w3d_rb_increment_80351ef8(Ptr32<D24fRbNode> node);
Ptr32<D24fRbNode> w3d_rb_rebalance_for_erase_80352010(Ptr32<D24fRbNode> z, Ptr32<D24fRbNode> &root, Ptr32<D24fRbNode> &leftmost, Ptr32<D24fRbNode> &rightmost);
void w3d_auto_80351ea0(Ptr32<void> tree, Ptr32<D24fRbNode> root);
void w3d_handle_storage_release(Ptr32<void> p);
void w3d_actor_member_delete_backend(Ptr32<void> p);
extern char lbl_80413a38[];
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
};
struct D24fSet {
    D24fTree t;
    D24fConstIterator begin() const { return t.begin(); }
    D24fConstIterator end() const { return t.end(); }
    void erase(D24fConstIterator f, D24fConstIterator l) { t.erase((D24fIterator &)f, (D24fIterator &)l); }
    void clear() { t.clear(); }
};
struct D24fRegistry;
struct D24fNotifyGuard { Ptr32<D24fRegistry> o; template <class W3dU> D24fNotifyGuard(Ptr32<W3dU> w3d_p) : D24fNotifyGuard((D24fRegistry *)w3d_p.get()) {}
 D24fNotifyGuard(D24fRegistry *p); ~D24fNotifyGuard(); };
struct D24fRegistry { Ptr32<void> vtable; D24fSet tree; };
inline D24fNotifyGuard::D24fNotifyGuard(D24fRegistry *p) : o(p) { D24F_VCALL0(o, 12); }
inline D24fNotifyGuard::~D24fNotifyGuard() { D24F_VCALL0(o, 16); }
inline void notify(D24fConstIterator first, D24fConstIterator last, Ptr32<D24fRegistry> self) {
    while (first != last) { D24F_VCALL1(*first, 20, self); ++first; }
}
extern "C" void d24f_registry_destroy_80356560(Ptr32<D24fRegistry> self, int flags) {
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


