#include "w3d_ptr.h"
#line 1 "k2a_actor_restricted_800ef788.cpp"
struct K2aVec3 {
    float x, y, z;
    K2aVec3() {}
    K2aVec3(const K2aVec3 &other) { float a = other.x; float b = other.y; float c = other.z; x = a; y = b; z = c; }
};
struct K2aActor { char pad0[676]; K2aVec3 position; char pad_2b0[72]; int restricted; };
struct K2aTurnInfo { char pad0[156]; int override_flag; };
struct K2aHolder { char pad0[28]; Ptr32<void> ref; };
extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<void>);
extern "C" Ptr32<K2aTurnInfo> w3d_auto_801797b4(Ptr32<void>);
extern "C" int w3d_turns_get_active_actor(Ptr32<void>);
extern "C" Ptr32<K2aActor> w3d_s20_lookup_handle_object_80164fc8(Ptr32<void>);
extern "C" Ptr32<void> w3d_turns_804ab400;

extern "C" int k2a_actor_restricted_800ef788(Ptr32<K2aHolder> self)
{
    Ptr32<K2aTurnInfo> info = w3d_auto_801797b4(w3d_empty_80341584(self->ref));
    Ptr32<K2aActor> actor = w3d_s20_lookup_handle_object_80164fc8((Ptr32<void>)w3d::G(w3d_turns_get_active_actor(w3d_turns_804ab400)));
    K2aVec3 position(actor->position);
    int result = 0;
    if (actor->restricted == 0 || info->override_flag != 0)
        result = 1;
    return result;
}


