#include "w3d_ptr.h"
#line 1 "d24b_weapon_projectile_start_8009c248.cpp"
/* Weapon projectile start (0x8009c248): casts the owner (+28) to its weapon
 * description (0x80341584, 0x801797b4), derives the count +48 from the weapon's
 * ratio (at least 1), subscribes the object (0x80162024) to five cached
 * messages with handler slots +128 to +144, reads ActiveWormIndex,
 * ObjectCount.Active and Water.Level into +32, +36 and +40, publishes the aim
 * limits and posts the changed and target messages when the weapon has limits,
 * clears +52 and AI.BulletCount, publishes RetreatTime (weapon +208 overriding
 * DefaultRetreatTime), creates the handle in +92 (0x801261bc, 0x80126308),
 * creates the 132-byte helper in +148 unless 0x80020834 reports an active team,
 * and sets +108 when Camera.CurrentMode is 1. Field and type names are inferred
 * from the original instructions. Strings and globals are external views of
 * original data; the unit owns its literal pool at 0x803801f8. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct PropertyKey {
    Ptr32<const char> name;
    PropertyKey() {}
    template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) { name = n; }
    inline void SetFloat(float value);
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; unsigned short unknown02; Ptr32<void> vtable; };
struct Vec3 {
    float x, y, z;
    Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
/* Retaining reference passed by value; the callee releases it. */
struct OwnerRef {
    Ptr32<Object> value;
    template <class W3dU> OwnerRef(Ptr32<W3dU> w3d_p) : OwnerRef((Object *)w3d_p.get()) {}
 OwnerRef(Object *o) { value = o; if (value) value->vtable->retain(value); }
    OwnerRef(const OwnerRef &);
};
struct Weapon : Object {
    char unknown04[196] __attribute__((aligned(__alignof__(Object))));
    unsigned total;   /* +200 */
    unsigned part;    /* +204 */
    int retreatTime;  /* +208 */
    float handleTime; /* +212 */
    char unknown216[20];
    float minAngle;   /* +236 */
    char unknown240[60];
    float maxAngle;   /* +300 */
    int limited;      /* +304 */
};
struct ProjectileHandle;
struct Helper;
struct WeaponProjectile {
    char unknown00[20];
    int id;            /* +20 */
    char unknown24[4];
    Ptr32<Object> owner;     /* +28 */
    char wormIndex[4]; /* +32 */
    char objectCount[4]; /* +36 */
    char waterLevel[4]; /* +40 */
    char unknown44[4];
    int count;         /* +48 */
    int unknown52;     /* +52 */
    char unknown56[36];
    Ptr32<ProjectileHandle> handle; /* +92 */
    char unknown96[12];
    int cameraMode;    /* +108 */
    char unknown112[16];
    char slot128[4], slot132[4], slot136[4], slot140[4], slot144[4];
    Ptr32<Helper> helper;    /* +148 */
};
extern "C" Ptr32<Object> w3d_identity_80341584(Ptr32<Object>);
extern "C" Ptr32<Weapon> w3d_as_weapon_801797b4(Ptr32<Object>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<WeaponProjectile>, const unsigned short &, Ptr32<void>);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" int w3d_float_write_800fc4c8(Ptr32<PropertyKey>, float);
extern "C" int w3d_int_read_800fc1f0(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_int_read_800fc230(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_int_write_800fc3b0(Ptr32<PropertyKey>, int);
extern "C" int w3d_int_write_800fc43c(Ptr32<PropertyKey>, int);
extern "C" Ptr32<void> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<void>);
extern "C" Ptr32<void> w3d_target_message_801190b4(Ptr32<void>, unsigned short, int);
extern "C" Ptr32<void> w3d_heap_allocate_802098d8(Ptr32<void>, int);
extern "C" Ptr32<ProjectileHandle> w3d_handle_construct_801261bc(Ptr32<void>, Ptr32<Vec3>, int, int, float);
extern "C" void w3d_handle_member_query_80126308(Ptr32<ProjectileHandle>, int);
extern "C" int w3d_active_team_value_80020834(Ptr32<void>);
extern "C" Ptr32<Helper> w3d_helper_construct_8009daa4(Ptr32<void>, OwnerRef);
extern Ptr32<void> w3d_message_arena_804b1754;
extern Ptr32<void> w3d_game_804b1760;
extern char w3d_pool_804af5bc[8];
extern MessageCache w3d_message_804ae008, w3d_message_804ae000, w3d_message_804ae018, w3d_message_804af798,
    w3d_message_804ae0a8, w3d_message_804ae040, w3d_message_804ae048;
extern unsigned char w3d_vtable_8040db38[];
extern "C" char w3d_string_80380180[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_80380190[]; /* "ObjectCount.Active" */
extern "C" char w3d_string_803801a4[]; /* "Water.Level" */
extern "C" char w3d_string_803801b0[]; /* "Weapon.MinAimAngle" */
extern "C" char w3d_string_803801c4[]; /* "Weapon.MaxAimAngle" */
extern "C" char w3d_string_80380078[]; /* "AI.BulletCount" */
extern "C" char w3d_string_803801d8[]; /* "DefaultRetreatTime" */
extern "C" char w3d_string_803801ec[]; /* "RetreatTime" */
extern "C" char w3d_string_803800a0[]; /* "Camera.CurrentMode" */

inline void PropertyKey::SetFloat(float value) { w3d_float_write_800fc4c8(this, value); }
// Port (francotirador de UM): rama Sniper de UM 0x55cff0 (core/native/francotirador.cpp).
extern "C" int w3d_franco_es_francotirador(void);
extern "C" void w3d_franco_start(void);

extern "C" void w3d_d24b_weapon_projectile_start_8009c248(Ptr32<WeaponProjectile> self)
{
    Ptr32<Weapon> weapon = w3d_as_weapon_801797b4(w3d_identity_80341584(self->owner));
    if (weapon->total)
        self->count = (int)((float)weapon->part / (float)weapon->total * 50.0f);
    if (self->count == 0) self->count = 1;
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae008, 1), self->slot128);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae000, 1), self->slot132);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae018, 1), self->slot136);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804af798, 1), self->slot140);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae0a8, 1), self->slot144);
    {
        PropertyKey key;
        key.name = w3d_string_80380180;
        w3d_resource_property_800fc1b0(&key, self->wormIndex);
    }
    {
        PropertyKey key;
        key.name = w3d_string_80380190;
        w3d_resource_property_800fc1b0(&key, self->objectCount);
    }
    {
        PropertyKey key;
        key.name = w3d_string_803801a4;
        w3d_resource_property_800fc1b0(&key, self->waterLevel);
    }
    const bool sniper = w3d_franco_es_francotirador() != 0;
    if (weapon->limited || sniper) {
        float scale = 3.14159274f;
        float divisor = 180.0f;
        // UM: con Sniper, Min/MaxAimAngle = ∓90° y ni cursor de puntería ni retícula, solo la mira (CreateSniperCursor).
        PropertyKey(w3d_string_803801b0).SetFloat(sniper ? -1.57079637f : weapon->minAngle * scale / divisor);
        PropertyKey(w3d_string_803801c4).SetFloat(sniper ? 1.57079637f : weapon->maxAngle * scale / divisor);
        Ptr32<Message> changed = (Ptr32<Message>)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
        changed->id = w3d_cached_message_id_8015f5a0(&w3d_message_804ae040, 1);
        changed->vtable = w3d_vtable_8040db38;
        w3d_message_post_8016239c(changed);
        if (!sniper) {
            Ptr32<void> memory = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12);
            unsigned short id = w3d_cached_message_id_8015f5a0(&w3d_message_804ae048, 1);
            w3d_message_post_8016239c(w3d_target_message_801190b4(memory, id, self->id));
        }
    }
    self->unknown52 = 0;
    {
        PropertyKey key;
        key.name = w3d_string_80380078;
        w3d_int_write_800fc43c(&key, 0);
    }
    int retreat;
    {
        PropertyKey key;
        key.name = w3d_string_803801d8;
        w3d_int_read_800fc1f0(&key, &retreat);
    }
    if (weapon->retreatTime) retreat = weapon->retreatTime;
    {
        PropertyKey key;
        key.name = w3d_string_803801ec;
        w3d_int_write_800fc3b0(&key, retreat);
    }
    Vec3 offset(0.0f, 0.0f, 0.0f);
    Ptr32<void> memory = w3d_heap_allocate_802098d8(w3d_pool_804af5bc, 8);
    Ptr32<ProjectileHandle> handle = w3d_handle_construct_801261bc(memory, &offset, 0, 1087, weapon->handleTime);
    self->handle = handle;
    w3d_handle_member_query_80126308(handle, self->id);
    if (w3d_game_804b1760 && w3d_active_team_value_80020834(w3d_game_804b1760)) {
        self->helper = 0;
    } else {
        self->helper = w3d_helper_construct_8009daa4(w3d_heap_allocate_802098d8(w3d_pool_804af5bc, 132), OwnerRef(self->owner));
    }
    int mode;
    {
        PropertyKey key;
        key.name = w3d_string_803800a0;
        w3d_int_read_800fc230(&key, &mode);
    }
    self->cameraMode = mode == 1;
    if (sniper) w3d_franco_start();
}


