// GWMP8P rev0 0x800cb0fc. Follow camera update. Names are inferred.
// Remembers the old vectors, moves the target to the position at +80 of the
// tracked object at the index read from the state object, pulls the eye
// toward the target when it is more than 400 away, runs the orbit input
// step, and when the range test 0x800cc070 says the eye is blocked tries the
// eye raised and lowered by 10, a step toward the target, then the eye
// turned by 15 degrees either way, and takes the first free one. Finally
// eases the look and eye vectors with weights 0.9 and 0.1. Class layouts are
// partial views. The dt float is written before the input pointer because
// that order sets the argument moves.
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator*=(float k) { x *= k; y *= k; z *= k; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Transform { Axis axis[3]; Pos position; const Pos &P() const { return position; } };
struct Row { float x, y, z, w; };
struct Mat44 {
    Row row[4];
    Mat44(const Transform &t) {
        row[0].x = t.axis[0].x; row[0].y = t.axis[0].y; row[0].z = t.axis[0].z; row[0].w = 0.0f;
        row[1].x = t.axis[1].x; row[1].y = t.axis[1].y; row[1].z = t.axis[1].z; row[1].w = 0.0f;
        row[2].x = t.axis[2].x; row[2].y = t.axis[2].y; row[2].z = t.axis[2].z; row[2].w = 0.0f;
        row[3].x = t.P().x; row[3].y = t.P().y; row[3].z = t.P().z; row[3].w = 1.0f;
    }
    const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" unsigned read_80178c48(void *);
struct Input;
struct Tracked { char unknown00[80]; Vec pos; };
extern "C" Tracked *query_800fc6dc(unsigned);
struct Cam { int unknown0; Vec eye; Vec look; Vec c; char unknown40[16]; void *state; char unknown60[16]; Vec pos; char unknown88[12]; Vec target; };
extern "C" int in_range_800cc070(Cam *, const Vec *, const Vec *);
extern "C" int orbit_800cc148(Cam *, Input *, float);
inline float DistSq(const Vec &a, const Vec &b) {
    float x = a.x - b.x; x *= x; float y = a.y - b.y; y *= y; float z = a.z - b.z; z *= z; return x + y + z;
}
extern "C" void d31h_follow_camera_honest_800cb0fc(Cam *self, float dt, Input *in) {
    Vec oldEye = self->eye;
    Vec oldC = self->c;
    Vec oldTarget = self->target;
    Vec oldLook = self->look;
    unsigned st = read_80178c48(self->state);
    if (st > 16) return;
    self->target = query_800fc6dc(st)->pos;
    if (DistSq(self->target, self->pos) > 160000.0f) {
        Vec d = self->target - self->pos;
        self->pos += d * 0.1f;
    }
    orbit_800cc148(self, in, dt);
    if (in_range_800cc070(self, &self->pos, &self->target)) {
        Vec up(0.0f, 10.0f, 0.0f);
        Vec hi = self->pos + up;
        Vec lo = self->pos - up;
        if (!in_range_800cc070(self, &hi, &self->target)) { self->pos = hi; }
        else if (!in_range_800cc070(self, &lo, &self->target)) { self->pos = lo; }
        else {
            Vec step = self->target - self->pos;
            step *= 0.1f;
            Vec mid = self->pos + step;
            if (!in_range_800cc070(self, &mid, &self->target)) { self->pos = mid; }
            else {
                Vec d = self->pos - self->target;
                Transform m;
                float a = 0.2617994f;
                construct_801f7538(&m, 0.0f, 1.0f, 0.0f, a);
                Mat44(m).rotate(hi, d);
                hi += self->target;
                construct_801f7538(&m, 0.0f, 1.0f, 0.0f, -a);
                Mat44(m).rotate(lo, d);
                lo += self->target;
                if (!in_range_800cc070(self, &hi, &self->target)) { self->pos = hi; }
                else if (!in_range_800cc070(self, &lo, &self->target)) { self->pos = lo; }
            }
        }
    }
    self->look = self->look * 0.9f + self->target * 0.1f;
    self->eye = self->eye * 0.9f + self->pos * 0.1f;
}
