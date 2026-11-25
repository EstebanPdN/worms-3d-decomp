// Front-end combo box widget property registration (Worms 3D GameCube PAL, 0x802233ac).
//
// In call order: resets the GameDataId string binding (0x801ed24c) to the
// shared empty string; resets the DataIndexId string binding (0x801ed24c) to
// the shared empty string; resets the HighlightedMessage string binding
// (0x801ed24c) to the shared empty string; resets the SelectedMessage string
// binding (0x801ed24c) to the shared empty string; resets the
// ControlHighlightMessage string binding (0x801ed24c) to the shared empty
// string; registers BorderColour (0x801ece2c); registers SliderAlwaysOn
// (0x801eb674); registers SliderTabExpand (0x801eb674); registers
// BackGroundType (0x801ece2c); registers DropDownSize (0x801ec52c);
// registers ItemHeight (0x801ec52c); registers ButtonArea (0x801ec52c);
// registers ControlFontSize (0x801ec52c); sets the OpenAudio string binding
// (0x801ed24c) to a temporary string made from "A.MenuDown" (0x803b7250,
// constructor 0x8020bb54); sets the CloseAudio string binding (0x801ed24c)
// to a temporary string made from "A.MenuDown" (0x803b7250, constructor
// 0x8020bb54); registers KeepComboOpen (0x801eb674); registers BorderSize
// (0x801ec52c); then calls the refresh routine 0x801e8d9c and returns 0.
// Names are read from the descriptors' name pointers in the original data.
//
// String resets assign a temporary copy of the shared empty string
// 0x804b06a0 (copy constructor, shared-header assignment, destructor), as in
// d20e_timer_widget_reset_80223a78.  No saved FPR, no extra compiler
// options.
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
void * fn_801ec52c(void *, const void *);
void fn_801f25b0(void *, PropertyInfo *);
void fn_801efec4(void *, PropertyInfo *);
void fn_801efdfc(void *, PropertyInfo *);
void fn_801eff8c(void *, PropertyInfo *);
void fn_801e8d9c(void *);
}
extern "C" void * fn_801ece2c(void *, const void *);
extern const unsigned char desc_803b726c[];  // GameDataId
extern const unsigned char desc_803b729c[];  // DataIndexId
extern const unsigned char desc_803b72c0[];  // HighlightedMessage
extern const unsigned char desc_803b72e4[];  // SelectedMessage
extern const unsigned char desc_803b7320[];  // ControlHighlightMessage
extern const unsigned char desc_803b7344[];  // BorderColour
extern const unsigned char desc_803b736c[];  // SliderAlwaysOn
extern const unsigned char desc_803b7394[];  // SliderTabExpand
extern const unsigned char desc_803b73bc[];  // BackGroundType
extern const unsigned char desc_803b73f4[];  // DropDownSize
extern const unsigned char desc_803b741c[];  // ItemHeight
extern const unsigned char desc_803b7450[];  // ButtonArea
extern const unsigned char desc_803b7488[];  // ControlFontSize
extern const unsigned char desc_803b74bc[];  // OpenAudio
extern const unsigned char desc_803b74ec[];  // CloseAudio
extern const unsigned char desc_803b7520[];  // KeepComboOpen
extern const unsigned char desc_803b7548[];  // BorderSize
extern const char lit_803b7250[];  // "A.MenuDown"
extern "C" int w3d_d24e_register_combo_box_properties_802233ac(void *owner) {
    fn_801ed24c(owner, desc_803b726c)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b729c)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b72c0)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b72e4)->value.set(d20e_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7320)->value.set(d20e_empty_804b06a0[0]);
    fn_801ece2c(owner, desc_803b7344);
    fn_801eb674(owner, desc_803b736c);
    fn_801eb674(owner, desc_803b7394);
    fn_801ece2c(owner, desc_803b73bc);
    fn_801ec52c(owner, desc_803b73f4);
    fn_801ec52c(owner, desc_803b741c);
    fn_801ec52c(owner, desc_803b7450);
    fn_801ec52c(owner, desc_803b7488);
    fn_801ed24c(owner, desc_803b74bc)->value.set(lit_803b7250);
    fn_801ed24c(owner, desc_803b74ec)->value.set(lit_803b7250);
    fn_801eb674(owner, desc_803b7520);
    fn_801ec52c(owner, desc_803b7548);
    fn_801e8d9c(owner);
    return 0;
}
