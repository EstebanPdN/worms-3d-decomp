#include "w3d_ptr.h"
#line 1 "d24e_light_properties_801bf7f4.cpp"
// Light property registration: three colour vectors and a matrix (Worms 3D GameCube PAL, 0x801bf7f4).
//
// In call order: registers Enable and Scoped (0x801eb674); creates the
// AmbientColor, DiffuseColor and SpecularColor vector bindings (0x801f0a50) reset to the
// constants 0x803ac0bc, 0x803ac0c0 and 0x803ac0bc; resets the CapturedTransform matrix
// binding (0x801f0d2c) to the matrix 0x8045e708; calls the refresh routine
// 0x801e8d9c and returns 0. Built with -mps-float (one saved FPR in a non-leaf
// function). The first vector is built by an inline constructor and assigned;
// the later ones are filled through a pointer and copied with an inline set().
struct Vec3 { float x, y, z; Vec3() {} Vec3(float v) : x(v), y(v), z(v) {} };
struct Vec3Binding { unsigned header[2]; Vec3 value; void set(const Vec3 &v) { value = v; } };
struct Matrix { float m[16]; };
struct MatrixBinding { unsigned header[2]; Matrix value; };
extern "C" Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<Vec3Binding> fn_801f0a50(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<MatrixBinding> fn_801f0d2c(Ptr32<void>, Ptr32<const void>);
extern "C" void fn_801e8d9c(Ptr32<void>);
extern const float k_803ac0bc[], k_803ac0c0[];
extern Matrix m_8045e708[];
extern const unsigned char desc_803abf90[];  // Enable
extern const unsigned char desc_803abfc0[];  // Scoped
extern const unsigned char desc_803abff8[];  // AmbientColor
extern const unsigned char desc_803ac02c[];  // DiffuseColor
extern const unsigned char desc_803ac060[];  // SpecularColor
extern const unsigned char desc_803ac098[];  // CapturedTransform
extern "C" int w3d_d24e_register_light_properties_801bf7f4(Ptr32<void> o) {
    fn_801eb674(o, desc_803abf90);
    fn_801eb674(o, desc_803abfc0);
    Ptr32<Vec3Binding> b1 = fn_801f0a50(o, desc_803abff8);
    float one = k_803ac0bc[0];
    const Vec3 &c1 = Vec3(one);
    b1->value = c1;
    Ptr32<Vec3Binding> b2 = fn_801f0a50(o, desc_803ac02c);
    float v2 = k_803ac0c0[0];
    Vec3 t2;
    Ptr32<Vec3> p2 = &t2;
    p2->x = v2;
    p2->y = v2;
    p2->z = v2;
    b2->set(t2);
    Ptr32<Vec3Binding> b3 = fn_801f0a50(o, desc_803ac060);
    Vec3 t3;
    Ptr32<Vec3> p3 = &t3;
    p3->x = one;
    p3->y = one;
    p3->z = one;
    b3->set(t3);
    fn_801f0d2c(o, desc_803ac098)->value = m_8045e708[0];
    fn_801e8d9c(o);
    return 0;
}


