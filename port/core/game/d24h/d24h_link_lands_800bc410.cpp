#include "w3d_ptr.h"
#line 1 "d24h_link_lands_800bc410.cpp"
// Land chunk linking (Worms 3D GameCube PAL, 0x800bc410, 448 bytes).
//
// Groups compatible chunks and stores the group's index list in each member.
// One chunk variable and one loop index are reused across the loops, as the
// original's registers show. Names are inferred.

struct LandChunk;
extern "C" int fn_800bc390(Ptr32<void>, Ptr32<LandChunk>, unsigned short, int);
struct Land;
extern "C" Ptr32<LandChunk> w3d_get_800b4d98(Ptr32<Land>);
struct LandList {
    Ptr32<Ptr32<Land>> start; Ptr32<Ptr32<Land>> finish; Ptr32<Ptr32<Land>> end_of_storage;
    unsigned size() const { return finish - start; }
    Ptr32<Land> & operator[](unsigned i) { return start[i]; }
};
extern LandList lbl_8043bb64;
struct Links {
    unsigned char u0[4];
    unsigned short kind;
    unsigned char u6[18];
    int capacity;
    unsigned short refs;
    unsigned char u30[2];
    unsigned short data[1];
};
extern "C" Ptr32<void> fn_801ef048(Ptr32<Ptr32<Links>>, int, int, int);
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
struct LinkRef {
    Ptr32<Links> links;
    Ptr32<unsigned short> Reserve(int n) {
        Ptr32<Links> l = links;
        if (l->kind == 1 && n == l->capacity) {
            l->refs++;
            return l->data;
        }
        return (Ptr32<unsigned short>)fn_801ef048(&links, n, 2, 0);
    }
};
struct LandChunk {
    unsigned char u0[424];
    int key;
    unsigned char u428[40];
    unsigned short count;
    unsigned short tag;
    LinkRef links;
};
extern "C" void w3d_d24h_link_lands_800bc410(Ptr32<void> self) {
    unsigned total = lbl_8043bb64.size();
    for (unsigned i = 0; i < total; i++) {
        Ptr32<LandChunk> chunk = w3d_get_800b4d98(lbl_8043bb64[i]);
        if (fn_800bc390(self, chunk, 0xffff, 0) == 0) continue;
        unsigned short ids[10];
        unsigned short tag = chunk->tag;
        int key = chunk->key;
        unsigned short sum = chunk->count;
        unsigned n = 1;
        unsigned j;
        ids[0] = i;
        for (j = 0; j < total && n <= 9; j++) {
            if (i != j) {
                chunk = w3d_get_800b4d98(lbl_8043bb64[j]);
                if (fn_800bc390(self, chunk, tag, key) != 0) {
                    sum += chunk->count;
                    if (sum <= 256) { ids[n] = j; n++; }
                }
            }
        }
        if (n > 1) {
            for (j = 0; j < n; j++) {
                Ptr32<const unsigned short> src = ids;
                chunk = w3d_get_800b4d98(lbl_8043bb64[src[j]]);
                fn_802eee50(chunk->links.Reserve(n), src, n + n);
            }
        }
    }
}


