#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_peer_800be8f8.c"
struct S19Ctx { char pad0[424]; int group; char pad428[36]; int value; };
extern struct { Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; int pad[2]; } lbl_8043bb64;
extern Ptr32<struct S19Ctx> w3d_get_800b4d98(Ptr32<void>);

int s19_find_peer_value_800be8f8(Ptr32<struct S19Ctx> self)
{
    Ptr32<Ptr32<void>> it = lbl_8043bb64.begin;
    Ptr32<Ptr32<void>> end = lbl_8043bb64.end;
    for (; it != end; it++) {
        if (w3d_get_800b4d98(*it) != self && w3d_get_800b4d98(*it)->group == self->group)
            return w3d_get_800b4d98(*it)->value;
    }
    return 0;
}

}
