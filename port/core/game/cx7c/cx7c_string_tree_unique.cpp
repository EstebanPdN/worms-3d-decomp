#include "w3d_ptr.h"
#line 1 "cx7c_string_tree_unique.cpp"
/* Inferred STLport red-black tree insertion. Node offsets: color +0,
 * parent +4, left +8, right +12, value +16. Table header +4/count +8.
 * Public names describe structure, not original game class identity.
 */
inline void *operator new(__SIZE_TYPE__,void *p) throw() {return p;}
struct Cx7cTreeNode {int color;Ptr32<Cx7cTreeNode> parent; Ptr32<Cx7cTreeNode> left; Ptr32<Cx7cTreeNode> right;};
struct Cx7cTreeIterator {
    Ptr32<Cx7cTreeNode> node;
    template <class W3dU> Cx7cTreeIterator(Ptr32<W3dU> w3d_p) : Cx7cTreeIterator((Cx7cTreeNode *)w3d_p.get()) {}
 Cx7cTreeIterator(Cx7cTreeNode *p):node(p) {}
    Cx7cTreeIterator(const Cx7cTreeIterator &other):node(other.node) {}
};
extern "C" {
Ptr32<void> cx7c_allocate_80212fd4(unsigned int);
Ptr32<void> cx7c_allocation_fallback_803413d8(unsigned int);
void cx7c_rebalance_80352404(Ptr32<Cx7cTreeNode>,Ptr32<Cx7cTreeNode> &);
}
static inline Ptr32<void> cx7c_tree_allocate(unsigned int size) {
    Ptr32<void> p=cx7c_allocate_80212fd4(size);
    if (!p) p=cx7c_allocation_fallback_803413d8(size);
    return p;
}
struct Cx7cTreeString;
extern "C" {
void cx7c_string_base_init_8020c5c0(Ptr32<Cx7cTreeString>);
Ptr32<unsigned short> cx7c_string_header_80341884(Ptr32<Cx7cTreeString>);
int cx7c_strcmp_802ef234(Ptr32<const char>,Ptr32<const char>);
}
struct Cx7cTreeString {
    Ptr32<char> data;
    Cx7cTreeString(const Cx7cTreeString &other) {
        cx7c_string_base_init_8020c5c0(this);
        data=other.data;
        ++*cx7c_string_header_80341884(this);
    }
};
struct Cx7cTreeValue {
    Cx7cTreeString key;unsigned int payload;
    Cx7cTreeValue(const Cx7cTreeValue &other):key(other.key),payload(other.payload) {}
};
struct Cx7cValueNode:Cx7cTreeNode {Cx7cTreeValue value __attribute__((aligned(__alignof__(Cx7cTreeNode))));};
struct Cx7cTree {
    unsigned int unknown_00;Ptr32<Cx7cTreeNode> header;unsigned int count;
    Ptr32<Cx7cTreeNode> create(const Cx7cTreeValue &value) {
        Ptr32<Cx7cValueNode> node=(Ptr32<Cx7cValueNode>)cx7c_tree_allocate(sizeof(Cx7cValueNode));
        new (&node->value) Cx7cTreeValue(value);
        return node;
    }
};
struct Cx7cInsertResult {
    Cx7cTreeIterator iterator;bool inserted;
    Cx7cInsertResult(const Cx7cTreeIterator &it,const bool &yes):iterator(it),inserted(yes) {}
};
extern "C" Ptr32<Cx7cTreeNode> cx7c_tree_predecessor_803526a0(Ptr32<Cx7cTreeNode>);
extern "C" Cx7cTreeIterator cx7c_tree_insert_8035a464(Ptr32<Cx7cTree>,Ptr32<Cx7cTreeNode>,Ptr32<Cx7cTreeNode>,const Cx7cTreeValue &,Ptr32<Cx7cTreeNode>);
extern "C" Cx7cInsertResult w3d_cx7c_string_tree_insert_unique_8035a5e4(Ptr32<Cx7cTree> self,const Cx7cTreeValue &value)
{
    Ptr32<Cx7cTreeNode> parent=self->header;
    Ptr32<Cx7cTreeNode> child=parent->parent;
    bool goes_left=true;
    while (child) {
        parent=child;
        goes_left=cx7c_strcmp_802ef234(value.key.data,((Ptr32<Cx7cValueNode>)parent)->value.key.data)<0;
        child=goes_left?w3d::R(parent->left):w3d::R(parent->right);
    }
    Cx7cTreeIterator position(parent);
    if (goes_left) {
        Cx7cTreeIterator first(self->header->left);
        if (position.node==first.node)
            return Cx7cInsertResult(cx7c_tree_insert_8035a464(self,child,parent,value,0),true);
        position.node=cx7c_tree_predecessor_803526a0(position.node);
    }
    goes_left=cx7c_strcmp_802ef234(((Ptr32<Cx7cValueNode>)position.node)->value.key.data,value.key.data)<0;
    if (goes_left)
        return Cx7cInsertResult(cx7c_tree_insert_8035a464(self,child,parent,value,0),true);
    return Cx7cInsertResult(position,goes_left);
}


