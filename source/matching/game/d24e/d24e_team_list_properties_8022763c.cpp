// Front-end team list widget property registration (Worms 3D GameCube PAL, 0x8022763c).
//
// In call order: sets the TeamName string binding (0x801ed24c) to a
// temporary string made from "TeamName" (0x803b81a8, constructor
// 0x8020bb54); registers Worms (0x801efff0) with a guarded function-local
// static descriptor built once from a zero-filled temporary; registers
// Campaign (0x801eff8c) with a guarded function-local static descriptor
// built once from a zero-filled temporary; registers TutorialsDone
// (0x801ebf38); registers NewTeam (0x801ebf38); registers Skill
// (0x801ec0f8); registers Grave (0x801ec0f8); registers SWeapon
// (0x801ec0f8); sets the Flag string binding (0x801ed24c) to a temporary
// string made from "0" (0x803b81a4, constructor 0x8020bb54); sets the Speech
// string binding (0x801ed24c) to a temporary string made from "Classic"
// (0x803b819c, constructor 0x8020bb54); registers InGame (0x801eb674); sets
// the Player string binding (0x801ed24c) to a temporary string made from ""
// (0x803b8198, constructor 0x8020bb54); then calls the refresh routine
// 0x801e8d9c and returns 0. Names are read from the descriptors' name
// pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78. Property descriptors are function-local
// statics initialized from a GNU statement expression over a memset-zeroed
// local (d20e_box_properties_801c4930); guards and objects are zero-
// initialized statics of this function, not file-backed. First guarded
// descriptor uses a direct memset, second the inline clear().  No saved FPR,
// no extra compiler options.
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
void * fn_801eb674(void *, const void *);
void fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void fn_801efdfc(void *, PropertyInfo *);
void * fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}
extern "C" void * fn_801ebf38(void *, const void *);
extern "C" void * fn_801ec0f8(void *, const void *);
extern "C" void * fn_801efff0(void *, PropertyInfo *);
extern const unsigned char desc_803b81b4[];  // TeamName
extern const unsigned char desc_803b81fc[];  // TutorialsDone
extern const unsigned char desc_803b822c[];  // NewTeam
extern const unsigned char desc_803b825c[];  // Skill
extern const unsigned char desc_803b828c[];  // Grave
extern const unsigned char desc_803b82bc[];  // SWeapon
extern const unsigned char desc_803b82ec[];  // Flag
extern const unsigned char desc_803b8318[];  // Speech
extern const unsigned char desc_803b8344[];  // InGame
extern const unsigned char desc_803b8374[];  // Player
extern char lbl_803b81d8[];
extern char lbl_803b81e0[];
extern char lbl_804007e4[];
extern char lbl_8045e004[];
extern char lbl_8045ed94[];
extern const char lit_803b8198[];  // ""
extern const char lit_803b819c[];  // "Classic"
extern const char lit_803b81a4[];  // "0"
extern const char lit_803b81a8[];  // "TeamName"
extern "C" int w3d_d24e_register_team_list_properties_8022763c(void *owner) {
    fn_801ed24c(owner, desc_803b81b4)->value.set(lit_803b81a8);
    static PropertyInfo info1 = ({
        PropertyInfo t;
        memset(&t, 0, sizeof(t));
        t.name = lbl_803b81d8;  // "Worms"
        t.size = 56;
        t.elementType = 1;
        t.type = 9;
        t.typeObject = lbl_8045ed94;
        t;
    });
    fn_801efff0(owner, &info1);
    static PropertyInfo info12 = ({
        PropertyInfo t;
        t.clear();
        t.name = lbl_803b81e0;  // "Campaign"
        t.size = 52;
        t.elementType = 2;
        t.type = 9;
        t.typeObject = lbl_8045e004;
        t.member = lbl_804007e4;
        t;
    });
    fn_801eff8c(owner, &info12);
    fn_801ebf38(owner, desc_803b81fc);
    fn_801ebf38(owner, desc_803b822c);
    fn_801ec0f8(owner, desc_803b825c);
    fn_801ec0f8(owner, desc_803b828c);
    fn_801ec0f8(owner, desc_803b82bc);
    fn_801ed24c(owner, desc_803b82ec)->value.set(lit_803b81a4);
    fn_801ed24c(owner, desc_803b8318)->value.set(lit_803b819c);
    fn_801eb674(owner, desc_803b8344);
    fn_801ed24c(owner, desc_803b8374)->value.set(lit_803b8198);
    fn_801e8d9c(owner);
    return 0;
}
