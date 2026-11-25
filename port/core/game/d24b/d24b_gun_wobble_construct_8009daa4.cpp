#include "w3d_ptr.h"
#line 1 "d24b_gun_wobble_construct_8009daa4.cpp"
/* Gun wobble constructor (0x8009daa4): clears the retained slots +8, +12, +16
 * and +128, retains the by-value owner in +128, loads "GunWobble.MaxAmp",
 * "GunWobble.Period" and "ActiveWormIndex" through one handle (casts 0x80342a74,
 * 0x80342a78, 0x803426b4) into +8, +12 and +16, reads GunWobble.Speed, fills
 * eight random phase, amplitude and speed entries at +52, +20 and +84 (0x80162bc8)
 * and stamps the engine time (0x80165254) into +116 and +4 with zeroed +120 and
 * +124. Field and type names are inferred from the original instructions. Strings
 * and globals are external views of original data; the unit owns its two float
 * literals at 0x803804fc. */
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
struct OwnerRef {
    Ptr32<Object> value;
    OwnerRef(const OwnerRef &);
    ~OwnerRef() { if (value) value->vtable->release(value); }
};
struct PropertyKey { Ptr32<const char> name; };
struct EngineContext { char unknown00[52]; int time; };
struct GunWobble {
    char unknown00[4];
    int startTime;     /* +4 */
    Ptr32<Object> maxAmp;  /* +8 */
    Ptr32<Object> period;    /* +12 */
    Ptr32<Object> wormIndex; /* +16 */
    float amplitude[8];/* +20 */
    float phase[8];    /* +52 */
    float speed[8];    /* +84 */
    int time;          /* +116 */
    float value120;    /* +120 */
    float value124;    /* +124 */
    Ptr32<Object> owner;     /* +128 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" int w3d_float_read_800fc270(Ptr32<PropertyKey>, Ptr32<float>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_80342a78(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_803426b4(Ptr32<Object>);
extern "C" float w3d_random_80162bc8();
extern "C" Ptr32<EngineContext> w3d_engine_context_80165254();
extern "C" char w3d_string_803804b4[]; /* "GunWobble.MaxAmp" */
extern "C" char w3d_string_803804c8[]; /* "GunWobble.Period" */
extern "C" char w3d_string_803804dc[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_803804ec[]; /* "GunWobble.Speed" */

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

extern "C" Ptr32<GunWobble> w3d_d24b_gun_wobble_construct_8009daa4(Ptr32<GunWobble> self, OwnerRef owner)
{
    self->maxAmp = 0;
    self->period = 0;
    self->wormIndex = 0;
    self->owner = 0;
    if (owner.value) owner.value->vtable->retain(owner.value);
    if (self->owner) self->owner->vtable->release(self->owner);
    self->owner = owner.value;
    Handle handle;
    handle.value = 0;
    Store<w3d_identity_80342a74>(handle, w3d_string_803804b4, self->maxAmp);
    Store<w3d_identity_80342a78>(handle, w3d_string_803804c8, self->period);
    Store<w3d_identity_803426b4>(handle, w3d_string_803804dc, self->wormIndex);
    float speed;
    {
        PropertyKey key;
        key.name = w3d_string_803804ec;
        w3d_float_read_800fc270(&key, &speed);
    }
    float scale = 3.1415927410125732f;
    for (unsigned i = 0; i < 8; i++) {
        self->phase[i] = w3d_random_80162bc8();
        self->amplitude[i] = w3d_random_80162bc8() * scale;
        self->speed[i] = w3d_random_80162bc8() * speed;
    }
    int now = w3d_engine_context_80165254()->time;
    self->startTime = now;
    self->value124 = 0.0f;
    self->time = now;
    self->value120 = 0.0f;
    return self;
}


