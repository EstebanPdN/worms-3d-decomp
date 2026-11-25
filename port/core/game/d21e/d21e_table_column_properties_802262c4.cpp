#include "w3d_ptr.h"
#line 1 "d21e_table_column_properties_802262c4.cpp"
// Table column property registration (Worms 3D GameCube PAL, 0x802262c4).
//
// In call order: resets the ColumnName string binding (0x801ed24c) to the
// shared empty string; registers WidthPercent (0x801ec52c); registers Ratio
// (0x801ec52c); registers Justification (0x801ece2c); registers
// UnevenColumns (0x801eb674); registers Values (0x801efff0) with a guarded
// function-local static descriptor built once from a zero-filled temporary;
// registers Data (0x801efe60) with a guarded function-local static
// descriptor built once from a zero-filled temporary; then calls the refresh
// routine 0x801e8d9c and returns 0. Names are read from the descriptors'
// name pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Property descriptors are function-local
// statics initialized from a GNU statement expression over a memset-zeroed
// local (d20e_box_properties_801c4930); guards and objects are zero-
// initialized statics of this function, not file-backed. In the static block
// whose size or element type is 20 the value is the descriptor size held in
// a local (unsigned n = sizeof(t)) and reused for the memset and the field:
// the shared value gives the original register assignment (as in
// d21e_land_properties_8024e1fc). No saved FPR, no extra compiler options.
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
void fn_801eff8c(Ptr32<void>, Ptr32<PropertyInfo>);
void fn_801e8d9c(Ptr32<void>);
}
extern "C" Ptr32<void> fn_801ece2c(Ptr32<void>, Ptr32<const void>);
extern "C" Ptr32<void> fn_801efe60(Ptr32<void>, Ptr32<PropertyInfo>);
extern "C" Ptr32<void> fn_801efff0(Ptr32<void>, Ptr32<PropertyInfo>);
extern const unsigned char desc_803b7ed8[];  // ColumnName
extern const unsigned char desc_803b7f0c[];  // WidthPercent
extern const unsigned char desc_803b7f3c[];  // Ratio
extern const unsigned char desc_803b7f64[];  // Justification
extern const unsigned char desc_803b7f9c[];  // UnevenColumns
extern char lbl_803b7fc4[];
extern char lbl_803b7fcc[];
extern char lbl_8045ed58[];
extern char lbl_8045ed94[];
extern "C" int w3d_d21e_register_table_column_properties_802262c4(Ptr32<void> owner) {
    fn_801ed24c(owner, desc_803b7ed8)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ec52c(owner, desc_803b7f0c);
    fn_801ec52c(owner, desc_803b7f3c);
    fn_801ece2c(owner, desc_803b7f64);
    fn_801eb674(owner, desc_803b7f9c);
    static PropertyInfo info5 = ({
        PropertyInfo t;
        memset(w3d::VA(&t), 0, sizeof(t));
        t.name = lbl_803b7fc4;  // "Values"
        t.size = 24;
        t.elementType = 5;
        t.type = 9;
        t.typeObject = lbl_8045ed94;
        t;
    });
    fn_801efff0(owner, &info5);
    static PropertyInfo info16 = ({
        PropertyInfo t;
        unsigned n = sizeof(t);
        memset(w3d::VA(&t), 0, n);
        t.name = lbl_803b7fcc;  // "Data"
        t.size = n;
        t.elementType = 6;
        t.type = 9;
        t.typeObject = lbl_8045ed58;
        t;
    });
    fn_801efe60(owner, &info16);
    fn_801e8d9c(owner);
    return 0;
}


