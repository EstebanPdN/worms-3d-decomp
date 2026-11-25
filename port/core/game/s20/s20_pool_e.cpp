#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_pool_e.c"
/* Pool entry acquisition through a held reference. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern Ptr32<char> fn_801ef048(Ptr32<char>, int, int, int);

int w3d_s20_store_float_pair_801738c0(Ptr32<char> self, Ptr32<float> value) {
    Ptr32<S20Object> volatile held;
    Ptr32<S20Object> current = *(Ptr32<Ptr32<S20Object>>)(*(Ptr32<Ptr32<char>>)(self + 128) + 48);
    Ptr32<char> base;
    Ptr32<char> list;
    Ptr32<char> pool;
    Ptr32<char> entry;
    int count;
    held = current;
    if (current != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)current->vtable[3])(current);
    base = (Ptr32<char>)held;
    pool = *(Ptr32<Ptr32<char>>)(base + 68);
    list = base + 68;
    count = *(Ptr32<int>)(pool + 24);
    if (*(Ptr32<unsigned short>)(pool + 4) == 1) {
        *(Ptr32<unsigned short>)(pool + 28) += 1;
        entry = pool + 32;
    } else {
        entry = fn_801ef048(list, count, 8, 2);
    }
    {
        int offset = *(Ptr32<int>)(self + 124) * 8;
        float first = value[0];
        float second = value[1];
        *(Ptr32<float>)(*(Ptr32<int>)(self + 124) * 8 + entry) = first;
        {
            Ptr32<float> slot = (Ptr32<float>)(offset + entry);
            slot[1] = second;
        }
    }
    {
        Ptr32<S20Object> tail = held;
        if (tail != 0)
            ((Ptr32<void (Ptr32<S20Object>)>)tail->vtable[4])(tail);
    }
    return 0;
}


}
