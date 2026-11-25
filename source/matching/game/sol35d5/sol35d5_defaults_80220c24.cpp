// Inferred color descriptor registration and observed shared-string lifetimes.
struct SharedString;
extern "C" void sol35d5_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *sol35d5_string_header_80341884(SharedString *);
extern "C" void sol35d5_string_finish_8020c5c4(SharedString *);
extern "C" void sol35d5_string_release_80341588(SharedString *);
extern "C" void sol35d5_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;
    SharedString(const char *);

    // A real external C++ constructor preserves the observed call lifetime.

    SharedString(const SharedString &other) {
        sol35d5_string_init_8020c5c0(this);
        text = other.text;
        ++*sol35d5_string_header_80341884(this);
    }

    ~SharedString() {
        sol35d5_string_finish_8020c5c4(this);
        sol35d5_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            sol35d5_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString sol35d5_empty_804b06a0[];
// Four observed byte channels, with a word copy at the binding boundary.
union Color {
    struct Channels {
        unsigned char red, green, blue, alpha;
    } channels;
    unsigned word;

    Color(unsigned char red, unsigned char green,
          unsigned char blue, unsigned char alpha) {
        channels.red = red;
        channels.green = green;
        channels.blue = blue;
        channels.alpha = alpha;
    }
};

struct ColorBinding {
    unsigned header[2];
    Color value;
};

typedef char ColorSize[sizeof(Color) == 4 ? 1 : -1];
typedef char ColorOffset[(unsigned)&((ColorBinding*)0)->value == 8 ? 1 : -1];

extern "C" {
StringBinding *fn_801ed24c(void *, const void *);
ColorBinding *fn_801f15e0(void *, const void *);
void *fn_801eb674(void *, const void *);
void *fn_801ec52c(void *, const void *);
void fn_801e8d9c(void *);
}
extern const char desc_803b6408[];
extern const unsigned char desc_803b6668[];
extern const unsigned char desc_803b669c[];
extern const unsigned char desc_803b66c8[];
extern const unsigned char desc_803b66f8[];
extern const unsigned char desc_803b672c[];
extern const unsigned char desc_803b6754[];
extern "C" int sol35d5_defaults_80220c24(void *owner) {
    fn_801ed24c(owner, desc_803b6668)->value = SharedString(desc_803b6408);
    fn_801ed24c(owner, desc_803b669c)->value = SharedString(sol35d5_empty_804b06a0[0]);
    fn_801f15e0(owner, desc_803b66c8)->value = Color(255,255,255,255);
    fn_801eb674(owner, desc_803b66f8);
    fn_801eb674(owner, desc_803b672c);
    fn_801ec52c(owner, desc_803b6754);
    fn_801e8d9c(owner);
    return 0;
}
