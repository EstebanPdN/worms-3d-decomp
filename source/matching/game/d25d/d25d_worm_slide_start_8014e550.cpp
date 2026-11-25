// GWMP8P rev0 0x8014e550. Start a worm slide from state 0: load the slide
// names when the maximum speed is zero, add a random speed between the
// limits (+816, +820) along a normalized random horizontal direction with a
// 0.15 lift, enter state 9, and trace 'Worm Slide' at WormLogicEntity.cpp
// line 4937 when the object's class derives from either of two classes
// (0x80361860, 0x803618f0). Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Class { unsigned char u[20]; Class *base; };
inline int isA(Class *c, Class *t) {
    for (; c != t; c = c->base) if (c == c->base) return 0;
    return 1;
}
struct Worm;
struct WormVt { void *u[5]; Class *(*klass)(Worm *); };
struct Worm {
    WormVt *vt;
    unsigned char u4[672]; Vec vel;
    unsigned char u688[72]; int state;
    unsigned char u764[40]; char slideData[12]; float lo; float hi;
};
extern "C" void names_8014e4c8(Worm *);
extern "C" float random_801610a0(Worm *);
extern "C" int trace_80022e20(const char *, const char *, int, void *);
extern Class class_80361860[], class_803618f0[];
extern const char file_803a0e2c[];
extern "C" void d25d_worm_slide_start_8014e550(Worm *self) {
    float s = self->lo;
    if (self->state == 0) {
        if (self->hi == 0.0f) names_8014e4c8(self);
        float a = random_801610a0(self);
        float one = 1.0f, k = 0.15f;
        a = a + a - one;
        float b = random_801610a0(self);
        Vec d(a, k, b + b - one);
        d.normalize();
        s += random_801610a0(self) * (self->hi - self->lo);
        self->vel += d * s;
        self->state = 9;
        if (isA(self->vt->klass(self), class_80361860) || isA(self->vt->klass(self), class_803618f0))
            trace_80022e20("Worm Slide", file_803a0e2c, 4937, self->slideData);
    }
}
