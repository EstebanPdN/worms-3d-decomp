#include "w3d_ptr.h"
#line 1 "handle_resource_callbacks.cpp"
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
    Ptr32<void (Ptr32<HandleResource>)> acquire;
    Ptr32<void (Ptr32<HandleResource>)> release;
    unsigned int unknown_14[14];
    Ptr32<void (Ptr32<HandleResource>, Ptr32<const HandleVector3>, unsigned int)> set_position;
    unsigned int unknown_50;
    Ptr32<void (Ptr32<HandleResource>, Ptr32<const HandleVector3>, unsigned int)> set_radius_vector;
    Ptr32<void (Ptr32<HandleResource>, unsigned int)> activate;
};
struct HandleResource { Ptr32<HandleResourceMethods> methods; };
struct HandleSlot {
    float x, y, z, radius, radius_squared;
    unsigned int slot_word, unknown_18;
    Ptr32<HandleResource> resource;
};
struct HandleTable { Ptr32<HandleSlot> slots; unsigned char unknown_04[12]; };
extern "C" HandleTable w3d_handle_table;
inline HandleSlot &handle_slot(Ptr32<HandleSlot> base, unsigned int i) { return *(base + i); }
inline void acquire_resource(Ptr32<HandleResource> object)
{
    if (object != 0) object->methods->acquire(object);
}
inline void release_resource(Ptr32<HandleResource> object)
{
    if (object != 0) object->methods->release(object);
}
struct HandleResourceReference {
    Ptr32<HandleResource> object;
    template <class W3dU> HandleResourceReference(Ptr32<W3dU> w3d_p) : HandleResourceReference((HandleResource *)w3d_p.get()) {}
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
    Ptr32<HandleSlot> slot = &handle_slot(w3d_handle_table.slots, handle);
    if (slot->resource != 0) {
        float radius = slot->radius;
        HandleVector3 position(slot->x, slot->y, slot->z);
        HandleVector3 radius_vector(radius, radius, radius);
        slot->resource->methods->set_position(slot->resource, &position, 0);
        Ptr32<HandleResource> resource = handle_slot(w3d_handle_table.slots, handle).resource;
        resource->methods->set_radius_vector(resource, &radius_vector, 0);
    }
}


