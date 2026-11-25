#include "w3d_ptr.h"
extern "C" void w3d_hud_wind_observe(float);
#line 1 "d26i_wind_gauge_update_801303d4.cpp"
// GWMP8P rev0 0x801303d4. Updates the wind gauge needle rotation and its
// fade.
extern "C" float sin_802e88ac(float);
extern "C" float atan2_802e7e5c(float, float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Row { float x, y, z, w; };
struct Matrix {
    Row row[4];
    const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Camera { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Camera2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN6Camera2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN6Camera2v2Ev")); Ptr32<void> view();  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Camera, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Camera, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Camera, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Camera; };
struct Node { void w3d_r_v0() __asm__(W3D_SYM("_ZN4Node2v0Ev"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Node; };
struct World { char u0[48]; Ptr32<void> camera; };
extern Ptr32<World> world_804b1788;
extern const float span_8039dfec[];
struct Gauge {
    char u0[28]; Ptr32<void> node; int pending; char u36[24]; float phase; char u64[24]; int time; int reversed; unsigned int start; float t;
};
extern "C" void w3d_a_80130d1c(Ptr32<Gauge>, int);
extern "C" void w3d_b_80131610(Ptr32<Gauge>);
extern "C" Ptr32<void> w3d_wind_direction_80131520(Ptr32<Vec>, Ptr32<Gauge>);
extern "C" int w3d_matrix_from_801f6c2c(Ptr32<Matrix>, Ptr32<void>);
extern "C" void w3d_c_80130fb8(Ptr32<Gauge>, float);
extern "C" void w3d_d_80131338(Ptr32<Gauge>);
extern "C" void w3d_e_80130ed8(Ptr32<Gauge>);
typedef Ptr32<Ptr32<void> (Ptr32<void>)> GetFn;
typedef Ptr32<void (Ptr32<void>, const Vec &, int)> SetRot;
extern "C" int d26i_wind_gauge_update_801303d4(Ptr32<Gauge> self, unsigned int now) {
    w3d_a_80130d1c(self, 1);
    Vec wind;
    Matrix m;
    w3d_b_80131610(self);
    float wobble = sin_802e88ac(self->phase / span_8039dfec[0]);
    w3d_wind_direction_80131520(&wind, self);
    float heading = atan2_802e7e5c(wind.x, wind.z);
    Ptr32<void> cam = world_804b1788->camera;
    w3d_matrix_from_801f6c2c(&m, (*(Ptr32<GetFn>)(*(Ptr32<Ptr32<char>>)cam + 24))(cam));
    Vec axis(1.0f, 0.0f, 0.0f);
    Vec o;
    m.rotate(o, axis);
    float view = atan2_802e7e5c(o.z, o.x);
    Vec rot(0.0f, 0.0f, 0.0f);
    rot.y = view + 3.1415927f - wobble + heading;
    w3d_hud_wind_observe(rot.y);
    Ptr32<void> node = self->node;
    (*(Ptr32<SetRot>)(*(Ptr32<Ptr32<char>>)node + 80))(node, rot, 0);
    if ((float)self->start + 500.0f < (float)now) self->t = 1.0f;
    else self->t = (float)(now - self->start) / 500.0f;
    if (self->reversed == 0) self->t = 1.0f - self->t;
    w3d_c_80130fb8(self, self->t * 0.5f + 0.5f);
    self->time = now;
    w3d_d_80131338(self);
    if (self->pending == -1) w3d_e_80130ed8(self);
    return 0;
}


