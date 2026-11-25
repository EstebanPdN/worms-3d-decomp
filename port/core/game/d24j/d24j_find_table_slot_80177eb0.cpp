#include "w3d_ptr.h"
#line 1 "d24j_find_table_slot_80177eb0.cpp"
// Find a named slot in the open-addressed table (Worms 3D GameCube PAL, 0x80177eb0).
//
// Tries the direct-mapped pointer cache at +44 first (hits 0x804ab5bc), then
// probes linearly from the name hash modulo the capacity at +2116 (misses
// 0x804ab5c0). A slot that is empty and not marked deleted in the bit set at
// +28 ends the search with 0x80004005 and its index written out; 0xffff when
// every slot was probed. On success updates the search statistics and cache.
// The name is a plain pointer to the text pointer: as a scalar access it stays
// ordered after the counter store, which a struct member load does not.

extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" unsigned fn_80177e04(Ptr32<struct Table>, int);
extern "C" unsigned fn_80177e28(Ptr32<struct Table>, Ptr32<const char>);
struct String { Ptr32<char> data; };
template<class T> inline const T &v_max(const T &a, const T &b) { return a < b ? b : a; }
struct Item { Ptr32<Ptr32<void>> vtable; Ptr32<const char> name() { return ((Ptr32<Ptr32<const char> (Ptr32<Item>)>)vtable[8])(this); } };
struct Cache { Ptr32<const char> key; unsigned short index; };
struct Bits { Ptr32<unsigned int> words; bool test(unsigned i) { return (*(Ptr32<unsigned int>)((Ptr32<char>)words + (i >> 5 << 2)) & (1 << (i & 31))) != 0; } };
struct Table { char u[24]; Ptr32<Ptr32<Item>> entries; Bits deleted; char u32[12]; Cache cache[256]; char pad[24]; unsigned capacity;
    Ptr32<Item> get(unsigned i) { return entries[i]; }
};
extern unsigned hits_804ab5bc, misses_804ab5c0, collisions_804ab5ac, total_804ab5b8, longest_804ab5b4;
extern "C" int d24j_find_table_slot_80177eb0(Ptr32<Table> self, Ptr32<Ptr32<const char> const> name, Ptr32<unsigned short> out)
{
    unsigned c = fn_80177e04(self, (int)w3d::H((*name)));
    if (self->cache[c].key == *name) {
        *out = self->cache[c].index;
        if (strcmp(self->entries[*out]->name(), *name) == 0) {
            hits_804ab5bc++;
            return 0;
        }
    }
    misses_804ab5c0++;
    unsigned h = fn_80177e28(self, *name);
    if (self->get(h) == 0 && !self->deleted.test(h)) {
        *out = h;
        return 0x80004005;
    }
    unsigned probes = 0;
    unsigned pos = h % self->capacity;
    for (;;) {
        if (self->get(pos) == 0 && !self->deleted.test(pos)) {
            *out = pos;
            return 0x80004005;
        }
        Ptr32<Item> p = self->entries[pos];
        if (p && strcmp(p->name(), *name) == 0) {
            *out = pos;
            goto found;
        }
        probes++;
        pos = (h + probes) % self->capacity;
        if (probes >= self->capacity) {
            *out = 0xffff;
            return 0x80004005;
        }
    }
found:
    if (probes != 0) collisions_804ab5ac++;
    total_804ab5b8 += probes;
    longest_804ab5b4 = v_max(longest_804ab5b4, probes);
    self->cache[c].key = *name;
    self->cache[c].index = *out;
    return 0;
}


