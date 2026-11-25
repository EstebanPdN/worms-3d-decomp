struct K2aVec3 {
    float x, y, z;
    K2aVec3() {}
    K2aVec3(const K2aVec3 &other) { float a = other.x; float b = other.y; float c = other.z; x = a; y = b; z = c; }
};
struct K2aActor { char pad0[676]; K2aVec3 position; char pad_2b0[72]; int restricted; };
struct K2aTurnInfo { char pad0[156]; int override_flag; };
struct K2aHolder { char pad0[28]; void *ref; };
extern "C" void *w3d_empty_80341584(void *);
extern "C" K2aTurnInfo *w3d_auto_801797b4(void *);
extern "C" int w3d_turns_get_active_actor(void *);
extern "C" K2aActor *w3d_s20_lookup_handle_object_80164fc8(void *);
extern "C" void *w3d_turns_804ab400;

extern "C" int k2a_actor_restricted_800ef788(K2aHolder *self)
{
    K2aTurnInfo *info = w3d_auto_801797b4(w3d_empty_80341584(self->ref));
    K2aActor *actor = w3d_s20_lookup_handle_object_80164fc8((void *)w3d_turns_get_active_actor(w3d_turns_804ab400));
    K2aVec3 position(actor->position);
    int result = 0;
    if (actor->restricted == 0 || info->override_flag != 0)
        result = 1;
    return result;
}
