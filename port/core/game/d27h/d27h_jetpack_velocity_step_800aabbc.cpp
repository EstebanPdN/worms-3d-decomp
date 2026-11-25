#include "w3d_ptr.h"
#line 1 "d27h_jetpack_velocity_step_800aabbc.cpp"
// GWMP8P rev0 0x800aabbc. Jetpack velocity step. Names are inferred. Takes
// the current velocity, time and input, builds a thrust force rotated by
// pitch and yaw matrices when thrusting, scales it by the fuel limit or a
// sine fade, applies drag and adds the force.
extern "C" float sqrt_802e82c0(float);
extern "C" float sin_802e88ac(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
struct Pos { float x, y, z; };
struct Axis { float x, y, z; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &A(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x + P().x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y + P().y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z + P().z;
    }
};
extern "C" void construct_801f7538(Ptr32<Transform>, float, float, float, float);
extern "C" void multiply_801f740c(Ptr32<Transform>, Ptr32<const Transform>, Ptr32<const Transform>);
struct Setting;
extern "C" float get_float_80178df0(Ptr32<Setting>);
extern "C" Ptr32<Setting> as_float_80342a74(Ptr32<Setting>);
struct Jet {
    char u0[72];
    int active;      // +72
    int thrusting;   // +76
    char u80[12];
    float yaw;       // +92
    char u96[4];
    Vec velocity;    // +100
    char u112[12];
    Ptr32<Setting> over;   // +124
    char u128[16];
    int firing;      // +144
    char u148[12];
    float boost;     // +160
    char u164[12];
    Ptr32<Setting> f176;   // +176
    char u180[4];
    Ptr32<Setting> f184;   // +184
    char u188[4];
    Ptr32<Setting> f192;   // +192
    char u196[8];
    Ptr32<Setting> f204;   // +204
    char u208[20];
    Ptr32<Setting> dragA;  // +228
    Ptr32<Setting> dragB;  // +232
};
extern "C" void pre_800abd30(Ptr32<Jet>, const Vec &, const Vec &);
extern "C" void limit_800ac03c(Ptr32<Jet>);
extern "C" void limit_800abfe0(Ptr32<Jet>);
extern Vec g_gravity_8045e788[];
extern "C" Vec d27h_jetpack_velocity_step_800aabbc(Ptr32<Jet> self, const Vec &velocity, float time, const Vec &input) {
    self->velocity = velocity;
    pre_800abd30(self, velocity, input);
    float lift = get_float_80178df0(self->f192);
    float zero = 0.0f;
    Vec up(zero, lift + lift, zero);
    Vec force(g_gravity_8045e788[0]);
    self->firing = 0;
    int idle = 1;
    if (self->active) {
        if (self->thrusting || input.len() > zero) {
            self->firing = 1;
            Transform a, b, c;
            idle = 0;
            construct_801f7538(&a, 1.0f, zero, zero, get_float_80178df0(self->f184));
            construct_801f7538(&b, zero, 1.0f, zero, self->yaw);
            multiply_801f740c(&c, &a, &b);
            c.apply(force, up);
        } else {
            force = up;
        }
        float left = time - get_float_80178df0(self->f176);
        float lim = get_float_80178df0(as_float_80342a74(self->over));
        if (left > lim) {
            if (self->velocity.y > 0.0f) {
                force.y = 0.0f;
            } else {
                force.y *= get_float_80178df0(self->f204);
            }
            force.x *= get_float_80178df0(self->f204);
            force.z *= get_float_80178df0(self->f204);
        } else {
            float s = sin_802e88ac((1.0f - left / lim) * 1.5707964f);
            force.x *= s;
            force.y *= s;
            force.z *= s;
            if (self->velocity.y < -0.25f) limit_800ac03c(self);
            else limit_800abfe0(self);
            force.y += force.y * self->boost;
        }
    } else {
        limit_800abfe0(self);
    }
    if (idle) {
        self->velocity.x *= get_float_80178df0(self->dragB);
        self->velocity.z *= get_float_80178df0(self->dragB);
    } else {
        self->velocity.x *= get_float_80178df0(self->dragA);
        self->velocity.z *= get_float_80178df0(self->dragA);
    }
    self->velocity += force;
    return self->velocity;
}


