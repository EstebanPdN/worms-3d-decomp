#include "w3d_ptr.h"
#line 1 "d26j_rebuild_sorted_edges_8018b638.cpp"
// Rebuild a mesh's sorted edge table, GWMP8P rev0 0x8018b638. Frees the old
// table (0x801fe240), allocates 6 bytes per entry of the word list less one
// (0x801fe220), and fills each entry with the list word, a key looked up
// through page table (high byte, then part slot 10, then the low-byte id
// array) and the 1-based index, then sorts by qsort with comparator
// 0x8018b628. Names are inferred from use. The part slot is a named local
// because the original keeps 40 in a saved register (li r30,40; lwzx) rather
// than folding it into the load.

extern "C" void fn_801fe240(Ptr32<void>);
extern "C" Ptr32<void> fn_801fe220(unsigned);
extern "C" void qsort(Ptr32<void>, unsigned, unsigned, Ptr32<int (Ptr32<const void>, Ptr32<const void>)>);
extern "C" int cmp_8018b628(Ptr32<const void>, Ptr32<const void>);
struct Edge { unsigned short key, word, index; };
struct Page { Ptr32<void> data[16]; };
struct Leaf { char u[32]; unsigned short ids[1]; unsigned short Id(int i) { return ids[i]; } };
struct Pages { char u[32]; Ptr32<Page> page[256]; };
struct List { char u[24]; int count; char u28[4]; unsigned short pad; unsigned short word[1]; };
struct Mesh { char u[28]; Ptr32<Pages> pages; char u32[4]; Ptr32<List> list; };
struct Self {
    char u[36]; Ptr32<Mesh> mesh; char u40[28]; Ptr32<Edge> edges; unsigned count;
};
extern "C" int d26j_rebuild_sorted_edges_8018b638(Ptr32<Self> self)
{
    if (self->edges) fn_801fe240(self->edges);
    Ptr32<List> l = self->mesh->list;
    self->count = l->count - 1;
    self->edges = (Ptr32<Edge>)fn_801fe220(self->count * 6);
    Ptr32<Ptr32<Page>> pages = self->mesh->pages->page;
    for (unsigned i = 0; i < self->count; ++i) {
        unsigned short w = l->word[i];
        int part = 10; Ptr32<Leaf> leaf = (Ptr32<Leaf>)pages[w >> 8]->data[part];
        Ptr32<unsigned short> p = leaf->ids;
        unsigned short key = p[w & 255];
        self->edges[i].word = w;
        self->edges[i].key = key;
        self->edges[i].index = i + 1;
    }
    qsort(self->edges, self->count, 6, cmp_8018b628);
    return 0;
}


