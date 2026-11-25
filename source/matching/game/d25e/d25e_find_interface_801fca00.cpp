// (Worms 3D GameCube PAL, 0x801fca00).
//
// Iterator constructor: records the 16-byte key and the table index, takes
// the begin and end of row i of the 12-byte vector table 0x8045e890, then
// advances the cursor until an entry whose id pointer (entry+12) compares
// equal to the key with memcmp, or the end. Returns self.

extern "C" int memcmp(const void *, const void *, unsigned);
struct Entry { char u[12]; const void *id; };
struct Row { Entry **b, **e, **limit; Entry **begin() { return b; } Entry **end() { return e; } };
extern Row table_8045e890[];
struct Finder {
    Entry **cur, **end;
    const void *key;
    int index;
    Finder(int i, const void *k);
};
extern "C" Finder *w3d_d25e_find_interface_801fca00(Finder *self, int i, const void *k) {
    self->key = k;
    self->cur = table_8045e890[i].begin();
    self->index = i;
    self->end = table_8045e890[i].end();
    if (self->cur != self->end) {
        do {
            if (memcmp((*self->cur)->id, self->key, 16) == 0) break;
            ++self->cur;
        } while (self->cur != self->end);
    }
    return self;
}
