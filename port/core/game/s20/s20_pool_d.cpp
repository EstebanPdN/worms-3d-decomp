#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_pool_d.c"
/* Pool entry acquisition through a held reference. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern Ptr32<char> fn_801ef048(Ptr32<char>, int, int, int);

int w3d_s20_store_byte_value_80173f88(Ptr32<char> self, int value) {
    Ptr32<S20Object> volatile held;
    if (*(Ptr32<unsigned char>)w3d::G(value) != *(Ptr32<unsigned char>)(self + 132)) {
        Ptr32<S20Object> current;
        Ptr32<char> base;
        Ptr32<char> list;
        Ptr32<char> pool;
        Ptr32<char> entry;
        int count;
        *(Ptr32<unsigned char>)(self + 132) = *(Ptr32<unsigned char>)w3d::G(value);
        current = *(Ptr32<Ptr32<S20Object>>)(*(Ptr32<Ptr32<char>>)(self + 128) + 48);
        held = current;
        if (current != 0)
            ((Ptr32<void (Ptr32<S20Object>)>)current->vtable[3])(current);
        base = (Ptr32<char>)held;
        pool = *(Ptr32<Ptr32<char>>)(base + 100);
        list = base + 100;
        count = *(Ptr32<int>)(pool + 24);
        if (*(Ptr32<unsigned short>)(pool + 4) == 1) {
            *(Ptr32<unsigned short>)(pool + 28) += 1;
            entry = pool + 32;
        } else {
            entry = fn_801ef048(list, count, 1, 2);
        }
        entry[*(Ptr32<int>)(self + 124)] = *(Ptr32<unsigned char>)(self + 132);
        {
            Ptr32<S20Object> tail = held;
            if (tail != 0)
                ((Ptr32<void (Ptr32<S20Object>)>)tail->vtable[4])(tail);
        }
    }
    return 0;
}

}
