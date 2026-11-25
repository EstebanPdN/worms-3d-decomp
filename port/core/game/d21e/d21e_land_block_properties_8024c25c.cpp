#include "w3d_ptr.h"
#line 1 "d21e_land_block_properties_8024c25c.cpp"
// Land block property registration (Worms 3D GameCube PAL, 0x8024c25c).
//
// In call order: creates the Position vector binding (0x801f0210) reset to
// 0.0f; creates the Scale vector binding (0x801f0210) reset to 0.0f; resets
// the Transform matrix binding (0x801f0e4c) to the matrix 0x8045e748; resets
// the InvTransform matrix binding (0x801f0e4c) to the matrix 0x8045e748;
// creates the MinBounds vector binding (0x801f0210) reset to 0.0f; creates
// the MaxBounds vector binding (0x801f0210) reset to 0.0f; resets the
// AccumulatedMatrixNoScale matrix binding (0x801f0e4c) to the matrix
// 0x8045e748; resets the LocalMatrix matrix binding (0x801f0e4c) to the
// matrix 0x8045e748; resets the LocalMatrixNoScale matrix binding
// (0x801f0e4c) to the matrix 0x8045e748; registers MinLandScale
// (0x801ec52c); creates the FloorTexXVec vector binding (0x801f0210) reset
// to 0.0f; creates the FloorTexYVec vector binding (0x801f0210) reset to
// 0.0f; creates the WallTexXVec vector binding (0x801f0210) reset to 0.0f;
// creates the WallTexYVec vector binding (0x801f0210) reset to 0.0f; creates
// the FloorTexOffset 2D vector binding (0x801f00f0) reset to 0.0f; creates
// the WallTexOffset 2D vector binding (0x801f00f0) reset to 0.0f; creates
// the CentreOffset vector binding (0x801f0210) reset to 0.0f; registers
// EdgeOffset1 (0x801f25b0) with a guarded function-local static descriptor
// built once from a zero-filled temporary; registers EdgeOffset2
// (0x801f25b0) with a guarded function-local static descriptor built once
// from a zero-filled temporary; registers HeightMap (0x801efec4) with a
// guarded function-local static descriptor built once from a zero-filled
// temporary; registers PeturbCliffs (0x801ec52c); registers BitArray
// (0x801efdfc) with a guarded function-local static descriptor built once
// from a zero-filled temporary; registers SecondTextureBitArray (0x801efdfc)
// with a guarded function-local static descriptor built once from a zero-
// filled temporary; registers RLEVoxelData (0x801efdfc) with a guarded
// function-local static descriptor built once from a zero-filled temporary;
// registers CornerUsageCache (0x801efd34) with a guarded function-local
// static descriptor built once from a zero-filled temporary; registers XSize
// (0x801eb834); registers YSize (0x801eb834); registers ZSize (0x801eb834);
// registers XChildDim (0x801eb834); registers YChildDim (0x801eb834);
// registers ZChildDim (0x801eb834); registers HeightMapXSize (0x801eb834);
// registers HeightMapZSize (0x801eb834); registers Visible (0x801eb834);
// registers SmoothShading (0x801eb834); registers EdgeCrinkle (0x801eb834);
// registers EdgeFalloff (0x801eb834); resets the Tint colour binding
// (0x801f15e0) to 0; then calls the refresh routine 0x801e8d9c and returns
// 0. Names are read from the descriptors' name pointers in the original
// data. Vector resets use the constant 0x803c4be4 (0.0f).
//
// Property descriptors are function-local statics initialized from a GNU
// statement expression over a memset-zeroed local
// (d20e_box_properties_801c4930); guards and objects are zero-initialized
// statics of this function, not file-backed. Vectors are filled through a
// pointer and copied with an inline set(const Vec3 &) (d18e recipe). Each
// run of vector resets reads the 0.0f constant into its own local (the
// original reloads it after each group of matrix copies; one shared local is
// allocated to a general register, 630 words). The colour reset fills a
// local through a pointer and copies it with an inline set(). Built with
// -mps-float (one saved FPR in a non-leaf function).
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
Ptr32<void> fn_801eb834(Ptr32<void>, Ptr32<const void>);
void fn_801eb674(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
Ptr32<void> fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
Ptr32<void> fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
struct Matrix { float m[12]; };
struct MatrixBinding {
    unsigned header[2];
    Matrix value;
};
extern Matrix matrix_8045e748;
extern "C" Ptr32<MatrixBinding> fn_801f0e4c(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801efd34(Ptr32<void>, Ptr32<PropertyInfo>);
extern const unsigned char desc_803c4550[];  // Position
extern const unsigned char desc_803c457c[];  // Scale
extern const unsigned char desc_803c45ac[];  // Transform
extern const unsigned char desc_803c45e0[];  // InvTransform
extern const unsigned char desc_803c4610[];  // MinBounds
extern const unsigned char desc_803c4640[];  // MaxBounds
extern const unsigned char desc_803c4680[];  // AccumulatedMatrixNoScale
extern const unsigned char desc_803c46b0[];  // LocalMatrix
extern const unsigned char desc_803c46e8[];  // LocalMatrixNoScale
extern const unsigned char desc_803c471c[];  // MinLandScale
extern const unsigned char desc_803c4754[];  // FloorTexXVec
extern const unsigned char desc_803c4788[];  // FloorTexYVec
extern const unsigned char desc_803c47b8[];  // WallTexXVec
extern const unsigned char desc_803c47e8[];  // WallTexYVec
extern const unsigned char desc_803c481c[];  // FloorTexOffset
extern const unsigned char desc_803c4850[];  // WallTexOffset
extern const unsigned char desc_803c4884[];  // CentreOffset
extern const unsigned char desc_803c48dc[];  // PeturbCliffs
extern const unsigned char desc_803c4954[];  // XSize
extern const unsigned char desc_803c4984[];  // YSize
extern const unsigned char desc_803c49b4[];  // ZSize
extern const unsigned char desc_803c49e8[];  // XChildDim
extern const unsigned char desc_803c4a1c[];  // YChildDim
extern const unsigned char desc_803c4a50[];  // ZChildDim
extern const unsigned char desc_803c4a88[];  // HeightMapXSize
extern const unsigned char desc_803c4ac0[];  // HeightMapZSize
extern const unsigned char desc_803c4af0[];  // Visible
extern const unsigned char desc_803c4b28[];  // SmoothShading
extern const unsigned char desc_803c4b5c[];  // EdgeCrinkle
extern const unsigned char desc_803c4b90[];  // EdgeFalloff
extern const unsigned char desc_803c4bc0[];  // Tint
extern char lbl_803c48a8[];
extern char lbl_803c48b4[];
extern char lbl_803c48c0[];
extern char lbl_803c4904[];
extern char lbl_803c4910[];
extern char lbl_803c4928[];
extern char lbl_803c4938[];
extern char lbl_8045e47c[];
extern char lbl_8045ed1c[];
extern char lbl_8045ed4c[];
extern char lbl_8045ed7c[];
extern float constant_803c4be4[];
extern "C" int w3d_d21e_register_land_block_properties_8024c25c(Ptr32<void> owner) {
    Ptr32<VectorBinding> v1 = fn_801f0210(owner, desc_803c4550);
    float zero = constant_803c4be4[0];
    Vec3 t1;
    Ptr32<Vec3> p1 = &t1;
    p1->x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    Ptr32<VectorBinding> v2 = fn_801f0210(owner, desc_803c457c);
    Vec3 t2;
    Ptr32<Vec3> p2 = &t2;
    p2->x = zero;
    p2->y = zero;
    p2->z = zero;
    v2->set(t2);
    fn_801f0e4c(owner, desc_803c45ac)->value = matrix_8045e748;
    fn_801f0e4c(owner, desc_803c45e0)->value = matrix_8045e748;
    Ptr32<VectorBinding> v3 = fn_801f0210(owner, desc_803c4610);
    float zeroB = constant_803c4be4[0];
    Vec3 t3;
    Ptr32<Vec3> p3 = &t3;
    p3->x = zeroB;
    p3->y = zeroB;
    p3->z = zeroB;
    v3->set(t3);
    Ptr32<VectorBinding> v4 = fn_801f0210(owner, desc_803c4640);
    Vec3 t4;
    Ptr32<Vec3> p4 = &t4;
    p4->x = zeroB;
    p4->y = zeroB;
    p4->z = zeroB;
    v4->set(t4);
    fn_801f0e4c(owner, desc_803c4680)->value = matrix_8045e748;
    fn_801f0e4c(owner, desc_803c46b0)->value = matrix_8045e748;
    fn_801f0e4c(owner, desc_803c46e8)->value = matrix_8045e748;
    fn_801ec52c(owner, desc_803c471c);
    Ptr32<VectorBinding> v5 = fn_801f0210(owner, desc_803c4754);
    float zeroC = constant_803c4be4[0];
    Vec3 t5;
    Ptr32<Vec3> p5 = &t5;
    p5->x = zeroC;
    p5->y = zeroC;
    p5->z = zeroC;
    v5->set(t5);
    Ptr32<VectorBinding> v6 = fn_801f0210(owner, desc_803c4788);
    Vec3 t6;
    Ptr32<Vec3> p6 = &t6;
    p6->x = zeroC;
    p6->y = zeroC;
    p6->z = zeroC;
    v6->set(t6);
    Ptr32<VectorBinding> v7 = fn_801f0210(owner, desc_803c47b8);
    Vec3 t7;
    Ptr32<Vec3> p7 = &t7;
    p7->x = zeroC;
    p7->y = zeroC;
    p7->z = zeroC;
    v7->set(t7);
    Ptr32<VectorBinding> v8 = fn_801f0210(owner, desc_803c47e8);
    Vec3 t8;
    Ptr32<Vec3> p8 = &t8;
    p8->x = zeroC;
    p8->y = zeroC;
    p8->z = zeroC;
    v8->set(t8);
    Ptr32<Vec2Binding> w1 = fn_801f00f0(owner, desc_803c481c);
    Vec2 u1;
    u1.x = zeroC;
    u1.y = zeroC;
    w1->set(u1);
    Ptr32<Vec2Binding> w2 = fn_801f00f0(owner, desc_803c4850);
    Vec2 u2;
    u2.x = zeroC;
    u2.y = zeroC;
    w2->set(u2);
    Ptr32<VectorBinding> v9 = fn_801f0210(owner, desc_803c4884);
    Vec3 t9;
    Ptr32<Vec3> p9 = &t9;
    p9->x = zeroC;
    p9->y = zeroC;
    p9->z = zeroC;
    v9->set(t9);
    static PropertyInfo info80 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803c48a8;  // "EdgeOffset1"
        t.size = 400;
        t.elementType = 21;
        t.type = 9;
        t.typeObject = lbl_8045e47c;
        t;
    });
    fn_801f25b0(owner, &info80);
    static PropertyInfo info91 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803c48b4;  // "EdgeOffset2"
        t.size = 396;
        t.elementType = 22;
        t.type = 9;
        t.typeObject = lbl_8045e47c;
        t;
    });
    fn_801f25b0(owner, &info91);
    static PropertyInfo info102 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803c48c0;  // "HeightMap"
        t.size = 428;
        t.elementType = 23;
        t.type = 9;
        t.typeObject = lbl_8045ed7c;
        t;
    });
    fn_801efec4(owner, &info102);
    fn_801ec52c(owner, desc_803c48dc);
    static PropertyInfo info114 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803c4904;  // "BitArray"
        t.size = 440;
        t.elementType = 25;
        t.type = 9;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &info114);
    static PropertyInfo info125 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803c4910;  // "SecondTextureBitArray"
        t.size = 436;
        t.elementType = 26;
        t.type = 9;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &info125);
    static PropertyInfo info136 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803c4928;  // "RLEVoxelData"
        t.size = 432;
        t.elementType = 27;
        t.type = 9;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &info136);
    static PropertyInfo info147 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803c4938;  // "CornerUsageCache"
        t.size = 460;
        t.elementType = 28;
        t.type = 13;
        t.typeObject = lbl_8045ed1c;
        t;
    });
    fn_801efd34(owner, &info147);
    fn_801eb834(owner, desc_803c4954);
    fn_801eb834(owner, desc_803c4984);
    fn_801eb834(owner, desc_803c49b4);
    fn_801eb834(owner, desc_803c49e8);
    fn_801eb834(owner, desc_803c4a1c);
    fn_801eb834(owner, desc_803c4a50);
    fn_801eb834(owner, desc_803c4a88);
    fn_801eb834(owner, desc_803c4ac0);
    fn_801eb834(owner, desc_803c4af0);
    fn_801eb834(owner, desc_803c4b28);
    fn_801eb834(owner, desc_803c4b5c);
    fn_801eb834(owner, desc_803c4b90);
    fn_801f15e0(owner, desc_803c4bc0)->value = Colour(0, 0, 0, 0);
    fn_801e8d9c(owner);
    return 0;
}


