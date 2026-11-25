#include "w3d_ptr.h"
#line 1 "d25k_release_services_8021202c.cpp"
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
    Ptr32<void> reserved[4];
    Ptr32<int (Ptr32<Service>)> release;
};
struct Service { Ptr32<ServiceTable> table; };
struct Entry {
    Ptr32<const Key> key;
    Ptr32<Service> service;
};
struct Node {
    Ptr32<Node> next;
    Entry entry;
};
struct Hash;
struct Iterator {
    Ptr32<Node> node;
    Ptr32<Hash> table;
    Iterator(Ptr32<Node> n, Ptr32<Hash> t) : node(n), table(t) {}
    bool operator!=(const Iterator &o) const { return node != o.node; }
    Iterator &operator++();
    Ptr32<Entry> operator->() const { return &node->entry; }
};
extern "C" Ptr32<Node> next_bucket_8035c988(Ptr32<Iterator>);
inline Iterator &Iterator::operator++() {
    if (!node->next) node = next_bucket_8035c988(this);
    else node = node->next;
    return *this;
}
struct Buckets {
    Ptr32<Ptr32<Node>> first; Ptr32<Ptr32<Node>> finish; Ptr32<Ptr32<Node>> capacity;
    unsigned int size() const { return (unsigned int)(finish - first); }
    Ptr32<Node> & operator[](unsigned int n) { return *(first + n); }
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
extern "C" void clear_8035c81c(Ptr32<Hash>);
struct Registry {
    unsigned char unknown00[248];
    Hash services;
    Ptr32<Service> at(int index) {
        Ptr32<Hash> h = &services;
        Iterator it = h->begin();
        for (; index && it != h->end(); --index) ++it;
        return it != h->end() ? w3d::R(it->service) : 0;
    }
};

extern "C" void w3d_d25k_release_services_8021202c(Ptr32<Registry> self) {
    Ptr32<Hash> t = &self->services;
    unsigned int n = t->count;
    for (unsigned int i = 0; i < n; ++i) {
        Ptr32<Service> s = self->at(i);
        s->table->release(s);
    }
    clear_8035c81c(&self->services);
}


