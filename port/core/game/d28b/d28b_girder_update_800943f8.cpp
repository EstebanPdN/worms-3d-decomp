#include "w3d_ptr.h"
#line 1 "d28b_girder_update_800943f8.cpp"
/* Girder placement update (0x800943f8): returns 20 while the scene timer 0x8006e71c is set; refreshes
 * the handle at +728 from +220, then runs the state at +684: 0 positions the girder 40 units ahead of
 * the active worm at eye level along its yaw, sets the handles and the camera GirderCam; 6 goes to
 * 1; 1 reads input and on a hit rebuilds points and heading; 2 and 3 track through 0x80095db4; 4
 * tracks, clamps the target, then either places it, with the Girder.Move sound when the rotation
 * changed, or resets the pending values, and updates the state handle. Field names are inferred from
 * the original instructions; the sound object is a partial view with 4-byte virtual table entries.
 * Owns the literals at 0x8037ea64; the strings before them are external views. */
extern char lbl_8037ea24[], lbl_8037ea34[], lbl_8037ea44[], lbl_8037ea58[];
extern "C" int w3d_timer_is_one_8006e71c();
extern "C" Ptr32<void> w3d_cast_80342fa4(Ptr32<void>);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; p->y = b; p->z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
    void Set(float v) { Ptr32<Vec> p = this; x = v; p->y = v; p->z = v; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
extern "C" int w3d_set_vec_80178fa4(Ptr32<void>, Ptr32<const Vec>);
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
struct PropertyKey { Ptr32<const char> name; };
extern "C" int w3d_read_int_800fc1f0(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" int w3d_read_float_800fc270(Ptr32<PropertyKey>, Ptr32<float>);
struct Worm { char unknown00[72]; float yaw; char unknown76[4]; Vec position; };
extern "C" Ptr32<Worm> w3d_worm_800fc6dc(int);
extern "C" void w3d_euler_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat>);
struct Camera;
extern Ptr32<Camera> lbl_804aa8c8;
extern "C" int w3d_camera_set_80035714(Ptr32<Camera>, Ptr32<const char>, float);
extern int lbl_804ade28;
extern Vec lbl_80434b88[];
struct Girder;
extern "C" void w3d_points_80095b58(Ptr32<Girder>);
extern "C" void w3d_heading_80095450(Ptr32<Girder>);
extern "C" void w3d_input_80094a84(Ptr32<Girder>);
extern "C" void w3d_track_80095db4(Ptr32<Girder>);
extern "C" void w3d_clamp_800949a8(Ptr32<Girder>, Ptr32<Vec>);
extern "C" void w3d_cancel_800959cc(Ptr32<Girder>);
extern "C" int w3d_update_value_80178c54(Ptr32<void>, Ptr32<int>);
struct Sounds { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Sounds2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN6Sounds2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN6Sounds2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN6Sounds2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN6Sounds2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN6Sounds2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN6Sounds2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN6Sounds2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN6Sounds2v8Ev"));
    void w3d_r_v9() __asm__(W3D_SYM("_ZN6Sounds2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN6Sounds3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN6Sounds3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN6Sounds3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN6Sounds3v13Ev")); void w3d_r_v14() __asm__(W3D_SYM("_ZN6Sounds3v14Ev")); void w3d_r_v15() __asm__(W3D_SYM("_ZN6Sounds3v15Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN6Sounds3v16Ev")); void w3d_r_v17() __asm__(W3D_SYM("_ZN6Sounds3v17Ev")); void w3d_r_v18() __asm__(W3D_SYM("_ZN6Sounds3v18Ev")); void w3d_r_v19() __asm__(W3D_SYM("_ZN6Sounds3v19Ev")); void w3d_r_v20() __asm__(W3D_SYM("_ZN6Sounds3v20Ev")); void w3d_r_v21() __asm__(W3D_SYM("_ZN6Sounds3v21Ev"));
    void w3d_r_Play(Ptr32<const char>, Ptr32<const Vec>) __asm__(W3D_SYM("_ZN6Sounds4PlayEPKcPK3Vec"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sounds, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Play(Ptr32<const char> w3d_a0, Ptr32<const Vec> w3d_a1) { ((void (*)(w3d_u32, Ptr32<const char>, Ptr32<const Vec>))w3d::vfn(this->w3d_vptr_Sounds, 24))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Sounds; };
struct Audio { char unknown00[108]; Ptr32<Sounds> sounds; };
extern Ptr32<Audio> lbl_804b1788;
struct Girder {
    char unknown00[184]; Vec current; Vec start; Vec target; Vec a220; Vec a232; char unknown244[36]; Vec spot;
    int hit; int kept; int stamp; float a304; float a308; float a312; float a316; float a320; float a324; float a328; float a332; float a336; float a340;
    char unknown344[340]; int state; char unknown688[4]; int f692; int f696; int f700; int f704; int f708; int f712; int f716; int f720; Ptr32<void> h724; Ptr32<void> h728; char unknown732[16]; int f748; Ptr32<void> h752;
};
extern "C" int w3d_d28b_girder_update_800943f8(Ptr32<Girder> self, int now) {
    int paused = w3d_timer_is_one_8006e71c();
    if (paused) return 20;
    w3d_set_vec_80178fa4(w3d_cast_80342fa4(self->h728), &self->a220);
    switch (self->state) {
    case 0: {
        Vec rot(0.0f, 0.0f, 0.0f);
        Vec dir;
        dir.Set(0.0f);
        if (lbl_804ade28 == 0) {
            Ptr32<Vec> f = lbl_80434b88;
            f->x = 0.0f; f->y = 0.0f; lbl_804ade28 = 1; f->z = 1.0f;
        }
        PropertyKey index; index.name = lbl_8037ea34;
        Ptr32<Camera> cam = lbl_804aa8c8;
        int active;
        w3d_read_int_800fc1f0(&index, &active);
        PropertyKey eye; eye.name = lbl_8037ea44;
        float level;
        w3d_read_float_800fc270(&eye, &level);
        Ptr32<Worm> worm = w3d_worm_800fc6dc(active);
        if (worm) self->spot = worm->position;
        self->current = self->spot;
        rot.y = worm->yaw;
        Mat m;
        w3d_euler_801a3eb0(&rot, 0, &m);
        m.rotate(dir, lbl_80434b88[0]);
        self->current.y += level;
        self->current += dir * 40.0f;
        self->target = self->current;
        self->start = self->current;
        w3d_set_vec_80178fa4(w3d_cast_80342fa4(self->h724), &self->current);
        Vec aim = dir * 40.0f;
        w3d_set_vec_80178fa4(w3d_cast_80342fa4(self->h728), &aim);
        w3d_camera_set_80035714(cam, lbl_8037ea24, 1.0f);
        w3d_points_80095b58(self);
        w3d_heading_80095450(self);
        self->state = 2;
        break;
    }
    case 6:
        self->state = 1;
        return 20;
    case 1:
        w3d_input_80094a84(self);
        if (self->hit) {
            w3d_points_80095b58(self);
            w3d_heading_80095450(self);
            self->state = 2;
        }
        self->kept = self->hit;
        break;
    case 2:
        self->f700 = paused;
        self->f708 = paused;
        self->f692 = paused;
        self->f720 = paused;
        self->f748 = paused;
        w3d_track_80095db4(self);
        self->state = 3;
        break;
    case 3:
        w3d_track_80095db4(self);
        self->state = 4;
        break;
    case 4: {
        w3d_track_80095db4(self);
        self->f696 = self->f700;
        self->f704 = self->f708;
        self->start = self->current;
        self->a328 = self->a324;
        self->a308 = self->a304;
        w3d_clamp_800949a8(self, &self->target);
        int place = self->f692 == 0;
        if (self->f712) place = 1;
        if (self->f720) place = 0;
        if (place) {
            if (self->a304 != self->a312 || self->a324 != self->a332) {
                Ptr32<Sounds> s = lbl_804b1788->sounds;
                if (s) s->Play(lbl_8037ea58, &self->current);
            }
            self->current = self->target;
            self->a220 = self->a232;
            self->stamp = now;
            self->a304 = self->a312;
            self->a316 = self->a320;
            self->a324 = self->a332;
            self->a336 = self->a340;
            w3d_set_vec_80178fa4(w3d_cast_80342fa4(self->h724), &self->current);
        } else {
            self->f692 = place;
            self->a312 = self->a304;
            self->a332 = self->a324;
            self->a328 = self->a324;
            self->a308 = self->a304;
            self->a232.Set(0.0f);
            self->a220.Set(0.0f);
            self->a316 = 0.0f;
            self->a320 = 0.0f;
            self->a336 = 0.0f;
            self->a340 = 0.0f;
            self->target = self->current;
            self->start = self->current;
            w3d_cancel_800959cc(self);
        }
        if (self->f712 && self->f692 == 0) self->f712 = self->f692;
        if (self->f696 == 0) {
            Ptr32<void> h = self->h752;
            self->f716 = self->f696;
            int one = 1;
            w3d_update_value_80178c54(h, &one);
        }
        self->state = 1;
        break;
    }
    }
    return 20;
}


