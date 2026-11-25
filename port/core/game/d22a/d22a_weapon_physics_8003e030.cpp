#include "w3d_ptr.h"
#line 1 "d22a_weapon_physics_8003e030.cpp"
/* Weapon physics resources (0x8003e030): loads the "Gravity",
 * "Low.Gravity.Multiplier" and "Water.Level" resources into +96/+100/+104
 * through one handle (retaining the new object, releasing the previous one
 * and the handle), then subscribes the object to the message of cache
 * 0x804ad1b4 with the handler slot at +108 (0x80162024). Field and type
 * names are inferred from the original instructions. Strings and globals are
 * external views of original data; the unit owns no data.
 *
 * The subscription takes the message id by const reference; the int result
 * of the cache lookup converts to a temporary at the call, which gets the
 * last stack slot (sp+28) as in the original. A named local id takes the
 * first slot, before the property keys of the inline loader. */
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
private:
    Handle(const Handle &);
};
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Weapon {
    char unknown00[96];
    Ptr32<Object> gravity;              /* +96 */
    Ptr32<Object> lowGravityMultiplier; /* +100 */
    Ptr32<Object> waterLevel;           /* +104 */
    char subscription[4];         /* +108 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<Weapon>, const unsigned short &, Ptr32<void>);
extern MessageCache w3d_message_804ad1b4;
extern "C" char w3d_string_80374628[]; /* "Gravity" */
extern "C" char w3d_string_80374630[]; /* "Low.Gravity.Multiplier" */
extern "C" char w3d_string_80374648[]; /* "Water.Level" */

inline void LoadResource(Handle &h, Ptr32<const char> name, Ptr32<Object> &slot)
{
    PropertyKey key;
    key.name = name;
    h.value = 0;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Ptr32<Object> object = w3d_identity_80342a74(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
    if (h.value) h.value->vtable->release(h.value);
}

extern "C" void w3d_d22a_weapon_physics_8003e030(Ptr32<Weapon> self)
{
    Handle handle;
    LoadResource(handle, w3d_string_80374628, self->gravity);
    LoadResource(handle, w3d_string_80374630, self->lowGravityMultiplier);
    LoadResource(handle, w3d_string_80374648, self->waterLevel);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ad1b4, 1), self->subscription);
}


