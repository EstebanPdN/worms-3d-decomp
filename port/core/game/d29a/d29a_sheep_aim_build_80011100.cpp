#include "w3d_ptr.h"
#line 1 "d29a_sheep_aim_build_80011100.cpp"
// GWMP8P rev0 0x80011100. Aims a plan's sheep shot at the centre point:
// rejects near targets, then copies the shared motion, sets the velocity to
// the flat direction scaled by the weapon speed and requeues. Names are
// inferred from the original instructions.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec(const Vec &a, const Vec &b, int) { x = a.x - b.x; y = a.y - b.y; z = a.z - b.z; }
    Vec operator-(const Vec &o) const { return Vec(*this, o, 0); }
    float Length() const { return sqrt_802e82c0(x * x + y * y + z * z); }
    void Normalize() { float f = 1.0f / Length(); x *= f; y *= f; z *= f; }
    void operator*=(float f) { x *= f; y *= f; z *= f; }
};
inline Vec Flat(const Vec &v) { return Vec(v.x, 0.0f, v.z); }
struct MotionBase { int unknown[9]; void w3d_r_dispatch() __asm__(W3D_SYM("_ZN10MotionBase8dispatchEv"));  __attribute__((always_inline)) inline void dispatch() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_MotionBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_MotionBase; };
struct Motion : MotionBase { void w3d_r_dispatch() __asm__(W3D_SYM("_ZN6Motion8dispatchEv")); int rest[36] __attribute__((aligned(__alignof__(MotionBase)))); Motion();  __attribute__((always_inline)) inline void dispatch() { this->MotionBase::dispatch(); } };
struct Weapon { char unknown[576]; float speed; };
struct Plan {
    char unknown00[24];
    Vec position;   /* +24 */
    Vec velocity;   /* +36 */
    char unknown30[28];
    int object;     /* +76 */
    char unknown50[8];
    Vec stored;     /* +88 */
    int unknown64;
    Motion motion;  /* +104 */
};
extern Vec g_centre_8041d3a0;
extern Motion g_motion_8041e780;
extern char s_weapon_803697a4[];
extern "C" void cc27a_planner_set_gravity_8001aa48(Ptr32<const Vec>);
extern "C" int fn_8001aaf8(Ptr32<const Vec>, float, float);
extern "C" int w3d_auto_800fc330(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<Weapon>>);
extern "C" int cc23a_planner_requeue_offset_8000b6bc(Ptr32<Plan>, int);
extern "C" int w3d_d29a_sheep_aim_build_80011100(Ptr32<Plan> self)
{
    if (self->object) g_centre_8041d3a0 = self->stored;
    Vec p = Flat(self->position - g_centre_8041d3a0);
    if (p.Length() < 200.0f) return 0;
    cc27a_planner_set_gravity_8001aa48(&g_centre_8041d3a0);
    int ok = fn_8001aaf8(&self->position, 0.5f, 1.0f);
    if (ok) {
        self->motion = g_motion_8041e780;
        Ptr32<const char> name = s_weapon_803697a4;
        Ptr32<Weapon> w;
        w3d_auto_800fc330(&name, &w);
        float speed = w->speed;
        self->velocity = p;
        self->velocity.Normalize();
        self->velocity *= speed;
    }
    return cc23a_planner_requeue_offset_8000b6bc(self, ok);
}


