/* Original entries FUN_8003fb0c and FUN_8003f860. Names/types inferred.
 * Resource method implementations remain external dynamic dependencies.
 */
struct HandleVector3 {
    float x, y, z;
    HandleVector3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct HandleResource;
struct HandleResourceMethods {
    unsigned int unknown_00[3];
    void (*acquire)(HandleResource *);
    void (*release)(HandleResource *);
    unsigned int unknown_14[14];
    void (*set_position)(HandleResource *, const HandleVector3 *, unsigned int);
    unsigned int unknown_50;
    void (*set_radius_vector)(HandleResource *, const HandleVector3 *, unsigned int);
    void (*activate)(HandleResource *, unsigned int);
};
struct HandleResource { HandleResourceMethods *methods; };
struct HandleSlot {
    float x, y, z, radius, radius_squared;
    unsigned int slot_word, unknown_18;
    HandleResource *resource;
};
struct HandleTable { HandleSlot *slots; unsigned char unknown_04[12]; };
extern "C" HandleTable w3d_handle_table;
inline HandleSlot &handle_slot(HandleSlot *base, unsigned int i) { return *(base + i); }
inline void acquire_resource(HandleResource *object)
{
    if (object != 0) object->methods->acquire(object);
}
inline void release_resource(HandleResource *object)
{
    if (object != 0) object->methods->release(object);
}
struct HandleResourceReference {
    HandleResource *object;
    HandleResourceReference(HandleResource *value) : object(value) { acquire_resource(object); }
    ~HandleResourceReference() { release_resource(object); }
};
extern "C" void w3d_handle_activate_resource(unsigned int handle)
{
    HandleResourceReference captured(handle_slot(w3d_handle_table.slots, handle).resource);
    if (captured.object != 0) captured.object->methods->activate(captured.object, 0);
}
extern "C" void w3d_handle_update_resource(unsigned int handle)
{
    HandleSlot *slot = &handle_slot(w3d_handle_table.slots, handle);
    if (slot->resource != 0) {
        float radius = slot->radius;
        HandleVector3 position(slot->x, slot->y, slot->z);
        HandleVector3 radius_vector(radius, radius, radius);
        slot->resource->methods->set_position(slot->resource, &position, 0);
        HandleResource *resource = handle_slot(w3d_handle_table.slots, handle).resource;
        resource->methods->set_radius_vector(resource, &radius_vector, 0);
    }
}
