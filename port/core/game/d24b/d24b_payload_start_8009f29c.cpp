#include "w3d_ptr.h"
#line 1 "d24b_payload_start_8009f29c.cpp"
/* Payload targeting start (0x8009f29c): casts the owner (+192) to its weapon
 * description (0x80341584, 0x801797b4), reads Land.Radius into +332 and
 * Payload.Target into the vector +308, copies the target into +276 and the zero
 * vector 0x8045e788 into +288, reads AIStrike.TargetPoint instead when 0x80020834
 * reports an active team, starts the flight span (0x800ecee8) with the zero
 * vector, sets +336, copies the position +72 into +320, runs 0x800eb6e4,
 * 0x800ed090 and the object's slot +88 and posts a cached message. Field and type
 * names are inferred from the original instructions. Strings and globals are
 * external views of original data; the unit owns no data. */
struct Vec3 {
    float x, y, z;
    void set(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
};
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; unsigned short unknown02; Ptr32<void> vtable; };
struct PayloadWeapon { char unknown00[576]; int span; /* +576 */ };
struct Payload;
struct PayloadVtable { char unknown00[88]; Ptr32<void (Ptr32<Payload>)> start; /* +88 */ };
struct Payload {
    Ptr32<PayloadVtable> vtable;
    char unknown04[24];
    int unknown28;     /* +28 */
    char unknown32[40];
    Vec3 position;    /* +72 */
    char unknown84[108];
    Ptr32<void> owner;       /* +192 */
    char unknown196[80];
    Vec3 launch;      /* +276 */
    Vec3 launchVelocity; /* +288 */
    char unknown300[8];
    Vec3 target;       /* +308 */
    Vec3 start;       /* +320 */
    char radius[4];    /* +332 */
    int active;        /* +336 */
};
extern "C" Ptr32<void> w3d_identity_80341584(Ptr32<void>);
extern "C" Ptr32<PayloadWeapon> w3d_as_weapon_801797b4(Ptr32<void>);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" int w3d_vector_property_800fc2f0(Ptr32<PropertyKey>, Ptr32<Vec3>);
extern "C" int w3d_active_team_value_80020834(Ptr32<void>);
extern "C" void w3d_update_span_800ecee8(Ptr32<Payload>, int, int, Ptr32<Vec3>);
extern "C" void w3d_payload_begin_800eb6e4(Ptr32<Payload>);
extern "C" void w3d_post_events_800ed090(Ptr32<Payload>);
extern "C" Ptr32<void> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<void>);
extern Ptr32<void> w3d_message_arena_804b1754;
extern Ptr32<void> w3d_game_804b1760;
extern MessageCache w3d_message_804ae118;
extern unsigned char w3d_vtable_8040db38[];
extern Vec3 w3d_zero_8045e788[];
extern "C" char w3d_string_803806f8[]; /* "Land.Radius" */
extern "C" char w3d_string_80380704[]; /* "Payload.Target" */
extern "C" char w3d_string_80380714[]; /* "AIStrike.TargetPoint" */

extern "C" void w3d_d24b_payload_start_8009f29c(Ptr32<Payload> self)
{
    Vec3 local;
    Ptr32<Vec3> p = &self->target;
    Ptr32<PayloadWeapon> weapon = w3d_as_weapon_801797b4(w3d_identity_80341584(self->owner));
    {
        PropertyKey key;
        key.name = w3d_string_803806f8;
        w3d_resource_property_800fc1b0(&key, self->radius);
    }
    {
        PropertyKey key;
        key.name = w3d_string_80380704;
        w3d_vector_property_800fc2f0(&key, p);
    }
    self->launch = *(Ptr32<Vec3>)p;
    self->launchVelocity = w3d_zero_8045e788[0];
    if (w3d_game_804b1760 && w3d_active_team_value_80020834(w3d_game_804b1760)) {
        PropertyKey key;
        key.name = w3d_string_80380714;
        w3d_vector_property_800fc2f0(&key, p);
        local.set(*p);
    }
    local.set(self->target);
    local.set(w3d_zero_8045e788[0]);
    w3d_update_span_800ecee8(self, self->unknown28, weapon->span, &local);
    self->active = 1;
    self->start = self->position;
    w3d_payload_begin_800eb6e4(self);
    w3d_post_events_800ed090(self);
    self->vtable->start(self);
    Ptr32<Message> changed = (Ptr32<Message>)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
    changed->id = w3d_cached_message_id_8015f5a0(&w3d_message_804ae118, 1);
    changed->vtable = w3d_vtable_8040db38;
    w3d_message_post_8016239c(changed);
}


