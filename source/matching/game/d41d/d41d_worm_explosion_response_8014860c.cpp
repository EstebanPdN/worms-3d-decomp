// d41d: 0x8014860c. Worm's response to an explosion: distance against the
// blast radius gives a power; a function-local static zero vector guards the
// direction test; up to four random spreads are swept against the landscape
// before the impulse, and the outer radius gives damage. Class fields are
// partial views.
extern "C" float sqrtf_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    float len2() const { return x * x + y * y + z * z; }
    float operator[](int i) const { return (&x)[i]; }
};
struct Motion;
struct Item { char u0[80]; Vec pos; char u5c[128]; int f220; };
struct Obj;
struct Self { char u0[584]; int f584; char u24c[100]; Vec f688; char u2bc[532]; struct Obj *f1232; };
extern "C" {
Item *query_800fc6dc(int);
Vec center_800668b8(Motion *);
Vec center2_80066894(Motion *);
float radius_800668dc(Motion *);
float power_800668fc(Motion *);
float radius2_800668e4(Motion *);
float damage_800668f4(Motion *);
float rand_80162bc8();
void sweep_800b0824(const Vec &, const Vec &, const Vec &, int, int);
float water_80178df0(Obj *);
void impulse_80148c14(Self *, const Vec &, float);
void damage_80148a40(Self *, int);
}
extern int hits_804b1764;
extern Vec hit_8043ae20[];
static inline float dist(const Vec &a, const Vec &b) { float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z; return sqrtf_802e82c0(dx * dx + dy * dy + dz * dz); }
extern "C" void w3d_d41d_worm_explosion_response_8014860c(Self *self, Motion *m) {
    Item *it = query_800fc6dc(self->f584);
    if (it->f220 == 0) return;
    Vec pos = it->pos;
    float d = dist(pos, center_800668b8(m));
    float r = radius_800668dc(m);
    if (d < r) {
        float power = (r - d) * power_800668fc(m) / r;
        Vec diff = pos - center_800668b8(m);
        static Vec zero_local(0.0f, 0.0f, 0.0f);
const Vec &z = zero_local; int eq; { int i; for (i = 0; i < 3; i++) if (__builtin_fabsf(z[i] - diff[i]) > 1.1920929e-07f) { eq = 0; goto done; } eq = 1; done: ; }
        if (!eq) {
            float s = 1.0f / sqrtf_802e82c0(diff.len2());
            diff.x *= s; diff.y *= s; diff.z *= s;
            for (unsigned n = 0; n <= 3; n++) {
                float x = (rand_80162bc8() * 2 - 1.0f) * 0.15f;
                float zero = 0.0f;
                float z = rand_80162bc8() * 2 - 1.0f;
                Vec v;
                Vec *pv = &v;
                pv->x = x;
                pv->y = zero;
                pv->x += diff.x; v.y += diff.y; v.z = z * 0.15f + diff.z;
                float t = 1.0f / sqrtf_802e82c0(v.len2());
                v.x *= t; v.y *= t; v.z *= t;
                float f = (rand_80162bc8() * 0.15f * 2 + 0.85f) * power;
                Vec imp = v * f;
                sweep_800b0824(pos, imp, self->f688, 5000, 1);
                if ((unsigned)hits_804b1764 <= 4999 && hit_8043ae20->y > water_80178df0(self->f1232)) { power = f; n = 4; diff = v; }
            }
            impulse_80148c14(self, diff, power);
        }
    }
    d = dist(pos, center2_80066894(m));
    r = radius2_800668e4(m);
    if (d < r) {
        float a = (r - d) * damage_800668f4(m) / r;
        if (a > 0.0f && a < 1.0f) a = 1.0f;
        damage_80148a40(self, (int)a);
    }
}
