#include "w3d_ptr.h"
#line 1 "d24e_message_list_properties_80226f58.cpp"
// Front-end message list widget property registration (Worms 3D GameCube PAL, 0x80226f58).
//
// In call order: registers Columns (0x801eff8c) with a guarded function-
// local static descriptor built once from a zero-filled temporary; registers
// Messages (0x801efff0) with a guarded function-local static descriptor
// built once from a zero-filled temporary; sets the FontResource string
// binding (0x801ed24c) to a temporary string made from "FE.Font"
// (0x803b6408, constructor 0x8020bb54); registers FontSize (0x801ec52c);
// then calls the refresh routine 0x801e8d9c and returns 0. Names are read
// from the descriptors' name pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Property descriptors are function-local
// statics initialized from a GNU statement expression over a memset-zeroed
// local (d20e_box_properties_801c4930); guards and objects are zero-
// initialized statics of this function, not file-backed. All guarded
// descriptors use the inline clear().  No saved FPR, no extra compiler
// options.
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

    // Takes its value by copy, so the temporary is built at the call.
    void set(String_8020bb54 v) { *this = v; }
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
Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const void>);
void fn_801f25b0(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efec4(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801efdfc(Ptr32<void>, Ptr32<PropertyInfo>);
Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801efff0(Ptr32<void>, Ptr32<PropertyInfo>);
extern const unsigned char desc_803b80e0[];  // FontResource
extern const unsigned char desc_803b8110[];  // FontSize
extern char lbl_803b80cc[];
extern char lbl_803b80d4[];
extern char lbl_804007d8[];
extern char lbl_8045e004[];
extern char lbl_8045ed94[];
extern const char lit_803b6408[];  // "FE.Font"
extern "C" int w3d_d24e_register_message_list_properties_80226f58(Ptr32<void> owner) {
    static PropertyInfo info0 = ({
        PropertyInfo t;
        t.clear();
        t.name = lbl_803b80cc;  // "Columns"
        t.size = 32;
        t.type = 9;
        t.typeObject = lbl_8045e004;
        t.member = lbl_804007d8;
        t;
    });
    fn_801eff8c(owner, &info0);
    static PropertyInfo info11 = ({
        PropertyInfo t;
        t.clear();
        t.name = lbl_803b80d4;  // "Messages"
        t.size = 28;
        t.elementType = 1;
        t.type = 9;
        t.typeObject = lbl_8045ed94;
        t;
    });
    fn_801efff0(owner, &info11);
    fn_801ed24c(owner, desc_803b80e0)->value.set(lit_803b6408);
    fn_801ec52c(owner, desc_803b8110);
    fn_801e8d9c(owner);
    return 0;
}


