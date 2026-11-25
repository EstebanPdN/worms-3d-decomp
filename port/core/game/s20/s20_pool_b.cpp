#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_pool_b.c"
/* Pool entry acquisition with reference counting. */
extern Ptr32<char> fn_801ef048(Ptr32<char>, int, int, int);

int w3d_s20_acquire_two_entries_80171ee0(Ptr32<char> self, int count) {
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 76);
    Ptr32<char> list;
    Ptr32<char> pool;
    list = owner + 40;
    pool = *(Ptr32<Ptr32<char>>)list;
    if (*(Ptr32<unsigned short>)(pool + 4) == 1 && count == *(Ptr32<int>)(pool + 24))
        *(Ptr32<unsigned short>)(pool + 28) += 1;
    else
        fn_801ef048(list, count, 8, 1);
    list = owner + 36;
    pool = *(Ptr32<Ptr32<char>>)list;
    if (*(Ptr32<unsigned short>)(pool + 4) == 1 && count == *(Ptr32<int>)(pool + 24))
        *(Ptr32<unsigned short>)(pool + 28) += 1;
    else
        fn_801ef048(list, count, 8, 1);
    return 0;
}

extern Ptr32<void> fn_8034435c(int);

Ptr32<char> w3d_s20_acquire_sized_8018d5b8(Ptr32<char> self, Ptr32<int> out) {
    *out = (*(Ptr32<int>)(self + 184) - *(Ptr32<int>)(self + 180)) >> 1;
    fn_8034435c(*(Ptr32<int>)(self + 116));
    if (*(Ptr32<int>)(self + 240) != 0) {
        Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 172);
        Ptr32<char> list = owner + 72;
        Ptr32<char> pool = *(Ptr32<Ptr32<char>>)list;
        int count = *out + *out;
        if (*(Ptr32<unsigned short>)(pool + 4) == 1 && count == *(Ptr32<int>)(pool + 24)) {
            *(Ptr32<unsigned short>)(pool + 28) += 1;
            return pool + 32;
        }
        return fn_801ef048(list, count, 4, 0);
    }
    return 0;
}

}
