// d24d: 0x8014cb88 (448 bytes). Worm death blast: read the five "Worm.Death*"
// settings (0x800fc270), post a 52-byte explosion message (0x800666b4) with the
// position (+560), the same position 10 below, and the five values. In mode 27 (+760)
// the "EffectWaterExplosion" effect runs at the water level (the level from +1232
// times 16, truncated, bit 0 set, times 0.0625); otherwise "EffectWormExplosion" runs
// at the position. Finishes with 0x8014fee8.
extern float d24d_ten_803a15e4[];  // 10.0, first word of this function's pool; the rest starts on an 8-byte boundary
struct d24d_Vec3 { float x, y, z; d24d_Vec3() {} d24d_Vec3(float a, float b, float c) { x = a; y = b; z = c; } };
struct d24d_SettingKey { const char *name; };
extern "C" int d24d_setting_read_800fc270(d24d_SettingKey *, float *);
extern void *d24d_arena_804b1754;
extern "C" void *d24d_arena_alloc_801613f0(void *, int);
extern "C" void *d24d_explosion_message_800666b4(void *, const d24d_Vec3 *, const d24d_Vec3 *, float, float, float, float, float);
extern "C" int d24d_message_post_8016239c(void *);
extern "C" float d24d_water_level_80178df0(void *);
extern "C" int d24d_effect_800e5ca4(const d24d_Vec3 *, const char *, int, float);
extern "C" void d24d_post_death_8014fee8(void *);
extern const char d24d_setting_803a152c[], d24d_setting_803a154c[], d24d_setting_803a1568[], d24d_setting_803a1584[], d24d_setting_803a15a0[], d24d_effect_water_803a15b8[], d24d_effect_worm_803a15d0[];
struct d24d_DyingWorm { char pad[560]; d24d_Vec3 pos; char pad2[188]; int mode; char pad3[468]; void *water; };
extern "C" void d24d_worm_death_8014cb88(d24d_DyingWorm *self) {
    const d24d_Vec3 &at = d24d_Vec3(self->pos.x, self->pos.y - d24d_ten_803a15e4[0], self->pos.z);
    d24d_Vec3 *pos = &self->pos;
    d24d_SettingKey k0; float v0; k0.name = d24d_setting_803a152c; d24d_setting_read_800fc270(&k0, &v0);
    d24d_SettingKey k1; float v1; k1.name = d24d_setting_803a154c; d24d_setting_read_800fc270(&k1, &v1);
    d24d_SettingKey k2; float v2; k2.name = d24d_setting_803a1568; d24d_setting_read_800fc270(&k2, &v2);
    d24d_SettingKey k3; float v3; k3.name = d24d_setting_803a1584; d24d_setting_read_800fc270(&k3, &v3);
    d24d_SettingKey k4; float v4; k4.name = d24d_setting_803a15a0; d24d_setting_read_800fc270(&k4, &v4);
    d24d_message_post_8016239c(d24d_explosion_message_800666b4(d24d_arena_alloc_801613f0(d24d_arena_804b1754, 52), pos, &at, v0, v1, v2, v3, v4));
    if (self->mode == 27) {
        d24d_Vec3 p;
        p.x = self->pos.x; p.y = pos->y; p.z = pos->z;
        float level = d24d_water_level_80178df0(self->water);
        p.y = (float)((int)(level * 16.0f) | 1) * 0.0625f;
        d24d_effect_800e5ca4(&p, d24d_effect_water_803a15b8, 0, 0.0f);
    } else {
        d24d_effect_800e5ca4(pos, d24d_effect_worm_803a15d0, 0, 0.0f);
    }
    d24d_post_death_8014fee8(self);
}
