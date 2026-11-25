#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_e.c"
/* Small vector copies and virtual forwarding helpers. */
typedef struct S20Vec { float x; float y; float z; } S20Vec;
typedef Ptr32<void (Ptr32<void>)> S20Call0;
typedef Ptr32<void (Ptr32<void>, int)> S20Call1;

void w3d_s20_set_pending_vector_800ecec0(Ptr32<char> self, Ptr32<S20Vec> value) {
    *(Ptr32<S20Vec>)(self + 236) = *value;
    *(Ptr32<int>)(self + 248) = 1;
}

void w3d_s20_get_vector_800ed070(Ptr32<char> self, Ptr32<S20Vec> out) {
    *out = *(Ptr32<S20Vec>)(self + 72);
}

void w3d_s20_update_span_800ecee8(Ptr32<char> self, int first, int second, Ptr32<S20Vec> value) {
    Ptr32<S20Vec> current;
    if (*(Ptr32<int>)(self + 248) != 0) {
        *(Ptr32<int>)(self + 248) = 0;
        current = (Ptr32<S20Vec>)(self + 224);
    } else {
        current = (Ptr32<S20Vec>)(self + 224);
        *(Ptr32<S20Vec>)(self + 236) = *current;
    }
    *(Ptr32<int>)(self + 216) = first;
    *(Ptr32<int>)(self + 220) = second;
    *(Ptr32<S20Vec>)(self + 224) = *value;
}

void w3d_s20_release_object_800e0400(Ptr32<char> self) {
    Ptr32<void> object = *(Ptr32<Ptr32<void>>)(self + 4);
    if (object != 0)
        ((S20Call1)*(Ptr32<Ptr32<void>>)(*(Ptr32<Ptr32<char>>)object + 8))(object, 3);
    *(Ptr32<int>)(self + 4) = 0;
}

}
