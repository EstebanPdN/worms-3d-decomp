// Nth entry of a service hash table (Worms 3D GameCube PAL, 0x802118e8).
//
// Walks the hash table at +36 from its first occupied bucket, advancing
// index entries (a null next link continues in the next bucket, 0x8035c988).
// Returns the service of the reached entry, or null at the end of the table.
//
// Iterators are real two-word objects: both words are written at sp+8/sp+12
// and the end iterators at sp+16/sp+20 and sp+24/sp+28, and 0x8035c988 reads
// both words of the iterator it receives. begin() is the usual loop over the
// bucket vector.

struct Key { unsigned int words[4]; };
struct Service;
struct Entry {
    const Key *key;
    Service *service;
};
struct Node {
    Node *next;
    Entry entry;
};
struct Hash;
struct Iterator {
    Node *node;
    Hash *table;
    Iterator(Node *n, Hash *t) : node(n), table(t) {}
    bool operator!=(const Iterator &o) const { return node != o.node; }
    Iterator &operator++();
    Entry *operator->() const { return &node->entry; }
};
extern "C" Node *next_bucket_8035c988(Iterator *);
inline Iterator &Iterator::operator++() {
    if (!node->next) node = next_bucket_8035c988(this);
    else node = node->next;
    return *this;
}
struct Buckets {
    Node **first, **finish, **capacity;
    unsigned int size() const { return (unsigned int)(finish - first); }
    Node *&operator[](unsigned int n) { return *(first + n); }
};
struct Hash {
    unsigned int unknown00;
    Buckets buckets;
    Iterator end() { return Iterator(0, this); }
    Iterator begin() {
        for (unsigned int n = 0; n < buckets.size(); ++n)
            if (buckets[n]) return Iterator(buckets[n], this);
        return end();
    }
};
struct Registry {
    unsigned char unknown00[36];
    Hash services;
};

extern "C" Service *w3d_d25k_nth_service_802118e8(Registry *self, int index) {
    Hash *h = &self->services;
    Iterator it = h->begin();
    for (; index && it != h->end(); --index) ++it;
    return it != h->end() ? it->service : 0;
}
