#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ao.c"
/* Alpha-byte classification and an ordered-tree value lookup. */
typedef struct S20Entry { char pad[3]; unsigned char alpha; } S20Entry;
int w3d_s20_classify_item_bytes_801d5844(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> record;
    Ptr32<S20Entry> entries;
    unsigned int count;
    unsigned int i;
    int kind;
    if (*(Ptr32<int>)(base + 48) != 0) {
        *(Ptr32<int>)(base + 44) = 1;
        return 0;
    }
    record = *(Ptr32<Ptr32<char>>)(item + 20);
    kind = 0;
    count = *(Ptr32<unsigned int>)(record + 24);
    entries = (Ptr32<S20Entry>)(record + 32);
    for (i = 0; i < count; i++) {
        Ptr32<S20Entry> e = &entries[i];
        if (e->alpha != 255) {
            kind = 2;
            if (e->alpha != 0) {
                kind = 1;
                break;
            }
        }
    }
    *(Ptr32<int>)(base + 44) = kind;
    return 0;
}
int w3d_s20_find_value_801a688c(Ptr32<char> self, unsigned int key) {
    unsigned int wanted = key;
    Ptr32<unsigned int> wanted_ref = &wanted;
    Ptr32<char> header = self + 76;
    Ptr32<char> best = *(Ptr32<Ptr32<char>>)(header + 4);
    Ptr32<char> node = *(Ptr32<Ptr32<char>>)(best + 4);
    Ptr32<char> end;
    while (node != 0) {
        if (*(Ptr32<unsigned int>)(node + 16) >= key) {
            best = node;
            node = *(Ptr32<Ptr32<char>>)(node + 8);
        } else {
            node = *(Ptr32<Ptr32<char>>)(node + 12);
        }
    }
    end = *(Ptr32<Ptr32<char>>)(header + 4);
    if (best == end || *wanted_ref < *(Ptr32<unsigned int>)(best + 16))
        best = end;
    if (best == *(Ptr32<Ptr32<char>>)(self + 80))
        return 0;
    return *(Ptr32<int>)(best + 20);
}

}
