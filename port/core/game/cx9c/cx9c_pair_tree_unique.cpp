#include "w3d_ptr.h"
#line 1 "cx9c_pair_tree_unique.cpp"
/* Inferred STLport tree insertion. PPC32 node: parent +4, children +8/+12,
 * two unsigned key words +16/+20; header +4 and count +8 in the owner. */
struct Cx9cNode {int color;Ptr32<Cx9cNode> parent; Ptr32<Cx9cNode> left; Ptr32<Cx9cNode> right;};
struct Cx9cValue {unsigned int first,second;};
struct Cx9cValueNode:Cx9cNode {Cx9cValue value __attribute__((aligned(__alignof__(Cx9cNode))));};
struct Cx9cTree {unsigned int allocator;Ptr32<Cx9cNode> header;unsigned int count;};
struct Cx9cIterator {Ptr32<Cx9cNode> node;template <class W3dU> Cx9cIterator(Ptr32<W3dU> w3d_p) : Cx9cIterator((Cx9cNode *)w3d_p.get()) {}
 Cx9cIterator(Cx9cNode *p):node(p){} Cx9cIterator(const Cx9cIterator &p):node(p.node){}};
struct Cx9cResult {Cx9cIterator iterator;bool inserted;Cx9cResult(const Cx9cIterator &p,const bool &b):iterator(p),inserted(b){}};
extern "C" Ptr32<Cx9cNode> cx9c_previous_803526a0(Ptr32<Cx9cNode>);
extern "C" Cx9cIterator cx9c_insert_80355b6c(Ptr32<Cx9cTree>,Ptr32<Cx9cNode>,Ptr32<Cx9cNode>,const Cx9cValue &,Ptr32<Cx9cNode>);
static inline bool cx9c_less_node(const Cx9cValue &a,Ptr32<const Cx9cValueNode> b) {
 return a.first<b->value.first || (a.first==b->value.first && a.second<b->value.second);
}
static inline bool cx9c_node_less(Ptr32<const Cx9cValueNode> a,const Cx9cValue &b) {
 return a->value.first<b.first || (a->value.first==b.first && a->value.second<b.second);
}
extern "C" Cx9cResult w3d_cx9c_pair_tree_unique_80355e40(Ptr32<Cx9cTree> self,const Cx9cValue &value) {
 Ptr32<Cx9cNode> parent=self->header; Ptr32<Cx9cNode> child=parent->parent;bool goes_left=true;
 while(child) {parent=child;goes_left=cx9c_less_node(value,(Ptr32<Cx9cValueNode>)parent);child=goes_left?w3d::R(parent->left):w3d::R(parent->right);}
 Cx9cIterator position(parent);
 if(goes_left) {Cx9cIterator first(self->header->left);
  if(position.node==first.node)return Cx9cResult(cx9c_insert_80355b6c(self,child,parent,value,0),true);
  position.node=cx9c_previous_803526a0(position.node);
 }
 goes_left=cx9c_node_less((Ptr32<Cx9cValueNode>)position.node,value);
 if(goes_left)return Cx9cResult(cx9c_insert_80355b6c(self,child,parent,value,0),true);
 return Cx9cResult(position,goes_left);
}


