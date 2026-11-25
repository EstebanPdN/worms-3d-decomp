// Inferred color descriptor registration and observed shared-string lifetimes.
struct SharedString;
extern "C" void sol35d5_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *sol35d5_string_header_80341884(SharedString *);
extern "C" void sol35d5_string_finish_8020c5c4(SharedString *);
extern "C" void sol35d5_string_release_80341588(SharedString *);
extern "C" void sol35d5_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;

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
// Three observed float stores followed by a twelve-byte representation copy.
// Union view is a hypothesis; no fourth field is inferred from stack stride.
union Vec3 {
    struct Components { float x,y,z; } components;
    unsigned words[3];
    Vec3(float x,float y,float z) {
        components.x=x; components.y=y; components.z=z;
    }
};
struct VectorBinding { unsigned header[2]; Vec3 value; };
extern "C" {
StringBinding *fn_801ed24c(void *, const void *);
VectorBinding *fn_801f0210(void *, const void *);
void *fn_801ece2c(void *, const void *);
void fn_801e8d9c(void *);
}
extern const float constant_803b76c8[], constant_803b76cc[];
extern const unsigned char desc_803b7598[];
extern const unsigned char desc_803b75bc[];
extern const unsigned char desc_803b75e0[];
extern const unsigned char desc_803b7618[];
extern const unsigned char desc_803b763c[];
extern const unsigned char desc_803b7674[];
extern const unsigned char desc_803b76a4[];
extern "C" int sol35d5_defaults_80223a78(void *owner) {
    fn_801ed24c(owner, desc_803b7598)->value = SharedString(sol35d5_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b75bc)->value = SharedString(sol35d5_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b75e0)->value = SharedString(sol35d5_empty_804b06a0[0]);
    fn_801ed24c(owner, desc_803b7618)->value = SharedString(sol35d5_empty_804b06a0[0]);
    fn_801ece2c(owner, desc_803b763c);
    VectorBinding *first = fn_801f0210(owner, desc_803b7674);
    float zero = constant_803b76c8[0];
    first->value = Vec3(zero, zero, zero);
    fn_801f0210(owner, desc_803b76a4)->value = Vec3(constant_803b76cc[0],constant_803b76cc[0],zero);
    fn_801e8d9c(owner);
    return 0;
}
typedef char VecSize[sizeof(Vec3)==12?1:-1];
