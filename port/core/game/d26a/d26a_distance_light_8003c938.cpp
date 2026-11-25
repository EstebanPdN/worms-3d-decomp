#include "w3d_ptr.h"
#line 1 "d26a_distance_light_8003c938.cpp"
// GWMP8P rev0 0x8003c938. Distance-attenuated light: scales the ambient
// vector by a clamped inverse of the squared distance to the camera and
// sends it to a sink. Names are inferred from the original instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { x = o.x; y = o.y; z = o.z; }
};
inline Vec operator*(const Vec &a, float f) { Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
// v34: 4x4 como en el original (64 B): f4c_normalize_801f6c2c escribe las 16 casillas. Con 60 B, la última (w = 1,0) se
// salía de la pila y pisaba un registro guardado del llamador (en Azahar, salto a 0 al pausar tras ahogarse un gusano).
struct Mat { float rows[12]; Vec position; float w; };
extern "C" int w3d_normalize_801f6c2c(Ptr32<Mat>, Ptr32<void>);
struct Source {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN6Source2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN6Source2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN6Source2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN6Source2v3Ev"));
    Ptr32<void> w3d_r_Matrix() __asm__(W3D_SYM("_ZN6Source6MatrixEv"));    /* table +24 */
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<void> Matrix() { return ((Ptr32<void> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 6))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Source; };
struct Scene { char unknown00[48]; Ptr32<Source> source; };
extern Ptr32<Scene> g_scene_804b1788;
extern Vec g_ambient_804273c8[];
struct Sink {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Sink2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Sink2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Sink2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN4Sink2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN4Sink2v4Ev"));
    void w3d_r_v5() __asm__(W3D_SYM("_ZN4Sink2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN4Sink2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN4Sink2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN4Sink2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN4Sink2v9Ev"));
    void w3d_r_v10() __asm__(W3D_SYM("_ZN4Sink3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN4Sink3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN4Sink3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN4Sink3v13Ev")); void w3d_r_v14() __asm__(W3D_SYM("_ZN4Sink3v14Ev"));
    void w3d_r_v15() __asm__(W3D_SYM("_ZN4Sink3v15Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN4Sink3v16Ev")); void w3d_r_v17() __asm__(W3D_SYM("_ZN4Sink3v17Ev")); void w3d_r_v18() __asm__(W3D_SYM("_ZN4Sink3v18Ev"));
    void w3d_r_Apply(const Vec &, int) __asm__(W3D_SYM("_ZN4Sink5ApplyERK3Veci"));    /* table +84 */
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sink, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Apply(const Vec &w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, w3d_u32, int))w3d::vfn(this->w3d_vptr_Sink, 21))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0)), w3d_a1); }  Ptr32<void> w3d_vptr_Sink; };
struct Self { char unknown00[36]; Ptr32<Sink> sink; };
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline void Clamp(float &v, const float &lo, const float &hi) { v = fmax(fmin(v, hi), lo); }

extern "C" void w3d_d26a_distance_light_8003c938(Ptr32<Self> self, Ptr32<const Vec> v)
{
    Vec p;
    Mat m;
    w3d_normalize_801f6c2c(&m, g_scene_804b1788->source->Matrix());
    Ptr32<Vec> q = &p;
    q->x = m.position.x;
    q->y = m.position.y;
    q->z = m.position.z;
    float dx = p.x - v->x, dy = q->y - v->y, dz = q->z - v->z;
    float d = dx * dx + dy * dy + dz * dz;
    float lo = 62500.0f;
    float hi = 160000.0f;
    Clamp(d, lo, hi);
    float k = lo / d;
    float klo = 0.5f;
    float khi = 1.0f;
    Clamp(k, klo, khi);
    Ptr32<Sink> s = self->sink;
    s->Apply(g_ambient_804273c8[0] * k, 0);
}


