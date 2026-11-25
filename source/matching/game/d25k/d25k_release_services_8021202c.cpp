// Release every service of the keyed table (Worms 3D GameCube PAL, 0x8021202c).
//
// Reads the entry count of the hash table at +248 once, fetches each entry by
// position with the same walk as 0x802118e8 (inlined here), releases its
// service through table slot 4, then clears the table through 0x8035c81c.
//
// Iterators are real two-word objects: both words are written in the frame and
// 0x8035c988 reads both words of the iterator it receives.

struct Key { unsigned int words[4]; };
struct Service;
struct ServiceTable {
    void *reserved[4];
    int (*release)(Service *);
};
struct Service { ServiceTable *table; };
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
    unsigned int unknown10[2];
    unsigned int count;
    Iterator end() { return Iterator(0, this); }
    Iterator begin() {
        for (unsigned int n = 0; n < buckets.size(); ++n)
            if (buckets[n]) return Iterator(buckets[n], this);
        return end();
    }
};
extern "C" void clear_8035c81c(Hash *);
struct Registry {
    unsigned char unknown00[248];
    Hash services;
    Service *at(int index) {
        Hash *h = &services;
        Iterator it = h->begin();
        for (; index && it != h->end(); --index) ++it;
        return it != h->end() ? it->service : 0;
    }
};

extern "C" void w3d_d25k_release_services_8021202c(Registry *self) {
    Hash *t = &self->services;
    unsigned int n = t->count;
    for (unsigned int i = 0; i < n; ++i) {
        Service *s = self->at(i);
        s->table->release(s);
    }
    clear_8035c81c(&self->services);
}
