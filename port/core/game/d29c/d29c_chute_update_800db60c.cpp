#include "w3d_ptr.h"
#line 1 "d29c_chute_update_800db60c.cpp"
// d29c: 0x800db60c. Parachute update: stores position and velocity, tilts the wind-relative drag by the angle between the rotated forward axis and the wind, steps the motion, then integrates (20 ms step) or, when the clock is too short, resets and posts a message. Names are inferred; classes are partial views.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct V {
    float x, y, z;
    V() {}
    V(float a, float b, float c) { x = a; y = b; z = c; }
    V(const V &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    float dot(const V &o) const { return x * o.x + y * o.y + z * o.z; }
    V operator*(float s) const { V r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    void operator+=(const V &o) { x += o.x; y += o.y; z += o.z; }
};
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &R(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(V &o, const V &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
struct Chute {
    char u0[68]; int a68; int a72; char u76[12]; float angle; char u92[4];
    V pos; V vel; V wind; char u132[32]; int value;
    V advance(const V &a, float dt) {
        V d;
        V &p = pos; V &v = vel;
        V c = a * (dt * 0.5f * dt);
        V m;
        m.x = v.x * dt + c.x; m.y = v.y * dt + c.y; m.z = v.z * dt + c.z;
        p += m;
        d.x = a.x * dt; d.y = a.y * dt; d.z = a.z * dt;
        return d;
    }
};
extern "C" void construct_801f7538(Ptr32<Transform>, float, float, float, float);
extern "C" void step_800b0824(Ptr32<V>, Ptr32<V>, Ptr32<V>, int, int);
extern unsigned int time_804b1764;
extern Ptr32<void> arena_804b1754;
extern int msgid_804aebec;
extern V zero_8043ae20[];
extern "C" void motion_800dc244(Ptr32<Chute>, V &, V &);
extern "C" V heading_800dbaf4(Ptr32<Chute>);
extern "C" void roll_800dbc60(Ptr32<Chute>, float);
extern "C" void hide_800dc20c(Ptr32<Chute>);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<void> int_init_800a82f0(Ptr32<void>, unsigned short, int);
extern "C" int post_8016239c(Ptr32<void>);
template <class T> inline const T &mn(const T &a, const T &b) { return b < a ? b : a; }
template <class T> inline const T &mx(const T &a, const T &b) { return a < b ? b : a; }
extern "C" void d29c_chute_update_800db60c(Ptr32<Chute> self, V &pos, V &vel) {
    struct W { int a, b, c; }; *(W *)&self->pos = *(W *)&pos;
    *(Ptr32<W>)&self->vel = *(Ptr32<W>)&vel;
    V h(self->wind.x, 0.0f, self->wind.z);
    V f(0.0f, 0.0f, 1.0f);
    Transform t;
    construct_801f7538(&t, 0.0f, 1.0f, 0.0f, self->angle);
    V r;
    t.apply(r, f);
    float angle = 0.0f;
    if (h.lenSq() > 0.0f) {
        r.normalize();
        h.normalize();
        float d = h.dot(r);
        d = mn(d, 1.0f);
        d = mx(d, 0.0f);
        angle = acos_802e79e0(d);
    }
    float k = 1.0f - angle / 3.1415927f * 0.8f;
    V a;
    a.x = k * self->wind.x; a.y = self->wind.y; a.z = k * self->wind.z;
    step_800b0824(&self->pos, &self->vel, &a, 20, 1);
    if (time_804b1764 > 20) {
        motion_800dc244(self, pos, self->vel);
        float dt = 20.0f;
        V &v = self->vel;
        v += self->advance(a, dt);
        v += heading_800dbaf4(self);
        self->vel.y += self->vel.y * -0.2f;
        self->vel.x += self->vel.x * -0.02f;
        self->vel.z += self->vel.z * -0.02f;
        roll_800dbc60(self, angle);
    } else {
        *(Ptr32<W>)&self->pos = *(Ptr32<W>)&zero_8043ae20[0];
        { V &v = self->vel; v.x = 0.0f; v.y = 0.0f; v.z = 0.0f; }
        self->a68 = 1;
        self->a72 = 0;
        hide_800dc20c(self);
        post_8016239c(int_init_800a82f0(arena_801613f0(arena_804b1754, 12), msg_id_8015f5a0(&msgid_804aebec, 1), self->value));
    }
    *(Ptr32<W>)&pos = *(Ptr32<W>)&self->pos;
    *(Ptr32<W>)&vel = *(Ptr32<W>)&self->vel;
}


