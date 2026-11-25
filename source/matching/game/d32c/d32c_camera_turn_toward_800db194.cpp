// d32c: 0x800db194. Turns the actor towards the camera-relative input: applies the left and right turn flags, rotates the input by the inverse view unless it is already in world space, and steps the yaw by at most 0.02 towards it. Names are inferred; classes are partial views.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    float dot(const Vec3 &o) const { return x * o.x + y * o.y + z * o.z; }
};
inline Vec3 cross(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.y * b.z - a.z * b.y; r.y = a.z * b.x - a.x * b.z; r.z = a.x * b.y - a.y * b.x; return r; }
struct Row { float x, y, z, w; };
extern "C" void view_8015aa04(void *, struct Mat *);
extern "C" int norm_801f6c2c(struct Mat *, const struct Mat *);
extern char *camera_804aa8c8;
struct Mat { void Fetch() { view_8015aa04(camera_804aa8c8 + 328, this); } Row r[4]; const Row &R(int i) const { return r[i]; } };
struct Row3 { float x, y, z; };
struct Mat3 { Row3 r[3]; const Row3 &R(int i) const { return r[i]; } };
struct Cam { struct V { void *u[6]; const Mat *(*matrix)(Cam *); } *vtable; };
struct Svc { char u[48]; Cam *cam; };
struct Self { char u0[84]; Vec3 rot; char u96[52]; int left; int right; };
extern Svc *svc_804b1788;
extern "C" void turn_800dbd58(Self *, float);
extern "C" void axis_801f6480(Mat3 *, float, float, float, float);
extern "C" float steer_800dbda8(Self *);
extern "C" float damp_800dbd74(Self *);
extern "C" void smooth_800dc0b4(Self *, float);
extern "C" Vec3 d32c_camera_turn_toward_800db194(Self *self, const Vec3 &rot, const Vec3 &v, int world) {
    self->rot = *(const Vec3 *)&rot;
    if (self->left) {
        self->rot.y += 0.02f;
        turn_800dbd58(self, 0.02f);
    } else if (self->right) {
        self->rot.y -= 0.02f;
        turn_800dbd58(self, -0.02f);
    }
    if (v.len() > 0.0f) {
        Mat inv, m;
        m.Fetch();
        norm_801f6c2c(&inv, &m);
        norm_801f6c2c(&inv, svc_804b1788->cam->vtable->matrix(svc_804b1788->cam));
        Vec3 o;
        Vec3 w(0.0f - v.x, 0.0f, v.z);
        if (world) {
            o = w;
        } else {
            o.x = w.x * inv.R(0).x + w.y * inv.R(1).x + w.z * inv.R(2).x;
            o.y = w.x * inv.R(0).y + w.y * inv.R(1).y + w.z * inv.R(2).y;
            o.z = w.x * inv.R(0).z + w.y * inv.R(1).z + w.z * inv.R(2).z;
        }
        Vec3 z(0.0f, 0.0f, -1.0f);
        Vec3 fwd;
        Mat3 t;
        axis_801f6480(&t, 0.0f, 1.0f, 0.0f, rot.y);
        fwd.x = z.x * t.R(0).x + z.y * t.R(1).x + z.z * t.R(2).x;
        fwd.y = z.x * t.R(0).y + z.y * t.R(1).y + z.z * t.R(2).y;
        fwd.z = z.x * t.R(0).z + z.y * t.R(1).z + z.z * t.R(2).z;
        fwd.normalize();
        o.y = 0.0f;
        o.normalize();
        float c = fwd.dot(o);
        float ang = acos_802e79e0(c);
        if (ang > 0.02f) ang = 0.02f;
        if (c > -1.0f && c < 1.0f) {
            Vec3 n;
            n.x = fwd.y * o.z - fwd.z * o.y;
            n.y = fwd.z * o.x - fwd.x * o.z;
            n.z = fwd.x * o.y - fwd.y * o.x;
            if (n.y > 0.0f) {
                self->rot.y += ang;
                turn_800dbd58(self, ang);
            } else {
                self->rot.y -= ang;
                turn_800dbd58(self, -ang);
            }
        }
    }
    while (self->rot.y > 6.2831855f) self->rot.y -= 6.2831855f;
    while (self->rot.y < 0.0f) self->rot.y += 6.2831855f;
    self->rot.x = steer_800dbda8(self);
    self->rot.z = damp_800dbd74(self);
    smooth_800dc0b4(self, rot.y - self->rot.y);
    return self->rot;
}
