// GWMP8P rev0, 0x8035a6f8: inferred bidirectional ordered-tree insertion hint.
// Read-only GC32 views: tree allocator +0, header +4, count +8;
// node color +0, parent +4, left/right +8/+12, string storage pointer +16.
// External insert/unique helpers own all value construction and string retains.
// The observed iterator copy constructor requires the native aggregate-return
// ABI. Original class names and STL identity remain inferred.
// Valid live tree nodes, compatible string storage, iterator bounds and complete
// external insert/compare contracts are required; no portable/runtime proof.
struct Sol35f9StringHint8035a6f8Node {int color;Sol35f9StringHint8035a6f8Node *parent,*left,*right;};
struct Sol35f9StringHint8035a6f8Value {const char *key;unsigned payload;};
extern "C" int sol35f9_strcmp_802ef234(const char *,const char *);
struct Sol35f9StringHint8035a6f8ValueNode:Sol35f9StringHint8035a6f8Node {Sol35f9StringHint8035a6f8Value value;};
extern "C" Sol35f9StringHint8035a6f8Node *sol35f9_string_hint_8035a6f8_next_80351ef8(Sol35f9StringHint8035a6f8Node *);
extern "C" Sol35f9StringHint8035a6f8Node *sol35f9_string_hint_8035a6f8_previous_803526a0(Sol35f9StringHint8035a6f8Node *);
struct Sol35f9StringHint8035a6f8Iterator {
 Sol35f9StringHint8035a6f8Node *node;Sol35f9StringHint8035a6f8Iterator(Sol35f9StringHint8035a6f8Node *p):node(p){} Sol35f9StringHint8035a6f8Iterator(const Sol35f9StringHint8035a6f8Iterator &p):node(p.node){}
 Sol35f9StringHint8035a6f8Iterator &operator++(){node=sol35f9_string_hint_8035a6f8_next_80351ef8(node);return *this;}
 Sol35f9StringHint8035a6f8Iterator &operator--(){node=sol35f9_string_hint_8035a6f8_previous_803526a0(node);return *this;}
 bool operator==(const Sol35f9StringHint8035a6f8Iterator &p)const{return node==p.node;}
 bool operator!=(const Sol35f9StringHint8035a6f8Iterator &p)const{return node!=p.node;}
};
struct Sol35f9StringHint8035a6f8Result {Sol35f9StringHint8035a6f8Iterator iterator;bool inserted;Sol35f9StringHint8035a6f8Result(const Sol35f9StringHint8035a6f8Iterator &p,const bool &b):iterator(p),inserted(b){}};
struct Sol35f9StringHint8035a6f8Tree {unsigned int allocator;Sol35f9StringHint8035a6f8Node *header;unsigned int count;};
extern "C" Sol35f9StringHint8035a6f8Iterator sol35f9_string_hint_8035a6f8_insert_8035a464(Sol35f9StringHint8035a6f8Tree *,Sol35f9StringHint8035a6f8Node *,Sol35f9StringHint8035a6f8Node *,const Sol35f9StringHint8035a6f8Value &,Sol35f9StringHint8035a6f8Node *);
extern "C" Sol35f9StringHint8035a6f8Result sol35f9_string_hint_8035a6f8_unique_8035a5e4(Sol35f9StringHint8035a6f8Tree *,const Sol35f9StringHint8035a6f8Value &);
static inline bool sol35f9_string_hint_8035a6f8_value_less_node(const Sol35f9StringHint8035a6f8Value &a,const Sol35f9StringHint8035a6f8ValueNode *b) {
 return sol35f9_strcmp_802ef234(a.key,b->value.key)<0;
}
static inline bool sol35f9_string_hint_8035a6f8_node_less_value(const Sol35f9StringHint8035a6f8ValueNode *a,const Sol35f9StringHint8035a6f8Value &b) {
 return sol35f9_strcmp_802ef234(a->value.key,b.key)<0;
}
extern "C" Sol35f9StringHint8035a6f8Iterator sol35f9_string_tree_hint_8035a6f8(Sol35f9StringHint8035a6f8Tree *self,Sol35f9StringHint8035a6f8Iterator position,const Sol35f9StringHint8035a6f8Value &value) {
 if(position.node==self->header->left) {
  if(self->count==0)return sol35f9_string_hint_8035a6f8_unique_8035a5e4(self,value).iterator;
  {
   if(sol35f9_string_hint_8035a6f8_value_less_node(value,(Sol35f9StringHint8035a6f8ValueNode *)position.node))return sol35f9_string_hint_8035a6f8_insert_8035a464(self,position.node,position.node,value,0);
   else if(!sol35f9_string_hint_8035a6f8_node_less_value((Sol35f9StringHint8035a6f8ValueNode *)position.node,value)) return position;
   else {
    Sol35f9StringHint8035a6f8Iterator after=position;++after;
    if(after.node==self->header)return sol35f9_string_hint_8035a6f8_insert_8035a464(self,0,position.node,value,position.node);
    else if(sol35f9_string_hint_8035a6f8_value_less_node(value,(Sol35f9StringHint8035a6f8ValueNode *)after.node)) {
     if(position.node->right==0)return sol35f9_string_hint_8035a6f8_insert_8035a464(self,0,position.node,value,position.node);
     else return sol35f9_string_hint_8035a6f8_insert_8035a464(self,after.node,after.node,value,0);
    }else return sol35f9_string_hint_8035a6f8_unique_8035a5e4(self,value).iterator;
   }
  }
 }else if(position.node==self->header) {
  if(sol35f9_string_hint_8035a6f8_node_less_value((Sol35f9StringHint8035a6f8ValueNode *)self->header->right,value))return sol35f9_string_hint_8035a6f8_insert_8035a464(self,0,self->header->right,value,position.node);
  else return sol35f9_string_hint_8035a6f8_unique_8035a5e4(self,value).iterator;
 }else {
  Sol35f9StringHint8035a6f8Iterator before=position;--before;
  bool left=sol35f9_string_hint_8035a6f8_value_less_node(value,(Sol35f9StringHint8035a6f8ValueNode *)position.node);
  if(left && sol35f9_string_hint_8035a6f8_node_less_value((Sol35f9StringHint8035a6f8ValueNode *)before.node,value)) {
   if(before.node->right==0)return sol35f9_string_hint_8035a6f8_insert_8035a464(self,0,before.node,value,before.node);
   else return sol35f9_string_hint_8035a6f8_insert_8035a464(self,position.node,position.node,value,0);
  }else {
   Sol35f9StringHint8035a6f8Iterator after=position;++after;bool right=!left;
   if(!left && (right=sol35f9_string_hint_8035a6f8_node_less_value((Sol35f9StringHint8035a6f8ValueNode *)position.node,value)) && (after.node==self->header || sol35f9_string_hint_8035a6f8_value_less_node(value,(Sol35f9StringHint8035a6f8ValueNode *)after.node))) {
    if(position.node->right==0)return sol35f9_string_hint_8035a6f8_insert_8035a464(self,0,position.node,value,position.node);
    else return sol35f9_string_hint_8035a6f8_insert_8035a464(self,after.node,after.node,value,0);
   }
   if(left==right)return position;
   else return sol35f9_string_hint_8035a6f8_unique_8035a5e4(self,value).iterator;
  }
 }
}

typedef char Sol35f9StringHint8035a6f8NodeSize[sizeof(Sol35f9StringHint8035a6f8Node)==16?1:-1];
typedef char Sol35f9StringHint8035a6f8IteratorSize[sizeof(Sol35f9StringHint8035a6f8Iterator)==4?1:-1];
typedef char Sol35f9StringHint8035a6f8ResultSize[sizeof(Sol35f9StringHint8035a6f8Result)==8?1:-1];
typedef char Sol35f9StringHint8035a6f8TreeSize[sizeof(Sol35f9StringHint8035a6f8Tree)==12?1:-1];
