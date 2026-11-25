#include "w3d_ptr.h"
#line 1 "d21e_widget_properties_8021f3b4.cpp"
// Front-end widget property registration (Worms 3D GameCube PAL, 0x8021f3b4).
//
// In call order: registers StartDelay (0x801ebf38); registers EndDelay
// (0x801ebf38); creates the Position vector binding (0x801f0210) reset to
// 0.0f; creates the Scale vector binding (0x801f0210) reset to (50, 50, 0)
// (0x803b61e4 = 50.0f); resets
// the IncomingAnimation string binding (0x801ed24c) to the shared empty
// string; resets the OutgoingAnimation string binding (0x801ed24c) to the
// shared empty string; resets the HighlightedAnimation string binding
// (0x801ed24c) to the shared empty string; resets the ActivatedAnimation
// string binding (0x801ed24c) to the shared empty string; resets the
// ItemName string binding (0x801ed24c) to the shared empty string; resets
// the LeftItem string binding (0x801ed24c) to the shared empty string;
// resets the RightItem string binding (0x801ed24c) to the shared empty
// string; resets the UpItem string binding (0x801ed24c) to the shared empty
// string; resets the DownItem string binding (0x801ed24c) to the shared
// empty string; resets the ToolTipId string binding (0x801ed24c) to the
// shared empty string; registers FontSizeOverride (0x801ec52c); resets the
// EnableSwitch string binding (0x801ed24c) to the shared empty string;
// resets the IncomingAudio string binding (0x801ed24c) to the shared empty
// string; resets the OutgoingAudio string binding (0x801ed24c) to the shared
// empty string; resets the HighlightedAudio string binding (0x801ed24c) to
// the shared empty string; resets the ActivatedAudio string binding
// (0x801ed24c) to the shared empty string; then calls the refresh routine
// 0x801e8d9c and returns 0. Names are read from the descriptors' name
// pointers in the original data. Vector resets use the constant 0x803b61e0
// (0.0f).
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Vectors are filled through a pointer and
// copied with an inline set(const Vec3 &) (d18e recipe). The second vector's
// x and y read the separate constant 0x803b61e4 (50.0f): an index into the
// 0x803b61e0 pool shares the base address (24 words). Built with -mps-float
// (one saved FPR in a non-leaf function).
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
void fn_801eb834(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<const void>);
void fn_801eb674(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<const void>);
extern const unsigned char desc_803b5de4[];  // StartDelay
extern const unsigned char desc_803b5e18[];  // EndDelay
extern const unsigned char desc_803b5e4c[];  // Position
extern const unsigned char desc_803b5e78[];  // Scale
extern const unsigned char desc_803b5eb0[];  // IncomingAnimation
extern const unsigned char desc_803b5ee8[];  // OutgoingAnimation
extern const unsigned char desc_803b5f24[];  // HighlightedAnimation
extern const unsigned char desc_803b5f5c[];  // ActivatedAnimation
extern const unsigned char desc_803b5f8c[];  // ItemName
extern const unsigned char desc_803b5fbc[];  // LeftItem
extern const unsigned char desc_803b5fec[];  // RightItem
extern const unsigned char desc_803b6018[];  // UpItem
extern const unsigned char desc_803b6048[];  // DownItem
extern const unsigned char desc_803b6078[];  // ToolTipId
extern const unsigned char desc_803b60b0[];  // FontSizeOverride
extern const unsigned char desc_803b60e8[];  // EnableSwitch
extern const unsigned char desc_803b611c[];  // IncomingAudio
extern const unsigned char desc_803b6150[];  // OutgoingAudio
extern const unsigned char desc_803b6188[];  // HighlightedAudio
extern const unsigned char desc_803b61bc[];  // ActivatedAudio
extern float constant_803b61e0[];
extern float constant_803b61e4[];
extern "C" int w3d_d21e_register_widget_properties_8021f3b4(Ptr32<void> owner) {
    fn_801ebf38(owner, desc_803b5de4);
    fn_801ebf38(owner, desc_803b5e18);
    Ptr32<VectorBinding> v1 = fn_801f0210(owner, desc_803b5e4c);
    float zero = constant_803b61e0[0];
    Vec3 t1;
    Ptr32<Vec3> p1 = &t1;
    p1->x = zero;
    p1->y = zero;
    p1->z = zero;
    v1->set(t1);
    Ptr32<VectorBinding> v2 = fn_801f0210(owner, desc_803b5e78);
    Vec3 t2;
    Ptr32<Vec3> p2 = &t2;
    p2->x = constant_803b61e4[0];
    p2->y = constant_803b61e4[0];
    p2->z = zero;
    v2->set(t2);
    fn_801ed24c(owner, desc_803b5eb0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b5ee8)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b5f24)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b5f5c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b5f8c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b5fbc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b5fec)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6018)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6048)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6078)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ec52c(owner, desc_803b60b0);
    fn_801ed24c(owner, desc_803b60e8)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b611c)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6150)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6188)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b61bc)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801e8d9c(owner);
    return 0;
}


