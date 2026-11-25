// Inferred category-count query. Five pointer ranges start at offsets
// +0x1c,+0x2c,+0x3c,+0x4c,+0x5c. Each element is four bytes on GameCube.
// Category IDs map in the observed order 0,4,3,5,6; other IDs return zero.
struct R25bCountRange {
    unsigned *begin;
    unsigned *end;
    unsigned reserved[2];
};
struct R25bCategories {
    unsigned char reserved[0x1c];
    R25bCountRange ranges[5];
};
extern "C" int w3d_r25b_category_count_8027be7c(R25bCategories *owner, int category)
{
    switch (category) {
    case 0: return owner->ranges[0].end - owner->ranges[0].begin;
    case 4: return owner->ranges[1].end - owner->ranges[1].begin;
    case 3: return owner->ranges[2].end - owner->ranges[2].begin;
    case 5: return owner->ranges[3].end - owner->ranges[3].begin;
    case 6: return owner->ranges[4].end - owner->ranges[4].begin;
    default: return 0;
    }
}
