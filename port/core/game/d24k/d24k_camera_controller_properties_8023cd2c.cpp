#include "w3d_ptr.h"
#line 1 "d24k_camera_controller_properties_8023cd2c.cpp"
// Camera controller property registration (Worms 3D GameCube PAL, 0x8023cd2c).
//
// In call order: registers WormIndex (0x801ebf38); registers Random
// (0x801ebf38); registers WormData (0x801ecc6c); resets the
// TaskVerificationString string binding (0x801ed24c) to the shared empty
// string; registers ViewMatrix (0x801f0d2c); resets the CurrentCamera string
// binding (0x801ed24c) to the shared empty string; creates the
// TargetPosition vector binding (0x801f0210) reset to 0.0f; creates the
// TargetLookAt vector binding (0x801f0210) reset to 0.0f; creates the
// TargetUpVector vector binding (0x801f0210) reset to 0.0f; creates the
// TargetLookAhead vector binding (0x801f0210) reset to 0.0f; creates the
// LookAhead vector binding (0x801f0210) reset to 0.0f; creates the ObjectPos
// vector binding (0x801f0210) reset to 0.0f; creates the ObjectRot vector
// binding (0x801f0210) reset to 0.0f; creates the ObjectVelocity vector
// binding (0x801f0210) reset to 0.0f; registers fYaw (0x801ec52c); registers
// fPitch (0x801ec52c); registers fLookAbove (0x801ec52c); registers fDist
// (0x801ec52c); registers fTargetDist (0x801ec52c); creates the Position
// vector binding (0x801f0210) reset to 0.0f; creates the LookAt vector
// binding (0x801f0210) reset to 0.0f; creates the UpVector vector binding
// (0x801f0210) reset to 0.0f; registers RoundTime (0x801ebf38); registers
// HotSeattime (0x801ebf38); registers TurnTime (0x801ebf38); then calls the
// refresh routine 0x801e8d9c and returns 0. Names are read from the
// descriptors' name pointers in the original data. Vector resets use the
// constant 0x803bc3b0 (0.0f).
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Vectors are filled through a pointer and
// copied with an inline set(const Vec3 &) (d18e recipe). Each vector's
// pointer local is declared together right after the matrix copy (0x801f0d2c
// binding, 16-float matrix 0x8045e708), so all eleven addresses stay in
// saved registers; the first field is stored on the object itself and the
// others through the pointer. Built with -mps-float (one saved FPR in a non-
// leaf function).
extern "C" Ptr32<void> memset(...);
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> d20e_string_header_80341884(Ptr32<SharedString>);
extern "C" void d20e_string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void d20e_string_release_80341588(Ptr32<SharedString>);
extern "C" void d20e_release_header_8020bb2c(Ptr32<unsigned short>);

struct SharedString {
    Ptr32<char> text;

    // Copy constructor: initializes the shared string and takes a
    // reference on the source text (16-bit header counter).
    SharedString(const SharedString &other) {
        d20e_string_init_8020c5c0(this);
        text = other.text;
        ++*d20e_string_header_80341884(this);
    }

    ~SharedString() {
        d20e_string_finish_8020c5c4(this);
        d20e_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            d20e_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }

