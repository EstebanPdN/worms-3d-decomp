/* Weapon aim start (0x800c2e44): casts the owner (+28) to its weapon
 * description (0x80341584, 0x801797b4) and retains it in +44, subscribes the
 * object (0x80162024) to three cached messages with handler slots +84, +88
 * and +92, reads ActiveWormIndex into +36, publishes the minimum and maximum
 * aim angles (degrees from the weapon's radians, or fixed defaults when the
 * weapon has no limits) and posts the aim-changed message (plus a target
 * message when limited), publishes the retreat time, creates the 8-byte
 * handle in +96 and appends the active actor to the array at +100 unless it is
 * -1. Field and type names are inferred from the original instructions.
 * Strings and globals are external views of original data; the unit owns its
 * 20-byte float literal pool at 0x80383234. */
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);   /* +12 */
    void (*release)(Object *);  /* +16 */
};
struct Object { ObjectVtable *vtable; };
struct PropertyKey {
    const char *name;
    PropertyKey() {}
    PropertyKey(const char *n) { name = n; }
    inline void SetFloat(float value);
};
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; unsigned short unknown02; void *vtable; };
struct Vec3 {
    float x, y, z;
    Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
extern "C" char *w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(void *);
extern "C" void *w3d_copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct IntArray {
    int *begin, *end, *capacity;
    void push(const int &value) {
        if (end == capacity) {
            unsigned old = (char *)end - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 2;
            char *p = w3d_allocate_80212fd4(bytes);
            if (begin) {
                w3d_copy_802eee50(p, begin, minimum(bytes, old));
                w3d_release_802134fc(begin);
            }
            begin = (int *)p;
            end = (int *)(p + old);
            capacity = (int *)(p + bytes);
        }
        *end = value;
        end++;
    }
};
struct Weapon : Object {
    char unknown04[228];
    float maxAngle;   /* +232 */
    float minAngle;   /* +236 */
    float handleTime; /* +240 */
    int retreatTime;  /* +244 */
    char unknown248[8];
    int limited;      /* +256 */
};
struct AimHandle;
struct WeaponAim {
    char unknown00[20];
    int id;            /* +20 */
    char unknown24[4];
    void *owner;       /* +28 */
    char unknown32[4];
    char wormIndex[4]; /* +36 */
    char unknown40[4];
    Weapon *weapon;    /* +44 */
    char unknown48[36];
    char slot84[4], slot88[4], slot92[4];
    AimHandle *handle; /* +96 */
    IntArray actors;   /* +100 */
    int actor;         /* +112 */
};
extern "C" void *w3d_identity_80341584(void *);
extern "C" Weapon *w3d_as_weapon_801797b4(void *);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(WeaponAim *, const unsigned short &, void *);
extern "C" int w3d_resource_property_800fc1b0(PropertyKey *, void *);
extern "C" int w3d_float_write_800fc4c8(PropertyKey *, float);
extern "C" int w3d_int_read_800fc1f0(PropertyKey *, int *);
extern "C" int w3d_int_write_800fc3b0(PropertyKey *, int);
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_message_post_8016239c(void *);
extern "C" void *w3d_target_message_801190b4(void *, unsigned short, int);
extern "C" void *w3d_heap_allocate_802098d8(void *, int);
extern "C" AimHandle *w3d_handle_construct_801261bc(void *, Vec3 *, int, int, float);
extern "C" void w3d_handle_member_query_80126308(AimHandle *, int);
extern "C" int w3d_active_actor_80156f88(void *);
extern void *w3d_message_arena_804b1754;
extern void *w3d_turns_804ab400;
extern char w3d_pool_804af5bc[8];
extern MessageCache w3d_message_804ae6dc, w3d_message_804ae6fc, w3d_message_804ae724, w3d_message_804ae754,
    w3d_message_804ae75c;
extern unsigned char w3d_vtable_8040db38[];
extern "C" char w3d_string_803831dc[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_803831ec[]; /* "Weapon.MinAimAngle" */
extern "C" char w3d_string_80383200[]; /* "Weapon.MaxAimAngle" */
extern "C" char w3d_string_80383214[]; /* "DefaultRetreatTime" */
extern "C" char w3d_string_80383228[]; /* "RetreatTime" */


inline void PropertyKey::SetFloat(float value) { w3d_float_write_800fc4c8(this, value); }

inline void PostChanged()
{
    Message *changed = (Message *)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
    changed->id = w3d_cached_message_id_8015f5a0(&w3d_message_804ae754, 1);
    changed->vtable = w3d_vtable_8040db38;
    w3d_message_post_8016239c(changed);
}

extern "C" void w3d_d24b_weapon_aim_start_800c2e44(WeaponAim *self)
{
    Weapon *weapon = w3d_as_weapon_801797b4(w3d_identity_80341584(self->owner));
    if (weapon) weapon->vtable->retain(weapon);
    if (self->weapon) self->weapon->vtable->release(self->weapon);
    self->weapon = weapon;
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae6dc, 1), self->slot84);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae6fc, 1), self->slot88);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae724, 1), self->slot92);
    {
        PropertyKey key;
        key.name = w3d_string_803831dc;
        w3d_resource_property_800fc1b0(&key, self->wormIndex);
    }
    if (self->weapon->limited) {
        float scale = 3.14159274f;
        float divisor = 180.0f;
        PropertyKey(w3d_string_803831ec).SetFloat(self->weapon->minAngle * scale / divisor);
        PropertyKey(w3d_string_80383200).SetFloat(self->weapon->maxAngle * scale / divisor);
        PostChanged();
        void *memory = w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12);
        unsigned short id = w3d_cached_message_id_8015f5a0(&w3d_message_804ae75c, 1);
        w3d_message_post_8016239c(w3d_target_message_801190b4(memory, id, self->id));
    } else {
        PropertyKey(w3d_string_803831ec).SetFloat(-1.57079637f);
        PropertyKey(w3d_string_80383200).SetFloat(1.57079637f);
        PostChanged();
    }
    int retreat;
    {
        PropertyKey key;
        key.name = w3d_string_80383214;
        w3d_int_read_800fc1f0(&key, &retreat);
    }
    if (self->weapon->retreatTime) retreat = self->weapon->retreatTime;
    {
        PropertyKey key;
        key.name = w3d_string_80383228;
        w3d_int_write_800fc3b0(&key, retreat);
    }
    Vec3 offset(0.0f, 0.0f, 0.0f);
    void *memory = w3d_heap_allocate_802098d8(w3d_pool_804af5bc, 8);
    AimHandle *handle = w3d_handle_construct_801261bc(memory, &offset, 0, 63, self->weapon->handleTime);
    self->handle = handle;
    w3d_handle_member_query_80126308(handle, self->id);
    self->actor = w3d_active_actor_80156f88(w3d_turns_804ab400);
    if (self->actor != -1)
        self->actors.push(self->actor);
}
