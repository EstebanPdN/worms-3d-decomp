#include "w3d_ptr.h"
#line 1 "d27a_strike_camera_update_8002c840.cpp"
// GWMP8P rev0 0x8002c840. Moves the camera towards the point and heading of
// the AI strike properties. Names are inferred from the original
// instructions.
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" float atan2_802e7e5c(float, float);
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    float LengthSq() const { return x * x + y * y + z * z; }
    float Length() const { return sqrt_802e82c0(LengthSq()); }
    Vec &operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    void Normalize() { float k = 1.0f / Length(); x *= k; y *= k; z *= k; }
    float &operator[](int i) { return (&x)[i]; }
    const float &operator[](int i) const { return (&x)[i]; }
};
extern const char g_target_803728b8[], g_direction_803728d0[], g_up_803728e4[];
struct Message;
struct Arena;
extern Ptr32<Arena> g_arena_804b1754;
extern "C" Ptr32<Message> tsonnet_b33_arena_801613f0(Ptr32<Arena>, int);
extern "C" Ptr32<Message> w3d_auto_80131b50(Ptr32<Message>, int);
extern "C" int w3d_message_post_current(Ptr32<Message>);
extern "C" int w3d_auto_800fc2f0(Ptr32<Ptr32<const char>>, Vec &);
struct Camera {
    int unknown00;
    int unknown04, unknown08, unknown0c;
    Vec focus;         /* +16 */
    char unknown1c[48];
    int state;         /* +76 */
    float yaw;         /* +80 */
    float pitch;       /* +84 */
    float ax;          /* +88 */
    float height;      /* +92 */
    float az;          /* +96 */
    Vec b;             /* +100 */
    char unknown70[32];
    int k_pitch;       /* +144 */
    int unknown94;
    int k_walk;        /* +152 */
};
inline bool Close(const Vec &a, const Vec &b, float tol)
{
    for (int i = 0; i < 3; i++) {
        float d = a[i] - b[i];
        if (__builtin_fabsf(d) > tol) return false;
    }
    return true;
}
extern "C" void w3d_d27a_strike_camera_update_8002c840(Ptr32<Camera> self, float dt)
{
    if (self->state == 1) return;
    Vec target, dir, up;
    const float zero = 0.0f;
    Ptr32<const char> n1 = g_target_803728b8;
    w3d_auto_800fc2f0(&n1, target);
    Ptr32<const char> n2 = g_direction_803728d0;
    w3d_auto_800fc2f0(&n2, dir);
    Ptr32<const char> n3 = g_up_803728e4;
    w3d_auto_800fc2f0(&n3, up);
    Vec pos; pos.x = self->ax; pos.z = self->az; pos.y = target.y = zero;
    const float tol = 0.2f;
    float diff = atan2_802e7e5c(-dir.x, dir.z) - self->pitch;
    while (diff < -3.14159274f) diff += 6.28318548f;
    while (diff > 3.14159274f) diff -= 6.28318548f;
    float mag = __builtin_fabsf(diff);
    bool same = Close(target, self->focus, tol);
    if (same == 1) {
        if (mag <= 0.0174532924f) {
            if (self->state == 0) {
                Vec a(self->b);
                Vec c(target);
                w3d_message_post_current(w3d_auto_80131b50(tsonnet_b33_arena_801613f0(g_arena_804b1754, 12), 13));
                self->state = same;
            }
            return;
        }
    } else {
        float step = w3d_auto_80178df0((Ptr32<void>)w3d::G(self->k_walk)) * dt;
        Vec d = target - pos;
        if (d.Length() > step) { d.Normalize(); d *= step; }
        self->ax += d.x;
        self->az += d.z;
        self->b.x += d.x;
        self->b.z += d.z;
    }
    if (mag > 0.0174532924f) {
        if (diff > 0.0f) self->pitch += w3d_auto_80178df0((Ptr32<void>)w3d::G(self->k_pitch)) * dt;
        else self->pitch -= w3d_auto_80178df0((Ptr32<void>)w3d::G(self->k_pitch)) * dt;
    }
}


