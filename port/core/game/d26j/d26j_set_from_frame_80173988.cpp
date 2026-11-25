#include "w3d_ptr.h"
#line 1 "d26j_set_from_frame_80173988.cpp"
// Node set from a 2D frame, GWMP8P rev0 0x80173988. Transforms the unit x and
// y axes by the frame with its translation cleared, takes the z rotation from
// the first axis (atan 0x802e83ec with quadrant fixes, literal pi/2, -pi/2,
// pi), and applies rotation (virtual slot +144), the frame's translation
// (+140) and scale (+152). The scale's y is negated when the frame mirrors. A
// null first axis only clears the scale and returns 0. Stored literals are the
// pool words 0x803a6708..0x803a6718 in first-use order. -mps-float: the frame
// has the 8-byte gap below the FPR save area.

extern "C" float sqrt_802e82c0(float);
extern "C" float atan_802e83ec(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
};
struct Pos { float x, y, z; Pos(); };
struct Row { float x, y, z; };
struct Axes { Row row[3]; };
struct Mat {
    Axes a;
    Pos t;
    Mat(const Mat &o) { a = o.a; t = o.t; }
    const Row &R(int i) const { return a.row[i]; }
    const Pos &P() const { return t; }
    void zero(float v) { t.x = v; t.y = v; t.z = v; }
    void xform(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
struct Node {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN4Node2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN4Node3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN4Node3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN4Node3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN4Node3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN4Node3s28Ev"));
    void w3d_r_s32() __asm__(W3D_SYM("_ZN4Node3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN4Node3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN4Node3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN4Node3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN4Node3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN4Node3s52Ev"));
    void w3d_r_s56() __asm__(W3D_SYM("_ZN4Node3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN4Node3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN4Node3s64Ev")); void w3d_r_s68() __asm__(W3D_SYM("_ZN4Node3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN4Node3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN4Node3s76Ev"));
    void w3d_r_s80() __asm__(W3D_SYM("_ZN4Node3s80Ev")); void w3d_r_s84() __asm__(W3D_SYM("_ZN4Node3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN4Node3s88Ev")); void w3d_r_s92() __asm__(W3D_SYM("_ZN4Node3s92Ev")); void w3d_r_s96() __asm__(W3D_SYM("_ZN4Node3s96Ev")); void w3d_r_s100() __asm__(W3D_SYM("_ZN4Node4s100Ev"));
    void w3d_r_s104() __asm__(W3D_SYM("_ZN4Node4s104Ev")); void w3d_r_s108() __asm__(W3D_SYM("_ZN4Node4s108Ev")); void w3d_r_s112() __asm__(W3D_SYM("_ZN4Node4s112Ev")); void w3d_r_s116() __asm__(W3D_SYM("_ZN4Node4s116Ev")); void w3d_r_s120() __asm__(W3D_SYM("_ZN4Node4s120Ev")); void w3d_r_s124() __asm__(W3D_SYM("_ZN4Node4s124Ev"));
    void w3d_r_s128() __asm__(W3D_SYM("_ZN4Node4s128Ev")); void w3d_r_s132() __asm__(W3D_SYM("_ZN4Node4s132Ev")); void w3d_r_s136() __asm__(W3D_SYM("_ZN4Node4s136Ev"));
    int w3d_r_setTranslation(const Pos &) __asm__(W3D_SYM("_ZN4Node14setTranslationERK3Pos"));
    int w3d_r_setRotation(const Vec &) __asm__(W3D_SYM("_ZN4Node11setRotationERK3Vec"));
    void w3d_r_s148() __asm__(W3D_SYM("_ZN4Node4s148Ev"));
    int w3d_r_setScale(const Vec &) __asm__(W3D_SYM("_ZN4Node8setScaleERK3Vec"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s100() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s104() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s108() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s112() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s116() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s120() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s124() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s128() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s132() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s136() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int setTranslation(const Pos &w3d_a0) { return ((int (*)(w3d_u32, w3d_u32))w3d::vfn(this->w3d_vptr_Node, 35))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0))); }  __attribute__((always_inline)) inline int setRotation(const Vec &w3d_a0) { return ((int (*)(w3d_u32, w3d_u32))w3d::vfn(this->w3d_vptr_Node, 36))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0))); }  __attribute__((always_inline)) inline void s148() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Node, 37))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int setScale(const Vec &w3d_a0) { return ((int (*)(w3d_u32, w3d_u32))w3d::vfn(this->w3d_vptr_Node, 38))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0))); }  Ptr32<void> w3d_vptr_Node; };
// Decompose a 2D frame into rotation about z, translation and x/y scale.
extern "C" int d26j_set_from_frame_80173988(Ptr32<Node> self, Ptr32<const Mat> m)
{
    Vec ex(1.0f, 0.0f, 0.0f);
    Vec ey(0.0f, 1.0f, 0.0f);
    Vec u, v;
    Mat r(*m);
    r.zero(0.0f);
    r.xform(u, ex);
    r.xform(v, ey);
    float det = u.x * v.y - u.y * v.x;
    float angle;
    if (u.x == 0.0f) {
        if (u.y == 0.0f) {
            Vec s(0.0f, 0.0f, 0.0f);
            self->setScale(s);
            return 0;
        }
        if (u.y > 0.0f) angle = 1.5707964f;
        else angle = -1.5707964f;
    } else {
        angle = atan_802e83ec(u.y / u.x);
        if (u.x < 0.0f) angle += 3.1415927f;
    }
    Vec rot(0.0f, 0.0f, -angle);
    int res = self->setRotation(rot);
    if (res < 0) return res;
    res = self->setTranslation(m->t);
    if (res < 0) return res;
    Vec s = det > 0.0f ? Vec(u.len(), v.len(), 0.0f) : Vec(u.len(), -v.len(), 0.0f);
    return self->setScale(s);
}


