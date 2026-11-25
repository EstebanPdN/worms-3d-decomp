// d24d: 0x8014b498 (536 bytes). Worm landing: unless 0x8014df28 says otherwise, zero
// the fall deltas (+572, +580) and read "Worm.FallDamageRatio". A hard landing (speed
// +680 below -0.25, d24d_fall_ratio_803a13ac above 0) plays "Part_JumpCollideLarge" and a ground effect.
// When +652 is clear it adds (int)((-0.25 - speed) * d24d_fall_ratio_803a13ac) + 1 to the worm's health
// through the handle record, posts the owner message when matched, releases +800,
// sets +660 and posts a message with the worm id, then falls through to the knock
// sound. A soft landing plays "Part_JumpCollide" while the global counter
// 0x804ab3e8 is at most 15, then the knock sound. Built with -mps-float (two saved
// FPRs); the unflagged build differs only by the frame gap.
struct d24d_Vec3 { float x, y, z; };
struct d24d_SettingKey { const char *name; };
struct d24d_Handle { int value; unsigned key; d24d_Handle() { value = 0; key = 58280; } ~d24d_Handle(); };
struct d24d_WormInfo { char pad[164]; int health; };
struct d24d_Message { unsigned short id; void *data; };
struct d24d_Object { void **vtable; };
struct d24d_LandingWorm { char pad[560]; d24d_Vec3 pos; float a; char pad1[4]; float b; int worm; char pad3[64]; int f652; char pad4[4]; int f660; char pad5[16]; float speed; char pad6[116]; d24d_Object *f800; };
extern "C" int d24d_landing_blocked_8014df28(d24d_LandingWorm *);
extern "C" int d24d_setting_read_800fc270(d24d_SettingKey *, float *);
extern "C" int d24d_effect_800e5ca4(const d24d_Vec3 *, const char *, int, float);
extern "C" int d24d_ground_effect_800fdc80(int, int, const d24d_Vec3 *, int, int, int);
extern "C" d24d_WormInfo *d24d_worm_handle_800fc710(int, const d24d_Handle &);
extern "C" int d24d_owner_matches_8014c488(d24d_LandingWorm *);
extern void *d24d_arena_804b1754;
extern int d24d_owner_key_804afb68, d24d_landed_key_804afc60;
extern unsigned char d24d_part_count_804ab3e8;
extern char d24d_message_vtable_8040db38[];
extern "C" void *d24d_arena_alloc_801613f0(void *, int);
extern "C" unsigned d24d_message_id_8015f5a0(int *, int);
extern "C" void *d24d_message_init_800a82f0(void *, unsigned short, int);
extern "C" int d24d_message_post_8016239c(void *);
extern "C" void d24d_worm_knock_sound_80153aac(d24d_LandingWorm *);
extern const char d24d_fall_ratio_803a13ac[], d24d_part_large_803a13c4[], d24d_part_small_803a13dc[];
extern "C" void d24d_worm_landing_8014b498(d24d_LandingWorm *self) {
    if (d24d_landing_blocked_8014df28(self)) return;
    self->a = 0.0f;
    self->b = 0.0f;
    d24d_SettingKey k; float v; k.name = d24d_fall_ratio_803a13ac; d24d_setting_read_800fc270(&k, &v);
    if (self->speed < -0.25f && v > 0.0f) {
        d24d_Vec3 *pos = &self->pos;
        d24d_effect_800e5ca4(pos, d24d_part_large_803a13c4, 0, 0.0f);
        d24d_ground_effect_800fdc80(0, 200, pos, 500, -1, -1);
        if (self->f652 != 0) return;
        d24d_SettingKey k2; float v2; k2.name = d24d_fall_ratio_803a13ac; d24d_setting_read_800fc270(&k2, &v2);
        {
            int amount = (int)((-0.25f - self->speed) * v2) + 1;
            d24d_Handle h;
            d24d_worm_handle_800fc710(self->worm, h)->health += amount;
        }
        if (d24d_owner_matches_8014c488(self)) {
            d24d_Message *m = (d24d_Message *)d24d_arena_alloc_801613f0(d24d_arena_804b1754, 8);
            m->id = d24d_message_id_8015f5a0(&d24d_owner_key_804afb68, 1);
            m->data = d24d_message_vtable_8040db38;
            d24d_message_post_8016239c(m);
        }
        if (self->f800) ((void (*)(d24d_Object *))self->f800->vtable[4])(self->f800);
        self->f800 = 0;
        self->f660 = 1;
        void *n = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 12);
        d24d_message_post_8016239c(d24d_message_init_800a82f0(n, d24d_message_id_8015f5a0(&d24d_landed_key_804afc60, 1), self->worm));
    } else if (d24d_part_count_804ab3e8 <= 15) {
        d24d_effect_800e5ca4(&self->pos, d24d_part_small_803a13dc, 0, 0.0f);
        d24d_part_count_804ab3e8++;
    }
    d24d_worm_knock_sound_80153aac(self);
}
