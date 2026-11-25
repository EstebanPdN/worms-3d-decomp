// d32c: 0x800d3208. Aim and turn update: traces from the two muzzle points and the four offset rays around the steered tip, then either re-aims along the view (pulling the camera in on a hit), follows a ledge search, or turns from the probe flags, wrapping the yaw into 0..2pi. Names are inferred; classes are partial views.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
};
extern "C" float sqrt_802e82c0(float);
extern "C" float sin_802e88ac(float);
extern "C" float cos_802e86d4(float);
extern "C" int trace_800b0788(const Vec *, const Vec *);
extern unsigned hit_804b1764;
struct Type { char u0[92]; float f92; char u96[8]; float f104, f108; char u112[36]; float f148, f152, f156, f160; };
extern "C" void *empty_80341584(void *);
extern "C" Type *cast_801797b4(void *);
struct Input {
    int word, u4, u8, u12, u16; // word holds the blocking flag bits read with single-bit tests
    int Locked() const {
        int w = word;
        int r = 0;
        if (w < 0) goto yes;
        if (w & 0x40000000) goto yes;
        if (w & 0x20000000) goto yes;
        if (w & 0x10000000) goto yes;
        if (w & 0x08000000) goto yes;
        if (w & 0x04000000) goto yes;
        if (w & 0x02000000) goto yes;
        if (w & 0x01000000) goto yes;
        if (u8 > 0) goto yes;
        if (u12 > 0) goto yes;
        if (u16 > 0) goto yes;
        if (w & 0x00400000) yes: r = 1;
        return r;
    }
};
inline int Near(const float *a, const float *b) {
    for (int i = 0; i < 3; i++)
        if (__builtin_fabsf(b[i] - a[i]) > 0.1f) return 0;
    return 1;
}
struct Actor;
extern "C" void muzzle_800d4e3c(Actor *, Vec *, Vec *);
extern "C" void steer_800d489c(Actor *, Vec *);
extern "C" int ledge_800d4b90(Actor *, float *, float *);
extern "C" void probe_800d3e5c(Actor *, int, unsigned, unsigned, unsigned, unsigned, unsigned char *, float *, float *);
extern "C" void ease_800d4734(Actor *, float, int);
extern "C" void ease_800d47f0(Actor *, float, int);
extern Vec middle_8043ae20;
extern int guard_804ae9e8;
extern float seen_80440e1c[];
struct Actor {
    char u0[16]; float f16[3]; char u28[48]; Vec pos; float f88[3]; float u100[3]; Vec vel; char u124[12]; void *owner; Vec p140; char u152[24];
    float yaw, pitch; char u184[4]; float f188, f192; char u196[4]; unsigned char flags;
    void update(float dt, const Input *in);
};
void Actor::update(float dt, const Input *in) {
    Type *t = cast_801797b4(empty_80341584(owner));
    Vec eye(pos);
    if (!guard_804ae9e8) {
        float *s = seen_80440e1c;
        s[0] = 0.0f; s[1] = 0.0f; s[2] = 0.0f;
        guard_804ae9e8 = 1;
    }
    Vec a, b;
    muzzle_800d4e3c(this, &a, &b);
    Vec d1, d2;
    d1 = eye - a;
    d2 = eye - b;
    trace_800b0788(&a, &d1);
    unsigned h1 = hit_804b1764;
    trace_800b0788(&b, &d2);
    unsigned h2 = hit_804b1764;
    steer_800d489c(this, &a);
    Vec tip = a + vel;
    Vec c = tip;
    float co = cos_802e86d4(yaw);
    float si = sin_802e88ac(yaw);
    float zero = 0.0f;
    Vec u, v, w, n;
    Vec *pu = &u, *pv = &v, *pw = &w, *pn = &n;
    u.x = -co; pu->y = zero; u.z = si;
    v.x = co; pv->y = zero; v.z = -si;
    w.x = zero; pw->y = 1.0f; pw->z = zero;
    n.x = zero; pn->y = -1.0f; pn->z = zero;
    Vec e0 = c + u * t->f160;
    Vec e1 = c + v * t->f160;
    Vec e2 = c + w * t->f160;
    Vec e3 = c + n * t->f160;
    u = eye + u * t->f152 - e0;
    v = eye + v * t->f152 - e1;
    w = eye + w * t->f152 - e2;
    n = eye + n * t->f152 - e3;
    trace_800b0788(&e0, &u);
    unsigned h3 = hit_804b1764;
    trace_800b0788(&e1, &v);
    unsigned h4 = hit_804b1764;
    trace_800b0788(&e2, &w);
    unsigned h5 = hit_804b1764;
    trace_800b0788(&e3, &n);
    unsigned h6 = hit_804b1764;
    float tilt = zero;
    float turn = zero;
    unsigned char mode = 0;
    float la, lb;
    if (h1 <= 1000 && h2 <= 1000) {
        int p = (h3 > 1000 && h4 > 1000) || (h3 <= 1000 && h4 <= 1000);
        int q = (h5 > 1000 && h6 > 1000) || (h5 <= 1000 && h6 <= 1000);
        if (p && q) {
            Vec to = eye - p140;
            trace_800b0788(&p140, &to);
            if (hit_804b1764 <= 1000) {
                Vec m(middle_8043ae20);
                Vec dd = m - p140;
                float len = sqrt_802e82c0(dd.x * dd.x + dd.y * dd.y + dd.z * dd.z);
                if (len >= t->f104) {
                    f192 = len;
                } else if (ledge_800d4b90(this, &la, &lb)) {
                    if (!in->Locked()) {
                        if (la > yaw || la < yaw) yaw = la;
                    }
                    if (!in->Locked()) {
                        if (lb < pitch || lb > pitch) pitch = lb;
                    }
                    return;
                }
            }
        }
    } else {
        f192 = t->f92;
        Vec dd = eye - p140;
        float l2 = dd.x * dd.x + dd.y * dd.y + dd.z * dd.z;
        if (l2 > 0.0f) {
            float k = 1.0f / sqrt_802e82c0(l2);
            dd.x *= k; dd.y *= k; dd.z *= k;
        }
        Vec to = dd * (f192 - f188);
        trace_800b0788(&eye, &to);
        if (hit_804b1764 <= 1000) {
            Vec m(middle_8043ae20);
            Vec e = m - p140;
            f192 = sqrt_802e82c0(e.x * e.x + e.y * e.y + e.z * e.z);
        }
        if (Near(f88, f16)) { flags = 0; return; }
    }
    if (!mode) probe_800d3e5c(this, 1000, h3, h4, h5, h6, &mode, &tilt, &turn);
    if ((mode & 3) && (flags & 3) && (flags & 3) != (mode & 3)) { float k = t->f108; turn = turn * k; }
    else flags = (flags & 0xfc) | (mode & 3);
    if ((mode & 12) && (flags & 12) && (flags & 12) != (mode & 12)) { float k = t->f108; tilt = tilt * k; }
    else flags = (flags & 243) | (mode & 12);
    if ((mode & 12) == 4 && !(in->word & 0x04000000)) {
        yaw -= t->f148 * dt * tilt;
        while (yaw < 0.0f) yaw += 6.2831855f;
    }
    if ((mode & 12) == 8 && !(in->word & 0x08000000)) {
        yaw += t->f148 * dt * tilt;
        while (yaw > 6.2831855f) yaw -= 6.2831855f;
    }
    if ((mode & 3) == 1 && !(in->word & 0x02000000)) ease_800d4734(this, t->f156 * dt * turn, 1);
    if ((mode & 3) == 2 && !(in->word & 0x01000000)) ease_800d47f0(this, t->f156 * dt * turn, 1);
}
