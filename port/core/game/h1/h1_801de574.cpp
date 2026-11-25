#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_801de574.c"
/* Small helpers (session 47b5d14a, hand-matched). Offsets come from the
 * original instructions; field meanings are inferred. */

typedef struct W3dVisitState_802097ac {
    int words[8];
} W3dVisitState_802097ac;

extern unsigned char w3d_vtable_80416a90[];
extern int w3d_sda_visit_context_804b0688;

void w3d_actor_node_destroy(Ptr32<void> node, int flags);
int fn_80217940(Ptr32<void> root, Ptr32<W3dVisitState_802097ac> state, Ptr32<void (void)> visit);
int fn_80209758(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>);

void w3d_h1_node_owner_destroy_801de574(Ptr32<void> self)
{
    *(Ptr32<Ptr32<void>>)self = w3d_vtable_80416a90;
    w3d_actor_node_destroy((Ptr32<char>)self + 40, 0);
}

typedef struct W3dVisitRoot_802097ac {
    Ptr32<void> root;
} W3dVisitRoot_802097ac;

int w3d_h1_visit_with_context_802097ac(Ptr32<W3dVisitRoot_802097ac> self, int context)
{
    W3dVisitState_802097ac state;
    w3d_sda_visit_context_804b0688 = context;
    fn_80217940(self->root, &state, fn_80209758);
    return 0;
}



}
