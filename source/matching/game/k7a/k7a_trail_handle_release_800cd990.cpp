struct K7aTrailEntity;
extern "C" K7aTrailEntity *w3d_s20_lookup_handle_object_80164fc8(int handle);
extern "C" void w3d_trail_graphic_entity_set_flag_80122af8(K7aTrailEntity *entity);

struct K7aHandle
{
    int value;
    K7aHandle() { value = -1; }
};

struct K7aTrailOwner
{
    char pad0[32];
    int trail_handle;
};

extern "C" void w3d_k7a_trail_handle_release_800cd990(K7aTrailOwner *self)
{
    K7aHandle none;
    if (self->trail_handle != -1)
    {
        K7aTrailEntity *entity = w3d_s20_lookup_handle_object_80164fc8(self->trail_handle);
        if (entity)
            w3d_trail_graphic_entity_set_flag_80122af8(entity);
        self->trail_handle = none.value;
    }
}
