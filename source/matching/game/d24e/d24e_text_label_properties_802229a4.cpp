// Front-end colour text label widget property registration (Worms 3D GameCube PAL, 0x802229a4).
//
// In call order: sets the ResourceName string binding (0x801ed24c) to a
// temporary string made from "FE.Font" (0x803b6408, constructor 0x8020bb54);
// resets the TextGameDataId string binding (0x801ed24c) to the shared empty
// string; registers TextRed (0x801ebf38); registers TextGreen (0x801ebf38);
// registers TextBlue (0x801ebf38); registers BorderWidth (0x801ec52c);
// registers TextPlacement (0x801ece2c); registers FrameOffset (0x801ebf38);
// then calls the refresh routine 0x801e8d9c and returns 0. Names are read
// from the descriptors' name pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. String defaults go through an inline
// set() taking the string by value, which builds the temporary at the call.
// No saved FPR, no extra compiler options.
extern "C" void *memset(...);
struct String_8020bb54;
extern "C" void d20e_string_init_8020c5c0(String_8020bb54 *);
extern "C" unsigned short *d20e_string_header_80341884(String_8020bb54 *);
extern "C" void d20e_string_finish_8020c5c4(String_8020bb54 *);
extern "C" void d20e_string_release_80341588(String_8020bb54 *);
extern "C" void d20e_release_header_8020bb2c(unsigned short *);

struct String_8020bb54 {
    char *text;

    // Copy constructor: initializes the shared string and takes a
    // reference on the source text (16-bit header counter).
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
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
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
    const char *name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    void *typeObject;
    const void *member;
    int unknown16;
    void clear() { memset(this, 0, sizeof(*this)); }
};
extern "C" {
StringBinding *fn_801ed24c(void *, const void *);
VectorBinding *fn_801f0210(void *, const void *);
Vec2Binding *fn_801f00f0(void *, const void *);
ColourBinding *fn_801f15e0(void *, const void *);
void fn_801eb834(void *, const void *);
void fn_801eb674(void *, const void *);
void * fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void fn_801efdfc(void *, PropertyInfo *);
void fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}
extern "C" void * fn_801ebf38(void *, const void *);
extern "C" void * fn_801ece2c(void *, const void *);
extern const unsigned char desc_803b6e88[];  // ResourceName
extern const unsigned char desc_803b6eac[];  // TextGameDataId
extern const unsigned char desc_803b6ed8[];  // TextRed
extern const unsigned char desc_803b6f0c[];  // TextGreen
extern const unsigned char desc_803b6f40[];  // TextBlue
extern const unsigned char desc_803b6f74[];  // BorderWidth
extern const unsigned char desc_803b6fac[];  // TextPlacement
extern const unsigned char desc_803b6fe0[];  // FrameOffset
extern const char lit_803b6408[];  // "FE.Font"
extern "C" int w3d_d24e_register_text_label_properties_802229a4(void *owner) {
    fn_801ed24c(owner, desc_803b6e88)->value.set(lit_803b6408);
    fn_801ed24c(owner, desc_803b6eac)->value.set(d20e_empty_804b06a0[0]);
    fn_801ebf38(owner, desc_803b6ed8);
    fn_801ebf38(owner, desc_803b6f0c);
    fn_801ebf38(owner, desc_803b6f40);
    fn_801ec52c(owner, desc_803b6f74);
    fn_801ece2c(owner, desc_803b6fac);
    fn_801ebf38(owner, desc_803b6fe0);
    fn_801e8d9c(owner);
    return 0;
}
