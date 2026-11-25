#include "w3d_ptr.h"
#line 1 "d17b_land_sphere_query_800bdb5c.cpp"
// Landscape sphere query over the registered land groups.
// Partial GC32 reference views: only observed offsets are named; full class
// identities and sizes are unknown. Recovered from the sol33a query draft.
// Built with the original paired-single float switch (-mps-float), which
// reserves the 8 frame bytes that pair the saved FPR.
struct d17b_QueryVec {
    float x, y, z;
    d17b_QueryVec(const d17b_QueryVec &v) { float a = v.x, b = v.y, c = v.z; x = a; y = b; z = c; }
};
struct d17b_LandGroup;
// The selection helpers keep 32 words before a 32-word (1024-bit) group mask at +128.
// The original valid domain keeps the group count within the 1024 mask bits.
struct d17b_LandMask {
    unsigned unknown00[32];
    unsigned masks[32];
};
struct d17b_LandGroupRange { Ptr32<Ptr32<d17b_LandGroup>> begin; Ptr32<Ptr32<d17b_LandGroup>> end; Ptr32<Ptr32<d17b_LandGroup>> capacity; };
extern d17b_LandGroupRange d17b_land_groups_8043bb64;
struct d17b_ResultValue;
extern Ptr32<d17b_ResultValue> d17b_land_query_result_804ae5dc;
extern "C" Ptr32<d17b_ResultValue> w3d_constructor_native_cast_80342a78(Ptr32<d17b_ResultValue>);
extern "C" int s9_update_value_80178d28(Ptr32<d17b_ResultValue>, Ptr32<const int>);
extern "C" void d17b_land_select_mask_800bd53c(Ptr32<d17b_LandMask>, const d17b_QueryVec &, float);
extern "C" int d17b_land_group_intersect_800b1410(Ptr32<d17b_LandGroup>, d17b_QueryVec, float);

// Clears the shared query result, selects the land groups touched by the
// sphere into the mask, then tests each selected group in registry order.
// Returns 1 at the first group that intersects the sphere, otherwise 0.
extern "C" int d17b_land_sphere_query_800bdb5c(Ptr32<d17b_LandMask> self, const d17b_QueryVec &position, float radius) {
    int changed = 0;
    s9_update_value_80178d28(w3d_constructor_native_cast_80342a78(d17b_land_query_result_804ae5dc), &changed);
    d17b_land_select_mask_800bd53c(self, position, radius);
    unsigned bit = 1;
    Ptr32<Ptr32<d17b_LandGroup>> i = d17b_land_groups_8043bb64.begin; Ptr32<Ptr32<d17b_LandGroup>> end = d17b_land_groups_8043bb64.end;
    if (i != end) {
        Ptr32<unsigned int> word = self->masks;
        do {
            if (*word & bit) {
                if (d17b_land_group_intersect_800b1410(*i, d17b_QueryVec(position), radius))
                    return 1;
            }
            bit <<= 1;
            if (!bit) { bit = 1; ++word; }
            ++i;
        } while (i != end);
    }
    return 0;
}


