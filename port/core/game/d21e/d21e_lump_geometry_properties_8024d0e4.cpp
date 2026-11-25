#include "w3d_ptr.h"
#line 1 "d21e_lump_geometry_properties_8024d0e4.cpp"
// Lump geometry property registration (Worms 3D GameCube PAL, 0x8024d0e4).
//
// In call order: registers HighDetailGeometry (0x801ecc6c); registers
// FringeGeometry (0x801ecc6c); registers HighWaterBlendGeometry
// (0x801ecc6c); registers BapupGeometry (0x801eff8c) with a guarded
// function-local static descriptor built once from a zero-filled temporary;
// registers IsInGenerationQueue (0x801eb834); registers IsInShadowQueue
// (0x801eb834); registers HighDetailDirty (0x801eb834); registers
// BoundsDirty (0x801eb834); registers ShadowCache (0x801efdfc) with a
// guarded function-local static descriptor built once from a zero-filled
// temporary; registers VerticesToShadow (0x801ebbb8); registers VertexCount
// (0x801ebbb8); registers SiblingVertexCount (0x801ebbb8); registers
// QuickAccessColorSet (0x801ecc6c); registers QuickAccessCoordSet
// (0x801ecc6c); creates the RoofFloorTextureCentre 2D vector binding
// (0x801f00f0) reset to 0.0f; creates the WallTextureCentre 2D vector
// binding (0x801f00f0) reset to 0.0f; registers FringeSourceIndices
// (0x801efd98) with a guarded function-local static descriptor built once
// from a zero-filled temporary; then calls the refresh routine 0x801e8d9c
// and returns 0. Names are read from the descriptors' name pointers in the
// original data. Vector resets use the constant 0x803c4fe0 (0.0f).
//
// Property descriptors are function-local statics initialized from a GNU
// statement expression over a memset-zeroed local
// (d20e_box_properties_801c4930); guards and objects are zero-initialized
// statics of this function, not file-backed. All three static descriptors
// are zeroed through an inline clear() member (direct memset: 80 words;
// mixed forms 30-50 words). Built with -mps-float (one saved FPR in a non-
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
void fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
Ptr32<void> fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ebbb8(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801ecc6c(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801efd98(Ptr32<void>, Ptr32<PropertyInfo>);
extern const unsigned char desc_803c4cac[];  // HighDetailGeometry
extern const unsigned char desc_803c4ce0[];  // FringeGeometry
extern const unsigned char desc_803c4d1c[];  // HighWaterBlendGeometry
extern const unsigned char desc_803c4d64[];  // IsInGenerationQueue
extern const unsigned char desc_803c4d9c[];  // IsInShadowQueue
extern const unsigned char desc_803c4dd4[];  // HighDetailDirty
extern const unsigned char desc_803c4e08[];  // BoundsDirty
extern const unsigned char desc_803c4e50[];  // VerticesToShadow
extern const unsigned char desc_803c4e84[];  // VertexCount
extern const unsigned char desc_803c4ec0[];  // SiblingVertexCount
extern const unsigned char desc_803c4efc[];  // QuickAccessColorSet
extern const unsigned char desc_803c4f34[];  // QuickAccessCoordSet
extern const unsigned char desc_803c4f70[];  // RoofFloorTextureCentre
extern const unsigned char desc_803c4fa8[];  // WallTextureCentre
extern char lbl_803c4d40[];
extern char lbl_803c4e30[];
extern char lbl_803c4fcc[];
extern char lbl_803fe4c4[];
extern char lbl_8045e004[];
extern char lbl_8045ed34[];
extern char lbl_8045ed4c[];
extern float constant_803c4fe0[];
extern "C" int w3d_d21e_register_lump_geometry_properties_8024d0e4(Ptr32<void> owner) {
    fn_801ecc6c(owner, desc_803c4cac);
    fn_801ecc6c(owner, desc_803c4ce0);
    fn_801ecc6c(owner, desc_803c4d1c);
    static PropertyInfo info3 = ({
        PropertyInfo t;
        t.clear();
        t.name = lbl_803c4d40;  // "BapupGeometry"
        t.size = 80;
        t.elementType = 10;
        t.type = 13;
        t.typeObject = lbl_8045e004;
        t.member = lbl_803fe4c4;
        t;
    });
    fn_801eff8c(owner, &info3);
    fn_801eb834(owner, desc_803c4d64);
    fn_801eb834(owner, desc_803c4d9c);
    fn_801eb834(owner, desc_803c4dd4);
    fn_801eb834(owner, desc_803c4e08);
    static PropertyInfo info19 = ({
        PropertyInfo t;
        t.clear();
        t.name = lbl_803c4e30;  // "ShadowCache"
        t.size = 76;
        t.elementType = 15;
        t.type = 13;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &info19);
    fn_801ebbb8(owner, desc_803c4e50);
    fn_801ebbb8(owner, desc_803c4e84);
    fn_801ebbb8(owner, desc_803c4ec0);
    fn_801ecc6c(owner, desc_803c4efc);
    fn_801ecc6c(owner, desc_803c4f34);
    Ptr32<Vec2Binding> w1 = fn_801f00f0(owner, desc_803c4f70);
    float zero = constant_803c4fe0[0];
    Vec2 u1;
    u1.x = zero;
    u1.y = zero;
    w1->set(u1);
    Ptr32<Vec2Binding> w2 = fn_801f00f0(owner, desc_803c4fa8);
    Vec2 u2;
    u2.x = zero;
    u2.y = zero;
    w2->set(u2);
    static PropertyInfo info46 = ({
        PropertyInfo t;
        t.clear();
        t.name = lbl_803c4fcc;  // "FringeSourceIndices"
        t.size = 96;
        t.elementType = 23;
        t.type = 13;
        t.typeObject = lbl_8045ed34;
        t;
    });
    fn_801efd98(owner, &info46);
    fn_801e8d9c(owner);
    return 0;
}


