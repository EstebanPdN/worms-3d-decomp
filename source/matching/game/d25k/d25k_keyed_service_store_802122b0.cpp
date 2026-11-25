// Keyed service store (Worms 3D GameCube PAL, 0x802122b0).
//
// Retains the service (table slot 3 of its interface), then assigns it in the
// hash table at +248: the bucket is (key[0] + key[2]) mod bucket count, nodes
// compare the 16-byte key with memcmp, and a missing key inserts a key/zero
// entry through 0x8035c75c. Returns 0.
//
// Iterators are real two-word objects: the original writes both words at
// sp+8/sp+12 (found) and sp+16/sp+20 (end). The entry has a user copy
// constructor, so it is block mode and takes sp+24, below the key temporary at
// sp+32 that binds the reference parameter of operator[].

struct Interface;
struct InterfaceTable {
    void *reserved[3];
    int (*retain)(Interface *);
    int (*release)(Interface *);
};
struct Interface { InterfaceTable *table; };

struct Key { unsigned int first, second, third, fourth; };

struct Table;
struct Node {
    Node *next;
    const Key *key;
    unsigned int value;
};

struct Iterator {
    Node *node;
    Table *table;
    Iterator(Node *n, Table *t) : node(n), table(t) {}
    Iterator(const Iterator &other) : node(other.node), table(other.table) {}
    bool operator==(const Iterator &other) const { return node == other.node; }
};

extern "C" int compare_802eedc0(const void *, const void *, unsigned int);

struct Buckets {
    Node **begin, **end, **capacity;
    unsigned int size() const { return end - begin; }
    Node *operator[](unsigned int index) const {
        return *(Node **)((unsigned int)begin + (index << 2));
    }
};

struct Entry {
    const Key *key;
    unsigned int value;
    Entry(const Key *const &k, const unsigned int &v) : key(k), value(v) {}
    Entry(const Entry &o) : key(o.key), value(o.value) {}
};

extern "C" Entry *insert_8035c75c(Table *, const Entry &);

struct Table {
    unsigned int unknown00;
    Buckets buckets;
    unsigned int unknown10[3];
    Iterator find(const Key *const &key) {
        Node *node = buckets[(key->first + key->third) % buckets.size()];
        for (; node; node = node->next)
            if (compare_802eedc0(node->key, key, 16) == 0) break;
        return Iterator(node, this);
    }
    Iterator end() { return Iterator(0, this); }
    unsigned int &operator[](const Key *const &key) {
        Iterator it = find(key);
        if (it == end()) return insert_8035c75c(this, Entry(key, 0))->value;
        return it.node->value;
    }
    void set(const Key *key, unsigned int value) { (*this)[key] = value; }
};

struct Owner {
    unsigned char unknown00[248];
    Table table;
};

extern "C" int w3d_d25k_keyed_service_store_802122b0(Owner *self, const Key *key, Interface *value) {
    value->table->retain(value);
    self->table.set(key, (unsigned int)value);
    return 0;
}
