#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_handle_800da7bc.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(int);
int s19_handle_value_800da7bc(Ptr32<void> self)
{
    int result;
    Ptr32<void> object;
    if (FIELD(self, int, 28) == -1) {
        result = -1;
    } else {
        object = w3d_s20_lookup_handle_object_80164fc8(FIELD(self, int, 28));
        if (object) {
            result = FIELD(object, int, 164);
        } else {
            FIELD(self, int, 28) = -1;
            result = -1;
        }
    }
    return result;
}

}
