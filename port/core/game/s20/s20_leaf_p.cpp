#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_p.c"
/* Virtual helpers on held objects. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef Ptr32<int (Ptr32<S20Object>)> S20CallInt;
typedef Ptr32<void (Ptr32<S20Object>)> S20CallVoid;
typedef struct S20Owner132 { char pad[132]; Ptr32<S20Object> held; } S20Owner132;
typedef struct S20Owner72 { char pad[72]; Ptr32<S20Object> first; Ptr32<S20Object> second; } S20Owner72;

int w3d_s20_query_then_run_801ad108(Ptr32<S20Owner132> self) {
    if (((S20CallInt)self->held->vtable[6])(self->held) < 0)
        return 0;
    return ((S20CallInt)self->held->vtable[16])(self->held);
}

int w3d_s20_release_both_801b1ac4(Ptr32<S20Owner72> self) {
    int result = 0;
    if (self->first != 0)
        ((S20CallVoid)self->first->vtable[4])(self->first);
    self->first = 0;
    if (self->second != 0)
        ((S20CallVoid)self->second->vtable[4])(self->second);
    self->second = 0;
    return result;
}

}
