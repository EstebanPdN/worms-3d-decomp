// d25c: 0x800d4b90. Search for a clear motion: read the two axis endpoints (0x800d4e3c), try the current heading
// offset by +/- i * pi/4 for i = 0..3, then the descriptor's base height. Names are inferred. -mps-float
// explains the 40 bytes between the second vector and the conversion slot (five saved FPRs).
struct Desc { char u0[64]; float base; };
struct Self { char u0[136]; void *h136; char u140[36]; float f176; float f180; };
struct Vec3 { float x, y, z; Vec3() {} };
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" void prepare_800d4e3c(Self *, Vec3 *, Vec3 *);
extern "C" int test_800d4cec(Self *, float, float, Vec3 *, Vec3 *);
extern float quarter_pi_80388d38[];
extern "C" int d25c_ledge_search_800d4b90(Self *self, float *ox, float *oy) {
    Vec3 a, b;
    Desc *d = desc_801797b4(empty_80341584(self->h136));
    float angle = quarter_pi_80388d38[0];
    prepare_800d4e3c(self, &a, &b);
    float y = self->f180;
    for (unsigned i = 0; i <= 3; i++) {
        float step = (float)i * angle;
        float x = self->f176 + step;
        if (test_800d4cec(self, x, y, &a, &b)) { *ox = x; *oy = y; return 1; }
        x = self->f176 - step;
        if (test_800d4cec(self, x, y, &a, &b)) { *ox = x; *oy = y; return 1; }
    }
    float y2 = d->base;
    float x2 = self->f176;
    if (test_800d4cec(self, x2, y2, &a, &b)) { *ox = x2; *oy = y2; return 1; }
    return 0;
}
