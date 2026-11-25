#include "w3d_ptr.h"
#line 1 "d33a_airstrike_aim_trace_80032c84.cpp"
// GWMP8P rev0 0x80032c84. Traces the airstrike aim ray from the start along
// the look vector, up to a range or a limit derived from the radius and
// anchor; unless fixed, also steps along the ray against the sphere list,
// keeps the nearer hit and rejects hits too far from the start, then writes
// the direction, target and up vector, and always writes the hit flag. Names
// are inferred from the original instructions.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Up(float u) { x = 0.0f; y = u; z = 0.0f; }
    float Len2() const { return x * x + y * y + z * z; }
    float Len() const { return sqrt_802e82c0(Len2()); }
    void Normalize() { float m = 1.0f / Len(); x *= m; y *= m; z *= m; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline float Dist(const Vec &a, const Vec &b) { float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z; return sqrt_802e82c0(dx * dx + dy * dy + dz * dz); }
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
struct Strike {
    char pad0[328];
    int world;
    Vec start;
    Vec end;
    Vec up;
    char pad2[756 - 368];
    Ptr32<void> radius; Ptr32<void> anchor; Ptr32<void> flag_out; Ptr32<void> dir_out; Ptr32<void> target_out; Ptr32<void> allow; Ptr32<void> range;
    char pad3[864 - 784];
    int spheres;
};
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" Ptr32<Vec> w3d_auto_80178ec4(Ptr32<void>);
extern "C" int w3d_auto_80178d1c(Ptr32<void>);
extern "C" int d26d_camera_ray_hit_8015a46c(Ptr32<int>, Vec, Vec, Ptr32<Vec>, Ptr32<Vec>, int);
extern "C" void w3d_handle_member_query_801262c0(Ptr32<int>, Ptr32<const Vec>);
extern "C" int w3d_turns_get_active_actor(Ptr32<void>);
extern "C" int d19c_nearest_sphere_801263fc(Ptr32<int>, Ptr32<const Vec>, int, Ptr32<void>);
extern "C" int w3d_s20_set_vector_if_changed_80178fa4(Ptr32<void>, Ptr32<const Vec>);
extern "C" int s8_property_read_800fc5dc(Ptr32<Ptr32<const char>>, Ptr32<Vec>);
extern "C" int s9_update_value_80178d28(Ptr32<void>, Ptr32<const unsigned int>);
extern "C" int s19_active_team_value_80020834(Ptr32<void>);
extern Ptr32<void> g_turns_804ab400;
extern unsigned int g_spacing_804b1790;
extern Ptr32<void> g_team_804b1760;
extern const char s_up_vector_803732d4[];
inline void Put(Ptr32<void> o, const unsigned &v) { s9_update_value_80178d28(o, &v); }
inline void Assign(Vec &a, const Vec &c) { a = c; }
extern "C" void w3d_d33a_airstrike_aim_trace_80032c84(Ptr32<Strike> self, int fixed, int upward)
{
    Vec dir = self->end - self->start;
    Vec target(0.0f, 0.0f, 0.0f);
    float radius = 0.0f;
    Vec normal;
    Vec ray;
    float reach;
    int hit = 0;
    if (fixed) {
        hit = 1;
        reach = w3d_auto_80178df0(self->range);
    } else {
        radius = w3d_auto_80178df0(self->radius);
        Vec anchor(*w3d_auto_80178ec4(self->anchor));
        float d = Dist(self->start, anchor);
        reach = Max(d, radius) + radius;
    }
    ray = dir;
    float k = 1.0f / ray.Len();
    ray.x = ray.x * k * reach;
    ray.y = ray.y * k * reach;
    ray.z = ray.z * k * reach;
    hit = d26d_camera_ray_hit_8015a46c(&self->world, self->start, ray, &target, &normal, hit);
    if (upward && normal.y < 0.0f) hit = 0;
    if (!fixed) {
        Vec eye(self->start);
        w3d_handle_member_query_801262c0(&self->spheres, &eye);
        Ptr32<void> actor = (Ptr32<void>)w3d::G(w3d_turns_get_active_actor(g_turns_804ab400));
        const float steps = 1000.0f;
        float one = 1.0f;
        Vec v = ray * (one / steps);
        if (d19c_nearest_sphere_801263fc(&self->spheres, &v, 1000, actor) != 0xffff) {
            Vec p = eye + v * (float)g_spacing_804b1790;
            if (!hit || Dist(p, eye) < Dist(target, eye)) {
                if (w3d_auto_80178d1c(self->allow)) {
                    hit = 1;
                    target = p;
                    Vec n;
                    Vec &r = n;
                    r.x = 0.0f; r.y = one; r.z = 0.0f;
                    normal = n;
                } else
                    hit = 0;
            }
        }
        dir.Normalize();
        Vec a;
        a = self->start;
        a.y = 0.0f;
        Vec b;
        b = target;
        b.y = 0.0f;
        Vec gap = a - b;
        if (gap.Len() > radius * 8.0f) hit = 0;
        w3d_s20_set_vector_if_changed_80178fa4(self->dir_out, &dir);
        w3d_s20_set_vector_if_changed_80178fa4(self->target_out, &target);
        Ptr32<const char> name = s_up_vector_803732d4;
        s8_property_read_800fc5dc(&name, &self->up);
    }
    Put(self->flag_out, hit);
    if (s19_active_team_value_80020834(g_team_804b1760)) {
        Put(self->flag_out, 1);
    }
}


