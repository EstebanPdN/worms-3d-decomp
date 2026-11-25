#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_pool_c.c"
/* Pool entry acquisition through a held reference, then a typed store. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern Ptr32<char> fn_801ef048(Ptr32<char>, int, int, int);

int w3d_s20_store_flag_byte_80173d38(Ptr32<char> self) {
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
    pool = *(Ptr32<Ptr32<char>>)(base + 96);
    list = base + 96;
    count = *(Ptr32<int>)(pool + 24);
    if (*(Ptr32<unsigned short>)(pool + 4) == 1) {
        *(Ptr32<unsigned short>)(pool + 28) += 1;
        entry = pool + 32;
    } else {
        entry = fn_801ef048(list, count, 1, 2);
    }
    {
        unsigned int flags = *(Ptr32<unsigned int>)(self + 8);
        int index = *(Ptr32<int>)(self + 124);
        entry[index] = flags & 1;
    }
    {
        Ptr32<S20Object> tail = held;
        if (tail != 0)
            ((Ptr32<void (Ptr32<S20Object>)>)tail->vtable[4])(tail);
    }
    return 0;
}

}
