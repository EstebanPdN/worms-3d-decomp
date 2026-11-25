#include "w3d_ptr.h"
#line 1 "d25g_body_bounce_8004ce58.cpp"
/* Worms 3D GameCube PAL 0x8004ce58. Bounce response: marks the body bounced, flips and damps its velocity by 0.4, and when the speed falls under 0.02 stops it, settles it at the rest position raised by +64 if it was rolling, and releases the trail; otherwise clears the moving flags and, when audio exists, moves the sound and sets its volume to min((speed-0.02)/0.02, 1) before updating it. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec3 { float x, y, z; };
struct Object { struct V { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; Ptr32<void (Ptr32<Object>)> update; Ptr32<void> u24[7]; Ptr32<void (Ptr32<Object>, int, float)> set_float; Ptr32<void (Ptr32<Object>, int, Ptr32<const Vec3>)> set_vector; }; Ptr32<struct V> vtable; };
struct Game { char u[108]; Ptr32<void> audio; };
struct Self {
    char u0[40];
    Vec3 position;
    Vec3 velocity;
    float lift;
    char u68[32];
    int rolling;
    int moving;
    char u108[64];
    int bounced;
    char u176[56];
    Ptr32<Object> sound;
    char u236[8];
    Ptr32<Object> trail;
};
extern Ptr32<Game> game_804b1788;
extern Vec3 zero_8045e788[];
extern Vec3 rest_8043ae20[];
extern "C" float sqrt_802e82c0(float);
extern "C" void settle_8004b8f4(Ptr32<Self>);
inline const float &lesser(const float &a, const float &b) { return b < a ? b : a; }
extern "C" void w3d_d25g_body_bounce_8004ce58(Ptr32<Self> self)
{
    float zero = 0.0f;
    self->bounced = 1;
    Ptr32<Vec3> v = &self->velocity;
    self->velocity.y = zero - self->velocity.y;
    const float k = 0.4f;
    self->velocity.x *= k;
    v->y *= k;
    v->z *= k;
    float len = sqrt_802e82c0(self->velocity.x * self->velocity.x + v->y * v->y + v->z * v->z);
    float slow = 0.02f;
    if (len < slow) {
        self->velocity = zero_8045e788[0];
        if (self->rolling) {
            settle_8004b8f4(self);
            self->position = rest_8043ae20[0];
            self->velocity.x = zero;
            self->position.y += self->lift;
            v->y = zero;
            v->z = zero;
        }
        if (self->trail) self->trail->vtable->release(self->trail);
        self->trail = 0;
    } else {
        self->rolling = 0;
        self->moving = 0;
        if (game_804b1788->audio) {
            self->sound->vtable->set_vector(self->sound, 3, &self->position);
            float t = (len - slow) / slow;
            float one = 1.0f;
            t = lesser(t, one);
            Ptr32<Object> s = self->sound;
            s->vtable->set_float(s, 1, t);
            self->sound->vtable->update(self->sound);
        }
    }
}


