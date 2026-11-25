#include "w3d_ptr.h"
#line 1 "d28b_launch_effect_8009aaac.cpp"
/* Launch effect setup (0x8009aaac): reads the active worm, posts the launch message and reads
 * Weapon.GraphicalLaunchLocation, then, when the target object exists, takes its position or, when
 * that is the default vector, a point 1000 units ahead along the worm pitch and yaw (0x801a3eb0), and
 * sets the emitter at +32: position, scale with z from a hundredth of the distance, and rotation from
 * the direction (0x8009b070). Returns 0. Field names are inferred from the original instructions;
 * Emitter is a partial view of the original virtual table with 4-byte entries. Owns the strings and
 * float literals from 0x8037ffbc. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; Ptr32<void> vtable; };
extern "C" char lbl_8040db38[];
extern "C" Ptr32<void> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_message_post_8016239c(Ptr32<void>);
extern Ptr32<void> lbl_804b1754;
extern MessageCache lbl_804adfbc;
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Scale(float f) { x *= f; y *= f; z *= f; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator/(const Vec &a, float k) { float f = 1.0f / k; Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline float Distance(const Vec &a, const Vec &b) { float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z; return sqrt_802e82c0(dx * dx + dy * dy + dz * dz); }
inline bool operator==(const Vec &a, const Vec &b) { return *(Ptr32<int>)&a.x == *(Ptr32<int>)&b.x && *(Ptr32<int>)&a.y == *(Ptr32<int>)&b.y && *(Ptr32<int>)&a.z == *(Ptr32<int>)&b.z; }
struct Row { float x, y, z; };
struct Mat {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern const Vec lbl_8045e788[];
struct PropertyKey { Ptr32<const char> name; };
extern "C" int w3d_read_time_800fc1f0(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_read_vec_800fc2f0(Ptr32<PropertyKey>, Ptr32<Vec>);
struct Worm { char unknown00[72]; float yaw; char unknown76[40]; float pitch; };
extern "C" Ptr32<Worm> w3d_worm_800fc6dc(int);
struct Holder { char unknown00[72]; Vec position; };
extern "C" Ptr32<Holder> w3d_lookup_80164fc8(int);
extern "C" void w3d_euler_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat>);
struct Emitter {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN7Emitter2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN7Emitter2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN7Emitter2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN7Emitter2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN7Emitter2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN7Emitter2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN7Emitter2v6Ev"));
    void w3d_r_v7() __asm__(W3D_SYM("_ZN7Emitter2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN7Emitter2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN7Emitter2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN7Emitter3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN7Emitter3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN7Emitter3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN7Emitter3v13Ev"));
    void w3d_r_v14() __asm__(W3D_SYM("_ZN7Emitter3v14Ev")); void w3d_r_v15() __asm__(W3D_SYM("_ZN7Emitter3v15Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN7Emitter3v16Ev"));
    void w3d_r_SetPosition(Ptr32<const Vec>, int) __asm__(W3D_SYM("_ZN7Emitter11SetPositionEPK3Veci"));
    void w3d_r_SetRotation(Ptr32<const Vec>, int) __asm__(W3D_SYM("_ZN7Emitter11SetRotationEPK3Veci"));
    void w3d_r_SetScale(Ptr32<const Vec>, int) __asm__(W3D_SYM("_ZN7Emitter8SetScaleEPK3Veci"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Emitter, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void SetPosition(Ptr32<const Vec> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<const Vec>, int))w3d::vfn(this->w3d_vptr_Emitter, 19))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void SetRotation(Ptr32<const Vec> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<const Vec>, int))w3d::vfn(this->w3d_vptr_Emitter, 20))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void SetScale(Ptr32<const Vec> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<const Vec>, int))w3d::vfn(this->w3d_vptr_Emitter, 21))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Emitter; };
struct Entity;
extern "C" Vec f7b_direction_angles_8009b070(Ptr32<Entity>, const Vec &);
struct Entity { char unknown00[32]; Ptr32<Emitter> emitter; int target; };
extern "C" int w3d_d28b_launch_effect_8009aaac(Ptr32<Entity> self) {
    Vec pos;
    Vec target;
    Vec mid;
    Vec spin(1.0f, 1.0f, 1.0f);
    Vec rot;
    PropertyKey index; index.name = "ActiveWormIndex";
    int active;
    w3d_read_time_800fc1f0(&index, &active);
    Ptr32<Worm> worm = w3d_worm_800fc6dc(active);
    Ptr32<Message> m = (Ptr32<Message>)w3d_arena_alloc_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(&lbl_804adfbc, 1);
    m->vtable = lbl_8040db38;
    w3d_message_post_8016239c(m);
    PropertyKey where; where.name = "Weapon.GraphicalLaunchLocation";
    w3d_read_vec_800fc2f0(&where, &pos);
    Ptr32<Holder> h = w3d_lookup_80164fc8(self->target);
    if (h) {
        target = h->position;
        if (lbl_8045e788[0] == target) {
            Vec ang;
            Vec dir;
            Mat mat;
            ang = lbl_8045e788[0];
            ang.x = -worm->pitch;
            ang.y = worm->yaw;
            float one = 1.0f;
            Vec fwd;
            Ptr32<Vec> p = &fwd;
            fwd.x = 0.0f;
            p->y = 0.0f;
            p->z = one;
            w3d_euler_801a3eb0(&ang, 0, &mat);
            mat.rotate(dir, fwd);
            dir.Scale(one / dir.len());
            target = pos + dir * 1000.0f;
        }
        mid = pos + (target - pos) / 2.0f;
        spin.z = Distance(target, pos) * 0.01f;
        rot = f7b_direction_angles_8009b070(self, target - pos);
        self->emitter->SetPosition(&pos, 0);
        self->emitter->SetScale(&spin, 0);
        self->emitter->SetRotation(&rot, 0);
    }
    return 0;
}


