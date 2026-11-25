#include "w3d_ptr.h"
#line 1 "d28b_homing_update_8009f86c.cpp"
/* Homing projectile steering (0x8009f86c): stops when the destination at +308 is within the reach
 * at +552 of the weapon. Otherwise sweeps up and down by rate over frame time (slot +64), then along
 * the velocity by reach over frame time; when that sweep hits, adds lift (or subtracts it when only
 * the up sweep hit), subtracts the pull toward the point 0x8043ae20, and integrates the velocity at
 * +48. Always renormalizes the velocity and clamps its length to the limit at +564. Field names are
 * inferred from the original instructions; the class is a partial view with 4-byte virtual table
 * entries. Owns the conversion double and the 1.0 literal at 0x80380790. */
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Scale(float f) { x *= f; y *= f; z *= f; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { Scale(1.0f / len()); }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator/(const Vec &a, float k) { float f = 1.0f / k; Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline void operator-=(Vec &a, const Vec &b) { a.x -= b.x; a.y -= b.y; a.z -= b.z; }
inline const float &Min(const float &a, const float &b) { return b < a ? b : a; }
extern const Vec lbl_8045e788[];
extern const Vec lbl_8043ae20[];
extern unsigned lbl_804b1944;
struct Weapon { char unknown00[544]; float pull; float lift; float reach; float rate; char unknown560[4]; float limit; const float &Limit() const { return limit; } };
extern "C" Ptr32<void> w3d_cast_80341584(Ptr32<void>);
extern "C" Ptr32<Weapon> w3d_weapon_801797b4(Ptr32<void>);
struct Base0 { void w3d_r_v0() __asm__(W3D_SYM("_ZN5Base02v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN5Base02v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN5Base02v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN5Base02v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN5Base02v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN5Base02v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN5Base02v6Ev"));
    void w3d_r_v7() __asm__(W3D_SYM("_ZN5Base02v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN5Base02v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN5Base02v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN5Base03v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN5Base03v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN5Base03v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN5Base03v13Ev"));
    int w3d_r_Sweep(Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<Vec>, Ptr32<Vec>) __asm__(W3D_SYM("_ZN5Base05SweepEPK3VecS2_PS0_S3_"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base0, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Sweep(Ptr32<const Vec> w3d_a0, Ptr32<const Vec> w3d_a1, Ptr32<Vec> w3d_a2, Ptr32<Vec> w3d_a3) { return ((int (*)(w3d_u32, Ptr32<const Vec>, Ptr32<const Vec>, Ptr32<Vec>, Ptr32<Vec>))w3d::vfn(this->w3d_vptr_Base0, 16))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2, w3d_a3); }  Ptr32<void> w3d_vptr_Base0; };
struct Bullet : Base0 {
    char unknown04[32] __attribute__((aligned(__alignof__(Base0)))); Vec pos; Vec vel; char unknown60[132]; Ptr32<void> weapon; char unknown196[112]; Vec dest;
};
extern "C" void w3d_d28b_homing_update_8009f86c(Ptr32<Bullet> self) {
    Ptr32<Weapon> w = w3d_weapon_801797b4(w3d_cast_80341584(self->weapon));
    Vec d = self->dest - self->pos;
    if (d.len() < w->reach) return;
    Vec in;
    Vec out;
    float dt = lbl_804b1944;
    Vec probe = lbl_8045e788[0];
    probe.y = w->rate / dt;
    int up = self->Sweep(&self->pos, &probe, &out, &in);
    probe.y = -probe.y;
    int down = self->Sweep(&self->pos, &probe, &out, &in);
    Vec step;
    Vec n(self->vel);
    n.normalize();
    step = n * w->reach / dt;
    if (self->Sweep(&self->pos, &step, &out, &in)) {
        Vec acc(lbl_8045e788[0]);
        if (up == 0 && down == 0) acc.y += w->lift;
        else {
            if (up) acc.y -= w->lift;
            if (down) { float k = w->lift; acc.y += k; }
        }
        Vec cam(lbl_8043ae20[0]);
        Vec to = cam - self->pos;
        to.normalize();
        acc -= to * w->pull;
        self->vel = self->vel + acc * lbl_804b1944;
    }
    n = self->vel;
    n.normalize();
    float speed = n.len();
    float limit = w->Limit();
    speed = Min(speed, limit);
    self->vel = n * speed;
}


