#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d24j_find_named_item_8017e22c.cpp"
// Find a named item in the owner's 1920-slot hash table (Worms 3D GameCube PAL, 0x8017e22c).
//
// Tries a direct-mapped name cache at +7704 first, counting hits at 0x804ab5f4.
// On a miss (0x804ab5f8) it probes linearly from the name's hash, returning
// 0x80004005 at an empty slot or after 1919 probes; it records collisions,
// total probes and the longest probe, then stores the result in the cache.
// The inline string equality and index reader end a CSE region, so the cache
// entry address is recomputed from the saved offset, as in the original.

extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" unsigned fn_8017e1a0(Ptr32<struct Owner>, int);
extern "C" unsigned fn_8017e1c4(Ptr32<struct Owner>, Ptr32<const char>);
struct Header { unsigned short references, length, capacity; };
extern "C" void w3d_string_release_header(Ptr32<Header>);
struct String {
    Ptr32<char> data;
    Ptr32<Header> header() const { return ((Ptr32<Header>)data) - 1; }
    static void release(Ptr32<Header> h) { if (--h->references == 0) w3d_string_release_header(h); }
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
struct Item { Ptr32<Ptr32<void>> vtable; Ptr32<const String> name() { return ((Ptr32<Ptr32<const String> (Ptr32<Item>)>)vtable[17])(this); } };
struct Cache { String name; unsigned short index; };
struct Owner { Ptr32<Ptr32<void>> vtable; char u[20]; Ptr32<Item> items[1920]; Cache cache[1];
    Ptr32<Item> & at(unsigned i) { return ((Ptr32<Item> *)w3d_restab_slots())[i]; }   // port (v29): tabla nativa
    Cache &entry(unsigned off) { return ((Ptr32<Owner>)w3d::G((off + (unsigned)w3d::H(this))))->cache[0]; }
    unsigned short &cached_index(unsigned off) { return ((Ptr32<Owner>)((Ptr32<char>)this + off))->cache[0].index; }
    Ptr32<char> cached_text(unsigned off) { return ((Ptr32<Owner>)w3d::G((off + (unsigned)w3d::H(this))))->cache[0].name.data; }
};
extern unsigned hits_804ab5f4, misses_804ab5f8, collisions_804ab5e4, total_804ab5f0, longest_804ab5ec;
inline unsigned short get_index(Ptr32<Owner> o, unsigned off) { return o->cached_index(off); }
extern "C" int d24j_find_named_item_8017e22c(Ptr32<Owner> self, Ptr32<const String> name, Ptr32<unsigned short> out)
{
    unsigned c = fn_8017e1a0(self, (int)w3d::H(name->data));
    unsigned off = c << 3;
    if (*(Ptr32<const String>)w3d::G((off + (unsigned)w3d::H(self) + 7704)) == *name) {
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
    const unsigned cap = w3d_restab_cap();
    while (*self->at((h + probes) % cap)->name() != *name) {
        probes++;
        if (self->at((h + probes) % cap) == 0) goto fail;
        if (probes > cap - 1) goto fail;
    }
    if (probes != 0) collisions_804ab5e4++;
    total_804ab5f0 += probes;
    longest_804ab5ec = v_max(longest_804ab5ec, probes);
    *out = (h + probes) % cap;
    unsigned off2 = c << 3;
    *(Ptr32<String>)w3d::G((off2 + (unsigned)w3d::H(self) + 7704)) = *name;
    self->cached_index(off2) = *out;
    return 0;
}


