// Menu property registration (Worms 3D GameCube PAL, 0x80225ab8).
//
// In call order: resets the ActiveItem string binding (0x801ed24c) to the
// shared empty string; resets the DefaultCancelItem string binding
// (0x801ed24c) to the shared empty string; resets the DefaultAcceptItem
// string binding (0x801ed24c) to the shared empty string; resets the
// MenuName string binding (0x801ed24c) to the shared empty string; resets
// the InitMessages string binding (0x801ed24c) to the shared empty string;
// registers PreventActiveUpdate (0x801eb674); registers MenuItems
// (0x801eff8c) with a guarded function-local static descriptor built once
// from a zero-filled temporary; then calls the refresh routine 0x801e8d9c
// and returns 0. Names are read from the descriptors' name pointers in the
// original data.
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
void * fn_801eb674(void *, const void *);
void fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void fn_801efdfc(void *, PropertyInfo *);
void * fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}

extern const unsigned char desc_803b7d40[];  // ActiveItem
extern const unsigned char desc_803b7d78[];  // DefaultCancelItem
extern const unsigned char desc_803b7db0[];  // DefaultAcceptItem
extern const unsigned char desc_803b7de0[];  // MenuName
extern const unsigned char desc_803b7e14[];  // InitMessages
extern const unsigned char desc_803b7e4c[];  // PreventActiveUpdate
extern char lbl_803b7e74[];
extern char lbl_804007cc[];
extern char lbl_8045e004[];
extern "C" int w3d_d21e_register_menu_properties_80225ab8(void *owner) {
    fn_801ed24c(owner, desc_803b7d40)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7d78)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7db0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7de0)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7e14)->value = SharedString(d20e_empty_804b06a0[0]);
    fn_801eb674(owner, desc_803b7e4c);
    static PropertyInfo info6 = ({
        PropertyInfo t;
        unsigned n = sizeof(t);
        memset(&t, 0, n);
        t.name = lbl_803b7e74;  // "MenuItems"
        t.size = n;
        t.elementType = 6;
        t.type = 9;
        t.typeObject = lbl_8045e004;
        t.member = lbl_804007cc;
        t;
    });
    fn_801eff8c(owner, &info6);
    fn_801e8d9c(owner);
    return 0;
}
