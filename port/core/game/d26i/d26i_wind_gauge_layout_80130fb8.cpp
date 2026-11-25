#include "w3d_ptr.h"
#line 1 "d26i_wind_gauge_layout_80130fb8.cpp"
// GWMP8P rev0 0x80130fb8. Lays out the wind gauge's nodes and mesh for a
// given scale.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct UV { float u, v; void set(const Vec &o) { float a = o.x, b = o.y; u = a; v = b; } };
struct Prop;
extern "C" float w3d_prop_float_80178df0(Ptr32<Prop>);
extern "C" Ptr32<const Vec> w3d_prop_vec_80178ec4(Ptr32<Prop>);
struct Mesh;
extern "C" Ptr32<Mesh> w3d_mesh_8034380c(Ptr32<void>);
extern "C" Ptr32<Vec> w3d_vertices_80189518(Ptr32<Mesh>);
extern "C" Ptr32<UV> w3d_uvs_8018963c(Ptr32<Mesh>);
struct Node {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Node2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Node2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Node2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN4Node2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN4Node2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN4Node2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN4Node2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN4Node2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN4Node2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN4Node2v9Ev")); void w3d_r_v10() __asm__(W3D_SYM("_ZN4Node3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN4Node3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN4Node3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN4Node3v13Ev")); void w3d_r_v14() __asm__(W3D_SYM("_ZN4Node3v14Ev")); void w3d_r_v15() __asm__(W3D_SYM("_ZN4Node3v15Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN4Node3v16Ev"));
    void w3d_r_setPos(const Vec &, int) __asm__(W3D_SYM("_ZN4Node6setPosERK3Veci")); void w3d_r_v18() __asm__(W3D_SYM("_ZN4Node3v18Ev")); void w3d_r_setDir(const Vec &, int) __asm__(W3D_SYM("_ZN4Node6setDirERK3Veci"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setPos(const Vec &w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, w3d_u32, int))w3d::vfn(this->w3d_vptr_Node, 19))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0)), w3d_a1); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setDir(const Vec &w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, w3d_u32, int))w3d::vfn(this->w3d_vptr_Node, 21))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0)), w3d_a1); }  Ptr32<void> w3d_vptr_Node; };
struct Gauge {
    char u0[28]; Ptr32<Node> needle; char u32[4]; Ptr32<Node> back; Ptr32<void> mesh; char u44[16]; Vec origin; char u72[48];
    Ptr32<Prop> dir; Ptr32<Prop> size; Ptr32<Prop> grow; char u132[4]; Ptr32<Prop> top; char u140[8]; Ptr32<Prop> quad; Ptr32<Prop> uv;
};
inline Vec readVec(Ptr32<Prop> p) {
    float x = w3d_prop_float_80178df0(p);
    float y = w3d_prop_float_80178df0(p);
    float z = w3d_prop_float_80178df0(p);
    return Vec(x, y, z);
}
extern "C" void d26i_wind_gauge_layout_80130fb8(Ptr32<Gauge> self, float s) {
    float x1 = w3d_prop_float_80178df0(self->size); float y1 = w3d_prop_float_80178df0(self->size);
    Vec a(x1, y1, w3d_prop_float_80178df0(self->size));
    float x2 = w3d_prop_float_80178df0(self->dir); float y2 = w3d_prop_float_80178df0(self->dir);
    Vec b(x2, y2, w3d_prop_float_80178df0(self->dir));
    Vec c(*w3d_prop_vec_80178ec4(self->top));
    Vec d(*w3d_prop_vec_80178ec4(self->uv));
    Vec e(*w3d_prop_vec_80178ec4(self->quad));
    a *= s; b *= s; c *= s; d *= s; e *= s;
    self->needle->setPos(self->origin, 0);
    self->needle->setDir(a, 0);
    self->back->setPos(self->origin + c, 0);
    self->back->setDir(b, 0);
    Ptr32<Mesh> mesh = w3d_mesh_8034380c(self->mesh);
    w3d_vertices_80189518(mesh)[0] = self->origin + e;
    e.x += w3d_prop_float_80178df0(self->grow) * s;
    w3d_vertices_80189518(mesh)[1] = self->origin + e;
    w3d_uvs_8018963c(mesh)[0].set(d);
    w3d_uvs_8018963c(mesh)[1].set(d);
}


