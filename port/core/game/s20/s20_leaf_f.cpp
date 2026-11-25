#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_f.c"
/* Fixed-capacity entry stack with 20-byte entries starting at offset 32. */
typedef struct S20Entry { int words[5]; } S20Entry;

void w3d_s20_remove_entry_800f287c(Ptr32<char> self, int index) {
    if (*(Ptr32<int>)(self + 1032) == 0)
        return;
    *(Ptr32<S20Entry>)(self + index * 20 + 32) = *(Ptr32<S20Entry>)(self + *(Ptr32<int>)(self + 1032) * 20 + 12);
    *(Ptr32<int>)(self + 1032) -= 1;
}

}
