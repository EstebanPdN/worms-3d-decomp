#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_actor_restricted_8002b0a0.c"
typedef struct K2aActor { char pad0[760]; int restricted; } K2aActor;
typedef struct K2aTurnInfo { char pad0[156]; int override_flag; } K2aTurnInfo;
typedef struct K2aHolder { char pad0[44]; Ptr32<void> ref; } K2aHolder;
extern Ptr32<void> w3d_empty_80341584(Ptr32<void>);
extern Ptr32<K2aTurnInfo> w3d_auto_801797b4(Ptr32<void>);
extern int w3d_turns_get_active_actor(Ptr32<void>);
extern Ptr32<K2aActor> w3d_s20_lookup_handle_object_80164fc8(Ptr32<void>);
extern Ptr32<void> w3d_turns_804ab400;

int k2a_actor_restricted_8002b0a0(Ptr32<K2aHolder> self)
{
    Ptr32<K2aActor> actor = w3d_s20_lookup_handle_object_80164fc8(w3d::G(w3d_turns_get_active_actor(w3d_turns_804ab400)));
    int result;
    if (self->ref != 0) {
        Ptr32<K2aTurnInfo> info = w3d_auto_801797b4(w3d_empty_80341584(self->ref));
        int flag = 0;
        if (actor->restricted == 0 || info->override_flag != 0)
            flag = 1;
        return flag;
    }
    return actor->restricted == 0;
}

}
