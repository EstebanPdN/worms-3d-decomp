#include "w3d_ptr.h"
#line 1 "h1_item_lists.cpp"
/* Keyed item lists guarded by their owner's lock (session b169b320).
 * The owner locks itself through vtable slot 0x0c for the duration
 * (unlock: slot 0x10) and keeps an STLport list<Item *>. remove erases
 * every item whose key (item slot 0x08) equals key; derive appends, for
 * every such item, the item its slot 0x14 returns for arg. Three classes
 * share these bodies. The list code follows STLport (erase, insert with
 * __n/__p locals, nodes from __malloc_alloc with a throw() placement new). */

inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned int size);
extern "C" Ptr32<void> w3d_handle_storage_fallback(unsigned int size);
extern "C" void w3d_handle_storage_release(Ptr32<void> p);

struct W3dItem;
struct W3dItemVtable
{
    Ptr32<void> unknown_00[2];
    Ptr32<int (Ptr32<W3dItem>)> key;                    /* 0x08 */
    Ptr32<void> unknown_0c[2];
    Ptr32<Ptr32<W3dItem> (Ptr32<W3dItem>, int)> derive;   /* 0x14 */
};
struct W3dItem
{
    Ptr32<W3dItemVtable> vtable;
};

struct W3dListNode
{
    Ptr32<W3dListNode> next;
    Ptr32<W3dListNode> prev;
    Ptr32<W3dItem> data;
};
struct W3dListIter
{
    Ptr32<W3dListNode> node;
    W3dListIter() {}
    template <class W3dU> W3dListIter(Ptr32<W3dU> w3d_p) : W3dListIter((W3dListNode *)w3d_p.get()) {}
 W3dListIter(W3dListNode *n) : node(n) {}
    W3dListIter(const W3dListIter &o) : node(o.node) {}
    Ptr32<W3dItem> & operator*() const { return node->data; }
    bool operator!=(const W3dListIter &o) const { return node != o.node; }
    W3dListIter &operator++() { node = node->next; return *this; }
};
static inline Ptr32<void> w3d_malloc_alloc(unsigned int n)
{
    Ptr32<void> result = w3d_handle_storage_allocate(n);
    if (0 == result)
        result = w3d_handle_storage_fallback(n);
    return result;
}
struct W3dItemList
{
    int unknown_00;
    Ptr32<W3dListNode> node;
    W3dListIter begin() { return W3dListIter(node->next); }
    W3dListIter end() { return W3dListIter(node); }
    W3dListIter erase(W3dListIter position)
    {
        Ptr32<W3dListNode> next_node = position.node->next;
        Ptr32<W3dListNode> prev_node = position.node->prev;
        Ptr32<W3dListNode> n = position.node;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        if (n)
            w3d_handle_storage_release(n);
        return W3dListIter(next_node);
    }
    Ptr32<W3dListNode> create_node(Ptr32<W3dItem> const &x)
    {
        Ptr32<W3dListNode> p = (Ptr32<W3dListNode>)w3d_malloc_alloc(sizeof(W3dListNode));
        *(Ptr32<W3dItem> *)w3d::w3d_any_host(&p->data) = Ptr32<W3dItem>(x);
        return p;
    }
    W3dListIter insert(W3dListIter position, Ptr32<W3dItem> const &x)
    {
        Ptr32<W3dListNode> tmp = create_node(x);
        Ptr32<W3dListNode> n = position.node;
        Ptr32<W3dListNode> p = n->prev;
        tmp->next = n;
        tmp->prev = p;
        p->next = tmp;
        n->prev = tmp;
        return tmp;
    }
    void push_back(Ptr32<W3dItem> const &x) { insert(end(), x); }
};

struct W3dItemOwner;
struct W3dItemOwnerVtable
{
    Ptr32<void> unknown_00[3];
    Ptr32<void (Ptr32<W3dItemOwner>)> lock;     /* 0x0c */
    Ptr32<void (Ptr32<W3dItemOwner>)> unlock;   /* 0x10 */
};
struct W3dItemOwner
{
    Ptr32<W3dItemOwnerVtable> vtable;
    W3dItemList items;
};
struct W3dOwnerLock
{
    Ptr32<W3dItemOwner> owner;
    template <class W3dU> W3dOwnerLock(Ptr32<W3dU> w3d_p) : W3dOwnerLock((W3dItemOwner *)w3d_p.get()) {}
 W3dOwnerLock(W3dItemOwner *o) : owner(o) { owner->vtable->lock(owner); }
    ~W3dOwnerLock() { owner->vtable->unlock(owner); }
};

#define W3D_ITEM_LIST_OPS(REMOVE, DERIVE) \
extern "C" void REMOVE(W3dItemOwner *self, int key) \
{ \
    W3dOwnerLock lock(self); \
    W3dListIter it = self->items.begin(); \
    W3dListIter last = self->items.end(); \
    while (it != last) { \
        W3dListIter next = it; \
        ++next; \
        if ((*it)->vtable->key(*it) == key) \
            self->items.erase(it); \
        it = next; \
    } \
} \
 \
extern "C" void DERIVE(W3dItemOwner *self, int key, int arg) \
{ \
    W3dOwnerLock lock(self); \
    W3dListIter it = self->items.begin(); \
    W3dListIter last = self->items.end(); \
    for (; it != last; ++it) \
        if ((*it)->vtable->key(*it) == key) \
            self->items.push_back((*it)->vtable->derive(*it, arg)); \
}

W3D_ITEM_LIST_OPS(w3d_items_remove_key_80357c90, w3d_items_derive_key_80357d78)
W3D_ITEM_LIST_OPS(w3d_items_remove_key_80357ea0, w3d_items_derive_key_80357f88)
W3D_ITEM_LIST_OPS(w3d_items_remove_key_8035d960, w3d_items_derive_key_8035da48)


