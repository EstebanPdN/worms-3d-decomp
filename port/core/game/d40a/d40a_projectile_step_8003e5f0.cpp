#include "w3d_ptr.h"
#line 1 "d40a_projectile_step_8003e5f0.cpp"
// GWMP8P rev0 0x8003e5f0. One physics step of a bouncing projectile: updates
// its acceleration and bounds, limits the step when an overlapping shape
// faces the velocity at more than a right angle, traces the sphere bottom
// along the velocity, and on a trace hit moves to the hit point and posts a
// collision message, or on a shape hit advances by the frame time and plays
// the item's effect; then normalises the surface normal and bounces, applies
// a planar impulse or comes to rest. Names and the meaning of the effect
// slot are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec operator*(float f) const { Vec r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline const float &Min(const float &a, const float &b) { return a < b ? a : b; }
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
inline const float &Clamp(const float &v, const float &lo, const float &hi) { return Max(Min(v, hi), lo); }
struct ItemInfo { char unknown00[20]; int effect; int sound; };
struct Shape { int unknown00[2]; };
struct Projectile {
    Ptr32<Ptr32<void>> table;
    char unknown04[24];
    Vec pos;
    Vec vel;
    Vec accel;
    float radius;
    Shape shape;
    int colour_a;
    int colour_b;
    int hit_flag;
    int moving;
    int miss_flag;
    Ptr32<void> speed_value;
    Ptr32<void> scale_value;
    char unknown68[8];
    int owner;
};
typedef Ptr32<void (Ptr32<Projectile>, int, int)> Effect;
struct Message { unsigned short id; Ptr32<void> table; };
extern "C" float w3d_value_80178df0(Ptr32<void>);
extern "C" void set_bounds_80126278(Ptr32<Shape>, Ptr32<Vec>, float);
extern "C" int nearest_sphere_801263fc(Ptr32<Shape>, Ptr32<Vec>, int, int);
extern "C" Ptr32<Vec> hit_delta_800418ac();
extern "C" void w3d_trace_800b0824(Ptr32<Vec>, Ptr32<Vec>, Ptr32<void>, int, int);
extern "C" void compute_800bd920();
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" int message_id_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" Ptr32<ItemInfo> item_8003f240(unsigned short);
extern "C" void impulse_8003ebdc(Ptr32<Projectile>, Ptr32<Vec>);
extern "C" void reflect_8003ee4c(Ptr32<Projectile>, Ptr32<Vec>);
extern Ptr32<void> w3d_arena_804b1754;
extern int w3d_message_804ad1ac;
extern Ptr32<void> w3d_message_table_8040db38[];
extern int g_steps_804b1790;
extern int g_hit_804b1764;
extern int traceReady_804b1784;
extern float g_dt_804b17a4;
extern int g_colour_804b17a8, g_colour_804b17ac;
extern unsigned short g_item_804aa95e;
extern Vec g_point_8043ae20[];
extern Vec g_normal_8043ae38[];
extern Vec zero_8045e788[];
extern "C" void w3d_d40a_projectile_step_8003e5f0(Ptr32<Projectile> self)
{
    int limit = 21;
    Vec n;
    self->accel.y = w3d_value_80178df0(self->speed_value) * w3d_value_80178df0(self->scale_value);
    set_bounds_80126278(&self->shape, &self->pos, self->radius);
    if (nearest_sphere_801263fc(&self->shape, &self->vel, 20, self->owner) != 0xffff) {
        n = *hit_delta_800418ac();
        n.normalize();
        float angle = 0.0f;
        Vec v = self->vel;
        if (v.lenSq() != 0.0f) {
            v.normalize();
            float d = v.dot(n);
            d = Clamp(d, -1.0f, 1.0f);
            angle = acos_802e79e0(d);
        }
        if (angle > 1.5707964f) limit = g_steps_804b1790;
    }
    Vec off = zero_8045e788[0];
    off.y = -self->radius;
    Vec p = self->pos + off;
    w3d_trace_800b0824(&p, &self->vel, &self->accel, 20, 1);
    int hit = g_hit_804b1764;
    if (hit < limit) {
        p = g_point_8043ae20[0];
        self->pos = p - off;
        Ptr32<Message> m = (Ptr32<Message>)arena_801613f0(w3d_arena_804b1754, 8);
        m->id = message_id_8015f5a0(&w3d_message_804ad1ac, 1);
        m->table = w3d_message_table_8040db38;
        post_8016239c(m);
        if (!traceReady_804b1784) compute_800bd920();
        n = g_normal_8043ae38[0];
    } else {
        if (limit > hit || limit == 21) return;
        n = *hit_delta_800418ac();
        Vec d = self->vel * g_dt_804b17a4;
        self->pos += d;
        Ptr32<Ptr32<void>> t = self->table;
        int a = item_8003f240(g_item_804aa95e)->effect;
        ((Effect)t[10])(self, a, item_8003f240(g_item_804aa95e)->sound);
    }
    n.normalize();
    if (n.y < 0.7072f) {
        if (self->vel.lenSq() > 0.0001f) {
            reflect_8003ee4c(self, &n);
            return;
        }
        impulse_8003ebdc(self, &n);
        return;
    }
    if (self->vel.lenSq() > 0.0001f) {
        reflect_8003ee4c(self, &n);
        return;
    }
    if ((unsigned)hit <= 20) {
        self->moving = 1;
        self->colour_a = g_colour_804b17a8;
        self->colour_b = g_colour_804b17ac;
    } else {
        self->miss_flag = 1;
    }
    self->vel = zero_8045e788[0];
    self->hit_flag = 0;
}


