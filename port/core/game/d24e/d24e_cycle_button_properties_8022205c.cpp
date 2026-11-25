#include "w3d_ptr.h"
#line 1 "d24e_cycle_button_properties_8022205c.cpp"
// Front-end cycling button widget property registration (Worms 3D GameCube PAL, 0x8022205c).
//
// In call order: resets the ResourceNames string binding (0x801ed24c) to the
// shared empty string; resets the GameDataId string binding (0x801ed24c) to
// the shared empty string; sets the BorderResource string binding
// (0x801ed24c) to a temporary string made from "FE.Button.%s" (0x803b61f8,
// constructor 0x8020bb54); resets the HighlightedMessage string binding
// (0x801ed24c) to the shared empty string; resets the SelectedMessage string
// binding (0x801ed24c) to the shared empty string; registers BorderColour
// (0x801ece2c); registers SquareButton (0x801eb674); registers BorderBehind
// (0x801eb674); registers LoopValues (0x801eb674); then calls the refresh
// routine 0x801e8d9c and returns 0. Names are read from the descriptors'
// name pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Literal defaults use the out-of-line
// string constructor 0x8020bb54.  No saved FPR, no extra compiler options.
extern "C" Ptr32<void> memset(...);
struct String_8020bb54;
extern "C" void d20e_string_init_8020c5c0(Ptr32<String_8020bb54>);
extern "C" Ptr32<unsigned short> d20e_string_header_80341884(Ptr32<String_8020bb54>);
extern "C" void d20e_string_finish_8020c5c4(Ptr32<String_8020bb54>);
extern "C" void d20e_string_release_80341588(Ptr32<String_8020bb54>);
extern "C" void d20e_release_header_8020bb2c(Ptr32<unsigned short>);

struct String_8020bb54 {
    Ptr32<char> text;

    // Copy constructor: initializes the shared string and takes a
    // reference on the source text (16-bit header counter).
    template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);

    String_8020bb54(const String_8020bb54 &other) {
        d20e_string_init_8020c5c0(this);
        text = other.text;
        ++*d20e_string_header_80341884(this);
    }

    ~String_8020bb54() {
        d20e_string_finish_8020c5c4(this);
        d20e_string_release_80341588(this);
    }

    String_8020bb54 &operator=(const String_8020bb54 &other) {
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
    String_8020bb54 value;
};

extern String_8020bb54 d20e_empty_804b06a0[];
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
Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<const void>);
void fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ece2c(Ptr32<void>, Ptr32<const void>);
extern const unsigned char desc_803b6b24[];  // ResourceNames
extern const unsigned char desc_803b6b54[];  // GameDataId
extern const unsigned char desc_803b6b78[];  // BorderResource
extern const unsigned char desc_803b6b9c[];  // HighlightedMessage
extern const unsigned char desc_803b6bc0[];  // SelectedMessage
extern const unsigned char desc_803b6be4[];  // BorderColour
extern const unsigned char desc_803b6c0c[];  // SquareButton
extern const unsigned char desc_803b6c34[];  // BorderBehind
extern const unsigned char desc_803b6c68[];  // LoopValues
extern const char lit_803b61f8[];  // "FE.Button.%s"
extern "C" int w3d_d24e_register_cycle_button_properties_8022205c(Ptr32<void> owner) {
    fn_801ed24c(owner, desc_803b6b24)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6b54)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6b78)->value = String_8020bb54(lit_803b61f8);
    fn_801ed24c(owner, desc_803b6b9c)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b6bc0)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ece2c(owner, desc_803b6be4);
    fn_801eb674(owner, desc_803b6c0c);
    fn_801eb674(owner, desc_803b6c34);
    fn_801eb674(owner, desc_803b6c68);
    fn_801e8d9c(owner);
    return 0;
}


