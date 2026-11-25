// Inferred sixteen-byte key, twelve-byte node, and twenty-eight-byte hash table.
struct Key {unsigned int first,second,third,fourth;};
struct Table;
struct Node {Node *next;const Key *key;unsigned int value;};
struct Iterator {Node *node;Table *table;
 Iterator(Node *n,Table *t):node(n),table(t){}
 Iterator(const Iterator &other):node(other.node),table(other.table){}
 bool operator==(const Iterator &other)const{return node==other.node;}
};
extern "C" int compare_802eedc0(const void *,const void *,unsigned int);
struct Buckets {Node **begin,**end,**capacity;
 unsigned int size()const{return end-begin;}
 Node *operator[](unsigned int index)const{return *(Node **)((unsigned int)begin+(index<<2));}
};
struct Table {unsigned int unknown;Buckets buckets;unsigned int other[3];
 Iterator find(const Key *const &key) {
  Node *node=buckets[(key->first+key->third)%buckets.size()];
  for(;node;node=node->next)if(compare_802eedc0(node->key,key,16)==0)break;
  return Iterator(node,this);
 }
 Iterator end(){return Iterator(0,this);}
 int lookup(const Key *key,unsigned int *out) {
  Iterator it=find(key);
  if(it==end()) return (int)0x80004005;
  *out=it.node->value;return 0;
 }
 int read(const Key *key,unsigned int *out){unsigned int value;int status=lookup(key,&value);*out=value;return status;}
};
struct Owner {unsigned char opaque[36];Table table;};
extern "C" unsigned int w3d_cx10b_hash_service_lookup_802117ec(Owner *self,const Key *key){unsigned int result;int status=self->table.read(key,&result);if(status<0)return 0;else return result;}



