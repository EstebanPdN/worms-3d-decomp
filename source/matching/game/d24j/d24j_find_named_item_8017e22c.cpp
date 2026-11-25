// Find a named item in the owner's 1920-slot hash table (Worms 3D GameCube PAL, 0x8017e22c).
//
// Tries a direct-mapped name cache at +7704 first, counting hits at 0x804ab5f4.
// On a miss (0x804ab5f8) it probes linearly from the name's hash, returning
// 0x80004005 at an empty slot or after 1919 probes; it records collisions,
// total probes and the longest probe, then stores the result in the cache.
// The inline string equality and index reader end a CSE region, so the cache
// entry address is recomputed from the saved offset, as in the original.

extern "C" int strcmp(const char *, const char *);
extern "C" unsigned fn_8017e1a0(struct Owner *, int);
extern "C" unsigned fn_8017e1c4(struct Owner *, const char *);
struct Header { unsigned short references, length, capacity; };
extern "C" void w3d_string_release_header(Header *);
struct String {
    char *data;
    Header *header() const { return ((Header *)data) - 1; }
    static void release(Header *h) { if (--h->references == 0) w3d_string_release_header(h); }
    String &operator=(const String &x) {
        ++x.header()->references;
        release(header());
        data = x.data;
        return *this;
    }
};
inline bool operator!=(const String &a, const String &b) { return strcmp(a.data, b.data) != 0; }
inline bool operator==(const String &a, const String &b) { return strcmp(a.data, b.data) == 0; }
template<class T> inline const T &v_max(const T &a, const T &b) { return a < b ? b : a; }
struct Item { void **vtable; const String *name() { return ((const String *(*)(Item *))vtable[17])(this); } };
struct Cache { String name; unsigned short index; };
struct Owner { void **vtable; char u[20]; Item *items[1920]; Cache cache[1];
    Item *&at(unsigned i) { return *(Item **)((i << 2) + (unsigned)this + 24); }
    Cache &entry(unsigned off) { return ((Owner *)(off + (unsigned)this))->cache[0]; }
    unsigned short &cached_index(unsigned off) { return ((Owner *)((char *)this + off))->cache[0].index; }
    char *cached_text(unsigned off) { return ((Owner *)(off + (unsigned)this))->cache[0].name.data; }
};
extern unsigned hits_804ab5f4, misses_804ab5f8, collisions_804ab5e4, total_804ab5f0, longest_804ab5ec;
inline unsigned short get_index(Owner *o, unsigned off) { return o->cached_index(off); }
extern "C" int d24j_find_named_item_8017e22c(Owner *self, const String *name, unsigned short *out)
{
    unsigned c = fn_8017e1a0(self, (int)name->data);
    unsigned off = c << 3;
    if (*(const String *)(off + (unsigned)self + 7704) == *name) {
        unsigned short index = get_index(self, off);
        unsigned i = index;
        if (i != 0xffff) {
            *out = index;
            if (*self->at(i)->name() == *name) {
                hits_804ab5f4++;
                return 0;
            }
        }
    }
    misses_804ab5f8++;
    unsigned h = fn_8017e1c4(self, name->data);
    if (self->at(h) == 0) {
fail:   return 0x80004005;
    }
    unsigned probes = 0;
    while (*self->at((h + probes) % 1920)->name() != *name) {
        probes++;
        if (self->at((h + probes) % 1920) == 0) goto fail;
        if (probes > 1919) goto fail;
    }
    if (probes != 0) collisions_804ab5e4++;
    total_804ab5f0 += probes;
    longest_804ab5ec = v_max(longest_804ab5ec, probes);
    *out = (h + probes) % 1920;
    unsigned off2 = c << 3;
    *(String *)(off2 + (unsigned)self + 7704) = *name;
    self->cached_index(off2) = *out;
    return 0;
}
