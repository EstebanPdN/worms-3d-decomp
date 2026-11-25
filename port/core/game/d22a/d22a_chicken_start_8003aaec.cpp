#include "w3d_ptr.h"
#line 1 "d22a_chicken_start_8003aaec.cpp"
/* Chicken start-up (0x8003aaec): clears the four state vectors (+40, +28,
 * +52, +64) from the zero vector 0x8045e788, resets the spawn index (+80) to
 * 0 and the hit points (+76) to -1, reads "Chicken.Spawn" and looks the named
 * spawn point up (0x8003ad14), reads "Chicken.HitPoints" into +76, loads the
 * "Gravity" and "Low.Gravity.Multiplier" resources into +84/+88 (retaining
 * the new object and releasing the previous one and the handle), reads the
 * "RandomNumber.Float" resource into +92 and posts a 12-byte "created"
 * message (0x800c1620) for the object id at +20. Field and type names are
 * inferred from the original instructions. Strings and globals are external
 * views of original data; the unit owns no data.
 *
 * As in 0x80060cc0 (d21a), one function-scope non-copyable Handle is reused
 * by an inline resource loader. The message initializer takes the id by
 * const reference to a small class constructed from the unsigned field: the
 * temporary gets the last stack slot (sp+40), as in the original; a by-value
 * aggregate parameter allocates its copy before the property keys. */
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
struct Chicken {
    char unknown00[20];
    unsigned id;             /* +20 */
    char unknown18[4];
    Vec3 vec28;              /* +28 */
    Vec3 vec40;              /* +40 */
    Vec3 vec52;              /* +52 */
    Vec3 vec64;              /* +64 */
    int hitPoints;           /* +76 */
    int spawnPoint;          /* +80 */
    Ptr32<Object> gravity;         /* +84 */
    Ptr32<Object> lowGravityMultiplier; /* +88 */
    Ptr32<Object> random;          /* +92 */
};
struct Message;
extern "C" int w3d_string_property_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" void w3d_find_spawn_point_8003ad14(Ptr32<Chicken>, Ptr32<const char>);
extern "C" int w3d_int_property_800fc1f0(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" Ptr32<Message> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<Message> w3d_created_message_init_800c1620(Ptr32<Message>, const ObjectId &);
extern "C" int w3d_message_post_8016239c(Ptr32<Message>);
extern Ptr32<void> w3d_message_arena_804b1754;
extern Vec3 w3d_zero_vector_8045e788;
extern "C" char w3d_string_80374270[]; /* "Chicken.Spawn" */
extern "C" char w3d_string_80374280[]; /* "Chicken.HitPoints" */
extern "C" char w3d_string_80374294[]; /* "Gravity" */
extern "C" char w3d_string_8037429c[]; /* "Low.Gravity.Multiplier" */
extern "C" char w3d_string_803742b4[]; /* "RandomNumber.Float" */

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

extern "C" void w3d_d22a_chicken_start_8003aaec(Ptr32<Chicken> self)
{
    Handle handle;
    self->vec40 = w3d_zero_vector_8045e788;
    self->vec28 = w3d_zero_vector_8045e788;
    self->vec52 = w3d_zero_vector_8045e788;
    self->vec64 = w3d_zero_vector_8045e788;
    PropertyKey spawnKey;
    spawnKey.name = w3d_string_80374270;
    Ptr32<const char> spawnName = 0;
    self->spawnPoint = 0;
    self->hitPoints = -1;
    w3d_string_property_800fc2b0(&spawnKey, &spawnName);
    w3d_find_spawn_point_8003ad14(self, spawnName);
    PropertyKey hitKey;
    hitKey.name = w3d_string_80374280;
    w3d_int_property_800fc1f0(&hitKey, &self->hitPoints);
    LoadResource(handle, w3d_string_80374294, self->gravity);
    LoadResource(handle, w3d_string_8037429c, self->lowGravityMultiplier);
    PropertyKey randomKey;
    randomKey.name = w3d_string_803742b4;
    w3d_resource_property_800fc1b0(&randomKey, &self->random);
    Ptr32<Message> message = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12);
    w3d_message_post_8016239c(w3d_created_message_init_800c1620(message, self->id));
}


