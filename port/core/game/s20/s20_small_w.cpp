#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_w.c"
/* Slot-table lookups and record copies. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_80177eb0(Ptr32<char>, Ptr32<void>, Ptr32<unsigned short>);

int w3d_s20_query_slot_80176cd4(Ptr32<char> self, int key, Ptr32<int> out) {
    unsigned short index;
    int result;
    if (fn_80177eb0(self, w3d::G(key), &index) >= 0) {
        Ptr32<S20Object> object = ((Ptr32<Ptr32<S20Object>>)*(Ptr32<Ptr32<void>>)(self + 24))[index];
        *out = ((Ptr32<int (Ptr32<S20Object>)>)object->vtable[6])(object);
        result = 0;
    } else {
        *out = 8;
        result = 0x80004005;
    }
    return result;
}

extern void fn_8020bd38(Ptr32<char>, int);

int w3d_s20_copy_record_80174274(Ptr32<char> self, int unused, Ptr32<char> source) {
    unsigned int flags;
    int first;
    int second;
    unsigned short third;
    fn_8020bd38(self + 20, *(Ptr32<int>)source);
    *(Ptr32<unsigned char>)(self + 27) = *(Ptr32<unsigned char>)(source + 4);
    *(Ptr32<unsigned char>)(self + 26) = *(Ptr32<unsigned char>)(source + 5);
    first = *(Ptr32<int>)(source + 8);
    flags = *(Ptr32<unsigned int>)(self + 24);
    *(Ptr32<int>)(self + 32) = first;
    flags &= 0xffff7fff;
    *(Ptr32<int>)(self + 36) = *(Ptr32<int>)(source + 12);
    third = *(Ptr32<unsigned short>)(source + 20);
    *(Ptr32<unsigned short>)(self + 44) = third;
    second = *(Ptr32<int>)(source + 16);
    *(Ptr32<unsigned int>)(self + 24) = flags;
    *(Ptr32<int>)(self + 48) = second;
    return 0;
}

}
