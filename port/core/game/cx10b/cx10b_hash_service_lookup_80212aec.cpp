#include "w3d_ptr.h"
#line 1 "cx10b_hash_service_lookup_80212aec.cpp"
// Inferred sixteen-byte key, twelve-byte node, and twenty-eight-byte hash table.
struct Key {unsigned int first,second,third,fourth;};
struct Table;
struct Node {Ptr32<Node> next;Ptr32<const Key> key;unsigned int value;};
struct Iterator {Ptr32<Node> node;Ptr32<Table> table;
 Iterator(Ptr32<Node> n,Ptr32<Table> t):node(n),table(t){}
 Iterator(const Iterator &other):node(other.node),table(other.table){}
 bool operator==(const Iterator &other)const{return node==other.node;}
};
extern "C" int compare_802eedc0(Ptr32<const void>,Ptr32<const void>,unsigned int);
struct Buckets {Ptr32<Ptr32<Node>> begin; Ptr32<Ptr32<Node>> end; Ptr32<Ptr32<Node>> capacity;
 unsigned int size()const{return end-begin;}
 Ptr32<Node> operator[](unsigned int index)const{return *(Ptr32<Ptr32<Node>>)w3d::G(((unsigned int)w3d::H(begin)+(index<<2)));}
};
struct Table {unsigned int unknown;Buckets buckets;unsigned int other[3];
 Iterator find(Ptr32<const Key> const &key) {
  Ptr32<Node> node=buckets[(key->first+key->third)%buckets.size()];
  for(;node;node=node->next)if(compare_802eedc0(node->key,key,16)==0)break;
  return Iterator(node,this);
 }
 Iterator end(){return Iterator(0,this);}
 int lookup(Ptr32<const Key> key,Ptr32<unsigned int> out) {
  Iterator it=find(key);
  if(it==end()) return (int)0x80004005;
  *out=it.node->value;return 0;
 }
 int read(Ptr32<const Key> key,Ptr32<unsigned int> out){unsigned int value;int status=lookup(key,&value);*out=value;return status;}
};
struct Owner {unsigned char opaque[64];Table table;};
extern "C" unsigned int w3d_cx10b_hash_service_lookup_80212aec(Ptr32<Owner> self,Ptr32<const Key> key){unsigned int result=0;self->table.read(key,&result);return result;}



