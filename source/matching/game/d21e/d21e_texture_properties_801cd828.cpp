// Texture property registration (Worms 3D GameCube PAL, 0x801cd828).
//
// In call order: resets the Name string binding (0x801ed24c) to the shared
// empty string; registers Width (0x801ebbb8); registers Height (0x801ebbb8);
// registers MipLevels (0x801ebbb8); registers Flags (0x801ebbb8); registers
// Strides (0x801efdfc) with a guarded function-local static descriptor built
// once from a zero-filled temporary; registers Offsets (0x801efdfc) with a
// guarded function-local static descriptor built once from a zero-filled
// temporary; registers Format (0x801ece2c); registers Data (0x801efd34) with
// a guarded function-local static descriptor built once from a zero-filled
// temporary; registers Palette (0x801ecc6c); then calls the refresh routine
// 0x801e8d9c and returns 0. Names are read from the descriptors' name
// pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Property descriptors are function-local
// statics initialized from a GNU statement expression over a memset-zeroed
// local (d20e_box_properties_801c4930); guards and objects are
// zero-initialized statics of this function, not file-backed. No saved FPR,
// no extra compiler options.
extern "C" void *memset(...);
struct SharedString;
extern "C" void d20e_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *d20e_string_header_80341884(SharedString *);
extern "C" void d20e_string_finish_8020c5c4(SharedString *);
extern "C" void d20e_string_release_80341588(SharedString *);
extern "C" void d20e_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;

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
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
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
void fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void * fn_801efdfc(void *, PropertyInfo *);
void fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}
extern "C" void * fn_801ebbb8(void *, const void *);
extern "C" void * fn_801ecc6c(void *, const void *);
extern "C" void * fn_801ece2c(void *, const void *);
extern "C" void * fn_801efd34(void *, PropertyInfo *);
extern const unsigned char desc_803ae7c4[];  // Name
extern const unsigned char desc_803ae7f0[];  // Width
extern const unsigned char desc_803ae820[];  // Height
extern const unsigned char desc_803ae854[];  // MipLevels
extern const unsigned char desc_803ae87c[];  // Flags
extern const unsigned char desc_803ae8bc[];  // Format
extern const unsigned char desc_803ae8f4[];  // Palette
extern char lbl_803ae8a4[];
extern char lbl_803ae8ac[];
extern char lbl_803ae8e4[];
extern char lbl_8045ed1c[];
extern char lbl_8045ed4c[];
extern "C" int w3d_d21e_register_texture_properties_801cd828(void *owner) {
    fn_801ed24c(owner, desc_803ae7c4)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ebbb8(owner, desc_803ae7f0);
    fn_801ebbb8(owner, desc_803ae820);
    fn_801ebbb8(owner, desc_803ae854);
    fn_801ebbb8(owner, desc_803ae87c);
    static PropertyInfo info5 = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803ae8a4;  // "Strides"
        t.size = 32;
        t.elementType = 5;
        t.type = 9;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &info5);
    static PropertyInfo info16 = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803ae8ac;  // "Offsets"
        t.size = 28;
        t.elementType = 6;
        t.type = 9;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &info16);
    fn_801ece2c(owner, desc_803ae8bc);
    static PropertyInfo info28 = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803ae8e4;  // "Data"
        t.size = 48;
        t.elementType = 8;
        t.type = 9;
        t.typeObject = lbl_8045ed1c;
        t;
    });
    fn_801efd34(owner, &info28);
    fn_801ecc6c(owner, desc_803ae8f4);
    fn_801e8d9c(owner);
    return 0;
}
