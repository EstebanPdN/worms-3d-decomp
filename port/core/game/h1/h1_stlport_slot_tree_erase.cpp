#include "w3d_ptr.h"
#line 1 "h1_stlport_slot_tree_erase.cpp"
/* STLport _Rb_tree::_M_erase for a map whose values hold an int key, a
 * held interface (released through vtable slot 0x10) and an object with an
 * out-of-line destructor (session b169b320): erases a subtree without
 * rebalancing, right subtree first, destroying each value and freeing the
 * node. */

extern "C" void w3d_handle_storage_release(Ptr32<void> p);
struct W3dInterface;
struct W3dInterfaceVtable
{
    Ptr32<void> unknown_00[4];
    Ptr32<int (Ptr32<W3dInterface>)> release;   /* 0x10 */
};
struct W3dInterface
{
    Ptr32<W3dInterfaceVtable> vtable;
};
struct W3dHeldRef
{
    Ptr32<W3dInterface> p;
    ~W3dHeldRef() { if (p) p->vtable->release(p); }
};
class W3dSlotObject
{
public:
    ~W3dSlotObject();
    int unknown_00;
};
struct W3dSlotEntry
{
    int key;                  /* node + 0x10 */
    W3dHeldRef owner;         /* node + 0x14 */
    W3dSlotObject object;     /* node + 0x18 */
};
struct W3dSlotNode
{
    int color;
    Ptr32<W3dSlotNode> parent;
    Ptr32<W3dSlotNode> left;
    Ptr32<W3dSlotNode> right;
    W3dSlotEntry value;
};
struct W3dSlotTree;
template <class T> inline void w3d_destroy(T *p) { p->~T(); }
extern "C" void w3d_slot_tree_erase_80355aec(Ptr32<W3dSlotTree> self, Ptr32<W3dSlotNode> x)
{
    while (x != 0) {
        w3d_slot_tree_erase_80355aec(self, x->right);
        Ptr32<W3dSlotNode> y = x->left;
        w3d_destroy(w3d::R(&x->value));
        if (x)
            w3d_handle_storage_release(x);
        x = y;
    }
}



