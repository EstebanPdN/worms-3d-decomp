/* Weapon projectile message handler (0x8009b670): message 64 starts the projectile
 * (0x8009c248) after the base handler (0x8015fb34; failure gives 0x80004005), message 66
 * stops it (0x8009c5e8); the fire message (cache 0x804ae018) restarts the delay and posts
 * the fire messages; the camera mode message updates +108; the finish message (cache
 * 0x804ae000) runs the sound refresh and arms the end state. Field and type names are
 * inferred from the original instructions. Owns its float literal at 0x803800e4. */
struct PropertyKey { const char *name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; unsigned short unknown02; void *vtable; };
struct EngineContext { char unknown00[52]; int time; };
struct Weapon {
    char unknown00[56];
    int fireDelay;   /* +56 */
    char unknown60[132];
    int endDelay;    /* +192 */
    char unknown196[8];
    unsigned total;  /* +204 */
    char unknown208[112];
    int repeating;   /* +320 */
};
struct Projectile {
    char unknown00[28];
    void *owner;     /* +28 */
    char unknown32[12];
    int state;       /* +44 */
    char unknown48[4];
    unsigned count;  /* +52 */
    char unknown56[28];
    int fireTime;    /* +84 */
    char unknown88[12];
    int disabled;    /* +100 */
    int flag104;     /* +104 */
    int cameraMode;  /* +108 */
    int flag112;     /* +112 */
    char unknown116[8];
    int endTime;     /* +124 */
};
struct Camera { char unknown00[820]; float value; };
extern "C" int w3d_base_handle_8015fb34(Projectile *, Message *);
extern "C" void w3d_start_8009c248(Projectile *);
extern "C" void w3d_stop_8009c5e8(Projectile *);
extern "C" int w3d_message_equals_8015f65c(int, MessageCache *);
extern "C" int w3d_restricted_8009d7e4(Projectile *);
extern "C" int w3d_int_write_800fc43c(PropertyKey *, int);
extern "C" int w3d_int_read_800fc230(PropertyKey *, int *);
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_message_post_8016239c(void *);
extern "C" void *w3d_identity_80341584(void *);
extern "C" Weapon *w3d_as_weapon_801797b4(void *);
extern "C" EngineContext *w3d_engine_context_80165254();
extern "C" int w3d_sound_refresh_8009c0cc(Projectile *);
extern "C" void w3d_base_finish_8015fd1c(Projectile *);
extern void *w3d_message_arena_804b1754;
extern Camera *w3d_camera_804aa8c8;
extern MessageCache w3d_message_804ae018, w3d_message_804ae060, w3d_message_804ae050, w3d_message_804ae008,
    w3d_message_804ae020, w3d_message_804ae028, w3d_message_804ae0a8, w3d_message_804ae000;
extern unsigned char w3d_vtable_8040db38[];
extern "C" char w3d_string_80380088[]; /* "Worm.DisableMovement" */
extern "C" char w3d_string_80380078[]; /* "AI.BulletCount" */
extern "C" char w3d_string_803800a0[]; /* "Camera.CurrentMode" */

inline void Post(MessageCache *cache)
{
    Message *m = (Message *)w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(cache, 1);
    m->vtable = w3d_vtable_8040db38;
    w3d_message_post_8016239c(m);
}

extern "C" int w3d_d24b_projectile_message_8009b670(Projectile *self, Message *message)
{
    int id = message->id;
    switch (id) {
    case 64:
        if (w3d_base_handle_8015fb34(self, message) >= 0) {
            w3d_start_8009c248(self);
            goto handled;
        }
        return 0x80004005;
    case 66:
        w3d_stop_8009c5e8(self);
        break;
    default:
        if (w3d_message_equals_8015f65c(id, &w3d_message_804ae018)) {
            if (!w3d_restricted_8009d7e4(self)) goto handled;
            if (self->state == 0) {
                if (self->disabled) {
                    PropertyKey key;
                    key.name = w3d_string_80380088;
                    w3d_int_write_800fc43c(&key, self->disabled);
                    self->disabled = 0;
                }
                Post(&w3d_message_804ae060);
                Weapon *weapon = w3d_as_weapon_801797b4(w3d_identity_80341584(self->owner));
                self->fireTime = w3d_engine_context_80165254()->time + weapon->fireDelay;
                if (self->count == 0) {
                    Post(&w3d_message_804ae050);
                    if (weapon->repeating == 0) {
                        w3d_camera_804aa8c8->value = 1.0f;
                        Post(&w3d_message_804ae008);
                    } else {
                        Post(&w3d_message_804ae020);
                        self->flag104 = 1;
                    }
                } else if (weapon->repeating && self->count >= weapon->total - 1) {
                    Post(&w3d_message_804ae028);
                    self->flag104 = 0;
                    Post(&w3d_message_804ae008);
                }
                self->state = 1;
                PropertyKey key;
                key.name = w3d_string_80380078;
                w3d_int_write_800fc43c(&key, 0);
            }
        } else if (w3d_message_equals_8015f65c(id, &w3d_message_804ae0a8)) {
            PropertyKey key;
            key.name = w3d_string_803800a0;
            int mode;
            w3d_int_read_800fc230(&key, &mode);
            self->cameraMode = mode == 1;
        } else if (w3d_message_equals_8015f65c(id, &w3d_message_804ae000)) {
            w3d_sound_refresh_8009c0cc(self);
            self->flag112 = 1;
            if (self->count == 0) {
                w3d_base_finish_8015fd1c(self);
            } else {
                Weapon *weapon = w3d_as_weapon_801797b4(w3d_identity_80341584(self->owner));
                w3d_engine_context_80165254();
                self->endTime = w3d_engine_context_80165254()->time + weapon->endDelay;
                self->state = 5;
            }
        }
        break;
    }
    return w3d_base_handle_8015fb34(self, message);
handled:
    return 0;
}
