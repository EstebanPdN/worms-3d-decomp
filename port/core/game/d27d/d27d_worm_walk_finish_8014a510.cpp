#include "w3d_ptr.h"
#line 1 "d27d_worm_walk_finish_8014a510.cpp"
// GWMP8P rev0 0x8014a510. Finish a worm's walk once 500 ms have passed since
// it began: with the settings bit set defer to the walk transition at
// 0x80150c3c, otherwise take the velocity and animation for the walking
// state, using the angle between the facing and the flattened input in state
// 4. Clear the flags, set state 6 and clear the top bit of the flag word.
// Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
extern "C" float sin_802e88ac(float);
extern "C" float cos_802e86d4(float);
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
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Row { float x, y, z, w; };
struct Matrix {
    Row r[4];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Worm;
extern "C" Vec input_8014c260(Ptr32<Worm>);
extern "C" void view_8014be44(Ptr32<Worm>, Ptr32<Matrix>);
extern "C" int invert_801f6c2c(Ptr32<Matrix>, Ptr32<const Matrix>);
extern "C" Ptr32<const Vec> speed_80178ec4(Ptr32<void>);
struct Worm {
    char u0[576]; float yaw; char u244[96]; Vec vel; char u2b0[28]; int f2cc; char u2d0[16]; int stop; char u2e4[4]; int f2e8; char u2ec[12]; int state; char u2fc[60]; unsigned flags;
};
extern "C" void setAnim_801492ec(Ptr32<Worm>, int);
extern Ptr32<void> speedA_804afdd8;
extern Ptr32<void> speedB_804afddc;
extern Ptr32<void> speedC_804afde0;
extern Ptr32<void> speedD_804afde4;
struct Context { char u0[52]; unsigned now; };
extern "C" Ptr32<Context> context_80165254();
struct Settings { char u0[188]; unsigned bits; };
extern Ptr32<Settings> settings_804b1788;
extern "C" void exit_80150c3c(Ptr32<Worm>);
extern "C" void d27d_worm_walk_finish_8014a510(Ptr32<Worm> self) {
    if ((unsigned)(self->state - 2) > 3) return;
    if ((unsigned)self->f2e8 + 500 >= context_80165254()->now) return;
    if (!self->f2cc && (int)self->flags >= 0) return;
    if (settings_804b1788->bits & 0x800000) { exit_80150c3c(self); return; }
    if (self->stop && (self->state == 2 || self->state == 4)) self->state = 5;
    switch (self->state) {
    case 2: {
        Vec v = *speed_80178ec4(speedA_804afdd8);
        self->vel.x = sin_802e88ac(self->yaw) * v.x;
        self->vel.y = v.y;
        self->vel.z = cos_802e86d4(self->yaw) * v.z;
        setAnim_801492ec(self, 3);
        break;
    }
    case 3: {
        Vec v = *speed_80178ec4(speedB_804afddc);
        self->vel.x = sin_802e88ac(self->yaw) * v.x;
        self->vel.y = v.y;
        self->vel.z = cos_802e86d4(self->yaw) * v.z;
        setAnim_801492ec(self, 5);
        break;
    }
    case 4: {
        Vec d(input_8014c260(self).x, 0.0f, -input_8014c260(self).z);
        float angle = 3.1415927f;
        if (d.lenSq() > 0.0f) {
            Matrix inv, m;
            float a = sin_802e88ac(self->yaw);
            Vec s(a, 0.0f, cos_802e86d4(self->yaw));
            view_8014be44(self, &m);
            invert_801f6c2c(&inv, &m);
            Vec q;
            inv.rotate(q, d);
            s.unit();
            q.y = 0.0f;
            q.unit();
            angle = acos_802e79e0(clamp(s.dot(q), -1.0f, 1.0f));
        }
        if (angle > 1.5707964f) {
            Vec v = *speed_80178ec4(speedD_804afde4);
            self->vel.x = sin_802e88ac(self->yaw) * v.x;
            self->vel.y = v.y;
            self->vel.z = cos_802e86d4(self->yaw) * v.z;
            setAnim_801492ec(self, 6);
        } else {
            Vec v = *speed_80178ec4(speedD_804afde4);
            self->vel.x = sin_802e88ac(self->yaw) * -v.x;
            self->vel.y = v.y;
            self->vel.z = cos_802e86d4(self->yaw) * -v.z;
            setAnim_801492ec(self, 36);
        }
        break;
    }
    case 5: {
        Vec v = *speed_80178ec4(speedC_804afde0);
        self->vel.x = sin_802e88ac(self->yaw) * v.x;
        self->vel.y = v.y;
        self->vel.z = cos_802e86d4(self->yaw) * v.z;
        setAnim_801492ec(self, 4);
        break;
    }
    }
    self->state = 6;
    self->flags &= 0x7fffffff;
    self->f2e8 = 0;
    self->f2cc = 0;
}


