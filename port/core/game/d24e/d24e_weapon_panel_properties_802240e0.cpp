#include "w3d_ptr.h"
#line 1 "d24e_weapon_panel_properties_802240e0.cpp"
// Front-end weapon panel widget property registration (Worms 3D GameCube PAL, 0x802240e0).
//
// In call order: resets the WeaponGrafixID string binding (0x801ed24c) to
// the shared empty string; resets the DataContainerID string binding
// (0x801ed24c) to the shared empty string; resets the LockedID string
// binding (0x801ed24c) to the shared empty string; resets the PageID string
// binding (0x801ed24c) to the shared empty string; resets the TypeID string
// binding (0x801ed24c) to the shared empty string; resets the ToolTipID
// string binding (0x801ed24c) to the shared empty string; sets the
// BorderResource string binding (0x801ed24c) to a temporary string made from
// "FE.Brd.%s" (0x803b76e4, constructor 0x8020bb54); registers BorderColour
// (0x801ece2c); resets the HighlightedMessage string binding (0x801ed24c) to
// the shared empty string; resets the SelectedMessage string binding
// (0x801ed24c) to the shared empty string; then calls the refresh routine
// 0x801e8d9c and returns 0. Names are read from the descriptors' name
// pointers in the original data.
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
void fn_801eb674(Ptr32<void>, Ptr32<const void>);
void fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ece2c(Ptr32<void>, Ptr32<const void>);
extern const unsigned char desc_803b7700[];  // WeaponGrafixID
extern const unsigned char desc_803b7734[];  // DataContainerID
extern const unsigned char desc_803b7764[];  // LockedID
extern const unsigned char desc_803b7790[];  // PageID
extern const unsigned char desc_803b77bc[];  // TypeID
extern const unsigned char desc_803b77ec[];  // ToolTipID
extern const unsigned char desc_803b7810[];  // BorderResource
extern const unsigned char desc_803b7834[];  // BorderColour
extern const unsigned char desc_803b785c[];  // HighlightedMessage
extern const unsigned char desc_803b7880[];  // SelectedMessage
extern const char lit_803b76e4[];  // "FE.Brd.%s"
extern "C" int w3d_d24e_register_weapon_panel_properties_802240e0(Ptr32<void> owner) {
    fn_801ed24c(owner, desc_803b7700)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7734)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7764)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7790)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b77bc)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b77ec)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7810)->value = String_8020bb54(lit_803b76e4);
    fn_801ece2c(owner, desc_803b7834);
    fn_801ed24c(owner, desc_803b785c)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7880)->value = String_8020bb54(d20e_empty_804b06a0[0]);
    fn_801e8d9c(owner);
    return 0;
}


