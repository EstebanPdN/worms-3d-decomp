// Camera rig aim (Worms 3D GameCube PAL, 0x800a98b0, 616 bytes).
//
// Field names are inferred. Vector subtraction returns through a named local and
// a member-wise copy, which gives the two result blocks the original writes.

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 operator-(const Vec3 &o) const {
        Vec3 r;
        r.x = x - o.x;
        r.y = y - o.y;
        r.z = z - o.z;
        return Vec3(r);
    }
    Vec3 Copy() const { return *this; }
};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
extern "C" int fn_80178c48(void *);
extern "C" float fn_80178df0(void *);
struct Query { unsigned char u[72]; float angle; unsigned char u76[4]; Vec3 pos; };
extern "C" Query *fn_800fc6dc(int);
extern "C" float fn_802e82c0(float);
extern "C" float fn_802e7c30(float);
extern "C" float fn_802e8988(float);
extern "C" float fn_802e88ac(float);
extern "C" float fn_802e86d4(float);
struct Rig {
    unsigned char u0[4];
    Vec3 eye;      // +4
    Vec3 goal;     // +16
    unsigned char u28[28];
    void *link;    // +56
    unsigned char u60[16];
    float tilt;    // +76
    float heading; // +80
    unsigned char u84[12];
    Vec3 from;     // +96
    unsigned char u108[12];
    void *dist;    // +120
    void *lift;    // +124
    unsigned char u128[40];
    void *pitch;   // +168
};
extern "C" void fn_800a9b60(Rig *);
extern "C" void w3d_d25h_rig_aim_800a98b0(Rig *self) {
    Vec3 target;
    if (fn_80178c48(self->link) >= 0) {
        Query *q = fn_800fc6dc(fn_80178c48(self->link));
        Vec3 p(q->pos);
        self->heading = q->angle;
        target = p;
    } else {
        self->heading = 0.0f;
        target = self->goal;
    }
    float zero = 0.0f;
    Vec3 d;
    Vec3 flat;
    d = self->goal - self->eye;
    flat = d;
    flat.y = zero;
    float len = flat.x * flat.x + zero + flat.z * flat.z;
    if (len > zero) {
        float k = 1.0f / fn_802e82c0(len);
        flat.x *= k;
        flat.y *= k;
        flat.z *= k;
        float a = fn_802e7c30(flat.x);
        if (d.z < zero) a = 3.1415927f - a;
        self->heading = a;
    }
    self->tilt = fn_80178df0(self->pitch);
    float total = fn_80178df0(self->dist) + fn_80178df0(self->lift);
    float high = target.y + fn_80178df0(self->lift);
    self->from.y = Max(total, high);
    float run = (self->from.y - target.y) / fn_802e8988(self->tilt);
    self->from.x = target.x - run * fn_802e88ac(self->heading);
    self->from.z = target.z - run * fn_802e86d4(self->heading);
    fn_800a9b60(self);
}
