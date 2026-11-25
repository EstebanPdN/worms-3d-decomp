#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_lookup_8008c454.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(int);

Ptr32<void> s19_lookup_slot_8008c454(Ptr32<void> self, int i)
{
    Ptr32<void> result = 0;
    Ptr32<void> object = w3d_s20_lookup_handle_object_80164fc8(*(Ptr32<int>)((char *)FIELD(self, void *, 308) + (i << 2)));
    if (object)
        result = object;
    return result;
}

Ptr32<void> s19_lookup_slot_8008c548(Ptr32<void> self, int i)
{
    Ptr32<void> result = 0;
    Ptr32<void> object = w3d_s20_lookup_handle_object_80164fc8(*(Ptr32<int>)((char *)FIELD(self, void *, 320) + (i << 2)));
    if (object)
        result = object;
    return result;
}

}
