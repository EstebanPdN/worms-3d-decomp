#include "w3d_ptr.h"
#line 1 "sol35b3_plane_test_800f66ac.cpp"
// Reference ABI only. Caller supplies live group tail storage, pointer arrays,
// readable bounds and flag objects, with matching native 32-bit layouts.
// Pointer subtraction requires begin/end in one array. No cross-platform
// proof of fused floating-point rounding, NaNs or original class identity.
// Inferred field views, derived solely from original load offsets.
struct Bounds {
    char unknown0[20];
    float a;
    char unknown24[8];
    float b;
    char unknown36[8];
    float c;
    char unknown48[4];
    float x, y, z;
};
struct Item { char unknown0[56]; unsigned char flags; };
// A live array of Item pointers follows this 32-byte header in native storage.
struct Group { char unknown0[32]; };
struct Node { char unknown0[76]; Ptr32<Group> group; };
struct Owner { char unknown0[80]; Ptr32<Ptr32<Node>> nodes; };
struct Batch {
    char unknown0[16];
    Ptr32<Ptr32<Bounds>> begin; Ptr32<Ptr32<Bounds>> end;
    unsigned capacity;
    int group;
    unsigned size() const { return end-begin; }
    Ptr32<Bounds> const & at(unsigned index) const { return begin[index]; }
};
extern const float sol35b3_plane_8038c578[];
extern "C" int sol35b3_plane_test_800f66ac(Ptr32<Owner> s, Ptr32<const Batch> batch) {
    Ptr32<Ptr32<Item>> items = reinterpret_cast<Item **>(w3d::R(s->nodes[batch->group]->group + 1));
    for (unsigned i=0; i<batch->size(); ++i) {
        if (items[i]->flags & 2) {
            Ptr32<Bounds> b = batch->at(i);
            if (b->b * b->y - __builtin_fabsf(b->a * b->x)
                    - __builtin_fabsf(b->c * b->z) < sol35b3_plane_8038c578[0])
                return 0;
        }
    }
    return 1;
}


