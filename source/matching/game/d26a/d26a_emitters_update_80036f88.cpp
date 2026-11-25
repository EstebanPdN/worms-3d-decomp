// GWMP8P rev0 0x80036f88. Emitter group update: positions ten emitters on a
// circle from the time value and pulses the optional extra emitter. Names
// are inferred from the original instructions.
extern "C" float cos_802e86d4(float);
extern "C" float sin_802e88ac(float);
struct Emitter;
struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char v) { r = v; g = v; b = v; a = v; }
    Colour(const Colour &o) { r = o.r; g = o.g; b = o.b; a = o.a; }
};
struct Group {
    char unknown00[36];
    Emitter *items[10];    /* +36 */
    Emitter *extra;        /* +76 */
};
extern "C" int w3d_emitter_setup_8025e128(Emitter *, float, float, float);
extern "C" int w3d_extra_8029358c(Emitter *, float, float, float, float);

extern "C" int w3d_d26a_emitters_update_80036f88(Group *self, unsigned t)
{
    Colour c(255);
    float angle = (float)t / 1000.0f * 6.2831855f;
    for (unsigned i = 0; i < 10; i++) {
        Emitter *e = self->items[i];
        float x = cos_802e86d4(angle) * 10.0f + 100.0f;
        float y = sin_802e88ac(angle) * 10.0f + 50.0f;
        w3d_emitter_setup_8025e128(e, 20.0f, x, y);
    }
    Emitter *x = self->extra;
    if (x) w3d_extra_8029358c(x, 20.0f, 100.0f, 50.0f, sin_802e88ac(angle) * 5.0f + 5.0f);
    return 0;
}
