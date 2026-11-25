// d24i: 0x8010391c (320 bytes). Walk the zero-terminated id table 0x803fcdec.
// For each id allocate a 32-byte entry from the arena 0x804af15c, construct it
// with the id and the owner (0x8005ff48), and append it to the owner's pointer
// vector at +384. The vector has the engine's byte-addressed growth shape
// (cc17c_child_add_80186664): max(used + 1, used * 3 / 2) entries.
extern "C" void *allocate_80212fd4(unsigned int);
extern "C" void free_802134fc(void *);
extern "C" void *copy_802eee50(void *, const void *, unsigned int, ...);
static inline const int &maximum(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &minimum(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
struct d24i_Entry;
struct d24i_Slots {
    unsigned char *begin, *end, *capacity;
    void push(d24i_Entry *const &value) {
        if (end == capacity) {
            unsigned int used = end - begin;
            unsigned int bytes = maximum((int)used + 1, (int)(used + (used >> 1))) << 2;
            unsigned char *data = (unsigned char *)allocate_80212fd4(bytes);
            if (begin) { copy_802eee50(data, begin, minimum(bytes, used)); free_802134fc(begin); }
            begin = data; end = data + used; capacity = data + bytes;
        }
        *(d24i_Entry **)end = value; end += 4;
    }
};
struct d24i_Owner {
    unsigned char unknown00[384];
    d24i_Slots entries;                  // +384
};
extern "C" void *d24i_heap_allocate_802098d8(void *, unsigned int);
extern "C" d24i_Entry *d24i_entry_construct_8005ff48(void *, int, d24i_Owner *);
extern unsigned int d24i_arena_804af15c;
extern int d24i_ids_803fcdec[];

extern "C" void d24i_build_entries_8010391c(d24i_Owner *self) {
    for (int i = 0; d24i_ids_803fcdec[i]; ++i) {
        d24i_Entry *entry = d24i_entry_construct_8005ff48(d24i_heap_allocate_802098d8(&d24i_arena_804af15c, 32), d24i_ids_803fcdec[i], self);
        self->entries.push(entry);
    }
}
