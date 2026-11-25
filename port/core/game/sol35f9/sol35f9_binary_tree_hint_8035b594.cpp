#include "w3d_ptr.h"
#line 1 "sol35f9_binary_tree_hint_8035b594.cpp"
// GWMP8P rev0, 0x8035b594: inferred bidirectional binary-key tree insertion hint.
// Read-only GC32 views: tree allocator +0, header +4, count +8;
// node color +0, parent +4, left/right +8/+12, binary-key pointer +16.
// Comparisons consume exactly 16 readable key bytes via original memcmp.
// External insert/unique helpers own all value/node construction.
// The observed nontrivial iterator copy requires native aggregate-return ABI.
// Original class names and STL identity remain inferred. Requires live valid
// tree nodes, readable keys, traversal bounds and compatible external helpers.
// Isolated instruction proof does not establish portable/runtime equivalence.
struct Sol35f9BinaryHint8035b594Node {int color;Ptr32<Sol35f9BinaryHint8035b594Node> parent; Ptr32<Sol35f9BinaryHint8035b594Node> left; Ptr32<Sol35f9BinaryHint8035b594Node> right;};
struct Sol35f9BinaryHint8035b594Value {Ptr32<const void> key;unsigned payload;};
extern "C" int sol35f9_binary_hint_8035b594_memcmp_802eedc0(Ptr32<const void>,Ptr32<const void>,unsigned int);
struct Sol35f9BinaryHint8035b594ValueNode:Sol35f9BinaryHint8035b594Node {Sol35f9BinaryHint8035b594Value value __attribute__((aligned(__alignof__(Sol35f9BinaryHint8035b594Node))));};
extern "C" Ptr32<Sol35f9BinaryHint8035b594Node> sol35f9_binary_hint_8035b594_next_80351ef8(Ptr32<Sol35f9BinaryHint8035b594Node>);
extern "C" Ptr32<Sol35f9BinaryHint8035b594Node> sol35f9_binary_hint_8035b594_previous_803526a0(Ptr32<Sol35f9BinaryHint8035b594Node>);
struct Sol35f9BinaryHint8035b594Iterator {
 Ptr32<Sol35f9BinaryHint8035b594Node> node;template <class W3dU> Sol35f9BinaryHint8035b594Iterator(Ptr32<W3dU> w3d_p) : Sol35f9BinaryHint8035b594Iterator((Sol35f9BinaryHint8035b594Node *)w3d_p.get()) {}
 Sol35f9BinaryHint8035b594Iterator(Sol35f9BinaryHint8035b594Node *p):node(p){} Sol35f9BinaryHint8035b594Iterator(const Sol35f9BinaryHint8035b594Iterator &p):node(p.node){}
 Sol35f9BinaryHint8035b594Iterator &operator++(){node=sol35f9_binary_hint_8035b594_next_80351ef8(node);return *this;}
 Sol35f9BinaryHint8035b594Iterator &operator--(){node=sol35f9_binary_hint_8035b594_previous_803526a0(node);return *this;}
 bool operator==(const Sol35f9BinaryHint8035b594Iterator &p)const{return node==p.node;}
 bool operator!=(const Sol35f9BinaryHint8035b594Iterator &p)const{return node!=p.node;}
};
struct Sol35f9BinaryHint8035b594Result {Sol35f9BinaryHint8035b594Iterator iterator;bool inserted;Sol35f9BinaryHint8035b594Result(const Sol35f9BinaryHint8035b594Iterator &p,const bool &b):iterator(p),inserted(b){}};
struct Sol35f9BinaryHint8035b594Tree {unsigned int allocator;Ptr32<Sol35f9BinaryHint8035b594Node> header;unsigned int count;};
extern "C" Sol35f9BinaryHint8035b594Iterator sol35f9_binary_hint_8035b594_insert_8035b32c(Ptr32<Sol35f9BinaryHint8035b594Tree>,Ptr32<Sol35f9BinaryHint8035b594Node>,Ptr32<Sol35f9BinaryHint8035b594Node>,const Sol35f9BinaryHint8035b594Value &,Ptr32<Sol35f9BinaryHint8035b594Node>);
extern "C" Sol35f9BinaryHint8035b594Result sol35f9_binary_hint_8035b594_unique_8035b478(Ptr32<Sol35f9BinaryHint8035b594Tree>,const Sol35f9BinaryHint8035b594Value &);
static inline bool sol35f9_binary_hint_8035b594_value_less_node(const Sol35f9BinaryHint8035b594Value &a,Ptr32<const Sol35f9BinaryHint8035b594ValueNode> b) {
 return sol35f9_binary_hint_8035b594_memcmp_802eedc0(a.key,b->value.key,16)<0;
}
static inline bool sol35f9_binary_hint_8035b594_node_less_value(Ptr32<const Sol35f9BinaryHint8035b594ValueNode> a,const Sol35f9BinaryHint8035b594Value &b) {
 return sol35f9_binary_hint_8035b594_memcmp_802eedc0(a->value.key,b.key,16)<0;
}
extern "C" Sol35f9BinaryHint8035b594Iterator sol35f9_binary_tree_hint_8035b594(Ptr32<Sol35f9BinaryHint8035b594Tree> self,Sol35f9BinaryHint8035b594Iterator position,const Sol35f9BinaryHint8035b594Value &value) {
 if(position.node==self->header->left) {
  if(self->count==0)return sol35f9_binary_hint_8035b594_unique_8035b478(self,value).iterator;
  {
   if(sol35f9_binary_hint_8035b594_value_less_node(value,(Ptr32<Sol35f9BinaryHint8035b594ValueNode>)position.node))return sol35f9_binary_hint_8035b594_insert_8035b32c(self,position.node,position.node,value,0);
   else if(!sol35f9_binary_hint_8035b594_node_less_value((Ptr32<Sol35f9BinaryHint8035b594ValueNode>)position.node,value)) return position;
   else {
    Sol35f9BinaryHint8035b594Iterator after=position;++after;
    if(after.node==self->header)return sol35f9_binary_hint_8035b594_insert_8035b32c(self,0,position.node,value,position.node);
    else if(sol35f9_binary_hint_8035b594_value_less_node(value,(Ptr32<Sol35f9BinaryHint8035b594ValueNode>)after.node)) {
     if(position.node->right==0)return sol35f9_binary_hint_8035b594_insert_8035b32c(self,0,position.node,value,position.node);
     else return sol35f9_binary_hint_8035b594_insert_8035b32c(self,after.node,after.node,value,0);
    }else return sol35f9_binary_hint_8035b594_unique_8035b478(self,value).iterator;
   }
  }
 }else if(position.node==self->header) {
  if(sol35f9_binary_hint_8035b594_node_less_value((Ptr32<Sol35f9BinaryHint8035b594ValueNode>)self->header->right,value))return sol35f9_binary_hint_8035b594_insert_8035b32c(self,0,self->header->right,value,position.node);
  else return sol35f9_binary_hint_8035b594_unique_8035b478(self,value).iterator;
 }else {
  Sol35f9BinaryHint8035b594Iterator before=position;--before;
  bool left=sol35f9_binary_hint_8035b594_value_less_node(value,(Ptr32<Sol35f9BinaryHint8035b594ValueNode>)position.node);
  if(left && sol35f9_binary_hint_8035b594_node_less_value((Ptr32<Sol35f9BinaryHint8035b594ValueNode>)before.node,value)) {
   if(before.node->right==0)return sol35f9_binary_hint_8035b594_insert_8035b32c(self,0,before.node,value,before.node);
   else return sol35f9_binary_hint_8035b594_insert_8035b32c(self,position.node,position.node,value,0);
  }else {
   Sol35f9BinaryHint8035b594Iterator after=position;++after;bool right=!left;
   if(!left && (right=sol35f9_binary_hint_8035b594_node_less_value((Ptr32<Sol35f9BinaryHint8035b594ValueNode>)position.node,value)) && (after.node==self->header || sol35f9_binary_hint_8035b594_value_less_node(value,(Ptr32<Sol35f9BinaryHint8035b594ValueNode>)after.node))) {
    if(position.node->right==0)return sol35f9_binary_hint_8035b594_insert_8035b32c(self,0,position.node,value,position.node);
    else return sol35f9_binary_hint_8035b594_insert_8035b32c(self,after.node,after.node,value,0);
   }
   if(left==right)return position;
   else return sol35f9_binary_hint_8035b594_unique_8035b478(self,value).iterator;
  }
 }
}

typedef char Sol35f9BinaryHint8035b594NodeSize[sizeof(Sol35f9BinaryHint8035b594Node)==16?1:-1];
typedef char Sol35f9BinaryHint8035b594IteratorSize[sizeof(Sol35f9BinaryHint8035b594Iterator)==4?1:-1];
typedef char Sol35f9BinaryHint8035b594ResultSize[sizeof(Sol35f9BinaryHint8035b594Result)==8?1:-1];
typedef char Sol35f9BinaryHint8035b594TreeSize[sizeof(Sol35f9BinaryHint8035b594Tree)==12?1:-1];


