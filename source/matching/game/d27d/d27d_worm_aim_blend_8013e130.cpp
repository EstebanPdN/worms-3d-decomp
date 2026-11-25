// GWMP8P rev0 0x8013e130. Blend a worm's aim fade weights toward the index
// entry's aim values at the configured rate, clamp them to [-1, 1], zero
// them outside the aiming states and below 0.01, then fade the two aim clips
// on the mesh, by the graphic value of the weight when it is non-zero and to
// 0.5 at rate 0 otherwise. Names are inferred.
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Vec { float x, y, z; };
struct Entry { char u0[20]; Vec aim; };
struct Worm { char u0[112]; int index; char u74[380]; int state; char u1f4[88]; float yawBlend; float pitchBlend; char u254[108]; void *rate; };
struct Mesh;
extern "C" Entry *index_query_800fc6dc(int);
extern "C" float level_80178df0(void *);
extern "C" float blend_8013e340(Worm *, float);
extern "C" int fade_80181884(Mesh *, const char *, float, float);
extern const char *pitchClip_804ab3b8;
extern const char *yawClip_804ab3b4;
extern "C" void d27d_worm_aim_blend_8013e130(Worm *self, Mesh *mesh) {
    Entry *e = index_query_800fc6dc(self->index);
    const Vec &aim = e->aim;
    float r = level_80178df0(self->rate);
    self->pitchBlend *= r;
    float t = 1.0f - r;
    self->pitchBlend += aim.x * t;
    self->yawBlend *= r;
    self->yawBlend += aim.z * t;
    self->pitchBlend = clamp(self->pitchBlend, -1.0f, 1.0f);
    self->yawBlend = clamp(self->yawBlend, -1.0f, 1.0f);
    switch (self->state) {
    case 3: case 4: case 5: case 6: case 26: case 36:
        break;
    default:
        self->pitchBlend = self->yawBlend = 0.0f;
    }
    if (__builtin_fabsf(self->pitchBlend) < 0.01f) self->pitchBlend = 0.0f;
    if (__builtin_fabsf(self->yawBlend) < 0.01f) self->yawBlend = 0.0f;
    if (self->pitchBlend != 0.0f) {
        const char *c = pitchClip_804ab3b8;
        fade_80181884(mesh, c, blend_8013e340(self, self->pitchBlend), 1.0f);
    } else {
        fade_80181884(mesh, pitchClip_804ab3b8, 0.5f, 0.0f);
    }
    if (self->yawBlend != 0.0f) {
        const char *c = yawClip_804ab3b4;
        fade_80181884(mesh, c, blend_8013e340(self, self->yawBlend), 1.0f);
    } else {
        fade_80181884(mesh, yawClip_804ab3b4, 0.5f, 0.0f);
    }
}
