// Inferred GC32 hash-table iteration API; native node and table layout.
// Retained STL gives an algorithm comparator, not original vendor identity.
namespace Sol35d11NthServiceV2 {
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
    if(node->next) node=node->next;
    else node=sol35d11_next_bucket_8035c988(this);
    return *this;
}
struct Hash {
    unsigned policy;
    Node **first, **finish, **capacity;
    Iterator end() { return Iterator(0,this); }
    Iterator begin() {
        unsigned n=0;
        if((unsigned(finish)-unsigned(first))>>2) {
            Node **slot=first;
            unsigned count=finish-first;
            do {
                Node *node=*slot++;
                if(node) return Iterator(node,this);
            } while(++n<count);
        }
        return end();
    }
};
struct Registry { unsigned prefix[9]; Hash services; };
typedef char node_size[(sizeof(Node)==12)?1:-1];
typedef char iterator_size[(sizeof(Iterator)==8)?1:-1];
}
extern "C" Sol35d11NthServiceV2::Service *sol35d11_nth_service_802118e8_v2(
    Sol35d11NthServiceV2::Registry *self, int index) {
    using namespace Sol35d11NthServiceV2;
    Iterator it=self->services.begin();
    for(;index && it!=self->services.end();--index) ++it;
    return it!=self->services.end()?it->service:0;
}
