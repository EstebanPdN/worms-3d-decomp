#include "w3d_ptr.h"
#line 1 "d21a_donkey_start_80060cc0.cpp"
/* Concrete Donkey start-up (0x80060cc0): queries the model (result unused),
 * loads the Donkey.Bounce and Donkey.MinBounceSpeed resources into retained
 * slots, reads Airstrike.TargetPoint, Donkey.ExtraHeight, Donkey.MinHeight and
 * Land.MaxHeight, clears the velocity, starts at the target point raised by
 * max(Land.MaxHeight + Donkey.ExtraHeight, Donkey.MinHeight), loads the
 * Donkey.Gravity resource, runs the set-up helpers 0x800eb6e4 and 0x800ed090,
 * reads Payload.Target, clears the +288 vector, starts the sound pair,
 * remembers the start velocity and registers itself as "Donkey" when the
 * registry service exists. Field and type names are inferred from the
 * original instructions. The property names are external views of the
 * original .rodata; the unit owns no data.
 *
 * One function-scope, non-copyable handle is reused for all three resource
 * loads: it keeps its stack slot below the vector and the property keys and
 * its address in one register from the start, as in the original. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
/* Resource handle filled by the resource property reader; not copyable. */
struct Handle {
    Ptr32<Object> value;
    Handle() {}
private:
    Handle(const Handle &);
};
struct Vec3 { float x, y, z; };
struct PropertyKey { Ptr32<const char> name; };
struct Donkey {
    char unknown000[36];
    Vec3 position;           /* +36 */
    Vec3 velocity;           /* +48 */
    char unknown03c[112];
    Ptr32<Object> gravity;         /* +172 */
    char unknown0b0[16];
    Ptr32<void> model;             /* +192 */
    char unknown0c4[80];
    Vec3 payloadTarget;      /* +276 */
    Vec3 vec288;             /* +288 */
    char unknown12c[8];
    Ptr32<Object> minBounceSpeed;  /* +308 */
    Ptr32<Object> bounce;          /* +312 */
    Vec3 startVelocity;      /* +316 */
    char registration[4];    /* +328, filled by the registry */
};
struct Registry;
struct RegistryVtable { Ptr32<void> unknown00[23]; Ptr32<void (Ptr32<Registry>, Ptr32<const char>, Ptr32<void>)> attach; };
struct Registry { Ptr32<RegistryVtable> vtable; };
struct Services { char unknown00[108]; Ptr32<Registry> registry; };
extern Ptr32<Services> w3d_services_804b1788;
/* 0x80341584 and 0x80342a74 return their argument unchanged. */
extern "C" Ptr32<void> w3d_identity_80341584(Ptr32<void>);
extern "C" Ptr32<void> w3d_model_query_801797b4(Ptr32<void>);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" int w3d_vector_property_800fc2f0(Ptr32<PropertyKey>, Ptr32<Vec3>);
extern "C" int w3d_float_property_800fc270(Ptr32<PropertyKey>, Ptr32<float>);
extern "C" void w3d_donkey_800eb6e4(Ptr32<Donkey>);
extern "C" void w3d_post_object_events_800ed090(Ptr32<Donkey>);
extern "C" void w3d_play_sound_pair_800edc28(Ptr32<Donkey>);
extern Vec3 w3d_zero_vector_8045e788;
extern "C" char w3d_string_803791f4[]; /* "Donkey.Bounce" */
extern "C" char w3d_string_80379204[]; /* "Donkey.MinBounceSpeed" */
extern "C" char w3d_string_8037921c[]; /* "Airstrike.TargetPoint" */
extern "C" char w3d_string_80379234[]; /* "Donkey.ExtraHeight" */
extern "C" char w3d_string_80379248[]; /* "Donkey.MinHeight" */
extern "C" char w3d_string_8037925c[]; /* "Land.MaxHeight" */
extern "C" char w3d_string_8037926c[]; /* "Donkey.Gravity" */
extern "C" char w3d_string_8037927c[]; /* "Payload.Target" */
extern "C" char w3d_string_8037928c[]; /* "Donkey" */
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }

/* Looks the named resource up and stores it, retained, in slot (the previous
 * value is released); the handle's own reference is released afterwards. */
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

extern "C" void w3d_d21a_donkey_start_80060cc0(Ptr32<Donkey> self)
{
    Handle handle;
    w3d_model_query_801797b4(w3d_identity_80341584(self->model));
    LoadResource(handle, w3d_string_803791f4, self->bounce);
    LoadResource(handle, w3d_string_80379204, self->minBounceSpeed);
    PropertyKey targetKey;
    targetKey.name = w3d_string_8037921c;
    Vec3 target;
    w3d_vector_property_800fc2f0(&targetKey, &target);
    PropertyKey extraKey;
    extraKey.name = w3d_string_80379234;
    float extraHeight;
    w3d_float_property_800fc270(&extraKey, &extraHeight);
    PropertyKey minKey;
    minKey.name = w3d_string_80379248;
    float minHeight;
    w3d_float_property_800fc270(&minKey, &minHeight);
    PropertyKey maxKey;
    maxKey.name = w3d_string_8037925c;
    float maxHeight;
    w3d_float_property_800fc270(&maxKey, &maxHeight);
    self->velocity = w3d_zero_vector_8045e788;
    self->position = target;
    self->position.y += Max(maxHeight + extraHeight, minHeight);
    LoadResource(handle, w3d_string_8037926c, self->gravity);
    w3d_donkey_800eb6e4(self);
    w3d_post_object_events_800ed090(self);
    PropertyKey payloadKey;
    payloadKey.name = w3d_string_8037927c;
    w3d_vector_property_800fc2f0(&payloadKey, &self->payloadTarget);
    self->vec288 = w3d_zero_vector_8045e788;
    w3d_play_sound_pair_800edc28(self);
    self->startVelocity = self->velocity;
    Ptr32<Registry> registry = w3d_services_804b1788->registry;
    if (registry) registry->vtable->attach(registry, w3d_string_8037928c, self->registration);
}


