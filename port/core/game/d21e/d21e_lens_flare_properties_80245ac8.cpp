#include "w3d_ptr.h"
#line 1 "d21e_lens_flare_properties_80245ac8.cpp"
// Lens flare property registration (Worms 3D GameCube PAL, 0x80245ac8).
//
// In call order: registers Active (0x801eb674); registers LensScale
// (0x801ec52c); registers FocalOffset (0x801ec52c); registers Elements
// (0x801eff8c) with a guarded function-local static descriptor built once
// from a zero-filled temporary; then calls the refresh routine 0x801e8d9c
// and returns 0. Names are read from the descriptors' name pointers in the
// original data.
//
// Property descriptors are function-local statics initialized from a GNU
// statement expression over a memset-zeroed local
// (d20e_box_properties_801c4930); guards and objects are zero-initialized
// statics of this function, not file-backed. The static descriptor (size 20)
// is zeroed through an inline clear() member and its size is the descriptor
// size held in a local (unsigned n = sizeof(t)): direct memset 25-26 words,
// clear() with a literal 20 13-17 words (register swap). No saved FPR, no
// extra compiler options.
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
Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<const void>);
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}

extern const unsigned char desc_803c23d4[];  // Active
extern const unsigned char desc_803c2408[];  // LensScale
extern const unsigned char desc_803c243c[];  // FocalOffset
extern char lbl_803c2464[];
extern char lbl_803f4540[];
extern char lbl_8045e004[];
extern "C" int w3d_d21e_register_lens_flare_properties_80245ac8(Ptr32<void> owner) {
    fn_801eb674(owner, desc_803c23d4);
    fn_801ec52c(owner, desc_803c2408);
    fn_801ec52c(owner, desc_803c243c);
    static PropertyInfo info3 = ({
        PropertyInfo t;
        unsigned n = sizeof(t);
        t.clear();
        t.name = lbl_803c2464;  // "Elements"
        t.size = n;
        t.elementType = 3;
        t.type = 9;
        t.typeObject = lbl_8045e004;
        t.member = lbl_803f4540;
        t;
    });
    fn_801eff8c(owner, &info3);
    fn_801e8d9c(owner);
    return 0;
}


