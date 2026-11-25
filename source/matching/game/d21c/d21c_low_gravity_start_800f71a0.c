/* d21c: 0x800f71a0 (576 bytes). Start the Low Gravity utility. A zero
 * vector is built on the stack (never read again) and the active actor is
 * fetched. A worm handle record {0, 0xe3a8} is prepared, the utility's
 * reference (+64) is written to "Worm.DisableMovementRef", the active worm
 * index and the scheme data are read and a 12-byte integer message carrying
 * the index is posted. The worm record selected by the index is fetched
 * through the handle; if its count (+170) is below its limit (+160) the
 * (negative) difference is stored at +164 and an 8-byte message is posted.
 * "Low.Gravity.OnValue" (default 1.0) is read and written to
 * "Low.Gravity.Multiplier", "UtilityLowGravity" is forwarded for the actor
 * object (+560) with 0 and 0.0, another integer message with the index and
 * two 8-byte messages are posted, +60 and +48 are cleared and the handle
 * record is released (0x80178474 with in-charge flag 2). Offsets are
 * observed; meanings are inferred.
 * Built with -mps-float: the 0.0 stays in f31 across calls and the
 * unflagged build differs only by the 8-byte frame gap below the register
 * save area. The deficit is stored through a pointer to the member: a
 * direct member store is a structure reference, which the scheduler moves
 * past the following load of the message pool and the record then needs a
 * copy in r9. Each message pointer is a block-local variable, as one shared
 * variable takes an extra saved register. The string "Worm.DisableMovementRef"
 * (0x8038c970) is first used by 0x800f70f0 and stays external; this unit
 * owns the rest of the pool, 0x8038c988..0x8038c9f0 (five keys, 0.0f,
 * 1.0f), in first-use order. */
typedef struct LgVec3 {
    float x, y, z;
} LgVec3;
typedef struct LgHandle {
    int id;
    int kind;
} LgHandle;
typedef struct LgKey {
    const char *text;
} LgKey;
typedef struct LgWorm {
    unsigned char unknown000[160];
    int limit;
    int deficit;
    unsigned char unknown168[2];
    unsigned short count;
} LgWorm;
typedef struct LgMessage {
    unsigned short id;
    const void *payload;
} LgMessage;
typedef struct LgUtility {
    unsigned char unknown00[48];
    int active;
    unsigned char unknown52[8];
    int running;
    int reference;
} LgUtility;

int w3d_turns_get_active_actor(int turns);
unsigned char *w3d_s20_lookup_handle_object_80164fc8(int actor);
int w3d_settings_write_int_800fc43c(LgKey *key, int value);
int w3d_settings_read_int_800fc1f0(LgKey *key, int *value);
int w3d_settings_read_800fc330(LgKey *key, int *value);
int w3d_settings_read_float_800fc270(LgKey *key, float *value);
int w3d_settings_write_float_800fc4c8(LgKey *key, float value);
LgWorm *w3d_worm_record_800fc710(int index, LgHandle *handle);
void w3d_handle_destroy_80178474(LgHandle *handle, int in_charge);
void *w3d_message_arena_801613f0(void *pool, int size);
unsigned int w3d_cached_message_id(void *cache, int create);
void *w3d_message_int_init(void *message, unsigned short id, int value);
int w3d_message_post_current(void *message);
int w3d_s20_forward_global_800e5ca4(void *target, const char *name, int flags, float value);
extern int w3d_turns_804ab400;
extern void *w3d_message_pool_804b1754;
extern unsigned char w3d_message_804af0d0, w3d_message_804af0d8, w3d_message_804af0e0,
    w3d_message_804af0f0, w3d_message_804af0f8;
extern const void *w3d_vtable_8040db38[];
extern const char w3d_key_worm_disable_movement_ref_8038c970[];

void d21c_low_gravity_start_800f71a0(LgUtility *self)
{
    LgVec3 origin;
    LgHandle handle;
    LgKey disable_key;
    LgKey index_key;
    int index;
    LgKey scheme_key;
    int scheme;
    LgKey on_key;
    float on_value;
    LgKey multiplier_key;
    float zero;
    int actor;
    LgWorm *worm;
    unsigned short count;
    int limit;
    unsigned char *object;

    zero = 0.0f;
    {
        float *p = &origin.x;
        origin.x = zero;
        p[1] = zero;
        p[2] = zero;
    }
    actor = w3d_turns_get_active_actor(w3d_turns_804ab400);
    handle.id = 0;
    on_value = 1.0f;
    handle.kind = 0xe3a8;
    disable_key.text = w3d_key_worm_disable_movement_ref_8038c970;
    w3d_settings_write_int_800fc43c(&disable_key, self->reference);
    index_key.text = "ActiveWormIndex";
    w3d_settings_read_int_800fc1f0(&index_key, &index);
    {
        void *m = w3d_message_arena_801613f0(w3d_message_pool_804b1754, 12);
        w3d_message_post_current(w3d_message_int_init(m,
        w3d_cached_message_id(&w3d_message_804af0d0, 1), index));
    }
    scheme_key.text = "GM.SchemeData";
    w3d_settings_read_800fc330(&scheme_key, &scheme);
    worm = w3d_worm_record_800fc710(index, &handle);
    count = worm->count;
    limit = worm->limit;
    if (count < limit) {
        int *deficit = &worm->deficit;
        LgMessage *msg;
        *deficit = count - limit;
        msg = w3d_message_arena_801613f0(w3d_message_pool_804b1754, 8);
        msg->id = w3d_cached_message_id(&w3d_message_804af0e0, 1);
        msg->payload = w3d_vtable_8040db38;
        w3d_message_post_current(msg);
    }
    object = w3d_s20_lookup_handle_object_80164fc8(actor);
    on_key.text = "Low.Gravity.OnValue";
    w3d_settings_read_float_800fc270(&on_key, &on_value);
    multiplier_key.text = "Low.Gravity.Multiplier";
    w3d_settings_write_float_800fc4c8(&multiplier_key, on_value);
    w3d_s20_forward_global_800e5ca4(object + 560, "UtilityLowGravity", 0, zero);
    {
        void *m = w3d_message_arena_801613f0(w3d_message_pool_804b1754, 12);
        w3d_message_post_current(w3d_message_int_init(m,
        w3d_cached_message_id(&w3d_message_804af0f8, 1), index));
    }
    self->running = 0;
    {
        LgMessage *msg = w3d_message_arena_801613f0(w3d_message_pool_804b1754, 8);
        msg->id = w3d_cached_message_id(&w3d_message_804af0f0, 1);
        msg->payload = w3d_vtable_8040db38;
        w3d_message_post_current(msg);
    }
    {
        LgMessage *msg = w3d_message_arena_801613f0(w3d_message_pool_804b1754, 8);
        msg->id = w3d_cached_message_id(&w3d_message_804af0d8, 1);
        msg->payload = w3d_vtable_8040db38;
        w3d_message_post_current(msg);
    }
    self->active = 0;
    w3d_handle_destroy_80178474(&handle, 2);
}
