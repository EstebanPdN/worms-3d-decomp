// GWMP8P rev0 0x801381f0. Compute a worm's look blend value: the signed
// angle between its forward axis and its flattened record direction, wrapped
// to plus or minus pi, scaled by the record's gain, clamped to plus or minus
// pi/2 and mapped into 0..1 as a fraction of a full turn. The axis is
// rotated through a 4x4 copy of the transform. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float asin_802e7c30(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void unit() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline const float &fminA(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fminB(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float clamp(const float &v, const float &lo, const float &hi) { return fmax(fminA(v, hi), lo); }
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform { Axis axis[3]; Pos position; const Pos &P() const { return position; } };
struct Row { float x, y, z, w; };
struct Matrix {
    Row row[4];
    Matrix(const Transform &t) {
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
struct Info { char u0[32]; Vec dir; char u2c[80]; float gain; };
struct Worm { char u0[68]; float yaw; char u48[40]; int index; };
extern "C" Info *index_query_800fc6dc(int);
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" float d26d_worm_look_blend_801381f0(Worm *self) {
    Info *in = index_query_800fc6dc(self->index);
    Vec v = in->dir;
    float a = 0.0f;
    v.y = a;
    if (v.lenSq() > a) {
        Vec fw(0.0f, 0.0f, -1.0f);
        Vec w;
        Transform t;
        construct_801f7538(&t, 0.0f, 1.0f, 0.0f, self->yaw);
        Matrix m(t);
        m.rotate(w, fw);
        v.unit();
        w.unit();
        float c = w.dot(v);
        c = clamp(c, -1.0f, 1.0f);
        a = asin_802e7c30(c);
        while (a < -3.1415927f) a += 6.2831855f;
        while (a > 3.1415927f) a -= 6.2831855f;
    }
    float s = in->gain * -a;
    s = fmax(s, -1.5707964f);
    s = fminB(s, 1.5707964f);
    float f = (s + 3.1415927f) / 6.2831855f;
    while (f > 1.0f) f -= 1.0f;
    while (f < 0.0f) f += 1.0f;
    return f;
}
