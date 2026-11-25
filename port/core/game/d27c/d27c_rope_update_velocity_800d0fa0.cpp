#include "w3d_ptr.h"
#line 1 "d27c_rope_update_velocity_800d0fa0.cpp"
// d27c: 0x800d0fa0. Sets a velocity from the offset to a computed target divided by 20 and scaled by a setting, then posts it as a message. Names are inferred.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
inline Vec3 scaled(Vec3 a, float s) { return a * s; }
struct Msg;
struct Self { char u0[64]; Vec3 vel; Vec3 pos; char u88[160]; Ptr32<void> h248; char u252[24]; int key; };
extern Ptr32<void> heap_804b1754;
extern int id_804ae958;
extern "C" Vec3 calc_800d0108(Ptr32<Self>, const Vec3 &, Ptr32<int>);
extern "C" float value_80178df0(Ptr32<void>);
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" short msg_id_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<void> init_80126000(Ptr32<void>, unsigned short, Ptr32<const Vec3>);
extern "C" int post_8016239c(Ptr32<void>);
extern "C" void d27c_rope_update_velocity_800d0fa0(Ptr32<Self> self) {
    Vec3 p(self->pos);
    Vec3 t = calc_800d0108(self, self->pos, &self->key);
        Vec3 q = t - p;
    const float one = 1.0f;
    float dt = 20.0f;
    self->vel = scaled(q, one / dt) * value_80178df0(self->h248);
    Ptr32<void> n = alloc_801613f0(heap_804b1754, 20);
    post_8016239c(init_80126000(n, msg_id_8015f5a0(&id_804ae958, 1), &self->vel));
}


