#include "w3d_ptr.h"
#line 1 "d27d_worm_walk_transition_80150c3c.cpp"
// GWMP8P rev0 0x80150c3c. Leave a worm's walking state: read the input
// direction twice into a flat vector; with no input pick the idle or stop
// speed table by state, otherwise compare the facing direction with the
// input rotated by the inverse view matrix and pick the forward or turn
// speed table for states 2 and 4. Set the velocity from the yaw and the
// table and play the animation, then clear the flags and set state 6. Names
// are inferred.
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
    char u0[576]; float yaw; char u244[96]; Vec vel; char u2b0[28]; int f2cc; char u2d0[24]; int f2e8; char u2ec[12]; int state;
};
extern "C" void setAnim_801492ec(Ptr32<Worm>, int);
extern Ptr32<void> speedA_804afdd8;
extern Ptr32<void> speedB_804afddc;
extern Ptr32<void> speedC_804afde0;
extern Ptr32<void> speedD_804afde4;
extern "C" void d27d_worm_walk_transition_80150c3c(Ptr32<Worm> self) {
    Vec d(input_8014c260(self).x, 0.0f, -input_8014c260(self).z);
    if (d.lenSq() == 0.0f) {
        if (self->state == 2) {
            Vec v = *speed_80178ec4(speedC_804afde0);
            self->vel.x = sin_802e88ac(self->yaw) * v.x;
            self->vel.y = v.y;
            self->vel.z = cos_802e86d4(self->yaw) * v.z;
            setAnim_801492ec(self, 4);
        } else {
            Vec v = *speed_80178ec4(speedD_804afde4);
            self->vel.x = 0.0f;
            self->vel.y = v.y;
            self->vel.z = 0.0f;
            setAnim_801492ec(self, 6);
        }
        self->state = 6;
        self->f2e8 = 0;
        self->f2cc = 0;
        return;
    } else {
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
        float angle = acos_802e79e0(clamp(s.dot(q), -1.0f, 1.0f));
        if (self->state == 2) {
            if (angle <= 1.5707964f) {
                Vec v = *speed_80178ec4(speedA_804afdd8);
                self->vel.x = sin_802e88ac(self->yaw) * v.x;
                self->vel.y = v.y;
                self->vel.z = cos_802e86d4(self->yaw) * v.z;
                setAnim_801492ec(self, 3);
            } else {
                Vec v = *speed_80178ec4(speedB_804afddc);
                self->vel.x = sin_802e88ac(self->yaw) * v.x;
                self->vel.y = v.y;
                self->vel.z = cos_802e86d4(self->yaw) * v.z;
                setAnim_801492ec(self, 5);
            }
        } else if (self->state == 4) {
            if (angle <= 1.5707964f) {
                Vec v = *speed_80178ec4(speedD_804afde4);
                self->vel.x = sin_802e88ac(self->yaw) * -v.x;
                self->vel.y = v.y;
                self->vel.z = cos_802e86d4(self->yaw) * -v.z;
                setAnim_801492ec(self, 36);
            } else {
                Vec v = *speed_80178ec4(speedD_804afde4);
                self->vel.x = sin_802e88ac(self->yaw) * v.x;
                self->vel.y = v.y;
                self->vel.z = cos_802e86d4(self->yaw) * v.z;
                setAnim_801492ec(self, 6);
            }
        }
    }
    self->state = 6;
    self->f2e8 = 0;
    self->f2cc = 0;
}


