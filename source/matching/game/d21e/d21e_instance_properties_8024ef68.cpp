// Instance pool property registration (Worms 3D GameCube PAL, 0x8024ef68).
//
// In call order: resets the Name string binding (0x801ed24c) to the shared
// empty string; registers MaxInstanceCount (0x801efdfc) with a guarded
// function-local static descriptor built once from a zero-filled temporary;
// then calls the refresh routine 0x801e8d9c and returns 0. Names are read
// from the descriptors' name pointers in the original data.
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
void fn_801eb674(void *, const void *);
void fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void * fn_801efdfc(void *, PropertyInfo *);
void fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}

extern const unsigned char desc_803c557c[];  // Name
extern char lbl_803c553c[];
extern char lbl_8045ed4c[];
extern "C" int w3d_d21e_register_instance_properties_8024ef68(void *owner) {
    fn_801ed24c(owner, desc_803c557c)->value = SharedString(d20e_empty_804b06a0[0]);
    static PropertyInfo info1 = ({
        PropertyInfo t;
        unsigned n = sizeof(t);
        memset(&t, 0, n);
        t.name = lbl_803c553c;  // "MaxInstanceCount"
        t.size = n;
        t.elementType = 1;
        t.type = 9;
        t.typeObject = lbl_8045ed4c;
        t;
    });
    fn_801efdfc(owner, &info1);
    fn_801e8d9c(owner);
    return 0;
}
