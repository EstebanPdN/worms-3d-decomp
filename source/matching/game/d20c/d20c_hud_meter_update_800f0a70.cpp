// d20c: 0x800f0a70 (432 bytes). Update a HUD meter sprite. Two timers
// (+104, +100) are polled and the texture size of +112 is scaled by 64 and
// 128. When the meter is enabled (+68 and +72 set), the engine context is not
// busy (+56), the game state is 7 and the timer at +116 reports zero, the
// sprite (+28) is shown (virtual slot +88 with 1), the level of the object
// looked up from the handle at +64 is read with 0x800f12f0, and the sprite's
// properties are written: first vector (0, 0), second vector (1, level),
// colour word from 0x804af024, third vector (0, height * level / 2, 0),
// fourth vector (width / 2, height * level / 2) and the visible byte 1.
// Otherwise the sprite is hidden (virtual slot +88 with 0) and the visible
// byte cleared. Offsets are observed; meanings are inferred.
// Built with -mps-float: the scaled sizes stay in f28..f31 across calls and
// the unflagged build differed only by the 8-byte frame gap below the
// register save area. The literal pool is referenced, not owned.
struct d20c_Vec2 {
    float x, y;
};
struct d20c_Vec3 {
    float x, y, z;
};
struct d20c_Sprite;
struct d20c_SpriteVtbl {
    unsigned char unknown00[88];
    void (*set_visible)(d20c_Sprite *self, int visible);   // +88
};
struct d20c_Sprite {
    d20c_SpriteVtbl *vtbl;
};
struct d20c_Meter {
    unsigned char unknown00[28];
    d20c_Sprite *sprite;                 // +28
    unsigned char unknown32[32];
    int level_handle;                    // +64
    int enabled_a;                       // +68
    int enabled_b;                       // +72
    unsigned char unknown76[24];
    void *timer_100;                     // +100
    void *timer_104;                     // +104
    void *unknown108;
    void *texture;                       // +112
    void *timer_116;                     // +116
};
struct d20c_EngineContext {
    unsigned char unknown00[56];
    int busy;                            // +56
};
struct d20c_Game {
    unsigned char unknown00[208];
    int state;                           // +208
};

extern "C" int w3d_timer_80178d1c(void *timer);
extern "C" float *w3d_texture_size_80178ec4(void *texture);
extern "C" d20c_EngineContext *w3d_engine_get_context(void);
extern "C" void *w3d_s20_lookup_handle_object_80164fc8(int handle);
extern "C" float w3d_level_ratio_800f12f0(void *object, int time);
extern "C" d20c_Vec2 *w3d_sprite_vec2_80189884(d20c_Sprite *sprite);
extern "C" d20c_Vec2 *w3d_sprite_vec2_801898e0(d20c_Sprite *sprite);
extern "C" int *w3d_sprite_colour_80189760(d20c_Sprite *sprite);
extern "C" d20c_Vec3 *w3d_sprite_vec3_80189518(d20c_Sprite *sprite);
extern "C" d20c_Vec2 *w3d_sprite_vec2_8018963c(d20c_Sprite *sprite);
extern "C" unsigned char *w3d_sprite_visible_80189704(d20c_Sprite *sprite);
extern "C" d20c_Game *w3d_game_804aaabc;
extern "C" int w3d_colour_804af024;
extern "C" const float w3d_f32_8038c21c[];   // 64.0f
extern "C" const float w3d_f32_8038c220[];   // 128.0f
extern "C" const float w3d_f32_8038c224[];   // 0.0f
extern "C" const float w3d_f32_8038c228[];   // 1.0f
extern "C" const float w3d_f32_8038c22c[];   // 0.5f

extern "C" void d20c_hud_meter_update_800f0a70(d20c_Meter *self, int time)
{
    w3d_timer_80178d1c(self->timer_104);
    w3d_timer_80178d1c(self->timer_100);
    float width = w3d_texture_size_80178ec4(self->texture)[0] * w3d_f32_8038c21c[0];
    float height = w3d_texture_size_80178ec4(self->texture)[1] * w3d_f32_8038c220[0];
    if (self->enabled_a != 0 && self->enabled_b != 0 &&
        w3d_engine_get_context()->busy == 0 && w3d_game_804aaabc->state == 7 &&
        w3d_timer_80178d1c(self->timer_116) == 0) {
        self->sprite->vtbl->set_visible(self->sprite, 1);
        float level = w3d_level_ratio_800f12f0(
            w3d_s20_lookup_handle_object_80164fc8(self->level_handle), time);
        d20c_Vec2 *origin = w3d_sprite_vec2_80189884(self->sprite);
        float zero = w3d_f32_8038c224[0];
        origin->x = zero;
        origin->y = zero;
        d20c_Vec2 *scale = w3d_sprite_vec2_801898e0(self->sprite);
        scale->y = level;
        scale->x = w3d_f32_8038c228[0];
        *w3d_sprite_colour_80189760(self->sprite) = w3d_colour_804af024;
        d20c_Vec3 *offset = w3d_sprite_vec3_80189518(self->sprite);
        float half = w3d_f32_8038c22c[0];
        float y = height * level * half;
        offset->x = zero;
        offset->y = y;
        offset->z = zero;
        d20c_Vec2 *size = w3d_sprite_vec2_8018963c(self->sprite);
        size->y = y;
        size->x = width * half;
        *w3d_sprite_visible_80189704(self->sprite) = 1;
    } else {
        self->sprite->vtbl->set_visible(self->sprite, 0);
        *w3d_sprite_visible_80189704(self->sprite) = 0;
    }
}
