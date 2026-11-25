// GWMP8P rev0 0x800accfc. Chase camera update. Names are inferred. Reads the
// tracked object at index st, builds a look point from its position offset
// by height and rise turned by its heading, and an eye point behind it along
// its horizontal velocity when it is moving, lowers it by the vertical
// velocity, then eases the eye, look and up vectors with three tunable
// weights, renormalises up, and keeps the eye between the minimum and
// maximum distance tunables, the far limit softened by 0.05. Class layouts
// are partial views. The tunable objects are read through 0x80178df0.
extern "C" float sqrt_802e82c0(float);
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
    void operator*=(float k) { x *= k; y *= k; z *= k; }
    void Normalize() { float i = 1.0f / len(); x *= i; y *= i; z *= i; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator/(const Vec &a, float k) { float i = 1.0f / k; Vec r; r.x = a.x * i; r.y = a.y * i; r.z = a.z * i; return r; }
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &R(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" unsigned read_80178c48(void *);
extern "C" float value_80178df0(void *);
struct Tracked { char unknown00[44]; float vx, vy, vz; char unknown56[16]; float heading; int unknown76; Vec pos; };
extern "C" Tracked *query_800fc6dc(unsigned);
struct Cam {
    int unknown0; Vec eye; Vec look; Vec up; char unknown40[16]; void *state; char unknown60[24];
    void *height; void *easeEye; void *easeLook; void *easeUp; char unknown100[12];
    void *drop; void *lag; void *rise; void *minDist; void *maxDist;
    Vec wantEye; Vec wantUp; Vec wantLook;
};
extern "C" void d31h_chase_camera_update_800accfc(Cam *self) {
    Vec oldEye = self->eye;
    Vec oldUp = self->up;
    Vec oldLook = self->wantLook;
    Vec oldL = self->look;
    unsigned st = read_80178c48(self->state);
    if (st > 16) return;
    self->wantLook = query_800fc6dc(st)->pos;
    Vec a = query_800fc6dc(st)->pos;
    Vec b = query_800fc6dc(st)->pos;
    {
        float h = value_80178df0(self->height);
        float v = value_80178df0(self->rise);
        float zero = 0.0f;
        Vec off;
        off.x = zero; off.y = h; off.z = v;
        {
            Transform m;
            construct_801f7538(&m, zero, 1.0f, zero, query_800fc6dc(st)->heading);
            Vec w;
            m.apply(w, off);
            b += w;
        }
        Tracked *q = query_800fc6dc(st);
        float vx = q->vx, vz = q->vz;
        off.x = vx; off.z = vz; off.y = 0.0f;
        float speed = off.len();
        if (speed > 1e-6f) {
            Vec n = off;
            n.Normalize();
            a -= n * value_80178df0(self->lag);
            a -= (n * speed) * value_80178df0(self->drop);
        } else {
            a = b;
        }
    }
    float vy = query_800fc6dc(st)->vy;
    a.y -= vy * value_80178df0(self->drop);
    self->wantEye = (a + b) / 2.0f;
    self->wantUp.Set(0.0f, 1.0f, 0.0f);
    float t0 = value_80178df0(self->easeEye);
    float t1 = value_80178df0(self->easeLook);
    float t2 = value_80178df0(self->easeUp);
    self->eye = self->eye * (1.0f - t0) + self->wantEye * t0;
    self->look = self->look * (1.0f - t1) + self->wantLook * t1;
    self->up = self->up * (1.0f - t2) + self->wantUp * t2;
    if (self->up.lenSq() == 0.0f) self->up.Set(0.0f, 1.0f, 0.0f);
    self->up.Normalize();
    Vec d = self->eye - self->look;
    if (d.lenSq() > 0.0f) {
        float dist = d.len();
        if (dist < value_80178df0(self->minDist)) {
            if (d.lenSq() == 0.0f) {
                self->eye = self->look - b * value_80178df0(self->minDist);
            } else {
                d.Normalize();
                d *= value_80178df0(self->minDist);
                self->eye = self->look + d;
            }
        }
        if (dist > value_80178df0(self->maxDist)) {
            float k = 0.05f;
            d.Normalize();
            d *= dist * (1.0f - k) + value_80178df0(self->maxDist) * k;
            self->eye = self->look + d;
        }
    }
}
