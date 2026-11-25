#include "w3d_ptr.h"
#line 1 "d24b_girder_camera_construct_80092d34.cpp"
/* Girder camera constructor (0x80092d34): runs the camera base constructor
 * 0x800d2dec with the "Shoulder" mode and 11, installs the secondary vtable
 * 0x8040f180 at +72, names the camera "GirderCamera" (0x800d31d8) and loads the
 * girder settings through one handle (0x800fc1b0, casts 0x80342fa4, 0x80342fa4,
 * 0x803426b4) into the retained slots +208, +212 and +216. Field and type names
 * are inferred from the original instructions. Strings and globals are external
 * views of original data; the unit owns no data. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct PropertyKey { Ptr32<const char> name; };
struct GirderCamera {
    char unknown00[72];
    Ptr32<void> vtable72;     /* +72 */
    char unknown76[132];
    Ptr32<Object> position;   /* +208 */
    Ptr32<Object> velocity;   /* +212 */
    Ptr32<Object> occlude;    /* +216 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342fa4(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_803426b4(Ptr32<Object>);
extern "C" Ptr32<void> w3d_camera_construct_800d2dec(Ptr32<GirderCamera>, Ptr32<void>, Ptr32<const char>, int);
extern "C" void w3d_camera_set_name_800d31d8(Ptr32<GirderCamera>, Ptr32<const char>);
extern unsigned char w3d_vtable_8040f180[];
extern "C" char w3d_string_8037e8b8[]; /* "Shoulder" */
extern "C" char w3d_string_8037e8c4[]; /* "GirderCamera" */
extern "C" char w3d_string_8037e8d4[]; /* "Girder.Position" */
extern "C" char w3d_string_8037e8e4[]; /* "Girder.Velocity" */
extern "C" char w3d_string_8037e8f4[]; /* "Girder.Camera.Occlude" */

template <Ptr32<Object> (*Cast)(Ptr32<Object>)>
inline void Store(Handle &h, Ptr32<const char> name, Ptr32<Object> &slot)
{
    PropertyKey key;
    key.name = name;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Ptr32<Object> object = Cast(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
}

extern "C" Ptr32<GirderCamera> w3d_d24b_girder_camera_construct_80092d34(Ptr32<GirderCamera> self, Ptr32<void> owner)
{
    w3d_camera_construct_800d2dec(self, owner, w3d_string_8037e8b8, 11);
    self->vtable72 = w3d_vtable_8040f180;
    self->position = 0;
    self->velocity = 0;
    self->occlude = 0;
    w3d_camera_set_name_800d31d8(self, w3d_string_8037e8c4);
    Handle handle;
    handle.value = 0;
    Store<w3d_identity_80342fa4>(handle, w3d_string_8037e8d4, self->position);
    Store<w3d_identity_80342fa4>(handle, w3d_string_8037e8e4, self->velocity);
    Store<w3d_identity_803426b4>(handle, w3d_string_8037e8f4, self->occlude);
    return self;
}


