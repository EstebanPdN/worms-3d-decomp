#include "w3d_ptr.h"
#line 1 "d24a_gravity_water_start_800670e0.cpp"
/* Gravity and water start-up (0x800670e0): loads the "Gravity" and
 * "Low.Gravity.Multiplier" resources into +72/+76 through one handle (cast
 * 0x80342a74, retaining the new object and releasing the previous one and the
 * handle), reads the "Water.Level" resource into +80, sets all components of
 * the vector at +52 to the original constant 0x8037a0c0, copies word +52 of
 * the engine context (0x80165254) into +92 and posts a 12-byte "created"
 * message (0x800c1620) for the object id at +20. Field and type names are
 * inferred from the original instructions. Strings and globals are external
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
private:
    Handle(const Handle &);
};
struct Vec3 { float x, y, z; };
struct PropertyKey { Ptr32<const char> name; };
struct ObjectId {
    unsigned value;
    ObjectId(unsigned v) { value = v; }
};
struct EngineContext { char unknown00[52]; int unknown52; };
struct GravityWater {
    char unknown00[20];
    unsigned id;             /* +20 */
    char unknown24[28];
    Vec3 vec52;              /* +52 */
    char unknown64[8];
    Ptr32<Object> gravity;         /* +72 */
    Ptr32<Object> lowGravityMultiplier; /* +76 */
    Ptr32<Object> waterLevel;      /* +80 */
    char unknown84[8];
    int unknown92;           /* +92 */
};
struct Message;
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" Ptr32<EngineContext> w3d_engine_context_80165254(void);
extern "C" Ptr32<Message> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> w3d_created_message_init_800c1620(Ptr32<Message>, const ObjectId &);
extern "C" int w3d_message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> w3d_message_arena_804b1754;
extern float w3d_constant_8037a0c0[];
extern "C" char w3d_string_8037a094[]; /* "Gravity" */
extern "C" char w3d_string_8037a09c[]; /* "Low.Gravity.Multiplier" */
extern "C" char w3d_string_8037a0b4[]; /* "Water.Level" */

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

extern "C" void w3d_d24a_gravity_water_start_800670e0(Ptr32<GravityWater> self)
{
    Handle handle;
    LoadResource(handle, w3d_string_8037a094, self->gravity);
    LoadResource(handle, w3d_string_8037a09c, self->lowGravityMultiplier);
    PropertyKey waterKey;
    waterKey.name = w3d_string_8037a0b4;
    w3d_resource_property_800fc1b0(&waterKey, &self->waterLevel);
    float zero = w3d_constant_8037a0c0[0];
    Ptr32<Vec3> v = &self->vec52;
    v->x = zero;
    v->y = zero;
    v->z = zero;
    self->unknown92 = w3d_engine_context_80165254()->unknown52;
    Ptr32<Message> message = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12);
    w3d_message_post_8016239c(w3d_created_message_init_800c1620(message, self->id));
}


