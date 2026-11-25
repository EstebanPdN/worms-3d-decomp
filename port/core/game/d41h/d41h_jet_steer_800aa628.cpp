#include "w3d_ptr.h"
#line 1 "d41h_jet_steer_800aa628.cpp"
// GWMP8P rev0 0x800aa628. Jet pack steering: copies the rotation, applies
// the left and right turn input, turns toward the input direction (in view
// space unless the input is already in screen space) by at most the turn
// rate, wraps the yaw to one turn, and clamps the forward speed taken from
// the current velocity. Returns the new rotation by value. Partial views;
// names inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Axis { float x, y, z; };
struct Mat33 {
    Axis axis[3];
    const Axis &A(int i) const;
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z;
    }
};
extern "C" void axis_angle_801f6480(Ptr32<Mat33>, float, float, float, float);
struct Row { float x, y, z, w; };
struct Mat44 {
    Row row[4];
    const Row &R(int i) const { return row[i]; }
    inline void Load();
    inline void Norm(const Mat44 &m);
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" void view_matrix_8015aa04(Ptr32<void>, Ptr32<Mat44>);
extern "C" int normalize_801f6c2c(Ptr32<Mat44>, Ptr32<const Mat44>);
extern Ptr32<char> lbl_804aa8c8;
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline void Mat44::Load() { view_matrix_8015aa04(lbl_804aa8c8 + 328, this); }
inline void Mat44::Norm(const Mat44 &m) { normalize_801f6c2c(this, &m); }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Setting;
extern "C" float get_float_80178df0(Ptr32<Setting>);
struct Jet {
    char u0[80];
    int left, right;  // +80, +84
    Vec v;            // +88
    Vec w;            // +100
    char u112[4];
    int screenInput;  // +116
    char u120[28];
    int turning;      // +148
    char u152[36];
    Ptr32<Setting> turnRate;  // +188
    char u192[32];
    Ptr32<Setting> maxSpeed;  // +224
};
extern "C" void blend_800abc18(Ptr32<Jet>, float);
extern "C" Vec d41h_jet_steer_800aa628(Ptr32<Jet> self, const Vec &rot, const Vec &input) {
    self->v = rot;
    self->turning = 0;
    float rate = get_float_80178df0(self->turnRate);
    float turn = rate + rate;
    if (self->left) {
        self->turning = 1;
        self->v.y += turn;
    } else if (self->right) {
        self->turning = 1;
        self->v.y -= turn;
    }
    Vec dir;
    Ptr32<Vec> d = &dir;
    float l = input.len();
    float zero = 0.0f;
    if (l > zero) {
        if (self->screenInput == 0) {
            Mat44 t;
            Ptr32<Mat44> tp = &t;
            Mat44 m;
            m.Load();
            tp->Norm(m);
            Vec v;
            Ptr32<Vec> pv = &v; v.x = zero - input.x; pv->y = zero; v.z = input.z;
            t.rotate(*d, v);
        } else {
            *d = input;
            dir.x = -dir.x;
        }
        {
            float z0 = 0.0f;
            float neg = -1.0f;
            Vec fwd;
            Ptr32<Vec> q = &fwd;
            fwd.x = z0;
            q->y = z0;
            q->z = neg;
            Vec out;
            Mat33 r;
            axis_angle_801f6480(&r, z0, 1.0f, z0, rot.y);
            out.x = fwd.x * r.A(0).x + fwd.y * r.A(1).x + fwd.z * r.A(2).x;
            out.y = fwd.x * r.A(0).y + fwd.y * r.A(1).y + fwd.z * r.A(2).y;
            out.z = fwd.x * r.A(0).z + fwd.y * r.A(1).z + fwd.z * r.A(2).z;
            float l0 = out.len();
            float one = 1.0f;
            float f0 = one / l0; out.x *= f0; out.y *= f0; out.z *= f0;
            dir.y = z0;
            { float f = one / sqrt_802e82c0(dir.x * dir.x + d->y * d->y + d->z * d->z); dir.x *= f; d->y *= f; d->z *= f; }
            float c = out.x * dir.x + out.y * d->y + out.z * d->z;
            float a = acos_802e79e0(c);
            if (a > turn) a = turn;
            if (a > z0) self->turning = 1;
            if (c > neg && c < one) {
                Vec cross;
                cross.x = out.y * d->z - out.z * d->y;
                cross.y = out.z * dir.x - out.x * d->z;
                cross.z = out.x * d->y - out.y * dir.x;
                if (cross.y > z0) self->v.y += a;
                else self->v.y -= a;
            }
        }
    }
    blend_800abc18(self, rot.y - self->v.y);
    while (self->v.y > 6.2831855f) self->v.y -= 6.2831855f;
    while (self->v.y < 0.0f) self->v.y += 6.2831855f;
    { const Vec &w = self->w; float a = w.x, b = w.y, c = w.z; dir.x = a; d->y = b; d->z = c; }
    dir.y = 0.0f;
    self->v.x = sqrt_802e82c0(dir.x * dir.x + d->y * d->y + d->z * d->z) * 6.0f;
    float lo = -get_float_80178df0(self->maxSpeed);
    float hi = get_float_80178df0(self->maxSpeed);
    self->v.x = clamp(self->v.x, lo, hi);
    return self->v;
}


