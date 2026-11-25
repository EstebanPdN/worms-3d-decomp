#include "w3d_ptr.h"
#line 1 "d20e_lump_properties_8024fcdc.cpp"
// Lump property registration (Worms 3D GameCube PAL, 0x8024fcdc).
//
// Registers the "Connectors" (size 80, type 9, member record 0x8040106c) and
// "Bounds" (size 76, element type 1, type 9, member record 0x80401078)
// properties through 0x801eff8c, each with a guarded function-local static
// descriptor (type object 0x8045e004); registers Outline (0x801ecc6c);
// creates the PreviewPos, PreviewOrientation and PreviewScale vector
// bindings (0x801f0210) reset to the constant 0x803c59ac (0.0f); registers
// PreviewType, RandomRoot, LandCost, Complexity, EmitterCost, LumpType and
// YPlacement through their binding helpers; calls the refresh routine
// 0x801e8d9c and returns 0. Names are read from the descriptors' name
// pointers and the name strings in the original data.
//
// Each static descriptor is initialized from a statement expression over a
// local zero-filled through an inline clear() (memset), the shape solved for
// 0x801c4930 (d20e_box_properties_801c4930). The inline clear() gives the
// memset argument a pointer pseudo that GCC 2.95 shares with the later uses
// of the same stack slot (original r31); a direct memset(&t, ...) leaves the
// second call's argument recomputed (1 word). Vectors follow the d18e recipe.
// The guards and static objects are zero-initialized statics of this
// function (original .sbss 0x804b08f8/0x804b08fc, .bss 0x80464ff4/0x80465008).
// Built with -mps-float (one saved FPR in a non-leaf function).
extern "C" Ptr32<void> memset(...);
// 20-byte property descriptor registered by 0x801eff8c.
struct D20ePropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> typeObject;
    Ptr32<const void> member;
    int unknown16;
    void clear() { memset(w3d::VA(this), 0, sizeof(*this)); }
};
struct D20eVec3 {
    float x, y, z;
    D20eVec3() {}
    D20eVec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct D20eVectorBinding {
    unsigned header[2];
    D20eVec3 value;
    void set(const D20eVec3 &v) { value = v; }
};
struct D20eDescriptor;
extern "C" Ptr32<void> fn_801eff8c(Ptr32<void> owner, Ptr32<D20ePropertyInfo> info);
extern "C" Ptr32<void> fn_801ecc6c(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<D20eVectorBinding> fn_801f0210(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<void> fn_801ece2c(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<void> fn_801eb674(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<void> fn_801ec0f8(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<void> fn_801ebd78(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" Ptr32<void> fn_801ec52c(Ptr32<void> owner, Ptr32<const D20eDescriptor> descriptor);
extern "C" void fn_801e8d9c(Ptr32<void> owner);
extern char lbl_803c5770[];        // "Connectors"
extern char lbl_803c577c[];        // "Bounds"
extern char lbl_8045e004[];        // property type object
extern const char lbl_8040106c[];  // Connectors member record
extern const char lbl_80401078[];  // Bounds member record
extern "C" const D20eDescriptor k_803c578c;   // Outline
extern "C" const D20eDescriptor k_803c57bc;   // PreviewPos
extern "C" const D20eDescriptor k_803c57f4;   // PreviewOrientation
extern "C" const D20eDescriptor k_803c5828;   // PreviewScale
extern "C" const D20eDescriptor k_803c5858;   // PreviewType
extern "C" const D20eDescriptor k_803c588c;   // RandomRoot
extern "C" const D20eDescriptor k_803c58c0;   // LandCost
extern "C" const D20eDescriptor k_803c58f4;   // Complexity
extern "C" const D20eDescriptor k_803c5928;   // EmitterCost
extern "C" const D20eDescriptor k_803c5950;   // LumpType
extern "C" const D20eDescriptor k_803c5984;   // YPlacement
extern "C" const float value_803c59ac[];      // 0.0f

extern "C" int w3d_d20e_register_lump_properties_8024fcdc(Ptr32<void> self)
{
    static D20ePropertyInfo connectors = ({
        D20ePropertyInfo t;
        t.clear();
        t.name = lbl_803c5770;
        t.size = 80;
        t.type = 9;
        t.typeObject = lbl_8045e004;
        t.member = lbl_8040106c;
        t;
    });
    fn_801eff8c(self, &connectors);
    static D20ePropertyInfo bounds = ({
        D20ePropertyInfo t;
        t.clear();
        t.name = lbl_803c577c;
        t.size = 76;
        t.elementType = 1;
        t.type = 9;
        t.typeObject = lbl_8045e004;
        t.member = lbl_80401078;
        t;
    });
    fn_801eff8c(self, &bounds);
    fn_801ecc6c(self, &k_803c578c);
    Ptr32<D20eVectorBinding> pos = fn_801f0210(self, &k_803c57bc);
    float zero = value_803c59ac[0];
    D20eVec3 a(zero, zero, zero);
    pos->value = a;
    Ptr32<D20eVectorBinding> orientation = fn_801f0210(self, &k_803c57f4);
    D20eVec3 b;
    Ptr32<D20eVec3> q = &b;
    q->x = zero;
    q->y = zero;
    q->z = zero;
    orientation->set(b);
    Ptr32<D20eVectorBinding> scale = fn_801f0210(self, &k_803c5828);
    D20eVec3 c;
    Ptr32<D20eVec3> r = &c;
    r->x = zero;
    r->y = zero;
    r->z = zero;
    scale->set(c);
    fn_801ece2c(self, &k_803c5858);
    fn_801eb674(self, &k_803c588c);
    fn_801ec0f8(self, &k_803c58c0);
    fn_801ebd78(self, &k_803c58f4);
    fn_801ebd78(self, &k_803c5928);
    fn_801ece2c(self, &k_803c5950);
    fn_801ec52c(self, &k_803c5984);
    fn_801e8d9c(self);
    return 0;
}


