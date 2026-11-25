#include "w3d_ptr.h"
#line 1 "d23a_worm_aim_start_80026e74.cpp"
/* Worm aiming start (0x80026e74): reads the "Tweaks.AimAngleDelta",
 * "ActiveWormIndex", "Weapon.MinAimAngle" and "Weapon.MaxAimAngle"
 * properties straight into +32, +28, +36 and +40 (0x800fc1b0), loads the
 * "Worm.AimMouseUD.Sensitivity" resource into +44 through a handle
 * (0x80342a74, retaining the new object and releasing the previous one and
 * the handle), subscribes the object (0x80162024) to seven messages with
 * handler slots +64, +48, +52, +56, +60, +68 and +72, registers the
 * ActiveWormIndex watcher 0x8002732c with target +100 (0x800fd62c, through
 * a temporary String) and runs 0x8002709c. Field and type names are inferred
 * from the original instructions. Strings and globals are external views of
 * original data; the unit owns no data.
 *
 * The handle and the String share the stack slot sp+8 (address kept in r29
 * across the whole function): both are block-scoped, both are BLKmode
 * (user copy constructors), so the String block reuses the freed handle slot. */
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
struct String;
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};
struct WormAim {
    char unknown00[28];
    Ptr32<Object> activeWormIndex;   /* +28 */
    Ptr32<Object> aimAngleDelta;     /* +32 */
    Ptr32<Object> minAimAngle;       /* +36 */
    Ptr32<Object> maxAimAngle;       /* +40 */
    Ptr32<Object> sensitivity;       /* +44 */
    char slot48[4];            /* +48 */
    char slot52[4];            /* +52 */
    char slot56[4];            /* +56 */
    char slot60[4];            /* +60 */
    char slot64[4];            /* +64 */
    char slot68[4];            /* +68 */
    char slot72[4];            /* +72 */
    char unknown76[24];
    char indexWatch[4];        /* +100 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<WormAim>, const unsigned short &, Ptr32<void>);
extern "C" int w3d_watch_property_800fd62c(Ptr32<String>, Ptr32<void>, Ptr32<WormAim>, Ptr32<void>);
extern "C" int w3d_worm_aim_on_index_8002732c(Ptr32<void>, Ptr32<void>);
extern "C" void w3d_worm_aim_update_8002709c(Ptr32<WormAim>);
extern MessageCache w3d_message_804acb1c, w3d_message_804acb24, w3d_message_804acb2c,
    w3d_message_804acb34, w3d_message_804acb3c, w3d_message_804acb54, w3d_message_804acb5c;
extern "C" char w3d_string_8036caec[]; /* "Tweaks.AimAngleDelta" */
extern "C" char w3d_string_8036cb04[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_8036cb14[]; /* "Weapon.MinAimAngle" */
extern "C" char w3d_string_8036cb28[]; /* "Weapon.MaxAimAngle" */
extern "C" char w3d_string_8036cb3c[]; /* "Worm.AimMouseUD.Sensitivity" */

inline void GetProperty(Ptr32<const char> name, Ptr32<Ptr32<Object>> out)
{
    PropertyKey key;
    key.name = name;
    w3d_resource_property_800fc1b0(&key, out);
}

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

extern "C" void w3d_d23a_worm_aim_start_80026e74(Ptr32<WormAim> self)
{
    GetProperty(w3d_string_8036caec, &self->aimAngleDelta);
    GetProperty(w3d_string_8036cb04, &self->activeWormIndex);
    GetProperty(w3d_string_8036cb14, &self->minAimAngle);
    GetProperty(w3d_string_8036cb28, &self->maxAimAngle);
    {
        Handle handle;
        LoadResource(handle, w3d_string_8036cb3c, self->sensitivity);
    }
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb54, 1), self->slot64);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb1c, 1), self->slot48);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb24, 1), self->slot52);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb2c, 1), self->slot56);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb34, 1), self->slot60);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb5c, 1), self->slot68);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acb3c, 1), self->slot72);
    {
        String name(w3d_string_8036cb04);
        w3d_watch_property_800fd62c(&name, (Ptr32<void>)w3d_worm_aim_on_index_8002732c, self, self->indexWatch);
    }
    w3d_worm_aim_update_8002709c(self);
}


