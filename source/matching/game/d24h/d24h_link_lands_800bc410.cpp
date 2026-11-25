// Land chunk linking (Worms 3D GameCube PAL, 0x800bc410, 448 bytes).
//
// Groups compatible chunks and stores the group's index list in each member.
// One chunk variable and one loop index are reused across the loops, as the
// original's registers show. Names are inferred.

struct LandChunk;
extern "C" int fn_800bc390(void *, LandChunk *, unsigned short, int);
struct Land;
extern "C" LandChunk *w3d_get_800b4d98(Land *);
struct LandList {
    Land **start, **finish, **end_of_storage;
    unsigned size() const { return finish - start; }
    Land *&operator[](unsigned i) { return start[i]; }
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
extern "C" void *fn_801ef048(Links **, int, int, int);
extern "C" void *fn_802eee50(void *, const void *, unsigned, ...);
struct LinkRef {
    Links *links;
    unsigned short *Reserve(int n) {
        Links *l = links;
        if (l->kind == 1 && n == l->capacity) {
            l->refs++;
            return l->data;
        }
        return (unsigned short *)fn_801ef048(&links, n, 2, 0);
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
extern "C" void w3d_d24h_link_lands_800bc410(void *self) {
    unsigned total = lbl_8043bb64.size();
    for (unsigned i = 0; i < total; i++) {
        LandChunk *chunk = w3d_get_800b4d98(lbl_8043bb64[i]);
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
                const unsigned short *src = ids;
                chunk = w3d_get_800b4d98(lbl_8043bb64[src[j]]);
                fn_802eee50(chunk->links.Reserve(n), src, n + n);
            }
        }
    }
}
