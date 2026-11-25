// d32c: 0x800d0108. Rope pendulum step: integrates the swing angle from gravity, input and damping, then places the free end from the two rotation matrices, retrying once with the old yaw when the probes report a block. Returns the end point and writes the angles back. Names are inferred; classes are partial views.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec(float a0, float b0, float c0) { float a = a0, b = b0, c = c0; x = a; y = b; z = c; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct Row { float x, y, z; };
extern "C" void vec_ctor_80343740(void *);
struct Mat {
    Row r[3]; float pos[3];
    Mat() { vec_ctor_80343740(pos); }
    const Row &R(int i) const { return r[i]; }
    const Vec &P() const { return *(const Vec *)pos; }
    void apply(Vec &o, const Vec &v) const {
        const Vec &p = P();
        const Row &a = R(0), &b = R(1), &c = R(2);
        o.x = v.x * a.x + v.y * b.x + v.z * c.x + p.x;
        o.y = v.x * a.y + v.y * b.y + v.z * c.y + p.y;
        o.z = v.x * a.z + v.y * b.z + v.z * c.z + p.z;
    }
    void place(Vec &o, const Vec &v) const {
        const Row &a = R(0), &b = R(1), &c = R(2);
        o.x = v.x * a.x + v.y * b.x + v.z * c.x + P().x;
        o.y = v.x * a.y + v.y * b.y + v.z * c.y + P().y;
        o.z = v.x * a.z + v.y * b.z + v.z * c.z + P().z;
    }
};
extern "C" void axis_801f7538(Mat *, float, float, float, float);
extern "C" void mul_801f740c(Mat *, const Mat *, const Mat *);
extern "C" float sqrt_802e82c0(float);
extern "C" float sin_802e88ac(float);
struct Prop;
extern "C" float read_80178df0(Prop *);
struct Seg { Vec pos; float len; char u16[12]; };
struct Rope;
extern "C" void limits_800d18bc(Rope *, float *, float *);
extern "C" int probe_800d066c(Rope *, Vec *);
extern "C" int drain_800d0058(Rope *, Vec *);
extern Vec start_8045e788;
extern float zero_80388144[], k_80388150[], k_80388154[], k_80388158[];
struct Rope {
    char u0[28]; Seg *begin, *end; char u36[60];
    float f96, f100, f104, f108, f112; char u116[84];
    Prop *p200, *p204; char u208[16]; Prop *p224; char u228[8]; Prop *p236, *p240; char u244[8]; Prop *p252; char u256[12];
    float f268; char u272[16]; float f288;
    Seg &at(int i) { return begin[i]; }
    Vec step(const Vec *target, Vec *state);
};
Vec Rope::step(const Vec *target, Vec *state) {
    int last = (end - begin) - 1;
    float g = read_80178df0(p200) * read_80178df0(p204) * read_80178df0(p252);
    Vec a(start_8045e788);
    Vec diff = *target - at(last).pos;
    float len = sqrt_802e82c0(diff.x * diff.x + diff.y * diff.y + diff.z * diff.z);
    a.y = state->y;
    float swing = zero_80388144[0];
    Mat m;
    axis_801f7538(&m, swing, 1.0f, swing, -a.y);
    Vec v;
    m.apply(v, diff);
    float n = 1.0f / sqrt_802e82c0(v.x * v.x + v.y * v.y + v.z * v.z);
    v.x *= n; v.y *= n; v.z *= n;
    f288 += f268;
    a.x = f288 + 1.5707964f;
    float w0 = -(-g / at(last).len);
    float w = w0 * sin_802e88ac(f288);
    float dt = k_80388150[0];
    float zero = zero_80388144[0];
    swing = w * dt;
    float la = zero;
    float lb = zero;
    limits_800d18bc(this, &la, &lb);
    if (la != zero) f96 = la;
    if (lb != zero) f108 = lb;
    if (f100 != zero) f96 = f100;
    float s = read_80178df0(p236);
    float t = f96;
    f96 = zero;
    f104 = t;
    float push = -t * s * dt;
    float lim = read_80178df0(p240);
    if (len > lim) push *= lim / len;
    f268 += push;
    float damp = read_80178df0(p224);
    f268 = f268 * damp + swing * dt;
    a.x += f268;
    if (f112 != zero) f108 = f112;
    float yaw = a.y;
    a.y = f108 * k_80388154[0] + yaw;
    f108 = zero;
    Mat m1, m2, m3;
    Vec local(zero, zero, at(last).len);
    Vec p, best;
    Vec *pp = &p;
    Vec *pb = &best;
    p.x = zero; pp->y = zero; pp->z = zero;
    best.x = zero; pb->y = zero; pb->z = zero;
    int first = 1;
    for (;;) {
        axis_801f7538(&m1, zero_80388144[0], 1.0f, zero_80388144[0], a.y);
        axis_801f7538(&m2, 1.0f, zero_80388144[0], zero_80388144[0], a.x);
        mul_801f740c(&m3, &m2, &m1);
        m3.place(p, local);
        best = at(last).pos + p;
        if (first) {
            if (probe_800d066c(this, &best) || drain_800d0058(this, &best)) {
                first = 0;
                a.y = yaw;
                continue;
            }
        }
        break;
    }
    float turn = k_80388158[0];
    *state = a;
    state->x += turn;
    return best;
}
