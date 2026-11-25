// Inferred GC32 hash-table iteration API; native node and table layout.
// Retained STL gives an algorithm comparator, not original vendor identity.
namespace Sol35d11NthService {
struct Key { unsigned words[4]; };
struct Service;
struct Pair { const Key *key; Service *service; };
struct Node { Node *next; Pair pair; };
struct Hash;
struct Iterator {
    Node *node; Hash *table;
    Iterator(Node *n, Hash *t): node(n), table(t) {}
    bool operator!=(const Iterator &other) const { return node != other.node; }
    Iterator &operator++();
    Pair *operator->() const { return &node->pair; }
};
extern "C" Node *sol35d11_next_bucket_8035c988(Iterator *);
inline Iterator &Iterator::operator++() {
    node=node->next;
    if(!node) node=sol35d11_next_bucket_8035c988(this);
    return *this;
}
struct Hash {
    unsigned policy;
    Node **first, **finish, **capacity;
    Iterator end() { return Iterator(0,this); }
    Iterator begin() {
        for(unsigned n=0;n<unsigned(finish-first);++n)
            if(first[n]) return Iterator(first[n],this);
        return end();
    }
};
struct Registry { unsigned prefix[9]; Hash services; };
typedef char node_size[(sizeof(Node)==12)?1:-1];
typedef char iterator_size[(sizeof(Iterator)==8)?1:-1];
}
extern "C" Sol35d11NthService::Service *sol35d11_nth_service_802118e8(
    Sol35d11NthService::Registry *self, int index) {
    using namespace Sol35d11NthService;
    Iterator it=self->services.begin();
    for(;index && it!=self->services.end();--index) ++it;
    return it!=self->services.end()?it->service:0;
}
