#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_pool_a.c"
/* Pool entry acquisition with reference counting. */
extern Ptr32<char> fn_801ef048(Ptr32<char>, int, int, int);

int w3d_s20_acquire_pair_entry_801a91e8(Ptr32<char> self, int count) {
    if (*(Ptr32<int>)(self + 160) == 0) {
        Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 176);
        Ptr32<char> pool;
        Ptr32<char> list;
        count = count + count;
        list = owner + 20;
        pool = *(Ptr32<Ptr32<char>>)list;
        if (*(Ptr32<unsigned short>)(pool + 4) == 1 && count == *(Ptr32<int>)(pool + 24))
            *(Ptr32<unsigned short>)(pool + 28) += 1;
        else
            fn_801ef048(list, count, 4, 1);
    }
    return 0;
}

}