    // Takes its value by copy, so the temporary is built at the call.
    void set(SharedString v) { *this = v; }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString d20e_empty_804b06a0[];
struct Vec3 { float x, y, z; };
struct VectorBinding {
    unsigned header[2];
    Vec3 value;
    void set(const Vec3 &v) { value = v; }
};
struct Vec2 { float x, y; };
struct Vec2Binding {
    unsigned header[2];
    Vec2 value;
    void set(const Vec2 &v) { value = v; }
};
struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) : r(r_), g(g_), b(b_), a(a_) {}
};
struct ColourBinding {
    unsigned header[2];
    Colour value;
};
struct PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> typeObject;
    Ptr32<const void> member;
    int unknown16;
    void clear() { memset(w3d::VA(this), 0, sizeof(*this)); }
};
extern "C" {
Ptr32<StringBinding> fn_801ed24c(Ptr32<void>, Ptr32<const void>);
Ptr32<VectorBinding> fn_801f0210(Ptr32<void>, Ptr32<const void>);
Ptr32<Vec2Binding> fn_801f00f0(Ptr32<void>, Ptr32<const void>);
Ptr32<ColourBinding> fn_801f15e0(Ptr32<void>, Ptr32<const void>);
void fn_801eb834(Ptr32<void>, Ptr32<const void>);
void fn_801eb674(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<const void>);
struct Matrix16 { float m[16]; };
struct Matrix16Binding {
    unsigned header[2];
    Matrix16 value;
};
extern Matrix16 matrix_8045e708;
extern "C" Ptr32<Matrix16Binding> fn_801f0d2c(Ptr32<void>, Ptr32<const void>);
extern const unsigned char desc_803bbed4[];  // WormIndex
extern const unsigned char desc_803bbf04[];  // Random
extern const unsigned char desc_803bbf38[];  // WormData
extern const unsigned char desc_803bbf74[];  // TaskVerificationString
extern const unsigned char desc_803bbfa4[];  // ViewMatrix
extern const unsigned char desc_803bbfd8[];  // CurrentCamera
extern const unsigned char desc_803bc00c[];  // TargetPosition
extern const unsigned char desc_803bc040[];  // TargetLookAt
extern const unsigned char desc_803bc074[];  // TargetUpVector
extern const unsigned char desc_803bc0a8[];  // TargetLookAhead
extern const unsigned char desc_803bc0d8[];  // LookAhead
extern const unsigned char desc_803bc108[];  // ObjectPos
extern const unsigned char desc_803bc138[];  // ObjectRot
extern const unsigned char desc_803bc16c[];  // ObjectVelocity
extern const unsigned char desc_803bc198[];  // fYaw
extern const unsigned char desc_803bc1c8[];  // fPitch
extern const unsigned char desc_803bc1fc[];  // fLookAbove
extern const unsigned char desc_803bc22c[];  // fDist
extern const unsigned char desc_803bc260[];  // fTargetDist
extern const unsigned char desc_803bc294[];  // Position
extern const unsigned char desc_803bc2c0[];  // LookAt
extern const unsigned char desc_803bc2f0[];  // UpVector
extern const unsigned char desc_803bc320[];  // RoundTime
extern const unsigned char desc_803bc354[];  // HotSeattime
extern const unsigned char desc_803bc388[];  // TurnTime
extern float constant_803bc3b0[];
extern "C" int w3d_d24k_camera_controller_properties_8023cd2c(Ptr32<void> owner) {
    fn_801ebf38(owner, desc_803bbed4);
    fn_801ebf38(owner, desc_803bbf04);
    fn_801ecc6c(owner, desc_803bbf38);
    fn_801ed24c(owner, desc_803bbf74)->value.set(d20e_empty_804b06a0[0]);
    Ptr32<Matrix16Binding> mb = fn_801f0d2c(owner, desc_803bbfa4);

    mb->value = matrix_8045e708;
    Vec3 t1;
    Ptr32<Vec3> p1 = &t1;
    Vec3 t2;
    Ptr32<Vec3> p2 = &t2;
    Vec3 t3;
    Ptr32<Vec3> p3 = &t3;
    Vec3 t4;
    Ptr32<Vec3> p4 = &t4;
    Vec3 t5;
    Ptr32<Vec3> p5 = &t5;
    Vec3 t6;
    Ptr32<Vec3> p6 = &t6;
    Vec3 t7;
    Ptr32<Vec3> p7 = &t7;
    Vec3 t8;
    Ptr32<Vec3> p8 = &t8;
    Vec3 t9;
    Ptr32<Vec3> p9 = &t9;
    Vec3 t10;
    Ptr32<Vec3> p10 = &t10;
    Vec3 t11;
    Ptr32<Vec3> p11 = &t11;
    fn_801ed24c(owner, desc_803bbfd8)->value.set(d20e_empty_804b06a0[0]);
    Ptr32<VectorBinding> v1 = fn_801f0210(owner, desc_803bc00c);
    float zero = constant_803bc3b0[0];
    t1.x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    Ptr32<VectorBinding> v2 = fn_801f0210(owner, desc_803bc040);
    t2.x = zero;
    p2->y = zero;
    p2->z = zero;
    v2->set(t2);
    Ptr32<VectorBinding> v3 = fn_801f0210(owner, desc_803bc074);
    t3.x = zero;
    p3->y = zero;
    p3->z = zero;
    v3->set(t3);
    Ptr32<VectorBinding> v4 = fn_801f0210(owner, desc_803bc0a8);
    t4.x = zero;
    p4->y = zero;
    p4->z = zero;
    v4->set(t4);
    Ptr32<VectorBinding> v5 = fn_801f0210(owner, desc_803bc0d8);
    t5.x = zero;
    p5->y = zero;
    p5->z = zero;
    v5->set(t5);
    Ptr32<VectorBinding> v6 = fn_801f0210(owner, desc_803bc108);
    t6.x = zero;
    p6->y = zero;
    p6->z = zero;
    v6->set(t6);
    Ptr32<VectorBinding> v7 = fn_801f0210(owner, desc_803bc138);
    t7.x = zero;
    p7->y = zero;
    p7->z = zero;
    v7->set(t7);
    Ptr32<VectorBinding> v8 = fn_801f0210(owner, desc_803bc16c);
    t8.x = zero;
    p8->y = zero;
    p8->z = zero;
    v8->set(t8);
    fn_801ec52c(owner, desc_803bc198);
    fn_801ec52c(owner, desc_803bc1c8);
    fn_801ec52c(owner, desc_803bc1fc);
    fn_801ec52c(owner, desc_803bc22c);
    fn_801ec52c(owner, desc_803bc260);
    Ptr32<VectorBinding> v9 = fn_801f0210(owner, desc_803bc294);
    t9.x = zero;
    p9->y = zero;
    p9->z = zero;
    v9->set(t9);
    Ptr32<VectorBinding> v10 = fn_801f0210(owner, desc_803bc2c0);
    t10.x = zero;
    p10->y = zero;
    p10->z = zero;
    v10->set(t10);
    Ptr32<VectorBinding> v11 = fn_801f0210(owner, desc_803bc2f0);
    t11.x = zero;
    p11->y = zero;
    p11->z = zero;
    v11->set(t11);
    fn_801ebf38(owner, desc_803bc320);
    fn_801ebf38(owner, desc_803bc354);
    fn_801ebf38(owner, desc_803bc388);
    fn_801e8d9c(owner);
    return 0;
}


