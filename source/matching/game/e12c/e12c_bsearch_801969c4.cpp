// Binary search of a float key in a sorted entry table (0x801969c4).
// The table node holds the entry array at +4 and a signed count at +8; each
// entry is 24 bytes with the key in the first four. A hit writes the index
// through out and returns 1; a miss writes the insertion index (0 for an empty
// table) and returns 0. A null node or null out returns 0 without writing.
struct e12c_Entry {
    float key;
    char rest[20];
};

struct e12c_Node {
    int unknown0;
    e12c_Entry *entries;
    unsigned short count;
};

struct e12c_Table {
    e12c_Node *node;
    int unknown4;
};

extern "C" int e12c_bsearch_801969c4(e12c_Table *table, int *out, float key) {
    if (table->node == 0) return 0;
    if (out == 0) return 0;
    *out = 0;
    int count = table->node->count;
    if (count > 0) {
        e12c_Entry *entries = table->node->entries;
        int lo = 0;
        int hi = count - 1;
        do {
            int mid = (lo + hi) / 2;
            e12c_Entry *entry = entries + mid;
            float value = entry->key;
            if (key < value) hi = mid - 1;
            else if (key > value) lo = mid + 1;
            else { *out = mid; return 1; }
        } while (lo <= hi);
        *out = lo;
    }
    return 0;
}
