// d24d: 0x80153aac (456 bytes). Play a worm's knock sound: when the audio system
// (0x804b1788 +108) exists and no sound (+1356) is still playing (slot 9), start
// "Worm.Knock1..4", chosen by the low two bits of 0x80161080, through audio slot 23.
// Position it (slot 14, kind 3, position +560). The volume is the speed (length of
// +676) / 0.3 clamped to [0.25, 1.0]; if above 0, slot 13 sets it and slot 5 plays.
// The float literals form this function's pool at 0x803a1bd4.
struct d24d_Object { void **vtable; };
extern struct { char pad[108]; d24d_Object *audio; } *d24d_game_804b1788;
extern "C" unsigned d24d_random_80161080(void *);
extern "C" float d24d_sqrt_802e82c0(float);
extern const char d24d_knock1_803a1ba4[], d24d_knock2_803a1bb0[], d24d_knock3_803a1bbc[], d24d_knock4_803a1bc8[];
struct d24d_Vec3 { float x, y, z; float len2() const { return x * x + y * y + z * z; } };
struct d24d_Worm { char pad[560]; char pos[116]; d24d_Vec3 vel; char pad2[668]; d24d_Object *sound; };
inline const float &d24d_min_float(const float &a, const float &b) { return a < b ? a : b; }
inline const float &d24d_max_float(const float &a, const float &b) { return a < b ? b : a; }
inline const float &d24d_clamp(const float &v, const float &lo, const float &hi) { return d24d_max_float(d24d_min_float(v, hi), lo); }
extern "C" void d24d_worm_knock_sound_80153aac(d24d_Worm *self) {
    if (!d24d_game_804b1788->audio) return;
    d24d_Object **slot = &self->sound;
    if (self->sound && ((int (*)(d24d_Object *))self->sound->vtable[9])(self->sound)) return;
    switch (d24d_random_80161080(self) & 3) {
    case 0: ((void (*)(d24d_Object *, const char *, d24d_Object **))d24d_game_804b1788->audio->vtable[23])(d24d_game_804b1788->audio, d24d_knock1_803a1ba4, slot); break;
    case 1: ((void (*)(d24d_Object *, const char *, d24d_Object **))d24d_game_804b1788->audio->vtable[23])(d24d_game_804b1788->audio, d24d_knock2_803a1bb0, slot); break;
    case 2: ((void (*)(d24d_Object *, const char *, d24d_Object **))d24d_game_804b1788->audio->vtable[23])(d24d_game_804b1788->audio, d24d_knock3_803a1bbc, slot); break;
    default: ((void (*)(d24d_Object *, const char *, d24d_Object **))d24d_game_804b1788->audio->vtable[23])(d24d_game_804b1788->audio, d24d_knock4_803a1bc8, slot); break;
    }
    ((void (*)(d24d_Object *, int, void *))self->sound->vtable[14])(self->sound, 3, self->pos);
    float v = d24d_sqrt_802e82c0(self->vel.len2()) / 0.3f;
    v = d24d_clamp(v, 0.25f, 1.0f);
    if (v > 0.0f) {
        ((void (*)(d24d_Object *, int, float))self->sound->vtable[13])(self->sound, 1, v);
        ((void (*)(d24d_Object *))self->sound->vtable[5])(self->sound);
    }
}
