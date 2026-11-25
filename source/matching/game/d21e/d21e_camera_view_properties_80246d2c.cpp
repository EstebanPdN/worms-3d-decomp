// Camera view property registration (Worms 3D GameCube PAL, 0x80246d2c).
//
// In call order: registers Camera2ObjectDistance (0x801ec52c); registers
// LookSpeed (0x801ec52c); registers UpSpeed (0x801ec52c); registers
// ZoomSpeed (0x801ec52c); registers MinPreferredDistance (0x801ec52c);
// registers MinPosition (0x801ec52c); registers MinTimeBetweenCuts
// (0x801ebf38); registers ViewPoint (0x801f254c) with a guarded function-
// local static descriptor built once from a zero-filled temporary; then
// calls the refresh routine 0x801e8d9c and returns 0. Names are read from
// the descriptors' name pointers in the original data.
//
// Property descriptors are function-local statics initialized from a GNU
// statement expression over a memset-zeroed local
// (d20e_box_properties_801c4930); guards and objects are zero-initialized
// statics of this function, not file-backed. The static descriptor (size 20)
// is zeroed through an inline clear() member and its size is the descriptor
// size held in a local (unsigned n = sizeof(t)): direct memset 25-26 words,
// clear() with a literal 20 13-17 words (register swap). No saved FPR, no
// extra compiler options.
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
void * fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void fn_801efdfc(void *, PropertyInfo *);
void fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}
extern "C" void * fn_801ebf38(void *, const void *);
extern "C" void * fn_801f254c(void *, PropertyInfo *);
extern const unsigned char desc_803c33cc[];  // Camera2ObjectDistance
extern const unsigned char desc_803c3400[];  // LookSpeed
extern const unsigned char desc_803c3430[];  // UpSpeed
extern const unsigned char desc_803c3464[];  // ZoomSpeed
extern const unsigned char desc_803c34a4[];  // MinPreferredDistance
extern const unsigned char desc_803c34d8[];  // MinPosition
extern const unsigned char desc_803c3514[];  // MinTimeBetweenCuts
extern char lbl_803c353c[];
extern char lbl_8045e494[];
extern "C" int w3d_d21e_register_camera_view_properties_80246d2c(void *owner) {
    fn_801ec52c(owner, desc_803c33cc);
    fn_801ec52c(owner, desc_803c3400);
    fn_801ec52c(owner, desc_803c3430);
    fn_801ec52c(owner, desc_803c3464);
    fn_801ec52c(owner, desc_803c34a4);
    fn_801ec52c(owner, desc_803c34d8);
    fn_801ebf38(owner, desc_803c3514);
    static PropertyInfo info7 = ({
        PropertyInfo t;
        unsigned n = sizeof(t);
        t.clear();
        t.name = lbl_803c353c;  // "ViewPoint"
        t.size = n;
        t.elementType = 7;
        t.type = 9;
        t.typeObject = lbl_8045e494;
        t;
    });
    fn_801f254c(owner, &info7);
    fn_801e8d9c(owner);
    return 0;
}
