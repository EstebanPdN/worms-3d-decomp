/* Remaining turn time (0x800155d0): loads the "TurnTimeRemaining" resource
 * (0x800fc1b0, cast 0x803426b4, retained in a local reference) and reads its
 * integer value (0x80178c48). When that is 0 it loads "TurnTime" the same way
 * and uses its value, or 60000 when that is also 0. Returns the milliseconds
 * scaled by 0.001 to seconds, releasing the references on the way. Field and
 * type names are inferred from the original instructions. Strings are external
 * views of original data; the unit owns its two literals (0x8036a5d8 and
 * 0x8036a5e0). */
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
};
struct Object { ObjectVtable *vtable; };
struct Ref {
    Object *value;
    Ref() { value = 0; }
    ~Ref() { if (value) value->vtable->release(value); }
private:
    Ref(const Ref &);
};
struct PropertyKey { const char *name; };
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, Object **);
extern "C" Object *w3d_identity_803426b4(Object *);
extern "C" int w3d_object_int_80178c48(Object *);
extern "C" char w3d_string_8036a5b4[]; /* "TurnTimeRemaining" */
extern "C" char w3d_string_8036a5c8[]; /* "TurnTime" */

inline void LoadResource(const char *name, Ref &slot)
{
    Ref handle;
    PropertyKey key;
    key.name = name;
    w3d_resource_property_800fc1b0(&key, &handle.value);
    Object *object = w3d_identity_803426b4(handle.value);
    if (object) object->vtable->retain(object);
    if (slot.value) slot.value->vtable->release(slot.value);
    slot.value = object;
}

extern "C" float w3d_d24a_turn_time_remaining_800155d0(void)
{
    Ref remaining;
    LoadResource(w3d_string_8036a5b4, remaining);
    int ms = w3d_object_int_80178c48(remaining.value);
    if (ms == 0) {
        Ref total;
        LoadResource(w3d_string_8036a5c8, total);
        ms = w3d_object_int_80178c48(total.value);
        if (ms == 0) ms = 60000;
    }
    return ms * 0.001f;
}
