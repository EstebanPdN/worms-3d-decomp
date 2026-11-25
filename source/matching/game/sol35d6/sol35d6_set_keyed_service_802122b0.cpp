// Observed two-word hash iterators, pointer key, conditional insertion pair.
namespace Sol35d6SetKeyedService {
struct Key { unsigned words[4]; };
struct Service;
struct Vtable { void *prefix[3]; int (*retain)(Service *); };
struct Service { Vtable *table; };
struct Entry {
    const Key *key; Service *value;
    Entry(const Key *const &k,Service *const &v):key(k),value(v) {}
};
struct Node { Node *next; Entry entry; };
struct Hash;
struct Iterator {
    Node *node; Hash *table;
    Iterator(Node *p,Hash *t):node(p),table(t) {}
    bool operator==(const Iterator &other) const { return node==other.node; }
};
extern "C" int sol35d6_compare_802eedc0(const void *,const void *,unsigned);
extern "C" Entry *sol35d6_insert_8035c75c(Hash *,const Entry *);
struct Hash {
    unsigned unknown; Node **begin,**finish,**capacity;
    unsigned other[2],count;
    Iterator end() { return Iterator(0,this); }
    Iterator find(const Key *const &key) {
        unsigned bucket=(key->words[0]+key->words[2])/(unsigned(finish-begin));
        unsigned index=(key->words[0]+key->words[2])-bucket*unsigned(finish-begin);
        Node *node=*(Node **)((char *)begin+(index<<2));
        for(;node;node=node->next)
            if(sol35d6_compare_802eedc0(node->entry.key,key,16)==0) break;
        return Iterator(node,this);
    }
    Service *&operator[](const Key *const &key) {
        Iterator found=find(key);
        if(found==end()) {
            Entry entry(key,(Service *)0);
            return sol35d6_insert_8035c75c(this,&entry)->value;
        }
        return found.node->entry.value;
    }
};
struct Owner { unsigned prefix[62]; Hash values; };
}
extern "C" int sol35d6_set_keyed_service_802122b0(
    Sol35d6SetKeyedService::Owner *self,const Sol35d6SetKeyedService::Key *key,
    Sol35d6SetKeyedService::Service *value) {
    value->table->retain(value);
    self->values[key]=value;
    return 0;
}
